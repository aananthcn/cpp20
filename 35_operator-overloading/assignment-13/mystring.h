#include <iostream>
#include <cstring>
#include <algorithm> // Required for std::min/std::max if you use them, but not strictly needed for the below methods.
#include <stdexcept> // Good practice for throwing exceptions on errors

namespace CU{

class string{
    // --- Friends ---
    friend std::ostream& operator<< (std::ostream& out , const CU::string& s);
    friend string operator+(const string& left, const string& right);
    friend string& operator+=(string& left, const string& right);

private:
    // Helper function to handle memory reallocation and data copying
    void reallocate_and_copy(size_t new_size, const char* data_to_copy, size_t data_length) {
        // Ensure null termination space is included in size
        if (new_size <= data_length) {
            new_size = data_length + 1;
        }

        char* new_data = new char[new_size];
        if (data_to_copy) {
            std::strncpy(new_data, data_to_copy, data_length);
            new_data[data_length] = '\0'; // Manually null-terminate
        } else {
            new_data[0] = '\0';
        }
        
        delete[] m_data;
        m_data = new_data;
        m_size = new_size;
    }

public : 
    // Default constructor
    string() : m_size(1), m_data(new char[1]) { 
        m_data[0] = '\0'; 
    }

    // C-string constructor
    // NOTE: I've updated this to calculate the size based on the input data,
    // which is standard practice, instead of using a hardcoded default.
    string(const char* data) {
        size_t len = std::strlen(data);
        m_size = len + 1; // Size must include the null-terminator
        m_data = new char [m_size];
        std::strcpy(m_data, data);
    }
    
    // Original C-string constructor with size (retained for backward compatibility, but less useful)
    string(const char* data, size_t size){
        size_t len = std::strlen(data);
        m_size = std::max(size, len + 1);
        m_data = new char [m_size];
        std::strcpy(m_data, data);
    }

    // Copy constructor (Deep Copy)
    string(const string& source){
        reallocate_and_copy(source.m_size, source.m_data, source.length());
    }

    // Copy assignment operator (Deep Copy, with self-assignment check and cleanup)
    string& operator= (const string& right_operand){
        // std::cout << "Copy assignment operator called" << std::endl; // Commented out for cleaner output
        if(this != & right_operand){
            // 1. Clean up old memory
            delete[] m_data;
            
            // 2. Allocate new memory and copy data
            m_size = right_operand.m_size;
            m_data = new char [m_size];
            std::strcpy(m_data, right_operand.m_data);
        }
        return *this;
    }

    // --- New Methods ---

    /**
     * @brief Clears the contents of the string, making it an empty string (length 0).
     */
    void clear(){
        if (m_data) {
            m_data[0] = '\0';
        } else {
            reallocate_and_copy(1, nullptr, 0); // Re-initialize to a 1-char buffer with '\0'
        }
    }

    /**
     * @brief Compares the value of the string to the argument string.
     * @return An integer value indicating the result of the comparison:
     * < 0 : *this is less than str
     * 0   : *this is equal to str
     * > 0 : *this is greater than str
     */
    int compare(const string& str) const {
        return std::strcmp(m_data, str.m_data);
    }

    /**
     * @brief Appends a copy of str to the string.
     */
    void append(const string& str) {
        *this += str; // Utilize the compound assignment operator
    }

    /**
     * @brief Inserts a copy of str at the position pos.
     * @param pos The position in the string to insert the string.
     * @param str The string to insert.
     */
    string& insert(size_t pos, const string& str) {
        size_t current_len = length();
        if (pos > current_len) {
            throw std::out_of_range("insert: position out of range");
        }

        size_t insert_len = str.length();
        size_t new_len = current_len + insert_len;
        size_t new_size = new_len + 1;

        // Allocate a new buffer
        char* new_data = new char[new_size];

        // 1. Copy part before insertion point
        std::strncpy(new_data, m_data, pos);

        // 2. Copy the inserted string
        std::strcpy(new_data + pos, str.m_data);

        // 3. Copy the part after the insertion point
        std::strcpy(new_data + pos + insert_len, m_data + pos);

        // Update members
        delete[] m_data;
        m_data = new_data;
        m_size = new_size;

        return *this;
    }

    /**
     * @brief Erases a portion of the string.
     * @param pos The starting position.
     * @param len The number of characters to erase. Defaults to npos (until the end).
     */
    string& erase(size_t pos, size_t len = npos) {
        size_t current_len = length();
        if (pos > current_len) {
            throw std::out_of_range("erase: position out of range");
        }

        // Adjust len to not go past the end of the string
        if (len == npos || pos + len > current_len) {
            len = current_len - pos;
        }

        // Move the characters that follow the erased part
        size_t chars_to_move = current_len - (pos + len) + 1; // +1 for null terminator
        std::memmove(m_data + pos, m_data + pos + len, chars_to_move);
        
        // Update size, though we're not reallocating immediately, the effective length changes.
        // Shrinking the buffer is an optimization; for simplicity, we just null-terminate.
        // We ensure the new end is null-terminated.
        m_data[current_len - len] = '\0';

        return *this;
    }

    // --- Existing Methods ---

    const char* c_str() const{
        return m_data;
    }

    size_t length() const {
        if (!m_data) return 0;
        return std::strlen(m_data);
    }
    
    // A constant to represent "until the end" for erase method
    static const size_t npos = -1; 

    // Destructor
    ~string(){
        delete [] m_data;
        m_data = nullptr;
    }
    
private : 
    // m_size is the total allocated memory (including null terminator)
    size_t m_size; 
    // m_data points to the character buffer
    char * m_data{nullptr};
};

// --- Global Friend Functions ---

inline std::ostream& operator<< (std::ostream& out , const CU::string& s){
    out << s.m_data;
    return out;
}

// FIX and Implementation for operator+=
inline string& operator+=(string& left, const string& right){
    size_t left_len = left.length();
    size_t right_len = right.length();
    size_t new_len = left_len + right_len;
    size_t new_size = new_len + 1;

    // Check if current buffer is large enough (m_size includes the null-terminator)
    if (new_size > left.m_size) {
        // Reallocate: Create new buffer, copy old data, then copy new data
        char* new_data = new char[new_size];
        std::strcpy(new_data, left.m_data); // Copy old content

        delete[] left.m_data;
        left.m_data = new_data;
        left.m_size = new_size;
    }

    // Append the right string
    std::strcat(left.m_data, right.m_data);
    
    return left;
}

inline string operator+(const string& left, const string& right){
    // Use the compound assignment operator for efficiency and correctness
    string tmp(left); 
    tmp += right;
    return tmp;
}

} // end namespace CU
#include <iostream>
#include <cstring>
#include <stdexcept>

#include "mystring.h"

// --- Test Utilities ---
#define TEST_ASSERT(condition, message) \
    if (!(condition)) { \
        std::cout << "[ FAILED ] " << message << std::endl; \
        return false; \
    }

using namespace CU;

// --- Test Functions ---

/**
 * @brief Tests constructors, length, and c_str().
 */
bool test_construction_and_access() {
    std::cout << "\n--- Test Construction and Access ---" << std::endl;
    
    // 1. C-string Constructor
    string s1("Hello");
    TEST_ASSERT(s1.length() == 5, "C-string construction length.");
    TEST_ASSERT(std::strcmp(s1.c_str(), "Hello") == 0, "C-string construction content.");

    // 2. Copy Constructor
    string s2 = s1;
    TEST_ASSERT(s2.length() == 5, "Copy constructor length.");
    TEST_ASSERT(std::strcmp(s2.c_str(), "Hello") == 0, "Copy constructor content.");
    
    // Check for deep copy (modifying original shouldn't affect copy)
    s1 = "World";
    TEST_ASSERT(std::strcmp(s2.c_str(), "Hello") == 0, "Deep copy check.");

    std::cout << "[ PASSED ] Construction and Access tests." << std::endl;
    return true;
}

/**
 * @brief Tests Copy Assignment Operator and stream operator.
 */
bool test_operators_assignment_and_stream() {
    std::cout << "\n--- Test Operators (=, <<) ---" << std::endl;
    
    string s1("Initial");
    string s2("Target");

    // 1. Copy Assignment
    s2 = s1;
    TEST_ASSERT(s2.length() == 7, "Copy assignment length.");
    TEST_ASSERT(std::strcmp(s2.c_str(), "Initial") == 0, "Copy assignment content.");

    // 2. Self Assignment (should not crash)
    s1 = s1;
    TEST_ASSERT(s1.length() == 7, "Self assignment length.");

    // 3. Stream Operator (just print, cannot easily assert output)
    std::cout << "Stream Output Test (Should show 'Initial'): " << s2 << std::endl;

    std::cout << "[ PASSED ] Assignment and Stream tests." << std::endl;
    return true;
}

/**
 * @brief Tests Concatenation Operators (+, +=).
 */
bool test_operators_concatenation() {
    std::cout << "\n--- Test Concatenation Operators (+, +=) ---" << std::endl;

    string s1("Hello, ");
    string s2("World!");

    // 1. operator+ (creates new string)
    string s3 = s1 + s2;
    TEST_ASSERT(s3.length() == 13, "operator+ length.");
    TEST_ASSERT(std::strcmp(s3.c_str(), "Hello, World!") == 0, "operator+ content.");

    // 2. operator+= (modifies left operand, tests reallocation)
    string s4("Test");
    s4 += "ing";
    TEST_ASSERT(s4.length() == 7, "operator+= length (literal).");
    TEST_ASSERT(std::strcmp(s4.c_str(), "Testing") == 0, "operator+= content (literal).");

    s4 += s2; // TestingWorld!
    TEST_ASSERT(s4.length() == 13, "operator+= length (string).");
    TEST_ASSERT(std::strcmp(s4.c_str(), "TestingWorld!") == 0, "operator+= content (string).");

    std::cout << "[ PASSED ] Concatenation tests." << std::endl;
    return true;
}

/**
 * @brief Tests clear(), compare(), and append().
 */
bool test_core_methods() {
    std::cout << "\n--- Test Core Methods (clear, compare, append) ---" << std::endl;

    // 1. compare()
    string c1("apple");
    string c2("banana");
    string c3("apple");
    
    TEST_ASSERT(c1.compare(c3) == 0, "Compare equal strings.");
    TEST_ASSERT(c1.compare(c2) < 0, "Compare less than.");
    TEST_ASSERT(c2.compare(c1) > 0, "Compare greater than.");

    // 2. append() (Uses +=)
    string a1("Hello ");
    string a2("Universe");
    a1.append(a2);
    TEST_ASSERT(a1.length() == 14, "Append length.");
    TEST_ASSERT(std::strcmp(a1.c_str(), "Hello Universe") == 0, "Append content.");

    // 3. clear()
    a1.clear();
    TEST_ASSERT(a1.length() == 0, "Clear length.");
    TEST_ASSERT(a1.c_str()[0] == '\0', "Clear null-termination.");
    
    std::cout << "[ PASSED ] Core methods tests." << std::endl;
    return true;
}

/**
 * @brief Tests insert() and erase().
 */
bool test_manipulation_methods() {
    std::cout << "\n--- Test Manipulation Methods (insert, erase) ---" << std::endl;

    string s("abcde");
    string ins("XYZ");

    // 1. insert() - middle
    s.insert(2, ins); // "abXYZcde"
    TEST_ASSERT(s.length() == 8, "Insert middle length.");
    TEST_ASSERT(std::strcmp(s.c_str(), "abXYZcde") == 0, "Insert middle content.");

    // 2. insert() - start
    s = "world";
    s.insert(0, "Hello "); // "Hello world"
    TEST_ASSERT(s.length() == 11, "Insert start length.");
    TEST_ASSERT(std::strcmp(s.c_str(), "Hello world") == 0, "Insert start content.");

    // 3. insert() - end
    s = "start";
    s.insert(5, "end"); // "startend"
    TEST_ASSERT(s.length() == 8, "Insert end length.");
    TEST_ASSERT(std::strcmp(s.c_str(), "startend") == 0, "Insert end content.");
    
    // ---
    
    // 4. erase() - middle
    s = "0123456789";
    s.erase(3, 4); // Erase "3456" -> "012789"
    TEST_ASSERT(s.length() == 6, "Erase middle length.");
    TEST_ASSERT(std::strcmp(s.c_str(), "012789") == 0, "Erase middle content.");

    // 5. erase() - until end (using npos)
    s = "abcdefg";
    s.erase(3); // Erase from 'd' onwards -> "abc"
    TEST_ASSERT(s.length() == 3, "Erase until end length.");
    TEST_ASSERT(std::strcmp(s.c_str(), "abc") == 0, "Erase until end content.");
    
    // 6. erase() - the whole string
    s.erase(0); // -> ""
    TEST_ASSERT(s.length() == 0, "Erase all length.");
    TEST_ASSERT(s.c_str()[0] == '\0', "Erase all content.");

    std::cout << "[ PASSED ] Manipulation methods tests." << std::endl;
    return true;
}

/**
 * @brief Main test harness function.
 */
int main() {
    std::cout << "Starting CU::string Test Suite..." << std::endl;
    std::cout << "==================================" << std::endl;

    int failed_count = 0;
    
    if (!test_construction_and_access()) failed_count++;
    if (!test_operators_assignment_and_stream()) failed_count++;
    if (!test_operators_concatenation()) failed_count++;
    if (!test_core_methods()) failed_count++;
    if (!test_manipulation_methods()) failed_count++; // Requires correct insert/erase implementation

    std::cout << "\n==================================" << std::endl;
    if (failed_count == 0) {
        std::cout << "✅ All tests passed successfully!" << std::endl;
    } else {
        std::cout << "❌ " << failed_count << " test group(s) failed." << std::endl;
    }

    // This block is mainly to check if destructors are called without crashing
    // when objects go out of scope.
    {
        string d1("Destructor Test");
        string d2 = d1 + " OK";
    } // d1 and d2 destructors called here

    return failed_count;
}
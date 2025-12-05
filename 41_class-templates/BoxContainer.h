#ifndef BOX_CONTAINER_AANANTH
#define BOX_CONTAINER_AANANTH

#include <cstddef>
#include <iostream>


#define BOXC_DEFAULT_CAPACITY (16)
#define BOXC_EXPAND_STEPS 	 (8)


template <typename T>
class BoxContainer {
public:
	BoxContainer(size_t capacity = BOXC_DEFAULT_CAPACITY);
	BoxContainer(const BoxContainer& src);
	~BoxContainer();

	// methods to add items to the box
	void add(const T& item);
	bool remove_item(const T& item);
	size_t remove_all(const T& item);
	size_t size() { return m_size; }

	// in-class operators
	void operator+=(const BoxContainer& right);
	void operator=(const BoxContainer& right);

	// friends
	friend std::ostream& operator<< <T>(std::ostream& out, const BoxContainer<T>& right);

private:
	// methods
	void expand(size_t new_capacity);

	// members
	T *m_items;
	size_t m_capacity {};
	size_t m_size {};
};


// C O N S T R U C T O R S 
template <typename T>
BoxContainer<T>::BoxContainer(size_t capacity) {
	m_items = new T[capacity];
	m_capacity = capacity;
}


template <typename T>
BoxContainer<T>::BoxContainer(const BoxContainer& source) {
	// setup new box
	m_items = new T[source.m_capacity];
	m_capacity = source.m_capacity;
	m_size = source.m_size;

	// copy the items in the box
	for (size_t i = 0; i < source.size(); i++) {
		m_items[i] = source.m_items[i];
	}
}


// D E S T R U C T O R S
template <typename T>
BoxContainer<T>::~BoxContainer()
{
	delete[] m_items;
}



// P R I V A T E   F U N C T I O N S
template <typename T>
void BoxContainer<T>::expand(size_t new_capacity) {
	std::cout << "Expanding to " << new_capacity << std::endl;
	T *new_items_container;

	if (new_capacity <= m_capacity) {
		return; // the needed capacity is already there
	}

	// allocate new memory
	new_items_container = new T[new_capacity];

	// copy the items from old box to the new
	for (size_t i = 0; i < m_size; i++) {
		new_items_container[i] = m_items[i];
	}

	// release the old container memory & update the box
	delete [] m_items;
	m_items = new_items_container;
	m_capacity = new_capacity;
}



// P U B L I C   F U N C T I O N S
template <typename T>
bool BoxContainer<T>::remove_item(const T& item) {
	// search the item in the box
	size_t index = m_capacity + 999;
	for (size_t i{0}; i < m_size; i++) {
		if (m_items[i] == item) {
			index = i;
			break;
		}
	}

	if (index > m_size)
		return false;

	// copy the last item to the slot of the searched item
	m_items[index] = m_items[m_size-1];
	m_size--;

	return true;
}

template <typename T>
size_t BoxContainer<T>::remove_all(const T& item) {
	size_t remove_count {};	
	bool removed {};

	do {
		removed = remove_item(item);
		if(removed)
			++remove_count;
	} while(removed == true);
	
	return remove_count;
}


template <typename T>
void BoxContainer<T>::add(const T& item) {
	if (m_size == m_capacity)
		expand(m_size + BOXC_EXPAND_STEPS);
	m_items[m_size] = item;
	++m_size;
}



// O P E R A T O R S
template <typename T>
void BoxContainer<T>::operator+=(const BoxContainer<T>& right) {
	// expand if the current size can't fit the incoming items
	if ((m_size + right.size()) > m_capacity)
		expand(m_size + right.size());
		
	// copy over the elements
	for(size_t i{}; i < right.m_size; ++i){
		m_items[m_size + i] = right.m_items[i];
	}
	
	m_size += right.m_size;
}

template <typename T>
BoxContainer<T> operator+(const BoxContainer<T>& left, const BoxContainer<T>& right) {
	// create a new container with capacity of both boxes
	BoxContainer<T> result(left.size() + right.size());

	// add them to the new
	result += left; 
	result += right;

	// return the new box
	return result;	
}

template <typename T>
void BoxContainer<T>::operator=(const BoxContainer<T>& right) {
	T *new_items;

	// reject self assignment
	if (this == &right)
            return;

	// construct a new box if capacities are different, delete old
	if (m_capacity != right.m_capacity)
	{ 
	    delete [] m_items;
	    new_items = new T[right.m_capacity];
	    m_items = new_items;
	    m_capacity = right.m_capacity;
	}
	
	// copy the items from right 
	for (size_t i{}; i < right.size(); ++i) {
		m_items[i] = right.m_items[i];
	}
	
	m_size = right.m_size;
}

template <typename T>
inline std::ostream& operator<<(std::ostream& out, const BoxContainer<T>& right) {
	out << "Box data = [ ";
	for (int i {}; i < right.m_size; i++) {
		out << right.m_items[i] << ", ";
	}
	out << "]" << std::endl;

	return out;
}

#endif
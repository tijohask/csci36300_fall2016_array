// $Id: Array.cpp 820 2011-01-17 15:30:41Z hillj $

// Honor Pledge:
//
// I pledge that I have neither given nor receieved any help
// on this assignment.

#include "Array.h"
#include <stdexcept>

/**
 * @class Array
 *
 * Basic implementation of a standard array class for chars.
 */

/// Default constructor.
Array::Array (): data_(NULL), cur_size_(0), max_size_(0)
{

}

/**
 * Initializing constructor.
 */
//Takes in a length
Array::Array (size_t length): data_(NULL), cur_size_(length), max_size_(length)
{
	// Ryan: Ensure length is not 0 here.
	// Fix: Added if statement to make sure length is greater than 0
	if(length > 0)
	{
		data_ = new char[length];
		this->fill(' ');
	}
}

/**
 * Initializing constructor.
 */
//Takes in a length, and a character to fill in the array with
Array::Array (size_t length, char fill): data_(NULL), cur_size_(length), max_size_ (length)
{
	// Ryan: Ensure length is not 0 here.
	// Fix: Added if statement to make sure length is greater than 0
	if(length > 0)
	{
		data_ = new char[length];//create a new array
		this->fill(fill);//and fill in the array with the character
	}
}

/**
 * Copy constructor
 */
//Takes in another array object
Array::Array (const Array & array): data_(NULL), cur_size_(array.size()), max_size_(array.max_size())
{
	// Ryan: Make sure that we are not allocating an array of size 0.
	// Fix: Added if statement to make sure we are not allocating an 
	// array of size 0
	if(max_size_ > 0)
	{
		data_ = new char[max_size_];//create a new character array
		for(size_t i = 0; i < cur_size_; i++)
		{//and copy the data in from the other array
			data_[i] = array[i];
		}
	}
}

/// Destructor
Array::~Array (void)
{
	// Ryan: Check to make sure this is not NULL.
	// Fix: Added if statement to make sure data is not NULL
	if(data_ != NULL)
	{//make sure the data is pointing to something
		delete [] data_;
	}
}

/**
 * Assignment operation
 */
const Array & Array::operator = (const Array & rhs)
{
	// Ryan: Check for self-assignment first.
	// Fix: Added if statement to check for self assignment

	//(this != &rhs) compares the addresses. 
	//If the object is being assigned to itself, its caught and nothing happens
	
	//(*this != rhs) compares the actual objects.
	//It'll save time if many identical arrays are being compared to 
	//each other, but it'll waste time if the majority of arrays are not
	//similar
	
	if(this != &rhs)
	{//compare the addresses. if they're the same, nothing needs to be done
		delete [] data_; //delete the old data
		data_ = new char[rhs.max_size()]; //allocate a new char array
		cur_size_ = rhs.size();//set the sizes to their new values
		max_size_ = rhs.max_size();
		for(int i = 0; i < cur_size_; i++)
		{//iterate through the array, copying the rhs
			data_[i] = rhs[i];
		}
	}
}

/**
 * Get the character at the specified index. If the index is not
 * within the range of the array, then std::out_of_range exception
 * is thrown.
 *
 * Used as arr[index]
 */
char & Array::operator [] (size_t index)
{
	if(index >= max_size_)
	{//throw exception if out of range
		throw std::out_of_range ("Index out of range");
	}
	return data_[index];//return the character otherwise
}

/**
 * The returned character is not modifiable.
 */
const char & Array::operator [] (size_t index) const
{
	if(index >= max_size_)
	{//throw exception if out of range
		throw std::out_of_range ("Index out of range");
	}
	return data_[index];//return the character otherwise
}

/**
 * Get the character at the specified index. If the \a index is not within
 * the range of the array, then std::out_of_range exception is thrown.
 */  
char Array::get (size_t index) const
{
	if(index >= max_size_)
	{//throw exception if out of range
		throw std::out_of_range ("Index out of range");
	}	
	return data_[index];//return the character otherwise
}

/** 
 * Set the character at the specified \a index. If the \a index is not
 * within range of the array, then std::out_of_range exception is 
 * thrown.
 */
void Array::set (size_t index, char value)
{
	if(index >= max_size_)
	{//throw exception if out of range
		throw std::out_of_range ("Index out of range");
	}
	//store the value otherwise	
	data_[index] = value;
	if(cur_size_ < index)
	{//readjust current size if necessary
		cur_size_ = index;
	}

}

/**
 * Set a new size for the array. If \a new_size is less than the current
 * size, then the array is truncated. If \a new_size if greater then the
 * current size, then the array is made larger and the new elements are
 * not initialized to anything. If \a new_size is the same as the current
 * size, then nothing happens.
 *
 * The array's original contents are preserved regardless of whether the 
 * array's size is either increased or decreased.
 */
void Array::resize (size_t new_size)
{
	if(max_size_ < new_size)
	{//the array will need to be expanded

		char* hold = data_;//store the old data
		data_ = new char[new_size];//make a new array
		max_size_ = new_size;//reassign the maximum size to the new value
		this->fill(' ');
		//fill the array with blanks. the compiler doesn't like
		//assigning uninitialized values
		for(size_t i = 0; i < cur_size_; i++)
		{//iterate through and copy the old array
			data_[i] = hold[i];
		}
		delete [] hold;
		//apparently this needs to be deleted.
		//thought the compiler would do this when it went out of scope.
	}

	else if(max_size_ > new_size)
	{//the array will need to be truncated
		
		if(cur_size_ > new_size)
		{//if the array is truncated past the previous last char
			cur_size_ = new_size;
		}
		char* hold = data_;//store the old data
		data_ = new char[new_size];//make a new array
		max_size_ = new_size;//reassign the maximum size to the new value
		this->fill(' ');
		//fill the array with blanks. the compiler doesn't like
		//assigning uninitialized values
		for(size_t i = 0; i < cur_size_; i++)
		{//iterate through and copy the old array
			data_[i] = hold[i];
		}
		delete [] hold;
		//apparently this needs to be deleted.
		//thought the compiler would do this when it went out of scope.
	}

	else
	{//nothing needs to be done
		return;
	}
}

/**
 * Locate the specified character in the array. The index of the first
 * occurrence of the character is returned. If the character is not
 * found in the array, then -1 is returned.
 */
int Array::find (char ch) const
{
	// Ryan: Why don't you use the other find function here - code reuse.
	// Fix: using other function as advised.
	return this->find(ch, 0);
}

/**
 * This version allows you to specify the start index of the search. If
 * the start index is not within the range of the array, then the
 * std::out_of_range exception is thrown.
 */
int Array::find (char ch, size_t start) const
{
	if(start >= max_size_)
	{//throw exception if out of range
		throw std::out_of_range ("Index out of range");
	}

	for(size_t i = start; i < cur_size_; i++)
	{//iterate through the array
		if(ch == data_[i])
		{//and return the int value of the index if found
			return static_cast<int>(i);
		}
	}
	return -1;
}

/**
 * Test the array for equality.
 */
bool Array::operator == (const Array & rhs) const
{
	// Ryan: Perform a self-comparison check first.
	// Fix: Added pointer comparison

	if(this == &rhs)
	{//Pointer comparison
		return true;
	}
	
	if(cur_size_ != rhs.size() || max_size_ != rhs.max_size())
	{//If the arrays have different sizes, they are not equal
		return false;
	}

	for(size_t i = 0; i < cur_size_; i++)
	{
		if(data_[i] != rhs.get(i))
		{
			//if the arrays have different characters,
			//they are not equal
			return false;
		} 
	}
	//if the arrays are the same size with the same characters,
	//they are equal
	return true;
}

/**
 * Test the array for inequality.
 */
bool Array::operator != (const Array & rhs) const
{
	// Ryan: Why don't you just use the above function to achieve this - code reuse.
	// Fix: using the above function as advised.
	//if the arrays have different sizes, they are not equal

	return !(*this == rhs);
}


/**
 * Fill the contents of the array with the provided character
 */
void Array::fill (char ch)
{
	//iterate through every character in the array
	for(size_t i = 0; i < max_size_; i++)
	{
		//and add the character
		data_[i] = ch;
	}
}

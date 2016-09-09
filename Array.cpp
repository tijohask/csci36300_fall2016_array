// $Id: Array.cpp 820 2011-01-17 15:30:41Z hillj $

// Honor Pledge:
//
// I pledge that I have neither given nor receieved any help
// on this assignment.

#include "Array.h"
#include <stdexcept>
using namespace std;

/**
 * @class Array
 *
 * Basic implementation of a standard array class for chars.
 */

/// Default constructor.
Array::Array (): data_(NULL), cur_size_(0), max_size_(0)
{
//	data_ = new char[0];
}

/**
 * Initializing constructor.
 *
 * @param[in]      length        Initial size
 */
Array::Array (size_t length): data_(NULL), cur_size_(0), max_size_(length)
{
	data_ = new char[length];
}

/**
 * Initializing constructor.
 *
 * @param[in]      length        Initial size
 * @param[in]      fill          Initial value for each element
 */
Array::Array (size_t length, char fill): data_(NULL), cur_size_(length), max_size_ (length)
{
	data_ = new char[length];//create a new array
	this->fill(fill);//and fill in the array with the character
}

/**
 * Copy constructor
 *
 * @param[in]     arr         The source array.
 */
Array::Array (const Array & array): data_(NULL), cur_size_(array.size()), max_size_(array.max_size())
{
	data_ = new char[max_size_];//create a new character array
	for(size_t i = 0; i < cur_size_; i++)
	{//and copy the data in from the other array
		data_[i] = array[i];
	}
}

//All constructors appear to be working
/// Destructor
Array::~Array (void)
{
	delete [] data_;
}

/**
 * Assignment operation
 *
 * @param[in]       rhs      Right-hand side of equal sign
 * @return          Reference to self
 */
const Array & Array::operator = (const Array & rhs)
{
	delete [] data_; //delete the old data
	data_ = new char[rhs.max_size()]; //allocate a new char array
	cur_size_ = rhs.size();//set the sizes to their new values
	max_size_ = rhs.max_size();
	for(int i = 0; i < cur_size_; i++)
	{//iterate through the array, copying the rhs
		data_[i] = rhs[i];
	}
}

/**
 * Get the character at the specified index. If the index is not
 * within the range of the array, then std::out_of_range exception
 * is thrown.
 *
 * @param[in]       index               Zero-based location
 * @exception       std::out_of_range   Invalid \a index value
 */
char & Array::operator [] (size_t index)
{
	if(index > max_size_)
	{//throw exception if out of range
		throw std::out_of_range ("Index out of range");
	}
	return data_[index];//return the character otherwise
}

/**
 * @overload
 *
 * The returned character is not modifiable.
 */
const char & Array::operator [] (size_t index) const
{
	if(index > max_size_)
	{//throw exception if out of range
		throw std::out_of_range ("Index out of range");
	}
	return data_[index];//return the character otherwise
}

/**
 * Get the character at the specified index. If the \a index is not within
 * the range of the array, then std::out_of_range exception is thrown.
 *
 * @param[in]       index                 Zero-based location
 * @return          Character at \index
 * @exception       std::out_of_range     Invalid index value
 */  
char Array::get (size_t index) const
{
	if(index > max_size_)
	{//throw exception if out of range
		throw std::out_of_range ("Index out of range");
	}	
	return data_[index];//return the character otherwise
}

/** 
 * Set the character at the specified \a index. If the \a index is not
 * within range of the array, then std::out_of_range exception is 
 * thrown.
 *
 * @param[in]       index                 Zero-based location
 * @param[in]       value                 New value for character
 * @exception       std::out_of_range     Invalid \a index value
 */
void Array::set (size_t index, char value)
{
	if(index > max_size_)
	{//throw exception if out of range
		throw std::out_of_range ("Index out of range");
	}
	else
	{//store the value
		data_[index] = value;
		if(cur_size_ < index)
		{//readjust current size if necessary
			cur_size_ = index;
		}
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
 *
 * @param[in]       new_size              New size of the array
 */
void Array::resize (size_t new_size)
{
	if(max_size_ < new_size)
	{//the array will need to be expanded

		char* hold = data_;//store the old data
		data_ = new char[new_size];//make a new array
		for(size_t i = 0; i < cur_size_; i++)
		{//iterate through and copy the old array
			data_[i] = hold[i];
		}
		max_size_ = new_size;//then reassign the size to the new value

	}

	else if(max_size_ > new_size)
	{//the array will need to be truncated
		
		if(cur_size_ > new_size)
		{//if the array is truncated past the previous last char
			cur_size_ = new_size;
		}
		char* hold = data_;//store the old data
		data_ = new char[new_size];//make a new array
		for(size_t i = 0; i < cur_size_; i++)
		{//iterate through and copy the old array
			data_[i] = hold[i];
		}
		max_size_ = new_size;//then reassign the size to the new value

	}

	else
	{
		return;
	}
}

/**
 * Locate the specified character in the array. The index of the first
 * occurrence of the character is returned. If the character is not
 * found in the array, then -1 is returned.
 *
 * @param[in]        ch        Character to search for
 * @return           Index value of the character
 * @retval           -1        Character not found
 */
int Array::find (char ch) const
{
	//cast the current size to an int for iteration
	//int current = static_cast<int>(cur_size_);
	for(size_t i = 0; i < cur_size_; i++)
	{//iterate through the array
		if(ch == data_[i])
		{//and return the int value of the index if found
			return static_cast<int>(i);
		}
	}
	return -1;
}

/**
 * @overload
 *
 * This version allows you to specify the start index of the search. If
 * the start index is not within the range of the array, then the
 * std::out_of_range exception is thrown.
 *
 * @param[in]       ch                   Character to search for
 * @param[in]       start                Index to begin search
 * @return          Index value of first occurrence
 * @retval          -1                   Character not found
 * @exception       std::out_of_range    Invalid index
 */
int Array::find (char ch, size_t start) const
{
	//int current = static_cast<int>(cur_size_);
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
 *
 * @param[in]       rhs                  Right hand side of equal to sign
 * @retval          true                 Left side is equal to right side
 * @retval          false                Left side is not equal to right side
 */
bool Array::operator == (const Array & rhs) const
{
	//if the arrays have different sizes, they are not equal
	if(cur_size_ != rhs.size() || max_size_ != rhs.max_size())
	{
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
 *
 * @param[in]       rhs                  Right-hand size of not equal to sign
 * @retval          true                 Left side is not equal to right side
 * @retval          false                Left size is equal to right side
 */
bool Array::operator != (const Array & rhs) const
{
	//if the arrays have different sizes, they are not equal	
	if(cur_size_ != rhs.size() || max_size_ != rhs.max_size())
	{
		return true;
	}

	for(size_t i = 0; i < cur_size_; i++)
	{
		if(data_[i] != rhs.get(i))
		{
			//if the arrays have different characters,
			//they are not equal
			return true;
		}
	}
	//if the arrays are the same size with the same characters,
	//they are equal
	return false;
}


/**
 * Fill the contents of the array.
 *
 * @param[in]       ch                   Fill character
 */
void Array::fill (char ch)
{
	//iterate through every character in the array...
	for(size_t i = 0; i < max_size_; i++)
	{
		//...and add the character
		data_[i] = ch;
	}
	//set the current size to the max size, because 
	//the array has been filled
	cur_size_ = max_size_;
}

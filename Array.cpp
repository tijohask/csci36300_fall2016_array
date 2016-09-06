// $Id: Array.cpp 820 2011-01-17 15:30:41Z hillj $

// Honor Pledge:
//
// I pledge that I have neither given nor receieved any help
// on this assignment.

#include "Array.h"
#include <stdio.h>
#include <iostream>
using namespace std;

//Q1: can size_t be incremented in a for loop?


Array::Array (void): data_(new char[0]), cur_size_(0), max_size_(0)
{
	
}

Array::Array (size_t length): data_(new char[length]), cur_size_(0), max_size_(length)
{

}

Array::Array (size_t length, char fill): data_(new char[length]), cur_size_(length), max_size_ (length)
{
	this->fill(fill);
}


Array::Array (const Array & array)
{
	//incomplete
}

Array::~Array (void)
{
	delete [] data_;
}

const Array & Array::operator = (const Array & rhs)
{
	//incomplete
}

char & Array::operator [] (size_t index)
{
	if(index > max_size_)
	{
		throw std::out_of_range ("Index out of range");
	}
	return data_[index];
}

const char & Array::operator [] (size_t index) const
{
	if(index > max_size_)
	{
		throw std::out_of_range ("Index out of range");
	}
	return data_[index];
}

char Array::get (size_t index) const
{
	if(index > max_size_)
	{
		throw std::out_of_range ("Index out of range");
	}	
	return data_[index];
}

void Array::set (size_t index, char value)
{
	if(index > max_size_)
	{
		throw std::out_of_range ("Index out of range");
	}
	else
	{
		data_[index] = value;
		if(cur_size_ < index)
		{
			cur_size_ = index;
		}
	}
}

void Array::resize (size_t new_size)
{
	if(max_size_ < new_size)
	{
		char* hold = data_;
		data_ = new char[new_size];
		for(size_t i = 0; i < cur_size_; i++)
		{
			data_[i] = hold[i];
		}
		max_size_ = new_size;		
	}
	else if(max_size_ > new_size)
	{
		if(cur_size_ > new_size)
		{
			cur_size_ = new_size;
		}
		char* hold = data_;
		data_ = new char[new_size];
		for(size_t i = 0; i < cur_size_; i++)
		{
			data_[i] = hold[i];
		}
		max_size_ = new_size;
	}
	else
	{
		return;
	}
}

int Array::find (char ch) const
{
	int current = static_cast<int>(cur_size_);
	for(int i = 0; i < current; i++)
	{
		if(ch == data_[i])
		{
			return i;
		}
	}
	return -1;
}

int Array::find (char ch, size_t start) const
{
	int current = static_cast<int>(cur_size_);
	for(int i = start; i < current; i++)
	{
		if(ch == data_[i])
		{
			return i;
		}
	}
	return -1;
}

bool Array::operator == (const Array & rhs) const
{
	//if the arrays have different sizes, they are not equal
	if(cur_size_ != rhs.size() || max_size_ != rhs.max_size())
	{
		return false;
	}
//	int current = static_cast<int>(cur_size_);
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

bool Array::operator != (const Array & rhs) const
{
	//if the arrays have different sizes, they are not equal	
	if(cur_size_ != rhs.size() || max_size_ != rhs.max_size())
	{
		return true;
	}
//	int current = static_cast<int>(cur_size_);
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

//bool Array::checkRange(size_t index)
//{

//}

void Array::fill (char ch)
{
	//iterate through every character in the array...
	for(size_t i = 0; i < max_size_; i++)
	{
		//...and add the character
		data_[i] = ch;
	}
}

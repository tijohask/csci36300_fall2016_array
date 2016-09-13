#include "Array.h"
#include <stdexcept>
#include <iostream>
//using namespace std;

void print_out(Array arr);
void test_constructors();
void test_set_and_get();
void test_fill();
void test_booleans();
void test_out_of_bounds();
void test_size();

int main()
{
	std::cout << "Begin Testing" << std::endl;
 
	test_constructors();
	test_set_and_get();
	test_fill();
	test_size();
	test_booleans();
	test_out_of_bounds();	

	std::cout << "Done" << std::endl;
}

void test_size()
{
	std::cout << "Testing sizes" << std::endl;

	Array arr5 (9);
	Array arr6 (4, 'l');
	std::cout << arr5.size() << std::endl;
	std::cout << arr5.max_size() << std::endl;

	arr5.set(5, 'c');
	print_out(arr5);
	arr5.set(3, 'b');
	print_out(arr5);
	
	std::cout << arr5.size() << std::endl;
	std::cout << arr5.max_size() << std::endl;

	arr5.resize(5);
	print_out(arr5);

	std::cout << arr5.size() << std::endl;
	std::cout << arr5.max_size() << std::endl;
	
	print_out(arr6);
	std::cout << arr6.size() << std::endl;
	std::cout << arr6.max_size() << std::endl;

	arr6.resize(6);
	print_out(arr6);

	std::cout << arr6.size() << std::endl;
	std::cout << arr6.max_size() << std::endl;

	arr6.set(4, 'L');
	print_out(arr6);

	std::cout << arr6.size() << std::endl;
	std::cout << arr6.max_size() << std::endl;

	std::cout << "Sizes Tested" << std::endl;
}

void test_constructors()
{
	std::cout << "Testing constructors" << std::endl;

	Array arr1;
	Array arr2 (9);
	Array arr3 (4, 'b');
	Array arr4 (arr3);
	arr1 = arr2;
	arr2 = arr3;
	print_out(arr1);
	print_out(arr2);
	print_out(arr3);
	print_out(arr4);

	std::cout << "Testing constructors" << std::endl;
}

void test_set_and_get()
{
	std::cout << "Testing sets and gets" << std::endl;

	Array arr3 (7, 'a');

	print_out(arr3);
	arr3.set(1, 'b');
	arr3.set(2, 'c');
	arr3.set(3, 'd');
	arr3.set(4, 'e');
	arr3.set(5, 'f');
	print_out(arr3);
	std::cout << arr3.get(5);
	std::cout << arr3.get(4);
	std::cout << arr3.get(3);
	std::cout << std::endl;	

	std::cout << "Sets and gets tested" << std::endl;
}

void test_fill()
{
	std::cout << "Testing fill" << std::endl;

	Array arrf (7);
	print_out(arrf);
	arrf.fill('f');
	print_out(arrf);
	arrf.fill('q');
	print_out(arrf);
	
	std::cout << "Fill Tested" << std::endl;
}

void test_booleans()
{
	std::cout << "Testing booleans" << std::endl;

	Array arr1;
	Array arr2 (9, 'o');
	Array arr3 = arr2;
	Array arr4 = arr3;
	arr3.set(5, 'b');
	print_out(arr1);
	print_out(arr2);
	print_out(arr3);
	print_out(arr4);
	if(arr4 == arr2)
	{
		std::cout << "True 4-2" << std::endl;//expected
	}
	else
	{
		std::cout << "False 4-2" << std::endl;
	}
	if(arr3 == arr2)
	{
		std::cout << "True 3-2" << std::endl;
	}
	else
	{
		std::cout << "False 3-2" << std::endl;//expected
	}
	if(arr4 != arr1)
	{
		std::cout << "True 4-1" << std::endl;//expected
	}
	else
	{
		std::cout << "False 4-1" << std::endl;
	}
	if(arr1 != arr2)
	{
		std::cout << "True 1-2" << std::endl;//expected
	}
	else
	{
		std::cout << "False 1-2" << std::endl;
	}

	std::cout << "Booleans tested" << std::endl;
}

void test_out_of_bounds()
{
	Array arr3 (9, 'b');
	try
	{
		arr3.get(18);
	}
	catch(std::out_of_range e)
	{
		std::cout << "Attempted out of bounds caught" << std::endl;
	}
	try
	{
		arr3.set(18, 'a');
	}
	catch(std::out_of_range e)
	{
		std::cout << "Attempted out of bounds caught" << std::endl;
	}
	try
	{
		arr3[18];
	}
	catch(std::out_of_range e)
	{
		std::cout << "Attempted out of bounds caught" << std::endl;
	}
}

void print_out(Array arr)
{
	std::cout << "\"";

	for(int i = 0; i < arr.max_size(); i++)
	{
		std::cout << arr[i];
	}

	std::cout << "\"";
	std::cout << std::endl;
}

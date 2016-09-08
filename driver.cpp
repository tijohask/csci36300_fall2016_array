#include "Array.h"
#include <stdexcept>
#include <iostream>
using namespace std;

void print_out(Array arr);
void test_constructors();
void test_set_and_get();
void test_fill();
void test_booleans();
void test_out_of_bounds();

int main()
{
	cout << "Begin Testing" << endl;
 
	test_constructors();
	test_set_and_get();
	test_fill();
	test_booleans();
	test_out_of_bounds();	

	cout << "Done" << endl;
}

void test_constructors()
{
	cout << "Testing constructors" << endl;

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

	cout << "Testing constructors" << endl;
}

void test_set_and_get()
{
	cout << "Testing sets and gets" << endl;

	Array arr3 (7, 'a');

	print_out(arr3);
	arr3.set(1, 'b');
	arr3.set(2, 'c');
	arr3.set(3, 'd');
	arr3.set(4, 'e');
	arr3.set(5, 'f');
	print_out(arr3);
	cout << arr3.get(5);
	cout << arr3.get(4);
	cout << arr3.get(3);
	cout << endl;	

	cout << "Sets and gets tested" << endl;
}

void test_fill()
{
	cout << "Testing fill" << endl;

	Array arrf (7);
	print_out(arrf);
	arrf.fill('f');
	print_out(arrf);
	arrf.fill('q');
	print_out(arrf);
	
	cout << "Fill Tested" << endl;
}

void test_booleans()
{
	cout << "Testing booleans" << endl;

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
		cout << "True 4-2" << endl;//expected
	}
	else
	{
		cout << "False 4-2" << endl;
	}
	if(arr3 == arr2)
	{
		cout << "True 3-2" << endl;
	}
	else
	{
		cout << "False 3-2" << endl;//expected
	}
	if(arr4 != arr1)
	{
		cout << "True 4-1" << endl;//expected
	}
	else
	{
		cout << "False 4-1" << endl;
	}
	if(arr1 != arr2)
	{
		cout << "True 1-2" << endl;//expected
	}
	else
	{
		cout << "False 1-2" << endl;
	}

	cout << "Booleans tested" << endl;
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
		cout << "Attempted out of bounds caught" << endl;
	}
	try
	{
		arr3.set(18, 'a');
	}
	catch(std::out_of_range e)
	{
		cout << "Attempted out of bounds caught" << endl;
	}
	try
	{
		arr3[18];
	}
	catch(std::out_of_range e)
	{
		cout << "Attempted out of bounds caught" << endl;
	}
}

void print_out(Array arr)
{
	cout << "\"";
	for(int i = 0; i < arr.size(); i++)
	{
		cout << arr[i];
	}
	for(int i = arr.size(); i < arr.max_size(); i++)
	{
		cout << " ";
	}
	cout << "\"";
	cout << endl;	
}

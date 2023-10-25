#pragma once

// input output
#include <iostream>
// basic functions
#include <iomanip>
// adds string data type
#include <string>

template <typename type>
class MyArray
{
public:
	// default constructor
	MyArray()
	{
		size = 0;
		head = 0;
		tail = 0;
		// no node creation calls
	}
	//alt 1
	MyArray(int length)
	{
		size = length;
		head = 0;
		tail = size - 1;
		// call node creation size amount of times
		ptr = new type[size];
		for (int i = 0; i < size; i++)
		{
			ptr[i] = 0;
		}
	}
	//alt 2
	MyArray(int start, int end)
	{
		size = end - start;
		head = start;
		tail = end;
		// call node creation size amount of times
		ptr = new type[size];
		for (int i = 0; i < size; i++)
		{
			ptr[i] = 0;
		}
	}

	//copy constructor
	MyArray(MyArray& Original)
	{
		size = Original.size;
		head = Original.head;
		tail = Original.tail;
		// call node creation Original.size amount of times
		ptr = new type[size];
		for (int i = 0; i < size; i++)
		{
			ptr[i] = Original.ptr[i];
		}
	}

	// destructor
	~MyArray()
	{
		// write to remove each node created
		delete[] ptr;
	}

private:
	// size of the array
	int size;
	// for arrays with alternate start and end points
	int head;
	int tail;

	type* ptr;

public:
	// functions


	//overloaded op's
	MyArray operator=(const MyArray& temp);
	type& operator[](int i);
	bool operator==(const MyArray& temp) const;
	bool operator!=(const MyArray& temp) const;

	friend std::istream& operator>>(std::istream& input, MyArray& pull)
	{
		for (int i = 0; i < pull.size; i++)
		{
			std::cout << "enter element num " << i << ": ";
			input >> pull.ptr[i];
			std::cout << "\n";
		}
		return input;
	}
	friend std::ostream& operator<<(std::ostream& output, MyArray& push)
	{
		for (int i = 0; i < push.size; i++)
		{
			std::cout << "Element num " << i << ": ";
			output << push.ptr[i] << "\n";
		}
		return output;
	}
};
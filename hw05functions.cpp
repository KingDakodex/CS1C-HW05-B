#include "hw05.h"

// functions for MyArray

template <typename type>
MyArray<type> MyArray<type>::operator=(const MyArray& temp)
{
	// checks to make sure its not already temp
	if (&temp != this)
	{
		// redefines the array
		if (size != temp.size)
		{
			delete[] ptr;
			size = temp.size;
			ptr = new type[size];
		}

		for (int i = 0; i < size; i++)
		{
			ptr[i] = temp.ptr[i];
		}
	}
	return *this;
}

template <typename type>
type& MyArray<type>::operator[](int temp)
{
	//check for out of range
	if (temp < head || temp >= size)
	{
		throw std::out_of_range("Out of Range");
	}
	return ptr[temp];
}

template <typename type>
bool MyArray<type>::operator==(const MyArray& temp) const
{
	if (size != temp.size)
	{
		return false;
	}
	for (int i = 0; i < size; i++)
	{
		if (ptr[i] != temp.ptr[i])
		{
			return false;
		}
	}
	return true;
}

template <typename type>
bool MyArray<type>::operator!=(const MyArray& temp) const
{
	return !(*this == temp);
}
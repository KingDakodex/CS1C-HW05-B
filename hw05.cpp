#include "hw05.h"
#include "hw05functions.cpp"

int main()
{

	MyArray<int> list1(5);
	MyArray<int> list2(5);

	std::cout << list1;

	std::cin >> list1;

	std::cout << list1;

	list2 = list1;

	std::cout << list2;

	for (int i = 0; i < 3; i++)
	{
		std::cout << "Enter element number " << i << "\n";
		std::cin >> list1[i];

	}

	for (int i = 0; i < 3; i++)
	{
		std::cout << "Element number " << i << ": " << list1[i];
	}

	MyArray<int> list3(-2, 6);

	std::cout << list3;

	list3[-2] = 7;
	list3[4] = 8;
	list3[0] = 54;
	list3[2] = list3[4] + list3[-2];

	std::cout << list3;

	return 0;
}
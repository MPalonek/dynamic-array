#include "dynamicArray.h"

int main()
{
	dynamicArray<int> dyn_arr;
	dynamicArray<int> dyn_arr2(16);

	dyn_arr.append(20);
	dyn_arr2.append(10);
	dyn_arr2.append(11);
	dyn_arr2.append(12);

	std::cout << "dyn_arr: " << dyn_arr[0] << "\ndyn_arr2: " << dyn_arr2[2] << std::endl;

	return 0;
}
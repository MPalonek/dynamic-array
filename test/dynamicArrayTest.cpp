#include <gtest/gtest.h> // googletest header file

#include "../app/dynamicArray.h"

// ---------------------------------------------------------------------
// dynamicArray<int> tests
// ---------------------------------------------------------------------

TEST(dynamicArrayIntSuite, CreateArray)
{
	dynamicArray<int> arr;
	EXPECT_EQ(arr.size(), 0);
}

TEST(dynamicArrayIntSuite, CreateArraySize10)
{
	dynamicArray<int> arr(10);
	EXPECT_EQ(arr.size(), 10);
}

TEST(dynamicArrayIntSuite, CreateArraySize5WithValues)
{
	dynamicArray<int> arr(5, 24);
	EXPECT_EQ(arr[0], 24);
	EXPECT_EQ(arr[1], 24);
	EXPECT_EQ(arr[2], 24);
	EXPECT_EQ(arr[3], 24);
	EXPECT_EQ(arr[4], 24);
	EXPECT_EQ(arr.size(), 5);
}

TEST(dynamicArrayIntSuite, InitilizerList)
{
	dynamicArray<int> arr{ 50, 40, 30, 20, 10 };
	EXPECT_EQ(arr[0], 50);
	EXPECT_EQ(arr[1], 40);
	EXPECT_EQ(arr[2], 30);
	EXPECT_EQ(arr[3], 20);
	EXPECT_EQ(arr[4], 10);
}

TEST(dynamicArrayIntSuite, CopyConstructArray)
{
	dynamicArray<int> arr{ 100, 200, 300, 400, 500, 600 };
	dynamicArray<int> arr2(arr);
	EXPECT_EQ(arr2[0], 100);
	EXPECT_EQ(arr2[1], 200);
	EXPECT_EQ(arr2[2], 300);
	EXPECT_EQ(arr2[3], 400);
	EXPECT_EQ(arr2[4], 500);
	EXPECT_EQ(arr2[5], 600);
	EXPECT_EQ(arr2.size(), arr.size());
}

TEST(dynamicArrayIntSuite, CopyAssignArray)
{
	dynamicArray<int> arr{ 30, 40, 50, 60 };
	dynamicArray<int> arr2{ 1, 2, 3, 4 };
	arr2 = arr;
	EXPECT_EQ(arr2[0], 30);
	EXPECT_EQ(arr2[1], 40);
	EXPECT_EQ(arr2[2], 50);
	EXPECT_EQ(arr2[3], 60);
	EXPECT_EQ(arr.size(), arr2.size());
}

TEST(dynamicArrayIntSuite, CopyAssignArraySmallerSize)
{
	dynamicArray<int> arr{ 3, 4, 5 };
	dynamicArray<int> arr2{ 20, 21, 22, 23, 24 };
	arr2 = arr;
	EXPECT_EQ(arr2[0], 3);
	EXPECT_EQ(arr2[1], 4);
	EXPECT_EQ(arr2[2], 5);
	EXPECT_EQ(arr.size(), arr2.size());
}

TEST(dynamicArrayIntSuite, CopyAssignArrayBiggerSize)
{
	dynamicArray<int> arr{ 30, 40, 50, 60, 70, 80 };
	dynamicArray<int> arr2{ 1, 2 };
	arr2 = arr;
	EXPECT_EQ(arr2[0], 30);
	EXPECT_EQ(arr2[1], 40);
	EXPECT_EQ(arr2[2], 50);
	EXPECT_EQ(arr2[3], 60);
	EXPECT_EQ(arr2[4], 70);
	EXPECT_EQ(arr2[5], 80);
	EXPECT_EQ(arr.size(), arr2.size());
}

TEST(dynamicArrayIntSuite, MoveConstructArray)
{
	dynamicArray<int> arr{ 4, 4, 7, 8 };
	dynamicArray<int> arr2 = std::move(arr);
	EXPECT_EQ(arr2[0], 4);
	EXPECT_EQ(arr2[1], 4);
	EXPECT_EQ(arr2[2], 7);
	EXPECT_EQ(arr2[3], 8);
	EXPECT_EQ(arr2.size(), 4);
}

TEST(dynamicArrayIntSuite, MoveAssignArray)
{
	dynamicArray<int> arr{ 5, 5, 8, 8 };
	dynamicArray<int> arr2{ 1 };
	arr2 = std::move(arr);
	EXPECT_EQ(arr2[0], 5);
	EXPECT_EQ(arr2[1], 5);
	EXPECT_EQ(arr2[2], 8);
	EXPECT_EQ(arr2[3], 8);
	EXPECT_EQ(arr2.size(), 4);
}

TEST(dynamicArrayIntSuite, AppendElements)
{
	dynamicArray<int> arr;
	arr.append(10);
	arr.append(20);
	arr.append(30);
	EXPECT_EQ(arr[0], 10);
	EXPECT_EQ(arr[1], 20);
	EXPECT_EQ(arr[2], 30);
}

TEST(dynamicArrayIntSuite, InsertElement)
{
	dynamicArray<int> arr{ 10, 20, 40 };
	arr.insert(30, 2);
	EXPECT_EQ(arr[0], 10);
	EXPECT_EQ(arr[1], 20);
	EXPECT_EQ(arr[2], 30);
	EXPECT_EQ(arr[3], 40);
}

TEST(dynamicArrayIntSuite, InsertElementAtEnd)
{
	dynamicArray<int> arr{ 10, 20, 30, 35 };
	arr.insert(40, 4);
	EXPECT_EQ(arr[0], 10);
	EXPECT_EQ(arr[1], 20);
	EXPECT_EQ(arr[2], 30);
	EXPECT_EQ(arr[3], 35);
	EXPECT_EQ(arr[4], 40);
}

TEST(dynamicArrayIntSuite, ReplaceExistingElement)
{
	dynamicArray<int> arr{ 30, 20, 0, 50 };
	arr[2] = 10;
	EXPECT_EQ(arr[0], 30);
	EXPECT_EQ(arr[1], 20);
	EXPECT_EQ(arr[2], 10);
	EXPECT_EQ(arr[3], 50);
}

TEST(dynamicArrayIntSuite, RangeLoop)
{
	dynamicArray<int> arr{ 1, 2, 3, 4 };
	for (auto& elem : arr)
	{
		elem = elem * elem;
	}
	EXPECT_EQ(arr[0], 1);
	EXPECT_EQ(arr[1], 4);
	EXPECT_EQ(arr[2], 9);
	EXPECT_EQ(arr[3], 16);
}

// ---------------------------------------------------------------------
// dynamicArray<double> tests
// ---------------------------------------------------------------------

TEST(dynamicArrayDoubleSuite, CreateArray)
{
	dynamicArray<double> arr;
	EXPECT_EQ(arr.size(), 0);
}

TEST(dynamicArrayDoubleSuite, CreateArraySize10)
{
	dynamicArray<double> arr(10);
	EXPECT_EQ(arr.size(), 10);
}

TEST(dynamicArrayDoubleSuite, CreateArraySize5WithValues)
{
	dynamicArray<double> arr(5, 2.4);
	EXPECT_EQ(arr[0], 2.4);
	EXPECT_EQ(arr[1], 2.4);
	EXPECT_EQ(arr[2], 2.4);
	EXPECT_EQ(arr[3], 2.4);
	EXPECT_EQ(arr[4], 2.4);
	EXPECT_EQ(arr.size(), 5);
}

TEST(dynamicArrayDoubleSuite, InitilizerList)
{
	dynamicArray<double> arr{ 5.0, 4.0, 3.0, 2.0, 1.0 };
	EXPECT_EQ(arr[0], 5.0);
	EXPECT_EQ(arr[1], 4.0);
	EXPECT_EQ(arr[2], 3.0);
	EXPECT_EQ(arr[3], 2.0);
	EXPECT_EQ(arr[4], 1.0);
}

TEST(dynamicArrayDoubleSuite, CopyConstructArray)
{
	dynamicArray<double> arr{ 0.0, 11.1, 22.2, 33.3, 44.4, 55.5 };
	dynamicArray<double> arr2(arr);
	EXPECT_EQ(arr2[0], 0.0);
	EXPECT_EQ(arr2[1], 11.1);
	EXPECT_EQ(arr2[2], 22.2);
	EXPECT_EQ(arr2[3], 33.3);
	EXPECT_EQ(arr2[4], 44.4);
	EXPECT_EQ(arr2[5], 55.5);
	EXPECT_EQ(arr2.size(), arr.size());
}

TEST(dynamicArrayDoubleSuite, CopyAssignArray)
{
	dynamicArray<double> arr{ 3.0, 4.0, 5.0, 6.0 };
	dynamicArray<double> arr2{ 0.1, 0.2, 0.3, 0.4 };
	arr2 = arr;
	EXPECT_EQ(arr2[0], 3.0);
	EXPECT_EQ(arr2[1], 4.0);
	EXPECT_EQ(arr2[2], 5.0);
	EXPECT_EQ(arr2[3], 6.0);
	EXPECT_EQ(arr.size(), arr2.size());
}

TEST(dynamicArrayDoubleSuite, CopyAssignArraySmallerSize)
{
	dynamicArray<double> arr{ 0.5, 0.6, 0.7 };
	dynamicArray<double> arr2{ -2.0, -1.0, 0.0, 1.0, 2.0 };
	arr2 = arr;
	EXPECT_EQ(arr2[0], 0.5);
	EXPECT_EQ(arr2[1], 0.6);
	EXPECT_EQ(arr2[2], 0.7);
	EXPECT_EQ(arr.size(), arr2.size());
}

TEST(dynamicArrayDoubleSuite, CopyAssignArrayBiggerSize)
{
	dynamicArray<double> arr{ 3.0, 4.0, 5.0, 6.0, 7.0, 8.0 };
	dynamicArray<double> arr2{ 0.1, 0.2 };
	arr2 = arr;
	EXPECT_EQ(arr2[0], 3.0);
	EXPECT_EQ(arr2[1], 4.0);
	EXPECT_EQ(arr2[2], 5.0);
	EXPECT_EQ(arr2[3], 6.0);
	EXPECT_EQ(arr2[4], 7.0);
	EXPECT_EQ(arr2[5], 8.0);
	EXPECT_EQ(arr.size(), arr2.size());
}

TEST(dynamicArrayDoubleSuite, MoveConstructArray)
{
	dynamicArray<double> arr{ 4.0, 4.0, 7.0, 8.0 };
	dynamicArray<double> arr2 = std::move(arr);
	EXPECT_EQ(arr2[0], 4.0);
	EXPECT_EQ(arr2[1], 4.0);
	EXPECT_EQ(arr2[2], 7.0);
	EXPECT_EQ(arr2[3], 8.0);
	EXPECT_EQ(arr2.size(), 4);
}

TEST(dynamicArrayDoubleSuite, MoveAssignArray)
{
	dynamicArray<double> arr{ 5.2, 5.2, 8.2, 8.2 };
	dynamicArray<double> arr2{ 1.5 };
	arr2 = std::move(arr);
	EXPECT_EQ(arr2[0], 5.2);
	EXPECT_EQ(arr2[1], 5.2);
	EXPECT_EQ(arr2[2], 8.2);
	EXPECT_EQ(arr2[3], 8.2);
	EXPECT_EQ(arr2.size(), 4);
}

TEST(dynamicArrayDoubleSuite, AppendElements)
{
	dynamicArray<double> arr;
	arr.append(1.0);
	arr.append(2.5);
	arr.append(3.75);
	EXPECT_EQ(arr[0], 1.0);
	EXPECT_EQ(arr[1], 2.5);
	EXPECT_EQ(arr[2], 3.75);
}

TEST(dynamicArrayDoubleSuite, InsertElements)
{
	dynamicArray<double> arr{ 0.1, 0.2, 0.4 };
	arr.insert(0.3, 2);
	EXPECT_EQ(arr[0], 0.1);
	EXPECT_EQ(arr[1], 0.2);
	EXPECT_EQ(arr[2], 0.3);
	EXPECT_EQ(arr[3], 0.4);
}

TEST(dynamicArrayDoubleSuite, InsertElementAtEnd)
{
	dynamicArray<double> arr{ 0.1, 0.2, 0.3 };
	arr.insert(0.4, 3);
	EXPECT_EQ(arr[0], 0.1);
	EXPECT_EQ(arr[1], 0.2);
	EXPECT_EQ(arr[2], 0.3);
	EXPECT_EQ(arr[3], 0.4);
}

TEST(dynamicArrayDoubleSuite, ReplaceExistingElement)
{
	dynamicArray<double> arr{ 1.5, 3.0, 0.0 };
	arr[2] = 3.3333;
	EXPECT_EQ(arr[0], 1.5);
	EXPECT_EQ(arr[1], 3.0);
	EXPECT_EQ(arr[2], 3.3333);
}

TEST(dynamicArrayDoubleSuite, RangeLoop)
{
	dynamicArray<double> arr{ 1.0, 2.0, 3.0, 4.0 };
	for (auto& elem : arr)
	{
		elem = elem + elem;
	}
	EXPECT_EQ(arr[0], 2.0);
	EXPECT_EQ(arr[1], 4.0);
	EXPECT_EQ(arr[2], 6.0);
	EXPECT_EQ(arr[3], 8.0);
}
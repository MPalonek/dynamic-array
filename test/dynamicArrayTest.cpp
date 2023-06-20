#include <gtest/gtest.h> // googletest header file

#include "../app/dynamicArray.h"

// ---------------------------------------------------------------------
// dynamicArray<int> tests
// ---------------------------------------------------------------------

TEST(dynamicArraySuite, CreateArrayInt)
{
	dynamicArray<int> arr;
	EXPECT_EQ(arr.size(), 0);
}

TEST(dynamicArraySuite, CreateArraySize10Int)
{
	dynamicArray<int> arr(10);
	EXPECT_EQ(arr.size(), 0);
}

TEST(dynamicArraySuite, InitilizerListInt)
{
	dynamicArray<int> arr{ 50, 40, 30, 20, 10 };
	EXPECT_EQ(arr[0], 50);
	EXPECT_EQ(arr[1], 40);
	EXPECT_EQ(arr[2], 30);
	EXPECT_EQ(arr[3], 20);
	EXPECT_EQ(arr[4], 10);
}

TEST(dynamicArraySuite, AppendElementsInt)
{
	dynamicArray<int> arr;
	arr.append(10);
	arr.append(20);
	arr.append(30);
	EXPECT_EQ(arr[0], 10);
	EXPECT_EQ(arr[1], 20);
	EXPECT_EQ(arr[2], 30);
}

TEST(dynamicArraySuite, InsertElementInt)
{
	dynamicArray<int> arr{ 10, 20, 40 };
	arr.insert(30, 2);
	EXPECT_EQ(arr[0], 10);
	EXPECT_EQ(arr[1], 20);
	EXPECT_EQ(arr[2], 30);
	EXPECT_EQ(arr[3], 40);
}

TEST(dynamicArraySuite, ReplaceExistingElementInt)
{
	dynamicArray<int> arr{ 30, 20, 0, 50 };
	arr[2] = 10;
	EXPECT_EQ(arr[0], 30);
	EXPECT_EQ(arr[1], 20);
	EXPECT_EQ(arr[2], 10);
	EXPECT_EQ(arr[3], 50);
}

TEST(dynamicArraySuite, AssignExistingArrToAnotherInt)
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

TEST(dynamicArraySuite, AssignExistingArrToAnotherDiffSizeInt)
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

// ---------------------------------------------------------------------
// dynamicArray<double> tests
// ---------------------------------------------------------------------

TEST(dynamicArraySuite, CreateArrayDouble)
{
	dynamicArray<double> arr;
	EXPECT_EQ(arr.size(), 0);
}

TEST(dynamicArraySuite, CreateArraySize10Double)
{
	dynamicArray<double> arr(10);
	EXPECT_EQ(arr.size(), 0);
}

TEST(dynamicArraySuite, InitilizerListDouble)
{
	dynamicArray<double> arr{ 5.0, 4.0, 3.0, 2.0, 1.0 };
	EXPECT_EQ(arr[0], 5.0);
	EXPECT_EQ(arr[1], 4.0);
	EXPECT_EQ(arr[2], 3.0);
	EXPECT_EQ(arr[3], 2.0);
	EXPECT_EQ(arr[4], 1.0);
}

TEST(dynamicArraySuite, AppendElementsDouble)
{
	dynamicArray<double> arr;
	arr.append(1.0);
	arr.append(2.5);
	arr.append(3.75);
	EXPECT_EQ(arr[0], 1.0);
	EXPECT_EQ(arr[1], 2.5);
	EXPECT_EQ(arr[2], 3.75);
}

TEST(dynamicArraySuite, InsertElementsDouble)
{
	dynamicArray<double> arr{ 0.1, 0.2, 0.4 };
	arr.insert(0.3, 2);
	EXPECT_EQ(arr[0], 0.1);
	EXPECT_EQ(arr[1], 0.2);
	EXPECT_EQ(arr[2], 0.3);
	EXPECT_EQ(arr[3], 0.4);
}

TEST(dynamicArraySuite, ReplaceExistingElementDouble)
{
	dynamicArray<double> arr{ 1.5, 3.0, 0.0 };
	arr[2] = 3.3333;
	EXPECT_EQ(arr[0], 1.5);
	EXPECT_EQ(arr[1], 3.0);
	EXPECT_EQ(arr[2], 3.3333);
}

TEST(dynamicArraySuite, AssignExistingArrToAnotherDouble)
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

TEST(dynamicArraySuite, AssignExistingArrToAnotherDiffSizeDouble)
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
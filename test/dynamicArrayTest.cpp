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

TEST(dynamicArraySuite, InsertElementsInt)
{
	dynamicArray<int> arr;
	arr.insert(10, 2);
	arr.insert(20, 4);
	arr.insert(30, 1);
	EXPECT_EQ(arr[1], 30);
	EXPECT_EQ(arr[2], 10);
	EXPECT_EQ(arr[4], 20);
}

TEST(dynamicArraySuite, ReplaceExistingElementWithInsertInt)
{
	dynamicArray<int> arr;
	arr.append(10);
	arr.insert(30, 2);
	arr.insert(50, 0);
	EXPECT_EQ(arr[0], 50);
	EXPECT_EQ(arr[2], 30);
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
	dynamicArray<double> arr;
	arr.insert(1.0, 2);
	arr.insert(2.5, 4);
	arr.insert(3.75, 1);
	EXPECT_EQ(arr[1], 3.75);
	EXPECT_EQ(arr[2], 1.0);
	EXPECT_EQ(arr[4], 2.5);
}

TEST(dynamicArraySuite, ReplaceExistingElementWithInsertDouble)
{
	dynamicArray<double> arr;
	arr.append(1.0);
	arr.insert(3.75, 2);
	arr.insert(5.55555, 0);
	EXPECT_EQ(arr[0], 5.55555);
	EXPECT_EQ(arr[2], 3.75);
}

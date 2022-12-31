## Quick Sort

This repository contains an implementation of the quick sort algorithm in C++

## Table of Contents

1. [Description](#description)
2. [Program Output](#output)
3. [Compile and Execution](#exe)
4. [Function Headers](#function)
5. [Classes](#class)
6. [Resources](#resources)

## Description <a name="description"></a>

Quick sort has been described as a "divide and conquer" algorithm due to splitting up problems into smaller subproblems, then sorting these subproblems. The quick sort algorithm uses two arrays to hold elements less than, and greater than or equal to, the pivot element. These arrays are further broken up into sub-arrays to be sorted and eventually reconstructed together to create the final sorted array.

The time complexity is as follows:

- Average case: 0(nlogn)

- Worst case: 0(n^2)

- Best case: 0(nlogn)

For an in-depth explanation of this algorithmic analysis visit: [opengenus.org](https://iq.opengenus.org/time-and-space-complexity-of-quick-sort/)

## Program Output <a name="output"></a>



### Compile and Execute <a name="exe"></a>

- Windows:

	To compile run the command: `g++ main.cpp -o quick_sort`

	To execute run the command: `quick_sort.exe`

- Linux / Mac OS:

	To compile run the command: `g++ main.cpp -o quick_sort`

	To execute run the command: `./quick_sort`


## Function Headers <a name="function"></a>

``` cpp
vector<int> user_data()
```

- Description:

	Prompts user to initialize a vector of integers to be sorted

- Parameters:

	None

- Return:

	`vector<int> data` Represents integers to be sorted

---

``` cpp
vector<int> quick_sort(vector<int> data, int bottom, int top)
```

- Description:

	Beginning of recursive calls that sorts the data

- Parameters:

	`vector<int> data` Represents unsorted data initialized by user

	`int bottom` Represents lower bound of vector to be sorted

	`int top` Represents upper bound of vector to be sorted

- Return:

	`vector<int> data` Represents the sorted data

---

``` cpp
Flag partition(vector<int> &data, int bottom, int top)
```

- Description:

	Sorts integers by swapping their positions in the subset of data from the lower to upper bound. Once no more integers can be swapped it finds and returns the next partition index.

- Parameters:

	`vector<int> &data` Represents a subset of the data to be sorted (passed by reference)

	`int bottom` Represents lower bound of data to be sorted

	`int top` Represents upper bound of data to be sorted

- Return:

	`Flag control` Object of class Flag containing the sorted subset of the data and a boolean representing a control flag


---

``` cpp
vector<int> swap(vector<int> data, int bottom_compare, int top_compare)
```
- Description:

	This function takes in the data and two integers to be swapped

- Parameters

	`vector<int> data` Represents the data being sorted

	`int bottom_compare` Represents element to be swapped

	`int top_compare` Represents element to be swapped

- Return:

	`vector<int> data` Contains data after elements have been swapped



## Classes <a name="class"></a>

``` cpp
class Flag
```

- Description:

	This class is used to return multiple values from the function `partition()` being the partition index and a boolean value representing a flag to identify when the initial bottom of at the data set has been sorted, triggering the start of sorting for the initial top half of the data

- Public Member Functions

	Constructors:

	`Flag(int index, int flag)` Initializes object with values passed in

	Accessors:

	`int get_index()` Returns partition_index

	`int get_flag()` Returns partition_flag

	Mutators:

	`void set_index(int)` Initializes partition_index

	`void set_flag(bool)` Initializes partition_flag

- Private Member Variables

	`int partition_index` Represents where the partitioning takes place

	`bool partition_flag` Indicates when sorting will stop


## Resources <a name="resources"></a>

To learn more about the implementation of this algorithm consider watching this informational [video](https://www.youtube.com/watch?v=7h1s2SojIRw)

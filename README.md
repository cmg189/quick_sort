
## Quick Sort
This repository contains the implementation of the quick sort algorithm in c plus plus

### Description

Quick sort has been described as a "divide and conquer" algorithm due to splitting up problems into smaller subproblems, then sorting these subproblems.

### Compile and Execute

- Windows:

	To compile run the command: `g++ main.cpp -o quick_sort`

	To execute run the command: `quick_sort.exe`

- Unix:

	To compile run the command: `g++ main.cpp -o quick_sort`

	To execute run the command: `./quick_sort.exe`


### Time Complexity
- Average case: 0(nlogn)

- Worst case: 0(n^2)

- Best case: 0(nlogn)

For an in-depth explanation of this algorithmic analysis visit: [opengenus.org](https://iq.opengenus.org/time-and-space-complexity-of-quick-sort/)

### Function Headers

`user_data()`

- Parameters:

	None

- Return:

	a vector<int> representing data initialized by user

- Description:

	This function prompts the user to enter integers to be sorted

`quick_sort()`

- Parameters:

	- vector\<int\> representing unsorted data initialized by user

	- int representing lower bound of vector to be sorted

	- int representing upper bound of vector to be sorted

- Return:

	vector\<int\> representing the sorted data

- Description:

	This function begins the recursive calls that sorts the data

`partition()`

- Parameters:

	- vector\<int\> passed by reference representing a subset of the data to be sorted

	- int representing lower bound of data to be sorted

	- int representing upper bound of data to be sorted

- Return:

	class Flag containing the sorted subset of the data and a boolean representing a control flag

- Description:

	This function sorts integers by swapping their positions in the subset of data from the lower to upper bound. Once no more integers can be swapped it finds and returns the next partition index


`swap()`

- Parameters

	- vector\<int\> representing the data

	- int representing element to be swapped

	- int representing element to be swapped

- Return:

	vector\<int\> containing data after elements have been swapped

- Description:

	This function takes in the data and two integers to be swapped

### Class Headers

`Flag`

- Description:

	This class is used to return multiple values from the function `partition()` being the partition index and a boolean value representing a flag to identify when the initial bottom of at the data set has been sorted, triggering the start of sorting for the initial top half of the data

- Public member functions:

	- Constructors:

	`flag(int, int)`

	- Accessors:

	`int get_index()`

	`int get_flag()`

	- Mutators:

	`void set_index(int)`

	`void set_flag(bool)`

- Private member variables:

	- `int partition_index`

	- `bool partition_flag`

### Resources

To learn more about the implementation of this algorithm consider watching this informational [video](https://www.youtube.com/watch?v=7h1s2SojIRw)

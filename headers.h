#include <iostream>
#include <vector>
using namespace std;


// used to return multiple data points
class Flag {
	public:
		Flag(int index, bool flag);	// constructor

		int get_index();	// accessors
		bool get_flag();

		void set_index(int index);	// mutators
		void set_flag(bool flag);

	private:
		int partition_index;
		bool partition_flag;				// true when initial bottom half is done sorting
};

// get vector of integers to be sorted
vector<int> user_data();

// recursivly sorts vector and returns sorted vector
vector<int> quick_sort(vector<int> data, int bottom, int top);

// returns partition index and flag to continue sorting
Flag partition(vector<int> &data, int bottom, int top);

// swaps two elements data[bottom_compare] and data[top_compare]
vector<int> swap(vector<int> data, int bottom_compare, int top_compare);

// output sorted data
void output_data(vector<int> data);

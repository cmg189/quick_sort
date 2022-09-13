#include "header.h"

int main(){
	cout << "\nQuick Sort Algorithm\n\n";

	// comment out for testing
	//vector<int> data = user_data();
	//int starting_index = 0;
	//int ending_index = data.size() -1;
	//vector<int> sorted_data = quick_sort(data, starting_index, ending_index);

	// testing purposes
	vector<int> test_data{12, 99, 100, 32, 57, 18, 1, 56, 83, 44, 13};
	int starting_index = 0;
	int ending_index = test_data.size() -1;
	vector<int> sorted_data = quick_sort(test_data, starting_index, ending_index);

	// output sorted data
	cout << "Data has been sorted:\n";
	for(int i=0; i< sorted_data.size(); i++){
		cout << sorted_data.at(i) << " ";
	}

	// deallocate memory
	test_data.clear();
	sorted_data.clear();

	cout << "\n\nProgram ended\n\n";
	return 0;
}

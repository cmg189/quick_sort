#include "headers.h"

int main(){
	// obtain unsorted data from user
	vector<int> data = user_data();

	// sort data
	int starting_index = 0;
	int ending_index = data.size() -1;
	vector<int> sorted_data = quick_sort(data, starting_index, ending_index);

	// output sorted data
	output_data(sorted_data);

	// end program
	cout << "\n\nProgram ended\n\n";
	return 0;
}

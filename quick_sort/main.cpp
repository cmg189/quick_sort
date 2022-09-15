#include "header.h"

int main(){
	cout << "\nQuick Sort Algorithm\n";

	// obtain data from user
	vector<int> data = user_data();
	int starting_index = 0;
	int ending_index = data.size() -1;

	// sorting data
	vector<int> sorted_data = quick_sort(data, starting_index, ending_index);


	// output sorted data
	cout << "Sorted:\n";
	for(int i=0; i< sorted_data.size(); i++){ cout << sorted_data.at(i) << " "; }

	// deallocate memory
	data.clear();
	sorted_data.clear();

	cout << "\n\nProgram ended\n\n";
	return 0;
}

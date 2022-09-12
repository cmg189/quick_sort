#include <iostream>
#include <vector>
using namespace std;

// returns a vector initalized by user
vector<int> user_data();

// recursivly sorts and returns vector
// takes an unsorted vector, starting index, and ending index
vector<int> quick_sort(vector<int> data, int bottom, int top);

// returns partition index to continue sorting
int partition(vector<int> data, int pivot_element, int bottom, int top);

vector<int> user_data(){

	cout << "\nEnter integers to be sorted\n" << "When finished enter -999\n\n";


	int user_num;
	vector<int> data;						// holds user inputs
	bool not_finished = true;		// flag to stop user input

	// get user input until -999 entered
	while(not_finished){
		cout << "integer: ";
		cin >> user_num;

		if(user_num == -999){ not_finished = false; }
		else{ data.push_back(user_num); }

	}// while

	cout << "\nYou entered: ";
	for(int i=0; i< data.size(); i++){
		cout << data.at(i) << " ";
	}
	cout << "\n\n";

	return data;
}


vector<int> quick_sort(vector<int> data, int bottom, int top){

	// base case
	if(data.at(bottom) >= data.at(top)){
		return data;
	}

	// get element to pivot
	int pivot_index = (bottom + top) / 2;
	//int pivot_index = top + ( (bottom - top) / 2 );   // safer calculation of pivot index protects from overflow
	int pivot_element = data.at(pivot_index);

	// get new index to continue partitioning
	int partition_index = partition(data, pivot_element, bottom, top);

	// sorting bottom half of vector
	quick_sort(data, bottom, partition_index -1);

	// sorting top half of vector
	quick_sort(data, partition_index, top);

	return data;
}


int partition(vector<int> data, int pivot_element, int bottom, int top){

	return bottom;
}

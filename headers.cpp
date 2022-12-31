#include "headers.h"

// constructor
Flag:: Flag(int index, bool flag){
	this-> partition_index = index;
	this-> partition_flag = flag;
	return;
}

// accessors
int Flag:: get_index(){ return partition_index; }
bool Flag:: get_flag(){ return partition_flag; }

// mutators
void Flag:: set_index(int index){
	this->partition_index = index;
	return;
}

void Flag:: set_flag(bool flag){
	this->partition_flag = flag;
	return;
}

// get vector of integers to be sorted
vector<int> user_data(){
	cout << "\n\t\t\tQuick Sort Algorithm\n";
	cout << "\nEnter integers to be sorted\n" << "When finished enter -999\n\n";

	int user_num;
	vector<int> data;						// holds user inputs
	bool not_finished = true;		// flag to stop user input

	// get user input until -999 entered
	while(not_finished){
		cout << "> ";
		cin >> user_num;

		if(user_num == -999){ not_finished = false; }
		else{ data.push_back(user_num); }

	}// while

	cout << "\nYou entered:\n";
	for(int i=0; i< data.size(); i++){
		cout << data.at(i) << " ";
	}
	cout << endl;

	return data;
}

// recursivly sorts vector and returns sorted vector
vector<int> quick_sort(vector<int> data, int bottom, int top){
	// find partition index and recursivly sort bottom half and top half
	if(bottom < top){
		Flag control = partition(data, bottom, top);		// returns partition index and flag to sort top half
		data = quick_sort(data, bottom, control.get_index());		// sorting bottom half
		data = quick_sort(data, control.get_index() +1, top);		// sorting top half
	}

	return data; // sorted data
}

// returns partition index and flag to continue sorting
Flag partition(vector<int> &data, int bottom, int top){
	// itterating elements
	int pivot = data[bottom];
	int top_compare = top;
	int bottom_compare = bottom; // bottom is the pivot index

	// loop and swap until top_compare itterates past bottom_compare
	while(bottom_compare < top_compare){
		// stop at element that is >= pivot (can itterate then compare)
		do{
			bottom_compare++;
		}while(data[bottom_compare] <= pivot );

		// stop at element that is < pivot (must compare then itterate)
		for(int i=0; data[top_compare] > pivot; i++){
			top_compare--;
		}

		// pivot not yet found, swapping bc and tc
		if(bottom_compare < top_compare){
			data = swap(data, bottom_compare, top_compare);
		}
	}// while

	// occurs when no element is >= pivot (already sorted) set bc back to pivot index (bottom)
	if(bottom_compare >= data.size()){
		bottom_compare = bottom;
	}

	data = swap(data, bottom, top_compare);	// found new pivot position (when bc passes tc)

	// flag is false since we are not finished sorting bottom/top half
	Flag control(top_compare, false);
	return control;
}

// swaps two elements data[bottom_compare] and data[top_compare]
vector<int> swap(vector<int> data, int bottom_compare, int top_compare){
	// array to hold elements in vector
	int temp_data[data.size()];
	for(int i=0; i< data.size(); i++){
		temp_data[i] = data.at(i);
	}

	// swap elements in array
	int temp = temp_data[bottom_compare];
	temp_data[bottom_compare] = temp_data[top_compare];
	temp_data[top_compare] = temp;

	// put elements back in vector
	int size = data.size();
	data.clear();
	for(int i=0; i< size; i++){
		data.push_back(temp_data[i]);
	}

	return data;	// returns swapped data
}

// output sorted data
void output_data(vector<int> data){
	cout << "\nSorted:\n";
	for(int i=0; i< data.size(); i++){
		cout << data.at(i) << " ";
	}

	return;
}

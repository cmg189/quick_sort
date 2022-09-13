#include <iostream>
#include <vector>
using namespace std;

// returns a vector initalized by user
vector<int> user_data();

// recursivly sorts and returns vector
// takes an unsorted vector, starting index, and ending index
vector<int> quick_sort(vector<int> data, int bottom, int top);

// returns partition index to continue sorting
int partition(vector<int> data, int bottom, int top);

// swaps two elements
vector<int> swap(vector<int> data, int bottom_compare, int top_compare);

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
	//cout << "b: " << bottom << " t: " << top << "\n";

	if(bottom < top){
		int partition_index = partition(data, bottom, top);

		data = quick_sort(data, bottom, partition_index);		// sorting bottom half of vector
		data = quick_sort(data, partition_index +1, top);		// sorting top half of the vector
	}

	for(int i=0; i< data.size(); i++){ cout << data.at(i) << " "; } cout << endl;
	return data;
}


int partition(vector<int> data, int bottom, int top){

	// itterating elements
	int pivot = data[bottom];
	int top_compare = top;
	int bottom_compare = bottom;

	while(bottom_compare < top_compare){

		do{ bottom_compare++; }while(data[bottom_compare] <= pivot);
		//if(data[bottom_compare] <= pivot){ bottom_compare++; }

		do{ top_compare--; }while(data[top_compare] > pivot);
		//if(data[top_compare] > pivot){ top_compare--; }

		if(bottom_compare < top_compare){
			vector<int> semi_sorted = swap(data, bottom_compare, top_compare);
		}
	}// while

	swap(data, bottom, top_compare);

	return top_compare;
}

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

	return data;
}

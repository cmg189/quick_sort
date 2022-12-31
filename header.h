#include <iostream>
#include <vector>
using namespace std;


// used to return multiple data points
class Flag {
	public:
		Flag(int index, bool flag);	// constructor

		void set_index(int index);	// access and mutate index
		int get_index();

		void set_flag(bool flag);		// access and mutate flag
		bool get_flag();

	private:
		int partition_index;
		bool partition_flag;				// true when initial bottom half is done sorting
};

// constructor
Flag:: Flag(int index, bool flag){
	this-> partition_index = index;
	this-> partition_flag = flag;
	return;
}

// accessor and mutator
void Flag:: set_index(int index){
	this->partition_index = index;
	return;
}
int Flag:: get_index(){ return partition_index; }

// accessor and mutator
void Flag:: set_flag(bool flag){
	this->partition_flag = flag;
	return;
}
bool Flag:: get_flag(){ return partition_flag; }


// returns a vector initalized by user
vector<int> user_data();

// recursivly sorts and returns vector
// takes an unsorted vector, starting index, and ending index
vector<int> quick_sort(vector<int> data, int bottom, int top);

// returns partition index and flag to continue sorting
Flag partition(vector<int> &data, int bottom, int top);

// swaps two elements data[bottom_compare] and data[top_compare]
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

	cout << "\nYou entered:\n";
	for(int i=0; i< data.size(); i++){
		cout << data.at(i) << " ";
	}
	cout << "\n\n";

	return data;
}


vector<int> quick_sort(vector<int> data, int bottom, int top){

	// find partition index and recursivly sort bottom half and top half
	if(bottom < top){
		Flag control = partition(data, bottom, top);		// returns partition index and flag to sort top half

		data = quick_sort(data, bottom, control.get_index());		// sorting bottom half
		//cout << "pi " << control.get_index()+1 << " top " << top << endl;
		data = quick_sort(data, control.get_index() +1, top);		// sorting top half
	}

	//for(int i=0; i< data.size(); i++){ cout << data.at(i) << " "; } cout << endl;
	// return sorted data
	return data;
}


Flag partition(vector<int> &data, int bottom, int top){

	// itterating elements
	int pivot = data[bottom];
	int top_compare = top;
	int bottom_compare = bottom; // bottom is the pivot index
	//cout << "pivot " << data[bottom]  <<" bc " << bottom_compare << " tc " << top_compare << endl;

	// loop and swap until top_compare itterates past bottom_compare
	while(bottom_compare < top_compare){

		do{ bottom_compare++; }while(data[bottom_compare] <= pivot );		// stop at element that is >= pivot (can itterate then compare)
		//do{ top_compare--; }while(data[top_compare] > pivot);
		for(int i=0; data[top_compare] > pivot; i++){ top_compare--; }	// stop at element that is < pivot (must compare then itterate)
		//cout << "stop bc " << bottom_compare << " tc " << top_compare << endl;

		// pivot not yet found, swapping bc and tc
		if(bottom_compare < top_compare){
			//cout << "swap bc tc " << data[bottom_compare] << " <-> " << data[top_compare] << endl;
			data = swap(data, bottom_compare, top_compare);
		}
	}// while

	// occurs when no element is >= pivot (already sorted) set bc back to pivot index (bottom)
	if(bottom_compare >= data.size()){ bottom_compare = bottom; }

	//cout << "swap pv tc " << data[bottom] << " <-> " << data[top_compare] << " bc " << bottom_compare << endl;
	// found new pivot position (when bc passes tc)
	data = swap(data, bottom, top_compare);


	//cout << "thr> "; for(int i=0; i< data.size(); i++){ cout << data.at(i) << " "; } cout << endl;
	//cout << "tc " << top_compare << endl;
	// flag is false bc we are not finished sorting bottom/top half
	Flag control(top_compare, false);
	return control;
}

vector<int> swap(vector<int> data, int bottom_compare, int top_compare){
	//cout << "one> "; for(int i=0; i< data.size(); i++){ cout << data.at(i) << " "; } cout << endl;

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

	//cout << "two> "; for(int i=0; i< data.size(); i++){ cout << data.at(i) << " "; } cout << endl;
	// return swapped data
	return data;
}

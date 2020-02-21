#include <stdlib.h>
#include <iostream> 
#include <ctime>
#include <ratio>
#include <chrono>
#include <fstream>

using namespace std; 
using namespace std::chrono;

void maxSubArray(int array[], int start, int end){
	int firstIndex, secIndex;
	int diff=0;
	for(int i = start; i < end; i++){
		for(int j = i; j < end; j++){
			if(diff < array[j+1] - array[i]){
				diff = array[j+1] - array[i];
				firstIndex = i;
				secIndex = j + 1;
			}
		}
	}
	
	if(firstIndex < 0 || secIndex > end){
		cout << "\nNot found the buying and selling days\n";
	}else
	cout <<"Maximum Profit: "<< diff << endl << "First Index:  " <<firstIndex <<endl<< "Second Index: "<< secIndex;
	
}

void RandomArray(int array[], int size){
    for(int i = 0; i <= size; i++){
        int r = rand() % size;
	    array[i] = r; 
    }
}
int main(){
	
	int size;                 //size of array
	cout << "Enter Size: ";
	cin >> size;
	int *array = new int[size]; 			//dynamically allocating memory to array
	int start = 0;
	
	RandomArray(array, size-1);
	
//calculating time of insterion sort by using now() function
	
	high_resolution_clock::time_point t1 = high_resolution_clock::now();         //start time

	maxSubArray(array, start, size-1);	

	high_resolution_clock::time_point t2 = high_resolution_clock::now();			//stop time
	duration<double> time_span = duration_cast<std::chrono::nanoseconds>(t2-t1);	//total time taken by insertion sort
	cout << endl << "Time for insertion Sort: " << time_span.count()<<"s";
	
//saving data into file 
	
	ofstream mfile(" maxSubArray.csv", ios::app); // open filename.csv in append mode
	for(int i = 0; i < size; i++){
	 	mfile << array[i] << endl; // append "some stuff" to the end of the file	
	}
	mfile.close();
	cout << endl << endl << "Array is saved into file...";
	
	delete array;   //freeing memory
	
	return 0;
}



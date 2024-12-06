#include <cstdlib>
#include <ctime>
#include "RedBlackTree.h"

using namespace std;


int main(){

	// create a simulated 3.7 million ID number system.
	const int N = 3700000;

	clock_t start = clock();
	RedBlackTree rbt = RedBlackTree();
	for(int i = 0; i < N; i++){
		rbt.Insert(i);
	}
	clock_t stop = clock();

	double duration = (static_cast<double>(stop - start)) / CLOCKS_PER_SEC;
	cout << "Collected " << rbt.Size() << " ID numbers in " << (duration) << " seconds." << endl;


	// Your code goes here to simulate leaving / joining.
	for (int i = 0; i < 5; ++i){
		int ID_Number = rand() % N;
		clock_t starttime = clock();
		//check if the id number is in the tree, remove it if so 
		if (rbt.Contains(ID_Number)){
			rbt.Remove(ID_Number);
		}
		//end the time
		clock_t endtime = clock();
		//do duration as above
		double duration2 = (static_cast<double>(endtime - starttime)) / CLOCKS_PER_SEC;
		cout << "Remove time for ID Number " << ID_Number << " is " << duration2 << "seconds" << endl;

	}
	//do the same for people joing
	for (int i = 0; i < 5; ++i){
		int ID_Number = rand() % N;
		clock_t starttime = clock();
		rbt.Insert(ID_Number);
		//end the time
		clock_t endtime = clock();
		//do duration as above
		double duration2 = (static_cast<double>(endtime - starttime)) / CLOCKS_PER_SEC;
		cout << "insert time for ID Number " << ID_Number << " is " << duration2 << "seconds" << endl;

	}


	return 0;
}
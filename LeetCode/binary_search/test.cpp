#include <time.h>
#include"binary_search.hpp"
#include"brute_search.hpp"

using namespace std;
int algo_compare(vector<int> &vec, int target){
	if(brute_search(vec, target) == binary_search(vec, target)) return 0;
	else return -1;
}

int main(){

	// Create a vector to store integers
	vector<int> vec;
	
	// random seed
	time_t seed;
	
	// size of vector
	int s;
	
	// Random target
	int target;
	
	// Initialize seed
	seed = time(NULL);
	srand (seed);
		
	// Populate the vector and search for a number
	while(1){
		// Change seed
		seed++;
		srand (seed);
		
		cout << seed << "\n";
		// Select the size of vector randomly between 5 and 20
		s = rand() % 16 + 5;
		
		// Create and push a 1st random number (between -15 to 15) in the vector
		vec.push_back((rand() % 31) - 15);
		
		// Push more random numbers by adding random positive value to previous number
		for (int i = 1; i < s; i++){
		vec.push_back(vec[i-1]+(rand()%5)+1); // +1 is added so that if rand() = 0 then the numbers are not repeted in the vector
		}
		
		cout << "Vector: ";
		for (int i = 0; i < s; i++){
		cout << vec[i] << " ";
		}
		cout << "\n";
		
		// Generating rrandom target (>= -15)
		target = vec[rand() % vec.size()];
		cout << "Target: " << target << "\n";
		
		// Call algorithm compare function
		if(algo_compare(vec, target) != 0){
		cout << "Error: Result not same\n";
		return -1;
		}
		cout << endl;
		//Clear the vector for next run
		vec.clear();
	}
}

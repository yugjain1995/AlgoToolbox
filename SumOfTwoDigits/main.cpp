#include "MaxSumOfTwoDigits.hpp"
#include <time.h>


int algo_compare(vector<int> &a){
	int ele1[2], ele2[2];
	brute_force(a, ele1);
	fast_algo(a, ele2);
	if(ele1[0]+ele1[1] != ele2[0]+ele2[1]){
	return -1;
	}
	else return 0;
}

int main(){
	/* initialize random seed: */
	time_t seed;
	
	// Take inputs. First input integer array size. Next check that this imput is within integer bound and higher than 1.
	int n = 0;
	cout << "How many intergers do you want to input (input between 2 and "<< INT_MAX <<"): ";
	cin >> n;
	if (cin.fail() || n < 2){
	    cout << "Not in expected range.\n";
	    return -1;
	}
	
	int r = 0;
	while(r == 0){ 
		seed = time(NULL);
		srand (seed);
		   
		vector<int> a;
		int i = 0;
		while(i<n){
		a.push_back(rand() % 10);
		i++;
		}
		
		cout << "Seed for randome number generation: " << seed << "\n";
		cout << "Random Array: ";
		for (int i = 0; i < a.size(); i++)
			cout << a[i] << " ";
		cout << "\n";

		// Compare two algorithms for this problem
		r = algo_compare(a);
		a.clear();
	}
	return 0;
}

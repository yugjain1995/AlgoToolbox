#include "MaxSumOfTwoDigits.hpp"

void brute_force(const vector<int> &a, int ele[2]){
	int preSum = 0, sum = 0;
	ele[0] = 0;
	ele[1] = 0;

	for(int i = 0; i < a.size()-1; i++){
		for(int j = i+1; j<a.size(); j++){
			sum = a[i] + a[j];
			if(preSum < sum){
			preSum = sum;
			ele[0] = a[i];
			ele[1] = a[j];
			}
		}
	}
	cout << "Max sum by brute force is: "<< ele[0] << " + " << ele[1] << " = " << preSum << "\n";
}


void fast_algo(const vector<int> &a, int ele[2]){
	ele[0] = 0;
	ele[1] = 0;
	for(int i = 0; i < a.size(); i++){
		if(a[i] > ele[1]){
			ele[0] = ele[1];
			ele[1] = a[i];
		}
		else if(a[i] > ele[0]){
			ele[0] = a[i];
		}
	}
	cout << "Max sum by fast algo is: "<< ele[0] << " + " << ele[1] << " = " << ele[0] + ele[1] << "\n";
}

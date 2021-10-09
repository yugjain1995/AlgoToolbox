#include"brute_search.hpp"

using namespace std;
int brute_search(vector<int> vec, int target){
	int s = vec.size();
	for(int i = 0; i < s; i++){
		if(vec[i] == target){
			cout << "Target found by brute search at: " << i << "\n";
			return i;
		}
	}
	cout << "No target found by brute search.\n";
	return -1;
}

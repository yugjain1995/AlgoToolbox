#include"binary_search.hpp"


using namespace std;
int binary_search(vector<int> vec, int target){
	int u = vec.size();
	int l = 0;
	int t;
	while(u > l+1)
	{
		t = (u+l)/2;
		if(vec[t] == target){
		cout << "Target found by Binary search at: " << t << "\n";
		return t;
		}
		else if(vec[t] > target){u = t;}
		else if(vec[t] < target){l = t;}
	}
	cout << "No target found by binary search.\n";
	return -1;
}

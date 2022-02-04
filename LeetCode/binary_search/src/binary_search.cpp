#include"binary_search.hpp"


using namespace std;
int binary_search(vector<int> vec, int target){
	int u = vec.size()-1;
	int l = 0;
	int t;
	if(vec[0] == target){
		cout << "Target found by Binary search at: 0\n";
		return 0;
	}
	else if(vec[u] == target){
		cout << "Target found by Binary search at: " << u << endl;
		return u;
	}
	while(u > (l+1))
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

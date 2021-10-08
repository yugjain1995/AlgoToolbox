#include "MaxSumOfTwoDigits.hpp"

int main(){

// Take inputs. First input integer array size. Next check that this imput is within integer bound and higher than 1. Then take input for array.
int n = 0;
cout << "How many intergers do you want to input (input between 2 and "<< INT_MAX <<"): ";
cin >> n;

if (cin.fail() || n < 2){
    cout << "Not in expected range.\n";
    return -1;
}
   
vector<int> a;
int i = 0;
int temp = 0;
cout << "Enter "<< n << " integers: ";
while(i<n){
cin >> temp;
a.push_back(temp);
i++;
}

cout << "Your input: ";
for (int i = 0; i < a.size(); i++)
        cout << a[i] << " ";
cout << "\n";

// Run two algorithms for this problem
int ele1[2], ele2[2];

brute_force(a, ele1);
fast_algo(a, ele2);
 
return 0;
}

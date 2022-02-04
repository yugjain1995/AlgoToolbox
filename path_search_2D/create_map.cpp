#include<bits/stdc++.h>


using namespace std;

bool compare_loca(int a[2], int b[2]){
    if(a[0] == b[0] && a[1] == b[1]){return true;}
    return false;
}

void create_map(int r, int c){
    string filename = "../map.txt";
    ofstream input_file;
    input_file.open(filename);
    string state = "EO";

    srand(time(0));
    int s[2] = {rand() % r, rand() % c}; // Start coordinates
    int g[2] = {rand() % r, rand() % c}; // Goal coordinates
    int curr[2];
    for(int i = 0; i < r; i++){
        for(int j = 0; j < c; j++){
            curr[0] = i; curr[1] = j;
            if(compare_loca(s, curr)){input_file << "S "; continue;}
            if(compare_loca(g, curr)){input_file << "G "; continue;}
            if(rand() % 2 == 0){
                input_file << state[rand() % 2] << " ";
            }
            else input_file << state[0] << " ";
        }
        if(i < r-1) input_file << "\n";
    }

    input_file.close();
}
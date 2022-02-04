#include<bits/stdc++.h>
#include <vector>

using namespace std;

bool contains(vector<pair<int, int>> vec, pair<int, int> elem)
{
    bool result = false;
    if( find(vec.begin(), vec.end(), elem) != vec.end() )
    {
        result = true;
    }
    return result;
}

vector<pair<int, int>> search(vector<vector<char>> &grid){
    vector<pair<int, int>> path; // Path to return
    vector<pair<int, int>> S; // Expand list
    vector<pair<int, int>> L; // Already expanded

    // Check if grid is empty
    if(grid.empty()){return path;}

    // Search for start location. If no start location then return empty vector
    for(int i = 0; i < grid.size(); i++){
        for(int j = 0; j < grid[0].size(); j++){
            if(grid[i][j] == 'S'){
                S.push_back(make_pair(i, j));
                cout << "Start location at (" << S[0].first << " " << S[0].second << ")\n";
                break;
            }
        }
    }
    if(S.empty()){cout << "No start location in the map.\n"; return path;} 

    // Search for path form start location to goal location
    pair<int, int> current;
    while(!S.empty()){
        // Get the lateset from Expand list
        current = S.back();

        // Check if goal found
        if(grid[current.first][current.second] == 'G'){
            path.push_back(current);
            S.pop_back();
            cout << "Goal found at (" << current.first << ", " << current.second << ")\n";
            break;
        }

        // Check this latest already not expanded
        if(contains(L, current)){S.pop_back(); continue;}

        // If latest already not expanded then expand and add to already expanded list
        if(current.first < grid.size() - 1 && 
            grid[current.first+1][current.second] != 'O' && 
            !contains(S, make_pair(current.first+1, current.second))){
                S.push_back(make_pair(current.first+1, current.second));}
                
        if(current.first > 0 && 
            grid[current.first-1][current.second] != 'O' && 
            !contains(S, make_pair(current.first-1, current.second))){
                S.push_back(make_pair(current.first-1, current.second));}

        if(current.second < grid[0].size() - 1 && 
            grid[current.first][current.second+1] != 'O' && 
            !contains(S, make_pair(current.first, current.second+1))){
                S.push_back(make_pair(current.first, current.second+1));}

        if(current.second > 0 && 
        grid[current.first][current.second-1] != 'O' && 
        !contains(S, make_pair(current.first, current.second-1))){
            S.push_back(make_pair(current.first, current.second-1));}

        L.push_back(make_pair(current.first, current.second));
    }

    if(S.empty()){cout << "No goal found!!\n"; return path;}

    // Add to path
    while(!S.empty()){
        current = S.back();
        if(!contains(L, current)){S.pop_back();}
        else{path.push_back(current); S.pop_back();}
    }

    return path;
}

int path_search(bool DISPLAY_MAP = false){
    vector<vector<char>> grid;
    vector<char> row;

        string filename("../map.txt");
        FILE* input_file = fopen(filename.c_str(), "r");
    if (input_file == nullptr) {
       return EXIT_FAILURE;
    }

    char character = 0;
    while (!feof(input_file)){
       character = getc(input_file);
       if(character == ' '){continue;}
       if(character == '\n' || feof(input_file)){
           grid.push_back(row);
           row.clear();
           continue;
       }
       row.push_back(character);
    }

    vector<pair<int, int>> path = search(grid);

    // Map the movements to N,S,E and W in a char vector return this vector
    pair<int, int> current;
    pair<int, int> next;
    for (int i = path.size()-1; i > 0; i--) {
        current = path[i];
        next = path[i-1];
        if(next.first > current.first){cout << "DOWN\n";}
        if(next.first < current.first){cout << "UP\n";}
        if(next.second > current.second){cout << "RIGHT\n";}
        if(next.second < current.second){cout << "LEFT\n";}
    }

// Display map
    if(DISPLAY_MAP){
        for(int i = 0; i < grid.size(); i++){
            for(int j = 0; j < grid[0].size(); j++){
                std::cout << grid[i][j] << "    ";
            }
            std::cout << "\n\n\n";
        }
    }
    return 0;
}
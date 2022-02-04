#include<bits/stdc++.h>
#include<create_map.h>
#include<path_search_2D.h>


int str2int(char* c){
    int i = 0;
    std::string s;
    while(c[i] != '\0'){
        s.push_back(c[i]);
        i++;
    }
    return std::stoi(s);
}

int main(int argc, char** argv){
    bool CREATE_MAP = false;
    bool SEARCH_PATH = false;
    bool DISPLAY_MAP = false;
    bool rowT = false;
    bool colT = false;
    int r = 10;
    int c = 10;
    std::string s;
    for(int i = 0; i < argc; i++){
        if(rowT){
            if(strcmp(argv[i], " ") == 0){continue;}
            else {r = str2int(argv[i]); rowT = false;}
        }
        if(colT){
            if(strcmp(argv[i], " ") == 0){continue;}
            else {c = str2int(argv[i]); colT = false;}
        }
        if(strcmp(argv[i], "-cm") == 0){
            CREATE_MAP = true;
        }
        if(strcmp(argv[i], "-sp") == 0){
            SEARCH_PATH = true;
        }
        if(strcmp(argv[i], "-d") == 0){
            DISPLAY_MAP = true;
        }
        if(strcmp(argv[i], "-r") == 0){
            rowT = true;
        }
        if(strcmp(argv[i], "-c") == 0){
            colT = true;
        }
    }

    if(CREATE_MAP){create_map(r, c);}
    if(SEARCH_PATH){path_search(DISPLAY_MAP);}    
}
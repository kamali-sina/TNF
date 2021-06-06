#include "Finder.hpp"
#include <fstream>
#include <string>

using namespace std;

Finder::Finder(std::string file_path){
    file_path_ = file_path;
    boot();
}

void Finder::boot(){
    cout<<"Booting, please wait..."<<endl;
    ifstream input_stream(file_path_);
    if (!input_stream){
        cout<<"error reading file!"<<endl;
    }
    string line;
    while (getline(input_stream, line)){
        
    } 
}



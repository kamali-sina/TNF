#include "Finder.hpp"
#include <fstream>
#include <string>

using namespace std;

Finder::Finder(std::string file_path){
    file_path_ = file_path;
    booted_ = false;
}

void Finder::boot(){
    ifstream input_stream(file_path_);
    if (!input_stream){
        cout<<"error reading file!"<<endl;
    }
    string line;
    while (getline(input_stream, line)){
        try{
            dataset_.push_back(parse_line(line));
        } catch (string &e){
            cout<<"Exception: "<< e;
        }
    }
    booted_ = true;
}

std::vector<std::string> Finder::parse_line(std::string line){
    int comma_1_loc = line.find(SEPERATOR);
    int comma_2_loc = line.find(SEPERATOR, comma_1_loc + 1);
    if (comma_1_loc == -1 || comma_2_loc == -1){
        throw "error: line: \"" + line + "\" is not in the defined format!\n";
    }
    string number_ID = line.substr(0, comma_1_loc);
    string string_ID = line.substr(comma_1_loc + 1, comma_2_loc - comma_1_loc - 1);
    if (string_ID.length() == 0){
        string_ID = "N/A";
    }
    string phone_number = line.substr(comma_2_loc + 1);
    vector<string> parsed_line;
    parsed_line.push_back(number_ID);
    parsed_line.push_back(string_ID);
    parsed_line.push_back(phone_number);
    return parsed_line;
}

void Finder::run(){
    string input;
    cout<<"----====Welcome to TNF====----"<<endl;
    while (true){
        cout<<"enter the phrase you want to search for: ";
        cin>>input;
        search(input);
    }
}


void Finder::search(std::string input){
    vector<vector<string>> results;
    cout<<"searching..."<<endl;
    if (!booted_){
        cout<<"Warning: the Finder has not booted completely yet, the resaults might be unaccurate. continue?(y,n) ";
        string x;
        cin>>x;
        if (x == "n" || x == "no"){
            cout<<"canceling search..."<<endl;
            return;
        }
    }
    for (int i = 0 ; i < dataset_.size() ; i++){
        for (int j = 0 ; j < DATASETCOLUMNS ; j++){
            if (dataset_[i][j].find(input) != -1){ results.push_back(dataset_[i]); break;}
        }
    }
    cout<<"Search done. Found " << results.size() << " match(s):"<<endl;
    for (vector<string> result : results){
        cout<<"       "<<result[0]<<", "<<result[1]<<", "<<result[2]<<endl;
    }
    cout<<endl;
}
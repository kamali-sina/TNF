#ifndef _FINDER_HPP
#define _FINDER_HPP

#include <iostream>
#include <fstream>
#include <string>
#include <vector>

#define SEPERATOR ','
#define NUMBERID 0
#define STRINGID 1
#define PHONENUMBER 2
#define DATASETCOLUMNS 3

class Finder{
    public:
    Finder(std::string file_path);
    void boot();
    void run();
    void setPath(std::string file_path){ file_path_ = file_path; }
    void setShowTime(bool value){ show_time_ = true;}
    bool getShowTime(){ return show_time_;}
    private:
    std::string file_path_;
    bool show_time_=false;
    bool booted_;
    std::vector<std::string> parse_line(std::string line);
    std::vector<std::vector<std::string>> dataset_;
    void search(std::string input);
};


#endif
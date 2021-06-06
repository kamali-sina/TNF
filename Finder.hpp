#ifndef _FINDER_HPP
#define _FINDER_HPP

#include <iostream>
#include <fstream>
#include <string>
#include <vector>



class Finder{
    public:
    Finder(std::string file_path);
    void run();

    private:
    void boot();
    void parse_line(std::string line);
    std::string file_path_;
    std::vector<std::vector<std::string>> dataset_;
};


#endif
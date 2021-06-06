#include <iostream>
#include <fstream>
// #include <string>

using namespace std;

int main (){
    fstream yourfile;
    ofstream ofile;
    string line,amme,a,b,c;
    int i = 0;
    int x,en;
    int currentpercent = 0;
    int whole = 42823960;

    yourfile.open("../TeleDB_light.txt", ios::in | ios::app);  //The path to your file goes here
    ofile.open("../output.csv");
    ofile<<"number_id,tele_id,phone"<<endl;
    while (getline(yourfile,line)){
        amme = line;
        x = amme.find("'id': ");
        if (x != -1){
            en = amme.find(",");
            a = amme.substr(x+6,en-x - 6 );
            amme = amme.substr(en+1);
            x = amme.find("username': ");
            en = amme.find(",");
            b  = amme.substr(x+12,en - x -13);
            x = amme.find("'phone': '");
            en = amme.find("}");
            c = amme.substr(x+10,en - x - 10 - 1);
            ofile<<a<<","<<b<<","<<c<<endl;
            i++;
            if (i > ((currentpercent/100) * whole)){
                cout<<currentpercent<<"% passed..."<<endl;
                currentpercent += 5;
            }
        }
    }
    yourfile.close();
    ofile.close();
}
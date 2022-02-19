//reading a dat file and fill a histogram
#include <iostream>
#include <fstream>

void makeplot(){

    //TFile f("output.txt","read");
    ifstream file;
    file.open("output.txt");
    if(!file.is_open()){cout<<"try again"<<endl;}

    //double x_pos[2e3], xsection[2e3];
    int i=0;
    while(1){
    
    if (!file.good()) break;

    file >> x_pos[i] >> xsection[i];
    i = i+1; //see https://root.cern/doc/master/basic_8C.htmls
    //cout<< i<<" " << x_pos << " " <<xsection << endl;




    }
}


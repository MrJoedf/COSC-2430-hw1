#include <string>
#include <vector>
#include <cctype>
#include <fstream>
#include <iostream>
#ifndef DECODE_H
#define DECODE_H

using namespace std;

class Decode{
  private:
    string infile, outfile, label;
    ifstream inputFile;
    ofstream outputFile;
  
  public:
    Decode(string infile, string outfile){
      this->infile = infile;
      this->outfile = outfile;
      this->inputFile.open(this->infile);
      this->outputFile.open(this->outfile);
    }

    string findNext(string label);
  
};
#endif

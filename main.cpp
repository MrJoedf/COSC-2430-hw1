#include <iostream>
#include <fstream>
#include <string>
#include "ArgumentManager.h"
#include <cctype>
#include "decode.h"
using namespace std;

int main(int argc, char *argv[]) {
  if(argc<2){
    return -1;
  }

  ArgumentManager am(argc, argv);
  string inputFileName = am.get("input");
  string outputFileName = am.get("output");

  ifstream inputFile; ofstream outputFile;
  inputFile.open(inputFileName);
  outputFile.open(outputFileName);

  string label = "start";

  Decode test(inputFileName, outputFileName);
  cout<<test.findNext(label);

  return 1;
}
//./main "input=input2.txt;output=output2.txt"
//./main "input=input1.txt;output=output1.txt"
//./main "input=input3.txt;output=output3.txt"
// ./main "input=input4.txt;output=output4.txt"

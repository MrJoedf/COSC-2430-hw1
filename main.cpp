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

  vector<string> labels;

  ArgumentManager am(argc, argv);
  string inputFileName = am.get("input");
  string outputFileName = am.get("output");

  ifstream inputFile; ofstream outputFile;
  inputFile.open(inputFileName);
  outputFile.open(outputFileName);

  string str, label = "start";
  
  string rows, columns; //?

  
  /*while(label!="finish"){
    string loopLabel =label;
    Decode test(inputFileName);
  //labels.push_back(label);
  //cout<<endl<<"FIND NEXT: "<<test.findNext(label);
    label = test.findNext(label);
  //cout<<loopLabel<<endl;
  labels.push_back(loopLabel);
  }
  int size = labels.size();
for(int i=0; i<size; i++){
  outputFile<<labels.back()<<endl;
  labels.pop_back();
}*/
Decode test(inputFileName, outputFileName);
  cout<<test.findNext(label);



  //maybe add vector to store labels and use putback to write them to output file in reverse order?
  

  
        
      

      
      
    

  
  

//maybe function to spirally traverse matrix and look for word? if it finds it then add to the output file?
  return 1;
}
//./main "input=input2.txt;output=output2.txt"
//./main "input=input1.txt;output=output1.txt"
//./main "input=input3.txt;output=output3.txt"
// ./main "input=input4.txt;output=output4.txt"
#include <iostream>
#include <string>
#include <vector>
#include <cctype>
#include "decode.h"
using namespace std;

//the "spiralParse" function is a slight modification of the function "spiralPrint" found at https://www.geeksforgeeks.org/print-a-given-matrix-in-spiral-form/
//Which was  contributed to the website by rathbupendra

string spiralParse(int rows, int columns, vector<vector<int>> matrix) 
{ 
	int i, k = 0, l = 0; 
    	string str;

	/* k - starting row index 
		m - ending row index 
		l - starting column index 
		n - ending column index 
		i - iterator 
	*/

	while (k < rows && l < columns) { 
		/* Print the first row from 
			the remaining rows */
		for (i = l; i < columns; ++i) { 
            		str+=char(matrix.at(k).at(i));
			} 
		k++; 

		/* Print the last column 
		from the remaining columns */
		for (i = k; i < rows; ++i) { 
            		str+=char(a.at(i).at(columns - 1));
		} 
		columns--; 

		/* Print the last row from 
				the remaining rows */
		if (k < rows) { 
			for (i = columns - 1; i >= l; --i) { 
                		str+=char(matrix.at(rows - 1).at(i));
			} 
			rows--; 
		} 

		/* Print the first column from 
				the remaining columns */
		if (l < columns) { 
			for (i = rows - 1; i >= k; --i) { 
                		str+=char(matrix.at(i).at(l));
			} 
			l++; 
		} 
	} 
    return str;
} 

string Decode::findNext(string label){
      string str, dimensions, next,test;
      vector<vector<int>> matrix;//vector of vectors
      int rows=0, columns=0,count=0;
   
      while(inputFile){
        if(getline(inputFile, str)){   //looks for word in a line
          if(str==label){//makes sure operation starts from the label onwards  
		  
            getline(inputFile, dimensions);//get int rows, cols   
              for(char num : dimensions){
                if(isdigit(num)){
                    //get nums
                    if(rows==0){
                      rows=(num-'0');
                    }else{
                      columns=(num-'0');
                    }
                }
              } 
	       //get matrix data
              for(int i = 0; i<rows; i++){
                count++;
                vector<int> lines;
                getline(inputFile, str);
                  for(char character : str){
                    if(character!=' '){
                      lines.push_back(character); //each line is a row for the matrix vector
                    }
                } matrix.push_back(lines); //adds the rows to the matrix vectors
            }
            
          }else{//if it's not the label, keep going
            continue;
          }
    
      test = ::spiralParse(rows,columns,matrix); //the word found when decoding the spiral matrix
      if(test!="finish" && count<rows){
        findNext(test);
      }else{
	 //return to the beginning of the file and repeat the function
        inputFile.clear();
        inputFile.seekg(0);
        findNext(test);
      }
   }   
     }if(label!="finish"){
      	outputFile<<label<<endl;
    }
      return test;
      };

//./main "input=input1.txt;output=output1.txt"
// ./main "input=input2.txt;output=output2.txt"

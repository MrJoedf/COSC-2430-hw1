#include <iostream>
#include <string>
#include <vector>
#include <cctype>
#include "decode.h"
using namespace std;

//the "spiralParse" function is a slight modification of the function "spiralPrint" found at https://www.geeksforgeeks.org/print-a-given-matrix-in-spiral-form/
//Which was  contributed to the website by rathbupendra
string spiralParse(int m, int n, vector<vector<int>> a) 
{ 
	int i, k = 0, l = 0; 
    string str;

	/* k - starting row index 
		m - ending row index 
		l - starting column index 
		n - ending column index 
		i - iterator 
	*/

	while (k < m && l < n) { 
		/* Print the first row from 
			the remaining rows */
		for (i = l; i < n; ++i) { 
			//cout << char(a[k][i]) << ""; 
            str+=char(a.at(k).at(i));
		} 
		k++; 

		/* Print the last column 
		from the remaining columns */
		for (i = k; i < m; ++i) { 
			//cout << char(a[i][n - 1]) << ""; 
            str+=char(a.at(i).at(n - 1));
		} 
		n--; 

		/* Print the last row from 
				the remaining rows */
		if (k < m) { 
			for (i = n - 1; i >= l; --i) { 
				//cout << char(a[m - 1][i]) << ""; 
                str+=char(a.at(m - 1).at(i));
			} 
			m--; 
		} 

		/* Print the first column from 
				the remaining columns */
		if (l < n) { 
			for (i = m - 1; i >= k; --i) { 
				//cout << char(a[i][l]) << ""; 
                str+=char(a.at(i).at(l));
			} 
			l++; 
		} 
	} 
    return str;
} 

string Decode::findNext(string label){
      string str, dimensions, next,test;
      vector<vector<int>> matrix;//vector of vectors
      vector<string> content;
      int count=0;
      int rows=0, columns=0;
      //cout<<"FILE OPEN: "<<inputFile.is_open()<<endl;
      
      
      while(inputFile){
        
        if(getline(inputFile, str)){    
          if(str==label){

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
             //cout<<"TEST"<<endl;
              for(int i = 0; i<rows; i++){
                count++;
                vector<int> lines;
                getline(inputFile, str);
                  //cout<<"STR: "<<str<<endl;
                  for(char character : str){
                    if(character!=' '){
                      lines.push_back(character);
                    }
                    
                    }matrix.push_back(lines);
                }
                /*for(char line :lines){
                      cout<<"LINE TEST: "<<line<<endl;
              }*/
            //get matrix data
          }else{//if it's not the label, keep going
            
            continue;
            
          }
        
      
      //cout<<"VECTOR TEST!"<<endl;
      /*for (vector<char> v : matrix){
          cout<<"NEW VECTOR!"<<endl;
          for (char x : v){
            cout << x << ' ';cout<<"HERE"<<endl;
          }
            std::cout << std::endl;
}
      cout<<"TEST: "<<str<<endl;
        cout<<"ROWS: "<<rows<<" COLUMNS: "<<columns<<endl;
      cout<<matrix.at(1).at(1)<<endl;
      return "TEST1";*/
      
      //content.push_back(::spiralParse(rows,columns,matrix));
     
        
       
    cout<<"TEST"<<endl;
      test = ::spiralParse(rows,columns,matrix);
      if(test!="finish" && count<rows){
        cout<<"RECURSE TEST!"<<endl;
        //outputFile<<test<<endl;
        findNext(test);

      }else{
        //cout<<test<<endl;
        cout<<"TEST:"<<test<<endl;
        cout<<"LABEL:"<<label<<endl;
        cout<<"ROWS: "<<rows<<"COUNT: "<<count<<endl;
        inputFile.clear();
        inputFile.seekg(0);
        findNext(test);
        
      }//outputFile<<label<<endl;
      }  
       
     }inputFile.seekg(0);
      if(label!="finish"){
      outputFile<<label<<endl;
    }
      return test;
      };





//./main "input=input1.txt;output=output1.txt"
// ./main "input=input2.txt;output=output2.txt"
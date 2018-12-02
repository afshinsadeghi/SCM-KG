#include <stdio.h>
#include <stdlib.h>
#include <algorithm>
#include <string.h>
#include <iostream>
#include <fstream>
#include <string>
#include <sstream>

using namespace std;


string to_string (int a)     //rewriting the to_string function from C++11
{
    ostringstream temp;
    temp<<a;
    return temp.str();
}


string getNameExtension(int index){
    //int digits[] = {10000,1000,100,10};
    //string result;
    //for(int i= 3 ;i > -1; i--){
    //   if(index> digits[i]){
//	 result += result +  to_string(index % digits[i]);
//	 index = index - (index % digits[i]);
//	}     
   // }
    //result = to_string(index/10000) + to_string(index %1000) + to_string(index%100 )+ to_string( index/100 ) + to_string( index % 10);
      return std::to_string(index);
}

int main(int argc, char* argv[])
{
    cout << " " << endl;
    cout << "Afshin Sadeghi contact email: sadeghi@cs.uni-bonn.de  ETL applier for big files written in C++" << endl;
    cout << "This file splits the big files by the line numbers. It does not break files like the linux split command." << endl;
    cout << "first arg is file name. the second is number of lines." << endl;
    cout << "Example: splitByLine articles.csv 100000" << endl; 
    cout << "For exmple by 50000 Breaks the operation after every 50000 and stores the output in a new file."<< endl;

    cout << " " << endl;     

    string outputFileSizeLimitInput;
    string line;
    string resultLine;	    
    string inputFile = "";  //  = "skgData/Authors.txt";
    if(argc > 1){
    inputFile =  argv[1];
    outputFileSizeLimitInput = argv[2];
    }
    

    if( inputFile == "" || inputFile == "-help" || inputFile == "-h"){
	cout << "Please enter file name and the number of lines to apply on split it." << endl;
   	exit(EXIT_FAILURE);
    }	
    std::ifstream fp1( inputFile.c_str());
    std::ofstream fp2;
    if (fp1 == NULL)
        exit(EXIT_FAILURE);

    string delimiter = "\t";
    int counter = 1;
    int subCounter = 1;
    int outputFileSizeLimit= atoi( outputFileSizeLimitInput.c_str() ); //lines
    string nameExtension = "0";
    string outputFile = inputFile + nameExtension + ".out"; 	 
    fp2.open( outputFile.c_str());
    string * cols;

while (std::getline(fp1, line)){

	   counter++; 
	   subCounter++;	   
	   resultLine = line;
	   //cout <<  resultLine << endl;
	   fp2 << resultLine << '\n';
	   //cout  << resultLine << '\n';
//	   cout << subCounter << " " << outputFileSizeLimit << '\n';
           if(subCounter > outputFileSizeLimit ){
		subCounter = 1;
		 nameExtension = getNameExtension((int) (counter/outputFileSizeLimit));
		 fp2.close();
		 fp2.clear();
		 outputFile = inputFile + nameExtension + ".out";
  		 fp2.open(outputFile.c_str());
		//cout << outputFile  << endl;
		//cin.get();
	   }	  	 
    
  }
  fp1.close();
  fp2.close();
  exit(EXIT_SUCCESS);
}


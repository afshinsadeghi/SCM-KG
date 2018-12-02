#include <stdio.h>
#include <stdlib.h>
#include <algorithm>
#include <string.h>
#include <iostream>
#include <fstream>
#include <string>
#include <sstream>

#define MAXCOLNUM 12
using namespace std;

string replace_char(string str, char  ch1, char ch2)
{
  std::replace( str.begin(), str.end(), ch1 , ch2);
  return str;
}

// break a line into colums
string *  break_line( string line, string delimiter )
{

  int colNum;
  static string cols [MAXCOLNUM];
  colNum = 0;
  size_t pos = 0;
  std::string token;
  while ((pos = line.find(delimiter)) != std::string::npos) {
    token = line.substr(0, pos);
    cols[colNum] = token;
    colNum ++;
    //std::cout << token << std::endl;
    line.erase(0, pos + delimiter.length());
 }   
  //std::cout << line << colNum << std::endl;
  cols[colNum] = line;
  return cols;
}

void remove_ending_new_line(string col){
 col.erase(std::remove(col.begin(), col.end(), '\n'), col.end());
}

string make_line(string delimiter, string * cols )
{
  int i;
  string line= cols[0];
  for(i = 1; i< MAXCOLNUM; i++){
        if(cols[i].size() > 0){
         line += delimiter + cols[i];
        }
    }        
return line;
}

string make_line_selective(string delimiter, string * cols , int col_num1, int col_num2)
{
  int i;
  string line= cols[col_num1];
  for(i = col_num1+1; i<= col_num2; i++){
        if(cols[i].size() > 0){
         line += delimiter + cols[i];
        }else{
         line += delimiter;
        }
    }
return line;
}

string make_line_selective4(string delimiter, string * cols , int col_num1, int col_num2, int col_num3, int col_num4)
{
  int i;
  string line= cols[col_num1];

	if(cols[col_num2].size() > 0){
         line += delimiter + cols[col_num2];
	}else{
         line += delimiter;
        }

	if(cols[col_num3].size() > 0){
         line += delimiter + cols[col_num3];
	}else{
         line += delimiter;
        }

	if(cols[col_num4].size() > 0){
         line += delimiter + cols[col_num4];
	}else{
         line += delimiter;
        }
return line;
}

string make_line_selective5(string delimiter, string * cols , int col_num1, int col_num2, int col_num3, int col_num4, int col_num5)
{
  int i;
  string line= cols[col_num1];

        if(cols[col_num2].size() > 0){
         line += delimiter + cols[col_num2];
        }else{
         line += delimiter;
        }

        if(cols[col_num3].size() > 0){
         line += delimiter + cols[col_num3];
        }else{
         line += delimiter;
        }

        if(cols[col_num4].size() > 0){
         line += delimiter + cols[col_num4];
        }else{
         line += delimiter;
        }
 	 if(cols[col_num5].size() > 0){
         line += delimiter + cols[col_num5];
        }else{
         line += delimiter;
        }
return line;
}

string make_line_selective7(string delimiter, string * cols , int col_num1, int col_num2, int col_num3, int col_num4, int col_num5, int col_num6, int col_num7)
{
  int i;
  string line= cols[col_num1];

        if(cols[col_num2].size() > 0){
         line += delimiter + cols[col_num2];
        }else{
         line += delimiter;
        }

        if(cols[col_num3].size() > 0){
         line += delimiter + cols[col_num3];
        }else{
         line += delimiter;
        }

        if(cols[col_num4].size() > 0){
         line += delimiter + cols[col_num4];
        }else{
         line += delimiter;
        }
         if(cols[col_num5].size() > 0){
         line += delimiter + cols[col_num5];
        }else{
         line += delimiter;
        }
        if(cols[col_num6].size() > 0){
         line += delimiter + cols[col_num6];
        }else{
         line += delimiter;
        }
         if(cols[col_num7].size() > 0){
         line += delimiter + cols[col_num7];
        }else{
         line += delimiter;
        }
return line;
}

string remove_ending_schar(string str){
    //remove ending space
    //if (col.substr( col.size()-2,col.size()-1)== " ") col.erase(col.size()-1);
    // remove special carachters;
    //col.erase(std::remove_if(col.begin(), col.end(), [](char c) { return std::isalpha(c); } ), col.end());
    str.erase(std::remove(str.begin(), str.end(), '\r'), str.end());
    str.erase(std::remove(str.begin(), str.end(), '\n'), str.end());
    return str;
}

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
    cout << "Notice: Currently the rules are not added, only the file name is asked" << endl;
    cout << "So you have to edit the main function in source code to apply them." << endl;
    cout << " " << endl;     

    string line;
    string resultLine;	    
    string inputFile = "";  //  = "skgData/Authors.txt";
    if(argc > 1){
    inputFile =  argv[1];
    }
    

    if( inputFile == "" || inputFile == "-help" || inputFile == "-h"){
	cout << "Please enter file name and delimiter and  rule to apply on it." << endl;
        cout << "Example: etler skgData/Authors.txt , -copy 2 3 " << endl;
 	cout <<     "It assigns ',' as delimiter and will apply copy rule"<<endl;
	cout << "-copy 2 3   Copies column 2 to create column 3." << endl;	
	cout << "-rem 3      Removes column 3" << endl;
        cout << "-repl 2 ' ' '_'  Replaces all spaces to underline in column 2" << endl;
	cout << "-counter 3  Adds a counter of line as column 3" << endl;
	cout << "-break 50000 Breaks the operation after every 50000 and stores the output in a new file."<< endl;
	cout << "Notice: only one rule is applied by each call" << endl;
   	exit(EXIT_FAILURE);
    }	
    std::ifstream fp1( inputFile.c_str());
    std::ofstream fp2;
    if (fp1 == NULL)
        exit(EXIT_FAILURE);

    string delimiter = "\t";
    int counter = 1;
    int subCounter = 1;
    int outputFileSizeLimit= 990000; //lines
    string nameExtension = "";
    string outputFile = inputFile + nameExtension + ".etl"; 	 
    fp2.open( outputFile.c_str());
    string * cols;

while (std::getline(fp1, line)){

	   counter++; 
	   subCounter++;	   
	   cols = break_line(line, delimiter);
	   //cols[1]= remove_ending_schar(cols[1]);
	   //cols[2]= cols[1];
	   //cols[2]= replace_char(cols[2], ' ', '_');
	   //resultLine = make_line(",", cols);
	   resultLine = make_line_selective5(",", cols, 0 , 1, 2, 3, 9); //give first and last col to incldue
	   //cout << cols[0] << cols[1] << endl;	   
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


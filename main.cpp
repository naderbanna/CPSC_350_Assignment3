#include "GenStack.h"
#include <iostream>
#include <fstream>

using namespace std;

int main (int argc, char **argv){

  GenStack <char> delimStack(10);
  GenStack <int> lineStack(10);

  //take input file and open file stream
  string inputFile;
  cout << "Enter a file name: " << endl;
  cin >> inputFile;
  ifstream fileStream;
  fileStream.open(inputFile);
  //read through each line and handle delimiters
  string lineStr = "";
  int ln = 0;
  while(getline(fileStream, lineStr)){
    //line counter
    ln++;
    for(int i = 0; i < lineStr.size(); i++){
      if(lineStr[i] == '(' || lineStr[i] == '{' || lineStr[i] == '['){
        delimStack.push(lineStr[i]);
        lineStack.push(ln);
      }if(lineStr[i] == ')' || lineStr[i] == '}' || lineStr[i] == ']'){
        if(delimStack.isEmpty() == true){
          delimStack.push(lineStr[i]);
          lineStack.push(ln);
        }if(delimStack.peek() == '(' && lineStr[i] == ')'){
          delimStack.pop();
          lineStack.pop();
        }if(delimStack.peek() == '{' && lineStr[i] == '}'){
          delimStack.pop();
          lineStack.pop();
        }if(delimStack.peek() == '[' && lineStr[i] == ']'){
          delimStack.pop();
          lineStack.pop();
        }
      }
    }
  }
  fileStream.close();
  //print error
  if(delimStack.isEmpty() != true){
    cout << "Error on Line " << lineStack.pop() << ": Delim " << delimStack.pop() << endl;
  }else{
    cout << "No errors found" << endl;
  }

  return 0;
}

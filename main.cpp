#include "GenStack.h"
#include <iostream>
#include <fstream>

using namespace std;

int main (int argc, char **argv){

  GenStack <char> delimStack(10);
  GenStack <int> lineStack(10);


  //take input file
  string inputFile;
  cout << "Enter a file name: " << endl;
  cin >> inputFile;

  ifstream fileStream;
  fileStream.open(inputFile);

  string lineStr = "";
  int ln = 0;

  while(getline(fileStream, lineStr)){
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
  
  cout << delimStack.peek() << " " << "Line: " << lineStack.peek() << endl;

  while(delimStack.isEmpty() != true){
    cout << "Error on Line " << lineStack.pop() << ": Found " << delimStack.pop() << endl;

  }
  //read input file by each char? and find the delimiters (), [], {}
  //make sure each delimiter has an inverse in the correct order
  //if there is an error, stop and display Line Error

  // cout << delimStack.pop() << " " << "Line: " << lineStack.pop() << endl;
  // cout << delimStack.pop() << " " << "Line: " << lineStack.pop() << endl;
  // cout << delimStack.pop() << " " << "Line: " << lineStack.pop() << endl;
  // cout << delimStack.pop() << " " << "Line: " << lineStack.pop() << endl;
  // cout << delimStack.pop() << " " << "Line: " << lineStack.pop() << endl;
  // cout << delimStack.pop() << " " << "Line: " << lineStack.pop() << endl;

  return 0;


}

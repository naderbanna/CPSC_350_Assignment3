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
  // while(getline(fileStream, lineStr)){
  //   ln++;
  //   for(int i = 0; i < lineStr.size(); i++){
  //     if(lineStr[i] == '(' && lineStr[i+1] != ')' || lineStr[i] == '{' && lineStr[i+1] != '}' || lineStr[i] == '[' && lineStr[i+1] != ']'){
  //         delimStack.push(lineStr[i]);
  //         lineStack.push(ln);
  //     }if(lineStr[i] == '(' ){
  //
  //     }if(lineStr[i] == ')' ){
  //       if(delimStack.peek() == '('){
  //         delimStack.pop();
  //         lineStack.pop();
  //       }
  //     }if(lineStr[i] == '}' ){
  //       if(delimStack.peek() == '{'){
  //           delimStack.pop();
  //           lineStack.pop();
  //         }
  //     }if(lineStr[i] == ']' ){
  //       if(delimStack.peek() == '['){
  //         delimStack.pop();
  //         lineStack.pop();
  //       }
  //     }if(lineStr[i] == ')' || lineStr[i] == '}' || lineStr[i] == ']'){
  //       delimStack.push(lineStr[i]);
  //       lineStack.push(ln);
  //     }
  //   }
  // }


  while(getline(fileStream, lineStr)){
    ln++;
    for(int i = 0; i < lineStr.size(); i++){
      if(lineStr[i] == '(' || lineStr[i] == '{' || lineStr[i] == '['){
        delimStack.push(lineStr[i]);
        lineStack.push(ln);
      }if(lineStr[i] == ')' || lineStr[i] == '}' || lineStr[i] == ']'){
        if(delimStack.peek() == '(' && lineStr[i] == ')'){
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
  //read input file by each char? and find the delimiters (), [], {}
  //make sure each delimiter has an inverse in the correct order
  //if there is an error, stop and display Line Error

  //GenStack *myStack = new GenStack(10);
  cout << "hello" << endl;


  //cout << delimStack.peek() << " " << "Line: " << lineStack.peek() << endl;
  cout << delimStack.pop() << " " << "Line: " << lineStack.pop() << endl;
  cout << delimStack.pop() << " " << "Line: " << lineStack.pop() << endl;
  cout << delimStack.pop() << " " << "Line: " << lineStack.pop() << endl;
  cout << delimStack.pop() << " " << "Line: " << lineStack.pop() << endl;
  cout << delimStack.pop() << " " << "Line: " << lineStack.pop() << endl;
  cout << delimStack.pop() << " " << "Line: " << lineStack.pop() << endl;


  //cout << Stack.peek() << endl;


  //cout << myStack.peek() << endl;
  //cout << myStack.pop() << endl;
  //cout << myStack.peek() << endl;
  //cout << myStack.pop() << endl;
  //cout << myStack.peek() << endl;
  //cout << myStack.pop() << endl;
  //cout << myStack.pop() << endl;
  //cout << myStack.pop() << endl;

  return 0;


}

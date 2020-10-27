#include "GenStack.h"
#include <iostream>

using namespace std;

int main (int argc, char **argv){

  //take input file
  //read input file by each char? and find the delimiters (), [], {}
  //make sure each delimiter has an inverse in the correct order
  //if there is an error, stop and display Line Error

  //GenStack *myStack = new GenStack(10);
  cout << "hello" << endl;

  GenStack <char> myStack(10);

  myStack.push('N');
  myStack.push('a');
  myStack.push('d');
  myStack.push('e');
  myStack.push('r');

  //cout << myStack.peek() << endl;
  cout << myStack.pop() << endl;
  //cout << myStack.peek() << endl;
  cout << myStack.pop() << endl;
  //cout << myStack.peek() << endl;
  cout << myStack.pop() << endl;
  cout << myStack.pop() << endl;
  cout << myStack.pop() << endl;

  return 0;


}

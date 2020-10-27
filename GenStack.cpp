// #include <iostream>
// #include "GenStack.h"
//
// using namespace std;
//
// template <class temp>
// GenStack<temp>::GenStack(){
//   myArray = new char[128];
//   mSize = 128;
//   top = -1;
// }
//
// template <class temp>
// GenStack<temp>::GenStack(int maxSize){
//   myArray = new char[maxSize];
//   mSize = maxSize;
//   top = -1;
// }
//
// template <class temp>
// GenStack<temp>::~GenStack(){
//   //some other stuff here idk
//   delete myArray;
// }
//
// template <class temp>
// void GenStack<temp>::push(temp data){
//   //check if full
//   myArray[++top] = data;
// }
//
// template <class temp>
// temp GenStack<temp>::pop(){
//
//   if(isEmpty()){
//     cout << "stack is empty" << endl;
//   }
//   return myArray[top--];
// }
//
//
//
//
//
// char GenStack::peek(){
//   return myArray[top];
// }
//
// bool GenStack::isFull(){
//   return (top == mSize-1);
// }
//
// bool GenStack::isEmpty(){
//   return (top == -1);
// }
//
// int GenStack::getSize(){
//   return top + 1;
// }

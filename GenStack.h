#include <iostream>
using namespace std;

template <class temp>
class GenStack{
  public:
    GenStack();
    GenStack(int maxSize);
    ~GenStack();

    void push(temp data);
    temp pop();
    temp peek();

    bool isFull();
    bool isEmpty();
    int getSize();
    void updateSize();

    int top;
    int mSize;

    temp *myArray;
};



template <class temp>
GenStack<temp>::GenStack(){
  myArray = new temp[128];
  mSize = 128;
  top = -1;
}

template <class temp>
GenStack<temp>::GenStack(int maxSize){
  myArray = new temp[maxSize];
  mSize = maxSize;
  top = -1;
}

template <class temp>
GenStack<temp>::~GenStack(){
  delete myArray;
}

template <class temp>
void GenStack<temp>::push(temp data){
  //check if full
  myArray[++top] = data;
}

template <class temp>
temp GenStack<temp>::pop(){

  if(isEmpty()){
    cout << "stack is empty" << endl;
  }
  return myArray[top--];
}

template <class temp>
temp GenStack<temp>::peek(){
   return myArray[top];
}

template <class temp>
bool GenStack<temp>::isFull(){
  return (top == mSize-1);
}

template <class temp>
bool GenStack<temp>::isEmpty(){
  return (top == -1);
}

template <class temp>
int GenStack<temp>::getSize(){
  return top + 1;
}

//not working
template <class temp>
void GenStack<temp>::updateSize(){
}

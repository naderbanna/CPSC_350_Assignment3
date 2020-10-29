#include <iostream>
using namespace std;
//template stack class
template <class temp>
class GenStack{
  public:
    GenStack();
    GenStack(int maxSize);
    ~GenStack();

    void push(temp data);
    temp pop();
    temp peek();
    //helper functions
    bool isFull();
    bool isEmpty();
    int getSize();
    void updateSize(temp newSize);
    
    int top;
    int mSize;
    int newSize;

    temp *myArray;
    temp *updateArray;
};

//default constructor
template <class temp>
GenStack<temp>::GenStack(){
  myArray = new temp[128];
  updateArray = new temp[128];
  mSize = 128;
  top = -1;
}
//overloaded constructor
template <class temp>
GenStack<temp>::GenStack(int maxSize){
  myArray = new temp[maxSize];
  updateArray = new temp[maxSize];
  mSize = maxSize;
  top = -1;
}
//desctructor
template <class temp>
GenStack<temp>::~GenStack(){
  delete updateArray;
  delete myArray;
}

template <class temp>
void GenStack<temp>::push(temp data){
  //check if full before push
  if(isFull()){
    //update to double the current size
    updateSize(getSize()*2);
    myArray[++top] = data;
  }else{
    myArray[++top] = data;
  }
}

template <class temp>
temp GenStack<temp>::pop(){
  //check if empty before pop
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


template <class temp>
void GenStack<temp>::updateSize(temp newSize){
  //new array of double size
  updateArray = new temp[newSize];
  //copy current array into new
  for (int i = 0; i < top+1 ; i++){
    updateArray[i] = myArray[i];
  }
  //set current array to the new array
  myArray = updateArray;

}

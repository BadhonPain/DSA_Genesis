#include <iostream>
using namespace std;

class ArrayStack
{
  int *data;
  int top; // index of the last inserted element
  int capacity;

public:
  ArrayStack(int capacity = 2)
  {
    this->capacity = capacity;
    data = new int[capacity];
    cout << "Created an empty Stack with capacity " << capacity << endl;
    top = -1; // index of the last inserted element
  }
  bool isEmpty();     // checks stack is empty or not
  bool isFull();      // checks stack is full or not
  void push(int val); // add new value to stack
  void pop();         // remove last inserted value
  int peek();         // return the top value
  int size();         // return the size of the stack
  void print();       // print the Stack

  ~ArrayStack()
  {
    delete[] data;
  }
};

bool ArrayStack ::isEmpty()
{
  return top == -1;
}
bool ArrayStack ::isFull()
{
  return top == capacity - 1;
}

void ArrayStack ::push(int val)
{
  if (isFull())
  {
    cout << "Stack is full !" << endl;
    return;
  }
  data[++top] = val;
  cout << val << " is pushed to the Stack" << endl;
}

void ArrayStack ::pop()
{
  if (isEmpty())
  {
    cout << "Stack is Empty !" << endl;
    return;
  }
  cout << data[top] << " is poped" << endl;
  top--;
}

int ArrayStack ::peek()
{
  if (isEmpty())
  {
    cout << "Stack is Empty !" << endl;
    return -1;
  }
  return data[top];
}

int ArrayStack ::size()
{
  return top + 1;
}

void ArrayStack ::print()
{
  if (isEmpty())
  {
    cout << "Stack is Empty !" << endl;
    return;
  }
  cout << "Stack: ";
  for (int i = top; i >= 0; i--)
  {
    cout << data[i] << " ";
  }
  cout << endl;
}

int main()
{
  ArrayStack ast(5);
  ast.push(10);
  ast.push(20);
  ast.push(30);
  cout << "Size of the Stack is: " << ast.size() << endl;
  cout << "Top value of the Stack: " << ast.peek() << endl;
  ast.pop();
  ast.pop();
  cout << "Size of the Stack is: " << ast.size() << endl;
  cout << "Top value of the Stack: " << ast.peek() << endl;
  ast.print();
  ast.pop();
  cout << "Size of the Stack is: " << ast.size() << endl;
  cout << "Top value of the Stack: " << ast.peek() << endl;
  ast.push(12);
  ast.push(87);
  cout << "Top value of the Stack: " << ast.peek() << endl;
}
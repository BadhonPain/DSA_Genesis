#include <iostream>
#include <vector>
using namespace std;

class VectorStack
{
  vector<int> v;

public:
  bool isEmpty(); // checks stack is empty or not
  // bool isFull();      // Never a Vectorstack become full
  void push(int val); // add new value to stack
  void pop();         // remove last inserted value
  int peek();         // return the top value
  int size();         // return the size of the stack
  void print();       // print the Stack
};

bool VectorStack ::isEmpty()
{
  return v.empty();
}

void VectorStack ::push(int val)
{
  v.push_back(val);
  cout << val << " is pushed to the Stack" << endl;
}

void VectorStack ::pop()
{
  if (isEmpty())
  {
    cout << "Stack is Empty !" << endl;
    return;
  }
  cout << v.back() << " is poped from the Stack" << endl;
  v.pop_back();
}

int VectorStack ::peek()
{
  if (isEmpty())
  {
    cout << "Stack is Empty !" << endl;
    return -1;
  }
  return v.back();
}

int VectorStack ::size()
{
  return v.size();
}

void VectorStack ::print()
{
  if (isEmpty())
  {
    cout << "Stack is Empty !" << endl;
    return;
  }
  cout << "Stack: ";
  for (int i = v.size() - 1; i >= 0; i--)
  {
    cout << v[i] << " ";
  }
  cout << endl;
}

int main()
{
  VectorStack vs;
  vs.push(1);
  vs.push(2);
  vs.push(3);
  cout << "Top of the Stack is: " << vs.peek() << endl;
  vs.print();
  vs.pop();
  vs.print();
  vs.pop();
  cout << "Top of the Stack is: " << vs.peek() << endl;
}

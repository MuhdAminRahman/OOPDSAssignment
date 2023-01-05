#include <cstdlib>
#include <iostream>
#include <string>
using namespace std;

struct StackNode {
    int value;
    StackNode *next;
    StackNode(int value1, StackNode *next1 = nullptr) {
      value = value1;
      next = next1;
    }
};

class DynIntStack {
  StackNode *top;

public:
  DynIntStack() {
     top = nullptr; 
  }

  ~DynIntStack();
  
  void push(int);
  void pop(int &);
  bool isEmpty() const;
  int peek(){
    return top->value;
  }
  // Stack Exception
  class Underflow {};
};
void DynIntStack::push(int num) { top = new StackNode(num, top); }
void DynIntStack::pop(int &num) {
  StackNode *temp;
  if (isEmpty()) {
    throw DynIntStack::Underflow();
  } else {
    // Pop value off top of stack
    num = top->value;
    temp = top;
    top = top->next;
    delete temp;
  }
}

bool DynIntStack::isEmpty() const { return top == nullptr; }

DynIntStack::~DynIntStack() {
  StackNode *garbage = top;
  while (garbage != nullptr) {
    top = top->next;
    garbage->next = nullptr;
    delete garbage;
    garbage = top;
  }
}
int main() {
  DynIntStack stack;
  int popped_value;
  for (int value = 5; value <= 45; value = value + 5) {
    cout << "Push: " << value << "\n";
    stack.push(value);
  }
  cout << "\n";
  

    cout << "----->" << stack.peek() << endl;

  while (!stack.isEmpty()) {
    cout << "Pop: ";
    stack.pop(popped_value);
    cout << popped_value << endl;
  }

  try {
    cout << "\nAttempting to pop again... ";
    stack.pop(popped_value);
  } catch (DynIntStack::Underflow) {
    cout << "Underflow exception occurred.\n";
  }
  return 0;
}

#ifndef queue.h
#define queue.h

#include <stack>
#include <cstddef>
using namespace std;

template <typename T>
class Queue {
 private:
  stack<T> stack1;
  stack<T> stack2;
  size_t size;
  const size_t capacity;

 public:
  void push(T k);
  void pop();
  T front();
  T back();
  bool isFull();
  bool isEmpty();

 };
//   Queue(size_t capacity) : capacity(capacity) {
//     size = 0;
//   }

  Queue(size_t capacity) {
    this->capacity=capacity;
    size = 0;
  }

  void push(T element) {
    if (size == capacity) {
      throw overflow_error("Queue is full");
    }
    stack1.push(element);
    size++;
  }

  void pop() {
    if (size == 0) {
      throw underflow_error("Queue is empty");
    }
    if (stack2.empty()) {
      while (!stack1.empty()) {
        stack2.push(stack1.top());
        stack1.pop();
      }
    }
    stack2.pop();
    size--;
  }

  T front() {
    if (size == 0) {
      throw underflow_error("Queue is empty");
    }
    if (stack2.empty()) {
      while (!stack1.empty()) {
        stack2.push(stack1.top());
        stack1.pop();
      }
    }
    return stack2.top();
  }

  T back() {
    if (size == 0) {
      throw underflow_error("Queue is empty");
    }
    if (stack1.empty()) {
      while (!stack2.empty()) {
        stack1.push(stack2.top());
        stack2.pop();
      }
    }
    return stack1.top();
  }

  bool isFull() {
    return size == capacity;
  }

  bool isEmpty() {
    return size == 0;
  }


#endif

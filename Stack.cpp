#include "Stack.h"

// Method 6
// To initialise top to
// -1(default constructor)
template <class T>
Stack<T>::Stack() { top = -1; }

// Method 7
// To add element element k to stack
template <class T>
void Stack<T>::push(T k)
{

    // Checking whether stack is completely filled
    if (isFull())
    {
        // Display message when no elements can be pushed
        // into it
        cout << "Stack is full\n";
    }

    // Inserted element
    cout << "Inserted element " << k << endl;

    // Incrementing the top by unity as element
    // is to be inserted
    top = top + 1;

    // Now, adding element to stack
    st[top] = k;
}

// Method 8
// To check if the stack is empty
template <class T>
bool Stack<T>::isEmpty()
{
    if (top == -1)
        return 1;
    else
        return 0;
}

// Utility methods

// Method 9
// To check if the stack is full or not
template <class T>
bool Stack<T>::isFull()
{
    // Till top in inside the stack
    if (top == (SIZE - 1))
        return 1;
    else

        // As top can not exceeds th size
        return 0;
}

// Method 10
template <class T>
void Stack<T>::pop()
{
    top--;
}

// Method 11
template <class T>
T Stack<T>::first()
{
    // Initialising a variable to store top element
    T top_element = st[top];

    // Returning the top element
    return top_element;
}
template <class T>
T Stack<T>::last()
{
    // create a variable to store the bottom element
    T bottom_element;
    // assign the bottom element to the first element in the stack array
    bottom_element = st[0];
    // return the bottom element
    return bottom_element;
}
template <typename T>
bool Stack<T>::search(T k)
{
    if (isEmpty())// check if the stack is empty
    {
        cout << "The stack is empty" << endl;
    }
    else
    {
        // iterate through the stack from top to bottom
        for (int i = top; i >= 0; i--)
        {
            // check if the current element matches the search element
            if (st[i] == element)
            {
                // return the index if found
                return i;
            }
        }
    }
    // return -1 if not found
    return -1;
}

template <typename T>
void Stack<T>::sort()
{
    // check if the stack is empty
    if (isEmpty())
    {
        cout << "The stack is empty" << endl;
    }
    else
    {
        // outer loop for iterating through the stack
        for (int i = 0; i < top; i++)
        {
            // inner loop for comparing elements
            for (int j = i + 1; j <= top; j++)
            {
                // check if the current element is greater than the next element
                if (st[i] > st[j])
                {
                    // swap the elements if true
                    T temp = st[i];
                    st[i] = st[j];
                    st[j] = temp;
                }
            }
        }
    }
}
template <class T>
void Stack<T>::print()
{
    // check if the stack is empty
    if (isEmpty())
    {
        cout << "The stack is empty" << endl;
    }
    else
    {
        cout << "Elements of the stack:" << endl;
        // iterate through the stack from top to bottom
        for (int i = top; i >= 0; i--)
        {
            // print the element
            cout << st[i] << endl;
        }
    }
}

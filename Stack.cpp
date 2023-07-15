#include <iostream>
#include <stack>
using namespace std;
int main() 
{
    stack<int> myStack;
    myStack.push(5);
    myStack.push(10);
    myStack.push(15);
    if (myStack.empty()) 
    {
        cout << "Stack is empty!" << endl;
    } else
    {
       cout << "Stack is not empty." << endl;
    }
    cout << "Top element: " << myStack.top() << endl;
    myStack.pop();
    cout << "After popping, top element: " << myStack.top() << endl;
    cout << "Size of stack: " << myStack.size() << endl;
    return 0;
}

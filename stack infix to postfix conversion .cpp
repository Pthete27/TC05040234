#include <iostream>
#include <stack>
#include <string>
#include <unordered_map>
using namespace std;
bool isOperator(char c)
{
    if (c == '+' || c == '-' || c == '*' || c == '/')
        return true;
    return false;
}
int getPrecedence(char op) {
    if (op == '+' || op == '-')
        return 1;
    if (op == '*' || op == '/')
        return 2;
    return 0;
}
// Function to convert infix to postfix
string infixToPostfix(const string& infix)
{
    stack<char> stack;
    string postfix;
    unordered_map<char, int> precedence;
    precedence['+'] = 1;
    precedence['-'] = 1;
    precedence['*'] = 2;
    precedence['/'] = 2;
    for (char c : infix)
    {
        if (isalnum(c))
            postfix += c;
        else if (c == '(')
            stack.push(c);
        else if (c == ')') 
        {
            while (!stack.empty() && stack.top() != '(')
            {
                postfix += stack.top();
                stack.pop();
            }
            stack.pop();
        }
        else if (isOperator(c)) 
        {
            while (!stack.empty() && precedence[c] <= precedence[stack.top()]) {
                postfix += stack.top();
                stack.pop();
            }
            stack.push(c);
        }
    }
  // Pop any remaining operators from the stack and append them to the postfix string
    while (!stack.empty()) {
        postfix += stack.top();
        stack.pop();
    }
    return postfix;
}
int main()
{
    string infixExpression;
    cout << "Enter an infix expression: ";
    getline(cin, infixExpression);
    string postfixExpression = infixToPostfix(infixExpression);
    cout << "Postfix expression: " << postfixExpression << endl;
    return 0;
}

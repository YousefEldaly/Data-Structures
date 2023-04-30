#include <iostream>
// #include <algorithm>
#include "stack_queue_implementation.h"
#include "Stack.cpp"
using namespace std;

//------------------------------------------------------------------------------------------------------------
// Convert the Infix Expression to Postfix Expression problem
//------------------------------------------------------------------------------------------------------------

bool isOperator(char c)
{
    return (c == '+' || c == '-' || c == '*' || c == '/' || c == '^');
}

int getPrecedence(char op)
{
    if (op == '^')
        return 3;
    else if (op == '*' || op == '/')
        return 2;
    else if (op == '+' || op == '-')
        return 1;
    else
        return 0;
}

string infixToPostfix(string infix)
{
    Stack<char> s;
    string postfix;

    for (int i = 0; i < infix.length(); i++)
    {
        char c = infix[i];

        if (isalnum(c))
        {
            postfix += c;
        }
        else if (isOperator(c))
        {
            while (!s.isEmpty() && isOperator(s.top()) && getPrecedence(c) <= getPrecedence(s.top()))
            {
                postfix += s.top();
                s.pop();
            }
            s.push(c);
        }
        else if (c == '(')
        {
            s.push(c);
        }
        else if (c == ')')
        {
            while (!s.isEmpty() && s.top() != '(')
            {
                postfix += s.top();
                s.pop();
            }
            s.pop();
        }
    }

    while (!s.isEmpty())
    {
        postfix += s.top();
        s.pop();
    }

    return postfix;
}

//------------------------------------------------------------------------------------------------------------
//  Longest Valid Parentheses problem
//------------------------------------------------------------------------------------------------------------

int longestValidParentheses(string str)
{
    Stack<int> s;
    int n = str.length(), maxLength = 0, start = -1;

    for (int i = 0; i < n; i++)
    {
        if (str[i] == '(')
        {
            s.push(i);
        }
        else
        {
            if (s.isEmpty())
            {
                start = i;
            }
            else
            {
                s.pop();
                if (s.isEmpty())
                {
                    maxLength = max(maxLength, i - start);
                }
                else
                {
                    maxLength = max(maxLength, i - s.top());
                }
            }
        }
    }

    return maxLength;
}

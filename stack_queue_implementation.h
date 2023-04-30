
//
// Created by Ahmed Ashraf on 4/29/2023.
//

#ifndef LINEAR_STRUCTURES_STACK_QUEUE_IMPLEMENTAION_H
#define LINEAR_STRUCTURES_STACK_QUEUE_IMPLEMENTAION_H

//------------------------------------------------------------------------------------------------------------
// Convert the Infix Expression to Postfix Expression problem
//------------------------------------------------------------------------------------------------------------

string infixToPostfix(string infix);
int getPrecedence(char op);
bool isOperator(char c);

//------------------------------------------------------------------------------------------------------------
// Longest Valid Parentheses problem
//------------------------------------------------------------------------------------------------------------

int longestValidParentheses(string str);

//------------------------------------------------------------------------------------------------------------
//  Generate Binary Numbers from 1 to N problem
//------------------------------------------------------------------------------------------------------------

void generateBinaryIntegers(int n);

#endif // LINEAR_STRUCTURES_STACK_QUEUE_IMPLEMENTAION_H
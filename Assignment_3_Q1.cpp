#include <iostream>
#include "Assignment_3_Q1.h"
#include <cctype>
#include <stack>

bool ExpressionManager::isOperator(char c) {
    return (c == '+' || c == '-' || c == '*' || c == '/' || c == '%');
}

bool ExpressionManager::isOpeningParenthesis(char c) {
    return (c == '(' || c == '{' || c == '[');
}

bool ExpressionManager::isClosingParenthesis(char c) {
    return (c == ')' || c == '}' || c == ']');
}

char ExpressionManager::getMatchingOpeningParenthesis(char c) {
    switch (c) {
        case ')': return '(';
        case '}': return '{';
        case ']': return '[';
        default: return '\0'; // Not a valid closing parenthesis
    }
}

bool ExpressionManager::isBalancedParentheses(const std::string& expression) {
    std::stack<char> parenthesesStack;

    for (char c : expression) {
        if (isOpeningParenthesis(c)) {
            parenthesesStack.push(c);
        } else if (isClosingParenthesis(c)) {
            if (parenthesesStack.empty() || parenthesesStack.top() != getMatchingOpeningParenthesis(c)) {
                return false; // Unmatched closing parenthesis
            }
            parenthesesStack.pop();
        }
    }

    return parenthesesStack.empty(); // Check if any unmatched opening parentheses are left
}

std::string ExpressionManager::infixToPostfix(const std::string& infix) {
    std::string postfix;
    std::stack<char> operators;

    for (char c : infix) {
        if (std::isalnum(c)) {
            postfix += c; // Operand, add to postfix
        } else if (isOperator(c)) {
            // Operator, pop higher or equal precedence operators from stack and add to postfix
            while (!operators.empty() && operators.top() != '(' && precedence(operators.top()) >= precedence(c)) {
                postfix += operators.top();
                operators.pop();
            }
            operators.push(c);
        } else if (isOpeningParenthesis(c)) {
            operators.push(c);
        } else if (isClosingParenthesis(c)) {
            // Pop operators from stack and add to postfix until matching opening parenthesis
            while (!operators.empty() && operators.top() != getMatchingOpeningParenthesis(c)) {
                postfix += operators.top();
                operators.pop();
            }
            operators.pop(); // Pop the matching opening parenthesis
        }
    }

    // Pop remaining operators from stack and add to postfix
    while (!operators.empty()) {
        postfix += operators.top();
        operators.pop();
    }

    return postfix;
}

int ExpressionManager::precedence(char c) {
    if (c == '+' || c == '-') return 1;
    if (c == '*' || c == '/' || c == '%') return 2;
    return 0; // For parentheses
}

int main() {
  ExpressionManager manager;

  // Test your functions here
  std::string infixExpression = "5+2/(3+4)-2";

  if (manager.isBalancedParentheses(infixExpression)) {
      std::string postfixExpression = manager.infixToPostfix(infixExpression);
      std::cout << "Postfix Expression: " << postfixExpression << std::endl;
  } else {
      std::cout << "The expression has unbalanced parentheses." << std::endl;
  }

  return 0;
}





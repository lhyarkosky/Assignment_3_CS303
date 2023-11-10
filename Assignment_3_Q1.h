#include <string>

class ExpressionManager {
public:
    bool isBalancedParentheses(const std::string& expression);
    std::string infixToPostfix(const std::string& infix);

private:
    bool isOperator(char c);
    bool isOpeningParenthesis(char c);
    bool isClosingParenthesis(char c);
    char getMatchingOpeningParenthesis(char c);
    int precedence(char c);
};

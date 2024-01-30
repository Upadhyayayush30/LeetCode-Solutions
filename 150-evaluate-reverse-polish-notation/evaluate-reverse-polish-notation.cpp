class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int> operandStack;

        for (const string& token : tokens) {
            if (isdigit(token[0]) || (token[0] == '-' && token.size() > 1 && isdigit(token[1]))) {
                operandStack.push(stoi(token));
            } else {
                int operand2 = operandStack.top();
                operandStack.pop();
                int operand1 = operandStack.top();
                operandStack.pop();

                int result;
                if (token == "+") {
                    result = operand1 + operand2;
                } else if (token == "-") {
                    result = operand1 - operand2;
                } else if (token == "*") {
                    result = operand1 * operand2;
                } else if (token == "/") {
                    result = operand1 / operand2;
                }

                operandStack.push(result);
            }
        }

        return operandStack.top();
    }
};
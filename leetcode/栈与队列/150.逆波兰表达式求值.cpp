class Solution
{
public:
    int evalRPN(vector<string> &tokens)
    {
        int operand1;
        int operand2;
        stack<int> operand; //存操作数
        for (int i = 0; i < tokens.size(); i++)
        {
            if (tokens[i] == "+" || tokens[i] == "-" || tokens[i] == "*" || tokens[i] == "/") //读到运算符
            {
                operand2 = operand.top();
                operand.pop();
                operand1 = operand.top();
                operand.pop();

                if (tokens[i] == "+")
                    operand.push(operand1 + operand2);
                else if (tokens[i] == "-")
                    operand.push(operand1 - operand2);
                else if (tokens[i] == "*")
                    operand.push(operand1 * operand2);
                else if (tokens[i] == "/")
                    operand.push(operand1 / operand2);
            }
            else                               //读到操作数
                operand.push(stoi(tokens[i])); // stoi: string to int
        }

        return operand.top();
    }
};

#include <iostream>
#include <stack>
#include <cctype>
using namespace std;

int postfixEvaluation(string s)
{
    stack<int> st;
    for (int i = 0; i < s.length(); i++)
    {
        char ch = s[i];
        if (ch == ' ')
            continue;

        if (isdigit(ch))
            st.push(ch - '0');
        else if (ch == '+' || ch == '-' || ch == '*' || ch == '/')
        {
            int operand2 = st.top();
            st.pop();
            int operand1 = st.top();
            st.pop();
            int result;
            if (ch == '+')
                result = operand1 + operand2;
            else if (ch == '-')
                result = operand1 - operand2;
            else if (ch == '*')
                result = operand1 * operand2;
            else if (ch == '/')
                result = operand1 / operand2;
            st.push(result);
        }
    }
    int final_result = st.top();
    st.pop();
    return final_result;
}

int main()
{
    cout << "=== Postfix Expression Evaluation ===" << endl
         << endl;

    string expr1 = "23+";       // 2 + 3 = 5
    string expr2 = "23*";       // 2 * 3 = 6
    string expr3 = "234*+";     // 2 + (3 * 4) = 14
    string expr4 = "53+82-*";   // (5 + 3) * (8 - 2) = 48
    string expr5 = "62/3-42*+"; // (6 / 2) - 3 + (4 * 2) = 8
    string expr6 = "23+45+*";   // (2 + 3) * (4 + 5) = 45

    cout << "Expression: \"" << expr1 << "\" = " << postfixEvaluation(expr1) << endl;
    cout << "Expression: \"" << expr2 << "\" = " << postfixEvaluation(expr2) << endl;
    cout << "Expression: \"" << expr3 << "\" = " << postfixEvaluation(expr3) << endl;
    cout << "Expression: \"" << expr4 << "\" = " << postfixEvaluation(expr4) << endl;
    cout << "Expression: \"" << expr5 << "\" = " << postfixEvaluation(expr5) << endl;
    cout << "Expression: \"" << expr6 << "\" = " << postfixEvaluation(expr6) << endl;

    cout << "\nDone!" << endl;

    return 0;
}
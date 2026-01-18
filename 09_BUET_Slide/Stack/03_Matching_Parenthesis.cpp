#include <iostream>
#include <stack>
using namespace std;

bool isValid(string s)
{
    stack<char> st;
    for (int i = 0; i < s.length(); i++)
    {
        char ch = s[i];

        if (ch == '(' || ch == '{' || ch == '[')
            st.push(ch);

        else if (ch == ')' || ch == '}' || ch == ']')
        {
            if (st.empty())
                return false;
            char peek = st.top();
            st.pop();
            if ((ch == ')' && peek != '(') ||
                (ch == '}' && peek != '{') ||
                (ch == ']' && peek != '['))
                return false;
        }
    }
    return st.empty();
}

int main() {
    cout << "=== Parenthesis Matching Demo ===" << endl << endl;
    
    string test1 = "()";
    string test2 = "()[]{}";
    string test3 = "(]";
    string test4 = "([)]";
    string test5 = "{[()]}";
    string test6 = "((())";
    string test7 = "())";
    string test8 = "";
    string test9 = "{[}]";
    string test10 = "a(b[c{d}e]f)g";
    
    cout << "Test 1: \"" << test1 << "\" -> " 
         << (isValid(test1) ? "Valid" : "Invalid") << endl;
    
    cout << "Test 2: \"" << test2 << "\" -> " 
         << (isValid(test2) ? "Valid" : "Invalid") << endl;
    
    cout << "Test 3: \"" << test3 << "\" -> " 
         << (isValid(test3) ? "Valid" : "Invalid") << endl;
    
    cout << "Test 4: \"" << test4 << "\" -> " 
         << (isValid(test4) ? "Valid" : "Invalid") << endl;
    
    cout << "Test 5: \"" << test5 << "\" -> " 
         << (isValid(test5) ? "Valid" : "Invalid") << endl;
    
    cout << "Test 6: \"" << test6 << "\" -> " 
         << (isValid(test6) ? "Valid" : "Invalid") << endl;
    
    cout << "Test 7: \"" << test7 << "\" -> " 
         << (isValid(test7) ? "Valid" : "Invalid") << endl;
    
    cout << "Test 8: \"" << test8 << "\" -> " 
         << (isValid(test8) ? "Valid" : "Invalid") << endl;
    
    cout << "Test 9: \"" << test9 << "\" -> " 
         << (isValid(test9) ? "Valid" : "Invalid") << endl;
    
    cout << "Test 10: \"" << test10 << "\" -> " 
         << (isValid(test10) ? "Valid" : "Invalid") << endl;
    
    cout << "\nDone!" << endl;
    
    return 0;
}
#include <string>

class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        int n = tokens.size();
        stack<string> st;
        for(int i = 0; i < n; i++) {
            string ch = tokens[i];
            
            if(ch == "+" || ch == "-" || ch == "*" || ch == "/") {
                string sop1 = st.top();
                int op2 = stoi(sop1);
                st.pop();
                int op1 = stoi(st.top());
                st.pop();

                string opr = tokens[i];
                int ans = 0;
                if(opr == "+") {
                    ans = op1 + op2;
                }
                else if(opr == "-") {
                    ans = op1 - op2;
                }
                else if(opr == "*") {
                    ans = op1 * op2;
                }
                else{
                    ans = op1 / op2;
                }

                st.push(to_string(ans));
            }
            else {
                st.push(ch);
            }
        }

        return stoi(st.top());
    }
};
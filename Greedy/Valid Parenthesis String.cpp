class Solution {
public:
    bool checkValidString(string s) {
        // stack<int> open;
        // stack<int> ast;

        // for(int i = 0; i < s.length(); i++) {
        //     char ch = s[i];
        //     if(ch == '(') open.push(i);
        //     else if(ch == '*') ast.push(i);
        //     else {
        //         if(!open.empty()) open.pop();
        //         else if(!ast.empty()) ast.pop();
        //         else return false;
        //     }
        // }

        // while(!open.empty()) {
        //     if(!ast.empty() && open.top() < ast.top()) {
        //         open.pop();
        //         ast.pop();
        //     }
        //     else {
        //         return false;
        //     }
        // }

        // return true;

        int leftMin = 0, leftMax = 0;

        for(const auto& ch: s) {
            if(ch == '(') {
                leftMin++;
                leftMax++;
            }
            else if(ch == '*') {
                leftMin--;
                leftMax++;
            }
            else{
                leftMin--;
                leftMax--;
            }

            if(leftMin < 0) leftMin = 0;
            if(leftMax < 0) return false;
        }

        return leftMin == 0;
    }
};
class Solution {
    unordered_map<char, vector<char>> mp = {
        {'2', {'a', 'b', 'c'}},
        {'3', {'d', 'e', 'f'}},
        {'4', {'g', 'h', 'i'}},
        {'5', {'j', 'k', 'l'}},
        {'6', {'m', 'n', 'o'}},
        {'7', {'p', 'q', 'r', 's'}},
        {'8', {'t', 'u', 'v'}},
        {'9', {'w', 'x', 'y', 'z'}},
    };

    vector<string> ans;
public:
    vector<string> letterCombinations(string digits) {
        string temp = "";
        solve(0, temp, digits);
        return ans;
    }

private:
    void solve(int i, string& temp, string& digits) {
        if(i == digits.length()) {
            ans.push_back(temp);
            return;
        }

        for(auto ch: mp[digits[i]]) {
            temp += ch;
            solve(i + 1, temp, digits);
            temp.pop_back();
        }
    }
};
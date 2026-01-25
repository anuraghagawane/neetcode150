class Solution {
    vector<vector<string>> ans;
public:
    vector<vector<string>> partition(string s) {
        vector<string> temp;
        solve(0, s.length(), temp, s);
        return ans;
    }

private:
    void solve(int i, int n, vector<string>& temp, string& s) {
        if(i == n) {
            ans.push_back(temp);
        }
        
        for(int j = i; j < n; j++) {
            string sbs = s.substr(i, j - i + 1);
            if(isPalindrome(sbs)) {
                temp.push_back(sbs);
                solve(j + 1, n, temp, s);
                temp.pop_back();
            }
        }
    }

    bool isPalindrome(string& s) {
        int i = 0;
        int j = s.length() - 1;

        while(i <= j) {
            if(s[i] != s[j]) return false;
            i++;
            j--;
        }

        return true;
    }
};
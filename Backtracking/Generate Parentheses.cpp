class Solution {
    vector<string> ans;
public:
    vector<string> generateParenthesis(int n) {
        string s = "(";
        solve(s, n - 1, n, n);
        return ans;
    }

private:
    void solve(string& s, int ro, int rc, int n) {
        if(ro == 0 && rc == 0) {
            ans.push_back(s);
            return;
        }

        int po = n - ro;
        int pc = n - rc;

        if(po > pc && rc > 0) {
            s += ')';
            solve(s, ro, rc - 1, n);
            s.pop_back();
        }
        if(ro > 0) {
            s += '(';
            solve(s, ro - 1, rc, n);
            s.pop_back();
        }
    }
};
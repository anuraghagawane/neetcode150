class Solution {
public:
    int countSubstrings(string s) {
        int ans = 0;

        for(int i = 0; i < s.length(); i++) {
            longestPalindrome(i, i, s, ans);
            longestPalindrome(i, i + 1, s, ans);
        }

        return ans;
    }

private:
    void longestPalindrome(int left, int right, string& s, int& ans) {
        int n = s.length();

        while(left >= 0 && right < n) {
            if(s[left] != s[right]) {
                break;
            }
            left--;
            right++;
            ans++;
        }
    }
};
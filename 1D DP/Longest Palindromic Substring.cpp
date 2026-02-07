class Solution {
public:
    string longestPalindrome(string s) {
        string ans = "";

        for(int i = 0; i < s.length(); i++) {
            string currAns = longestPalindrome(i - 1, i + 1, s);
            if(currAns.length() > ans.length()) ans = currAns;
            currAns = longestPalindrome(i, i + 1, s);
            if(currAns.length() > ans.length()) ans = currAns;
        }

        return ans;
    }

private:
    string longestPalindrome(int left, int right, string& s) {
        int n = s.length();

        while(left >= 0 && right < n) {
            if(s[left] != s[right]) {
                break;
            }
            left--;
            right++;
        }
        left++;
        right--;

        return s.substr(left, right - left + 1);
    }
};
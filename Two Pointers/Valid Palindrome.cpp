class Solution {
public:
    bool isPalindrome(string s) {
        // string st;
        // for(auto ch: s) {
        //     if(ch - 'A' >= 0 && ch - 'A' < 26) {
        //         st += char('a' + ch - 'A');
        //     }
        //     else if(ch - 'a' >= 0 && ch - 'a' < 26) {
        //         st += ch;
        //     }
        //     else if(ch - '0' >= 0 && ch - '0' < 10) {
        //         st += ch;
        //     }
        // }

        int i = 0;
        int j = s.length() - 1;
        while(i < j) {
            while(i < j && !isValidAlphaNumeric(s[i])) i++;
            while(j > i && !isValidAlphaNumeric(s[j])) j--;
            if(i >= j) break;
            if(getValidAlphaNumeric(s[i]) != getValidAlphaNumeric(s[j])) return false;
            i++;
            j--;
        }

        return true;
    }

    bool isValidAlphaNumeric(char ch) {
        if(ch - 'A' >= 0 && ch - 'A' < 26) {
            return true;
        }
        else if(ch - 'a' >= 0 && ch - 'a' < 26) {
            return true;
        }
        else if(ch - '0' >= 0 && ch - '0' < 10) {
            return true;
        }

        return false;
    }

    char getValidAlphaNumeric(char ch) {
        if(ch - 'A' >= 0 && ch - 'A' < 26) {
            return char('a' + ch - 'A');
        }
        else if(ch - 'a' >= 0 && ch - 'a' < 26) {
            return ch;
        }
        else if(ch - '0' >= 0 && ch - '0' < 10) {
            return ch;
        }

        return ' ';
    }
};
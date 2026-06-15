//brute

class Solution {
public:
    bool isPalindrome(string s) {
        string s2 = "";
        transform(s.begin(), s.end(), s.begin(), ::tolower);
        for ( int i = 0; i < s.length(); i++ ) {
            if ((s[i] >= 'a' && s[i] <= 'z') ||
                (s[i] >= 'A' && s[i] <= 'Z') ||
                (s[i] >= '0' && s[i] <= '9'))
            {
                s2 += tolower(s[i]);
            }
        }
        string s3 = s2;
        reverse(s2.begin(), s2.end());
        cout << s2 << endl;
        cout << s3 << endl;
        if (s3 == s2) return true;
        
        else return false;
    }
};

// optimal

class Solution {
public:

    bool isAlphaNum ( char ch ) {
        if ( ch >= '0' && ch <= '9' || tolower(ch) >= 'a' && tolower(ch) <= 'z' ) {
            return true;
        }
        return false;
    }

    bool isPalindrome(string s) {
        int ptr1 = 0;
        int ptr2 = s.length()-1;
        while ( ptr2 > ptr1 ) {
            if( !isAlphaNum(s[ptr1]) ) {
                ptr1++;
                continue;
            }
            if( !isAlphaNum(s[ptr2]) ) {
                ptr2--;
                continue;
            }
            if ( tolower(s[ptr1]) != tolower(s[ptr2]) ) {
                return false;
            }
            ptr1++;
            ptr2--;
        }
        return true;
    }
};

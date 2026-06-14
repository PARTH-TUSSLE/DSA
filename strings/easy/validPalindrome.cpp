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

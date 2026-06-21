//brute

class Solution {
public:
    string reverseVowels(string s) {
        vector<char>v;
        for (char ch: s) {
            if ( ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u' || ch == 'A' || ch == 'E' || ch == 'I' || ch == 'O' || ch == 'U') {
                v.push_back(ch);
            }
        }
        reverse(v.begin(), v.end());
        int vptr = 0;
        for (int i = 0; i < s.length(); i++) {
            if ( s[i] == 'a' || s[i] == 'e' || s[i] == 'i' || s[i] == 'o' || s[i] == 'u' || s[i] == 'A' || s[i] == 'E' || s[i] == 'I' || s[i] == 'O' || s[i] == 'U') {
                s[i] = v[vptr];
                vptr++;
            }
        }
        return s;
    }
};

// optimal -> 2ptr

class Solution {
public:

    bool isVowel( char ch ) {
        if ( ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u' || ch == 'A' || ch == 'E' || ch == 'I' || ch == 'O' || ch == 'U' ) {
            return true;
        }
        return false;
    }

    string reverseVowels(string s) {
        int ptr1 = 0;
        int ptr2 = s.length()-1;
        while ( ptr1 < ptr2 ) {
            if ( !isVowel(s[ptr1]) ) {
                ptr1++;
            } else if ( !isVowel(s[ptr2]) ) {
                ptr2--;
            } else {
                swap(s[ptr1], s[ptr2]);
                ptr1++;
                ptr2--;
            }
        }
        return s;
    }
};

//brute-1

class Solution {
public:
    string reverseWords(string s) {
        string ansString = "";
        vector<string> words;
        string word;

        stringstream ss(s);

        while (ss >> word) {
            words.push_back(word);
        }
        for ( int i = words.size()-1; i >= 0; i-- ) {
            if (i != 0) {
                ansString = ansString + words[i] + " ";
            } else {
                ansString = ansString + words[i];
            }
        }
        return ansString;
    }
};

// brute-2

class Solution {
public:
    string reverseWords(string s) {
        string ans = "";
        stringstream ss(s);
        string token;

        while (ss >> token) {
            ans = token + " " + ans;
        }
        
        return ans.substr(0, ans.length()-1);
    }
};

// optimal -> 2 ptr

class Solution {
public:
    string reverseWords(string s) {
        int i = 0;
        int l = 0;
        int r = 0;
        int n = s.length();
        reverse(s.begin(), s.end());
        while ( i < n ) {
            while ( i < n && s[i] != ' ' ) {
                s[r++] = s[i++];
            }
            if ( l < r ) {
                reverse(s.begin()+l, s.begin()+r);
                s[r] = ' ';
                r++;
                l = r;
            }
            i++;
        }
        return s.substr(0, r-1);
    }
};

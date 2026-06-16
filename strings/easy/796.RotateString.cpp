//brute 1
class Solution {
public:
    bool rotateString(string s, string goal) {
        char temp = s[0];
        for ( int i = 0; i < s.length(); i++ ) {
            for ( int i = 0; i < s.length()-1; i++ ) {
                s[i] = s[i+1];
            }
            s[s.length()-1] = temp;
            temp = s[0]; 
            if ( s == goal ) {
                return true;
            }
        }
        return false;
    }
};

//brute 2
class Solution {
public:
    bool rotateString(string s, string goal) {
        if (s.length() != goal.length()) {
            return false;
        }
        for ( int i = 0; i < s.length(); i++ ) {
            rotate(s.begin(), s.begin()+1, s.end());
            if ( s == goal ) {
                return true;
            }
        }
        return false;
    }
};

// optimal
class Solution {
public:
    bool rotateString(string s, string goal) {
        string s2 = s+s;
        if ( s2.find(goal) < s2.length() && s.length() == goal.length() ) {
            return true;
        }
        return false;
    }
};

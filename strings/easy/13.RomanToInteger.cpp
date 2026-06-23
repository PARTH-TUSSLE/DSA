// brute

class Solution {
public:
    int romanToInt(string s) {
        map<char, int>mpp = {
            {'I',1},
            {'V',5},
            {'X',10},
            {'L',50},
            {'C',100},
            {'D',500},
            {'M',1000}
        };
        int ans = 0;
        int i = 0;
        for ( i; i < s.length()-1; i++ ) {
            if ( mpp[(s[i])] >= mpp[(s[i+1])] ) {
                ans += mpp[(s[i])];
            } else {
                ans+=(mpp[(s[i+1])] - mpp[(s[i])]);
                i++;
            }
        }
        if (s[i] != NULL) {
            ans+=mpp[s[i]];
        }
        return ans;
    }
};

// optimal

class Solution {
public:
    int romanToInt(string s) {
        unordered_map<char, int> mpp = {
            {'I',1}, {'V',5}, {'X',10},
            {'L',50}, {'C',100},
            {'D',500}, {'M',1000}
        };

        int ans = 0;

        for (int i = 0; i < s.length(); i++) {
            if (i + 1 < s.length() && mpp[s[i]] < mpp[s[i + 1]])
                ans -= mpp[s[i]];
            else
                ans += mpp[s[i]];
        }

        return ans;
    }
};

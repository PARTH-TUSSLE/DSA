class Solution {
public:
    bool isIsomorphic(string s, string t) {
        unordered_map<char, char>mpp1;
        unordered_map<char, char>mpp2;

        for ( int i = 0; i < s.length(); i++ ) {
            char ch1 = s[i];
            char ch2 = t[i];
            if ( mpp1.find(ch1) != mpp1.end() && mpp1[ch1] != ch2 ||
                 mpp2.find(ch2) != mpp1.end() && mpp2[ch2] != ch1
            ) {
                return false;
            }
            mpp1[ch1] = ch2;
            mpp2[ch2] = ch1;
        }
        return true;
    }
};

// brute-1

class Solution {
public:
    bool isAnagram(string s, string t) {
        if ( s.length() != t.length() ) {
            return false;
        }
        map<char, int>mpp;
        map<char, int>mpp2;
        for ( int i = 0; i < s.length(); i++ ) {
            mpp[s[i]]++;
        }
        for ( int i = 0; i < t.length(); i++ ) {
            mpp2[t[i]]++;
        }
        for ( auto it: mpp ) {
            if ( mpp[it.first] != mpp2[it.first] ) {
                return false;
            }
        }
        return true;
    }
};

//brute -2

class Solution {
public:
    bool isAnagram(string s, string t) {
        sort(s.begin(), s.end());
        sort(t.begin(), t.end());
        return s==t;
    }
};

//optimal 

class Solution {
public:
    bool isAnagram(string s, string t) {
        vector<int> v(26,0);
        for ( char &ch: s ) {
            v[ch - 'a']++;
        }
        for ( char &ch: t ) {
            v[ch - 'a']--;
        }
        bool all_zeros = all_of(v.begin(), v.end(), [](int element){
            return element == 0;
        });
        return all_zeros;
    }
};

//brute
class Solution {
public:
    string removeOccurrences(string s, string part) {
        int ptr1 = 0;
        while ( ptr1 + part.length() <= s.length() ) {
            string check = s.substr(ptr1, part.length());
            if ( check == part ) {
                s.erase(ptr1, part.length());
                ptr1 = 0;
            } else {
                ptr1++;
            }
        }
        return s;
    }
};

//optimal

class Solution {
public:
    string removeOccurrences(string s, string part) {
        while (s.find(part) < s.length()) {
            s.erase(s.find(part), part.length());
        }
        return s;
    }
};

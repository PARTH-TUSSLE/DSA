class Solution {
public:
    void reverseString(vector<char>& s) {
        int len = s.size();
        char temp;
        int ptr1 = 0;
        int ptr2 = len-1;
        while (ptr2 > ptr1) {
            temp = s[ptr1];
            s[ptr1] = s[ptr2];
            s[ptr2] = temp;
            ptr1++;
            ptr2--;
        }
    }
};

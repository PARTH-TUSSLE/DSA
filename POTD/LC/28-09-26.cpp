// 1614. Maximum Nesting Depth of the Parentheses

class Solution {
public:
    int maxDepth(string s) {
        stack<char>st;
        int max = 0;
        int currMax = 0;
        for ( char ch : s ) {
            if ( ch == '(' ) {
                st.push('(');
                currMax++;
                if ( currMax > max ) {
                    max = currMax;
                } 
            } else if ( ch == ')' ) {
                st.pop();
                currMax--;
                if ( currMax > max ) {
                    max = currMax;
                } 
            }
        }
        return max;
    }
};

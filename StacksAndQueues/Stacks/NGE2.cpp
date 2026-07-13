// brute

class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        int n = nums.size();
        vector<int> v(n, -1);
        for ( int i = 0; i <= n-1; i++ ) {
            for ( int j = i+1; j <= i+n-1; j++ ) {
                int idx = j%n;
                if ( nums[idx] > nums[i] ) {
                    v[i] = nums[idx];
                    break;
                }
            }
        }
        return v;
    }
};

// optimal -> MS

class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        stack<int>st;
        int n = nums.size();
        vector<int> v(n);
        for ( int i = (2*n)-1; i >= 0; i-- ) {
            while ( !st.empty() && st.top() <= nums[i%n] ) {
                st.pop();
            }
            if ( i < n ) {
                if ( st.empty() ) {
                    v[i] = -1;
                } else {
                v[i] = st.top();
                }
            }
            st.push(nums[i%n]);
        }
        return v;
    }
};

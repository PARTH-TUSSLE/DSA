class Solution {
  public:
    vector<int> nextSmallerEle(vector<int>& arr) {
        int n = arr.size();
        vector<int> v(n, -1);
        stack<int>st;
        for ( int i = n-1; i >= 0; i-- ) {
            while( !st.empty() && st.top() >= arr[i] ) {
                st.pop();
            }
            if ( !st.empty() && arr[i] > st.top() ) {
                v[i] = st.top();
            }
            st.push(arr[i]);
        }
        return v;
    }
};

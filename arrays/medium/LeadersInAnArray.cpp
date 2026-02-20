// brute
class Solution {
  public:
    vector<int> leaders(vector<int>& arr) {
        int n = arr.size();
        vector<int>ans;
        for ( int i = 0; i <  n-1; i++) {
            int isLeader = true;
            for ( int j = i+1; j < n; j++ ) {
                if ( arr[i] < arr[j] ) {
                    isLeader = false;
                    break;
                }
            }
            if ( isLeader == true ) {
                ans.push_back(arr[i]);
            }
        }
        ans.push_back(arr[n-1]);
        return ans;
    }
};

// optimal
class Solution {
  public:
    vector<int> leaders(vector<int>& arr) {
        vector<int>ans;
        int max = INT_MIN;
        for ( int i = arr.size()-1; i >= 0; i-- ) {
            if ( arr[i] >= max ) {
                ans.push_back(arr[i]);
                max = arr[i];
            }
        }
        reverse(ans.begin(), ans.end());  
        return ans;
    }
};

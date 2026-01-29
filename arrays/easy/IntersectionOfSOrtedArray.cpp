//ans can contain duplicates
// brute
vector<int> intersection(vector<int> &arr1, vector<int> &arr2) {
        int n1 = arr1.size();
        int n2 = arr2.size();
        vector<int> visited(n2, 0);
        vector<int>ans;
        
        for ( int i = 0; i < n1; i++ ) {
            for ( int j = 0; j < n2; j++ ) {
                if ( arr1[i] == arr2[j] && visited[j] == 0 ) {
                    ans.push_back(arr1[i]);
                    visited[j] = 1;
                    break;
                }
                if ( arr2[j] > arr1[i] ) break;
            }
        }
                return ans;
    }

//optimised - two-pointer

class Solution {
  public:
    vector<int> intersection(vector<int> &arr1, vector<int> &arr2) {
        int n1 = arr1.size();
        int n2 = arr2.size();
        int i = 0;
        int j = 0;
        vector<int>ans;
        while ( i < n1 &% j < n2 ) {
            if ( arr1[i] < arr2[j] ){
                i++;
            } else if ( arr2[j] < arr1[i] ) {
                j++;
            } else {
                ans.push_back(arr[i])
            }
        }
        return ans;
    }
};

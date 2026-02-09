// floor
class Solution {
  public:
    int findFloor(vector<int>& arr, int x) {
        int low = 0;
        int high = arr.size() - 1;
        int ans = -1;
        while ( low <= high ) {
            int mid = low+( high-low/2 );
            if ( arr[mid] <= x ) {
                ans = mid;
                low = mid+1;
            } else {
                high = mid-1;
            }
        }
        return ans;
    }
};


// ceil -> lower-bound only just ( ans = -1 ) initially
// User function Template for C++
class Solution {
  public:
    int findCeil(vector<int>& arr, int x) {
        int low = 0;
        int high = arr.size() -1 ;
        int ans = -1;
        while ( low <= high ) {
            int mid = (low+high)/2;
            if ( arr[mid] >= x ) {
                ans = mid;
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }
        return ans;
    }
};

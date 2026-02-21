// brute

class Solution {
  public:
    int floorSqrt(int n) {
        int ans = 0;
        for ( int i = 0; i <= n; i++ ) {
            if ( i * i <= n ) {
                ans = i;
                continue;
            } 
            else {
                break;
            }
        }
        return ans;
    }
};

// optimal - Binary Search

class Solution {
  public:
    int floorSqrt(int n) {
        int low = 1;
        int high = n;
        int ans = 0;
        while ( low <= high ) {
            int mid = (low+high)/2;
            if ( mid*mid > n ) {
                high = mid-1;
            } else {
                ans = mid;
                low = mid+1;
            }
        }
        return ans;
    }
};
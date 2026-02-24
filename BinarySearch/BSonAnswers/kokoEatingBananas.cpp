// brute - iterate on every possible value of k
class Solution {
public:
    int totalHours ( vector<int>& piles, int k ) {
        int totalHrs = 0;
        for ( int i = 0; i < piles.size(); i++ ) {
            totalHrs += ceil((double)piles[i]/(double)k); 
        }
        return totalHrs;
    }
    int minEatingSpeed(vector<int>& piles, int h) {
        int ans = 1;
        int maxEl = *max_element(piles.begin(), piles.end());
        for ( int k = 1; k <= maxEl; k++ ) {
            if ( totalHours(piles, k) <= h ) {
                ans = k;
                break;
            }
        }
        return ans;
    }
};

// optimal - binary search
class Solution {
public:

    long long totalHours(vector<int>& piles, int k) {
        long long totalHrs = 0;

        for(int i = 0; i < piles.size(); i++) {
            totalHrs += (piles[i] + k - 1) / k; // integer ceil
        }
        return totalHrs;
    }

    int minEatingSpeed(vector<int>& piles, int h) {
        int low = 1;
        int high = *max_element(piles.begin(), piles.end());
        int ans = INT_MAX;
        while ( low <= high ) {
            int mid = low + (high - low)/2;
            if ( totalHours(piles, mid) <= h ) {
                ans = mid;
                high = mid-1;
            } else {
                low = mid+1;
            }
        }
        return ans;
    }
};

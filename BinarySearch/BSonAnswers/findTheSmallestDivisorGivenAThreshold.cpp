// brute
class Solution {
public:

    int totalSum ( vector<int>& nums, int divisor ) {
        int sum = 0;
        for ( int i = 0; i < nums.size(); i++ ) {
            sum += (nums[i] + divisor - 1) / divisor;
        }
        return sum;
    }

    int smallestDivisor(vector<int>& nums, int threshold) {
        int mini = 1;
        int maxi = *max_element(nums.begin(), nums.end());
        for ( int i = mini; i <= maxi; i++ ) {
            if ( totalSum(nums, i) <= threshold ) {
                return i;
            }
        }
        return -1;
    }
};

// optimal - binary search
class Solution {
public:

    int totalSum ( vector<int>& nums, int divisor ) {
        int sum = 0;
        for ( int i = 0; i < nums.size(); i++ ) {
            sum += (nums[i] + divisor - 1) / divisor;
        }
        return sum;
    }

    int smallestDivisor(vector<int>& nums, int threshold) {
        int low = 1;
        int high = *max_element(nums.begin(), nums.end());
        int ans = 0;
        while ( low <= high ) {
            int mid = low + (high - low)/2;
            if ( totalSum(nums, mid) <= threshold ) {
                ans = mid;
                high = mid-1;
            }
            else {
                low = mid+1;
            }
        }
        return ans;
    }
};

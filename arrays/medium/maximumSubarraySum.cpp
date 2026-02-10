// brute -> generate the sum for all subarrays

class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int maxSum = INT_MIN;
        for( int i = 0; i < nums.size(); i++ ) {
            int sum = 0;
            for ( int j = i; j < nums.size(); j++ ) {
                sum += nums[j];
                maxSum = max(maxSum, sum);
            }
        }
        return maxSum;
    }
};

// optimal -> Kadane's algorithm (2 pointer)
// follow-up question can be to actually return the subarray with that maximum sum

class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int maxSum = INT_MIN;
        int sum = 0;
        int i = 0;
        int j = 0;
        if ( nums.size() == 1 ) return nums[0];
        while ( j < nums.size() && i < nums.size() ) {
            sum+=nums[j];
            maxSum = max(maxSum, sum);
            if( sum < 0 ) {
                sum = 0;
                i++;
            }
            j++;
        }
        return maxSum;
    }
};

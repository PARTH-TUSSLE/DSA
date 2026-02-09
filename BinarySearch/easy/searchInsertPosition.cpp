// technically lower bound only
class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int n = nums.size();
        int low = 0;
        int high = n -1;
        int ans = n;
        while ( low <= high ) {
            int mid = low + (high - low)/2;
            if ( nums[mid] == target ) {
                return mid;
            } else if ( nums[mid] >= target ) {
                high = mid - 1;
                ans = mid;
            } else {
                low = mid + 1;
            }
        }
        return ans;
    }
};

// mazak
class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        return lower_bound(nums.begin(), nums.end(), target) - nums.begin(); //-> - nums.begin() returns the index and not the iterator.
    }
};

// brute 

class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int idx1 = -1;
        int idx2 = -1;
        for ( int i = 0; i < nums.size(); i++ ) {
            if ( nums[i] == target ) {
                idx1 = i;
                break;
            }
        }
        for ( int i = nums.size()-1; i >= 0; i-- ) {
            if ( nums[i] == target ) {
                idx2 = i;
                break;
            }
        }
        return {idx1, idx2};
    }
};

// optimal - binary search (self)
class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int idx1 = -1;
        int idx2 = -1;
        int high = nums.size()-1;
        int low = 0;
        while ( low <= high ) {
            int mid = (low+high)/2;
            if ( nums[mid] == target ) {
                idx1 = mid;
                high = mid-1;
            } else if ( nums[mid] > target ) {
                high = mid-1;
            } else {
                low = mid+1;
            }
        }
        high = nums.size()-1;
        low = 0;
        while ( low <= high ) {
            int mid = (low+high)/2;
            if ( nums[mid] == target ) {
                idx2 = mid;
                low = mid+1;
            } else if ( nums[mid] > target ) {
                high = mid-1;
            } else {
                low = mid+1;
            }
        }
        return {idx1, idx2};
    }
};

// optimal - striver

class Solution {
public:
    int lowerBound(vector<int>& nums, int target) {
        int low = 0;
        int high = nums.size() -1 ;
        int ans = nums.size();
        while ( low <= high ) {
            int mid = (low+high)/2;
            if ( nums[mid] >= target ) {
                ans = mid;
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }
        return ans;
    }

    int upperBound(vector<int>& nums, int target) {
        int low = 0;
        int high = nums.size() -1 ;
        int ans = nums.size();
        while ( low <= high ) {
            int mid = (low+high)/2;
            if ( nums[mid] > target ) {
                ans = mid;
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }
        return ans;
    }

    vector<int> searchRange(vector<int>& nums, int target) {
        int lb = lowerBound(nums, target);
        int ub = upperBound(nums, target);
        if( lb == nums.size()  || nums[lb] != target ) {
            return {-1, -1};
        }
        return {lb, ub-1};
    }
};

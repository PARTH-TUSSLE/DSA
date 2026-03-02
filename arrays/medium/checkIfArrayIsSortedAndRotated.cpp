// brute -> on the basis of rotation, create another array and check if sorted or not
class Solution {
public:
    bool check(vector<int>& nums) {
        int n = nums.size();
        vector<int>sorted(n);
        for ( int r = 0; r < n; r++) {
            int idx = 0;
            for ( int i = r; i < n; i++ ) {
                sorted[idx] = nums[i];
                idx++;
            }
            for ( int i = 0; i < r; i++ ) {
                sorted[idx] = nums[i];
                idx++;
            }
            bool isSorted = true; 
            for ( int i = 0; i < n-1; i++ ) {
                if ( sorted[i] > sorted[i+1] ) {
                    isSorted = false;
                    break;
                }
            }
            if ( isSorted ) {
            return true;
        } 
        }
        return false;
    }
};

// better
class Solution {
public:
    bool check(vector<int>& nums) {
        vector<int>original = nums;
        int n = nums.size();
        sort(nums.begin(), nums.end());
        for ( int r = 0; r <= n; r++ ) {
            bool isSorted = true;
            for ( int i = 0; i < n; i++ ) {
                if ( original[i] != nums[(i+r) % n] ) {
                    isSorted = false;
                    break;
                }
            }
            if ( isSorted ) {
                return true;
            }
        }
        return false;
    }
};

// optimal

class Solution {
public:
    bool check(vector<int>& nums) {
        int peak = 0;
        int n = nums.size();
        for ( int i = 0; i < n; i++ ) {
            if ( nums[i] > nums[(i+1)%n] ) {
                peak++;
            }
        }
        return peak <= 1;
    }
};

// Brute
class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int n = nums.size();
        vector<int>arr;
        for ( int i = 0; i < n; i++ ) {
            if ( nums[i] != 0 ) {
                arr.push_back(nums[i]);
            }
        }
        int n2 = arr.size();
        for ( int i = n2; i < n; i++ ){
            arr.push_back(0);
        }
        for ( int i = 0; i < n; i++ ) {
            nums[i] = arr[i];
        }
    }
};

// Optimized - 2 pointer
class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int j = -1;
        for ( int i = 0; i < nums.size(); i++ ) {
            if ( nums[i] == 0 ) {
                j = i;
                break;
            }
        }
        if ( j == -1) return ;
        for ( int i = j+1; i < nums.size(); i++ ) {
            if ( nums[i] != 0 ) {
                swap(nums[i], nums[j]);
                j++;
            }
        }
    }
};

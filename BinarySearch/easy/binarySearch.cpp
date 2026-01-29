// iterative
class Solution {
public:
    int search(vector<int>& nums, int target) {
        int n = nums.size();
        int low = 0;
        int high = n-1;
        while(high >= low){
           int mid = (low+high)/2;
            if( nums[mid] == target ) {
                return mid;
            } else if ( nums[mid] > target ) {
                high = mid-1;
            } else{
                low = mid+1;
            }
        }
        return -1;
    }
};


//recursive

class Solution {
public:

    int helper ( vector<int>& nums, int target, int low, int high ) {

        if ( low > high ) return -1;
        int mid = (low + high)/2;
        if ( nums[mid] == target ) {
            return mid;
        } else if ( nums[mid] > target ) {
            return helper( nums, target, low, mid-1 );

        } else {
            return helper( nums, target, mid+1, high );

        }
    }

    int search(vector<int>& nums, int target) {
        return helper( nums, target, 0, nums.size()-1 );
    }
};
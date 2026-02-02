// brute -> merge sort
// better -> count no of 0s, 1s and 2s

class Solution {
public:
    void sortColors(vector<int>& nums) {
        int zeros = 0;
        int ones = 0;
        int twos = 0;

        for ( int i = 0; i < nums.size(); i++ ) {
            if ( nums[i] == 0 ) {
                zeros +=1;
            } else if ( nums[i] == 1 ) {
                ones +=1;
            } else {
                twos +=1;
            }
        }
        for ( int i = 0; i < zeros; i++ ) {
            nums[i] = 0;
        }
        for ( int i = zeros; i < zeros + ones; i++ ) {
            nums[i] = 1;
        }
        for ( int i = zeros + ones; i < zeros + ones + twos; i++ ) {
            nums[i] = 2;
        }
    }
};

// Dutch-National Flag algorithm
class Solution {
public:
    void sortColors(vector<int>& nums) {
        int low = 0;
        int mid = 0;
        int n = nums.size();
        int high = n - 1;
        while ( mid <= high ) {
            if ( nums[mid] == 0 ) {
                swap(nums[low], nums[mid]);
                low ++;
                mid ++;
            } else if ( nums[mid] == 1 ) {
                mid ++;
            } else {
                swap(nums[mid], nums[high]);
                high --;
            }
        }
    }
};

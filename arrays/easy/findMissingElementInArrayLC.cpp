// optimal 1 - sum
class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int n = nums.size();
        int sum = (n*(n+1))/2;
        int sum2 = 0; 
        for ( int i = 0; i < n; i++ ) {
            sum2+=nums[i];
        }
        return sum - sum2;
    }
};
// optimal 2 - XOR method
class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int xor1 = 0;
        int xor2 = 0;
        int n = nums.size();
        for ( int i = 0; i < n; i++ ) {
            xor2 = xor2 ^ nums[i];
            xor1 = xor1 ^ i;
        }
        xor1 = xor1 ^ n;
        return xor1 ^ xor2;
    }
};

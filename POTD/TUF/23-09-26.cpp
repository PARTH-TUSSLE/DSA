// 716. Check if an Array Is Consecutive

class Solution {
public:
    bool isConsecutive(vector<int>& nums) {
        int x = *min_element(nums.begin(), nums.end());
        int n = nums.size();
        int z = x+n-1;
        unordered_map<int ,int>m;
        for ( int i = 0; i < n; i++ ) {
            m[nums[i]]= nums[i];
        }
        for ( int j = x; j <= z; j++ ) {
            if ( m.find(j) == m.end() ) {
                return false;
            }
        }
        return true;
    }
};

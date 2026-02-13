class Solution {
public:
    vector<int> occurrencesOfElement(vector<int>& nums, vector<int>& queries, int x) {
        map<int, int>mpp;
        int count = 1;
        vector<int>v;
        for ( int i = 0; i < nums.size(); i++ ) {
            if ( nums[i] == x ) {
                mpp[count] = i;
                count++;
            }
        }
        for ( int j = 0; j < queries.size(); j++ ) {
            if ( mpp.find(queries[j]) == mpp.end() ) {
                v.push_back(-1);
            } else {
                v.push_back(mpp[queries[j]]);
            }
        }
        return v;
    }
};

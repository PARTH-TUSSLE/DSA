// hadd brute
class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        map<int, int>mpp;
        vector<int>ans;
        for ( int i = 0; i < nums2.size(); i++ ) {
            for ( int j = i+1; j < nums2.size(); j++ ) {
                if ( nums2[j] > nums2[i] ) {
                    mpp[nums2[i]] = nums2[j];
                    break;
                } else {
                    mpp[nums2[i]] = -1;
                }
            }
        }
        if ( mpp.size() < nums2.size() ) {
            mpp[nums2[nums2.size()-1]] = -1;
        }
        for ( int i = 0; i < nums1.size(); i++ ) {
            ans.push_back(mpp[nums1[i]]);
        }
        return ans;
    }
};

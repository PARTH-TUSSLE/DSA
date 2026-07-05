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

//better
class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        vector<int>nge (nums2.size());
        stack<int>st;
        vector<int>ans;
        for ( int i = nums2.size()-1; i >= 0; i-- ) {
            while ( !st.empty() && st.top() <= nums2[i] ) {
                st.pop();
            }
            if ( st.empty() ) {
                nge[i] = -1;
            } else {
                nge[i] = st.top();
            }
            st.push(nums2[i]);
        }
        for ( int i = 0; i < nums1.size(); i++ ) {
            auto it = find(nums2.begin(), nums2.end(), nums1[i]);
            int idx = it - nums2.begin();
            ans.push_back(nge[idx]);
        }
        return ans;
    }
};

//optimal -> use unordered map to store the NGE

class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        stack<int> st;
        unordered_map<int, int> mp;

        for (int i = nums2.size() - 1; i >= 0; i--) {
            while (!st.empty() && st.top() <= nums2[i]) {
                st.pop();
            }

            if (st.empty())
                mp[nums2[i]] = -1;
            else
                mp[nums2[i]] = st.top();

            st.push(nums2[i]);
        }

        vector<int> ans;
        for (int num : nums1) {
            ans.push_back(mp[num]);
        }

        return ans;
    }
};

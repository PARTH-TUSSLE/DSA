// brute
class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int majEl;
        for ( int i = 0; i < nums.size(); i++ ) {
            int occurrence = 0;
            majEl = nums[i];
            for (  int j = 0; j < nums.size(); j++) {
                if ( nums[j] == majEl ) {
                    occurrence ++;
                }
            }
            if ( occurrence > (nums.size()/2) ) {
                return majEl;
            }

        }
        return majEl;
    }
};

// better - hashMap
class Solution {
public:
    int majorityElement(vector<int>& nums) {
        map<int, int>mpp;
        for ( int i = 0; i < nums.size(); i++ ) {
            mpp[nums[i]]++;
        }
        for ( auto it : mpp ) {
            if ( it.second > (nums.size()/2) ) {
                return it.first;
            }
        }
        return -1;
    }
};

// optimal - Moore's Voting Algorithm
class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int el;
        int cnt1 = 0;
        int cnt2 = 0;
        int n = nums.size();
        for ( int i = 0; i < n; i++ ) {
            if ( cnt1 == 0 ) {
                el = nums[i];
                cnt1 = 1;
            } else if ( nums[i] == el ) {
                cnt1 ++;
            } else {
                cnt1 --;
            }
        }
        for ( int i = 0; i < n; i++ ) {
          if ( nums[i] == el ) {
            cnt2++;
          }
        }
       if ( cnt2 > n/2 ) return el;
       return -1;
    }
};

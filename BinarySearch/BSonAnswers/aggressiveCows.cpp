// brute -> placing cows at consecutive places

class Solution {
public:

    bool isPossible(vector<int> &stalls, int distance, int cows) {
        int cowCnt = 1;              
        int lastCow = stalls[0];

        for (int i = 1; i < stalls.size(); i++) {
            if (stalls[i] - lastCow >= distance) {
                cowCnt++;
                lastCow = stalls[i];
                if (cowCnt == cows)
                    return true;
            }
        }
        return false;
    }

    int aggressiveCows(vector<int> &stalls, int k) {

        sort(stalls.begin(), stalls.end());

        int mini = stalls.front();
        int maxi = stalls.back();
        int ans = 0;   
    
        for (int dist = 1; dist <= maxi - mini; dist++) {
            if (isPossible(stalls, dist, k)) {
                ans = dist;          
            }
            else {
                break; 
            }
        }
        return ans;
    }
};

// optimal - binary search

class Solution {
public:

    bool isPossible(vector<int> &stalls, int distance, int cows) {
        int cowCnt = 1;              
        int lastCow = stalls[0];

        for (int i = 1; i < stalls.size(); i++) {
            if (stalls[i] - lastCow >= distance) {
                cowCnt++;
                lastCow = stalls[i];
                if (cowCnt == cows)
                    return true;
            }
        }
        return false;
    }

    int aggressiveCows(vector<int> &stalls, int k) {
        sort(stalls.begin(), stalls.end());

        int mini = stalls.front();
        int maxi = stalls.back();
        int ans = 0;   
        int low = 1;
        int high = maxi-mini;
        
        while ( low <= high ) {
            int mid = low+ (high-low)/2;
            if ( !isPossible(stalls, mid, k) ) {
                high = mid-1;
            } else {
                ans = mid;
                low = mid+1;
            }
        }
        return ans;
    }
};

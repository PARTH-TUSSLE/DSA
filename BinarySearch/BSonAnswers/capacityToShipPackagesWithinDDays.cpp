// brute

class Solution {
public:

    int daysTaken ( vector<int>& weights, int cap ) {
        int days = 1;
        int totalWeight = 0;
        for ( int i = 0; i < weights.size(); i++ ) {
            if ( totalWeight+weights[i] > cap ) {
                days+=1;
                totalWeight = weights[i];
            }
            else {
                totalWeight+=weights[i];
            }
        }
        return days;
    }

    int shipWithinDays(vector<int>& weights, int days) {
        int maxi = 0;
        int mini = *max_element(weights.begin(), weights.end());
        for ( int i = 0; i < weights.size(); i++ ) {
            maxi+=weights[i];
        }
        for ( int i = mini; i <= maxi; i++ ) {
            if ( daysTaken(weights, i) <= days ) {
                return i;
            }
        }

        return -1;
    }
};

// optimal - binary search

class Solution {
public:

    int daysTaken ( vector<int>& weights, int cap ) {
        int days = 1;
        int totalWeight = 0;
        for ( int i = 0; i < weights.size(); i++ ) {
            if ( totalWeight+weights[i] > cap ) {
                days+=1;
                totalWeight = weights[i];
            }
            else {
                totalWeight+=weights[i];
            }
        }
        return days;
    }

    int shipWithinDays(vector<int>& weights, int days) {
        int low = *max_element(weights.begin(), weights.end());
        int ans = 0;
        int high = 0;
        for ( int i = 0; i < weights.size(); i++ ) {
            high+=weights[i];
        }
        while ( low <= high ) {
            int mid = low+ (high-low)/2;
            if ( daysTaken(weights, mid) <= days ) {
                ans = mid;
                high = mid-1;
            } else {
                low = mid+1;
            }
        }

        return ans;
    }
};

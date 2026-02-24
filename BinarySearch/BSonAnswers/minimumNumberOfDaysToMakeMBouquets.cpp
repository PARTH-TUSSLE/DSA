// brute (TLE)

class Solution {
public:

    bool possibleOrNot ( vector<int>& bloomDay, int day, int m, int k ) {
        int bloomedFlowers = 0;
        int noOfBouquets = 0;
        for ( int i = 0; i < bloomDay.size(); i++ ) {
            if ( bloomDay[i] <=  day) {
                bloomedFlowers++;
            } else {
                noOfBouquets+=(bloomedFlowers/k);
                bloomedFlowers = 0;
            }
        }
        noOfBouquets+=(bloomedFlowers/k);
        if ( noOfBouquets >= m ) {
            return true;
        } else return false;
    }

    int minDays(vector<int>& bloomDay, int m, int k) {
        int mini = *min_element(bloomDay.begin(), bloomDay.end());
        int maxi = *max_element(bloomDay.begin(), bloomDay.end());
        if ( m*k > bloomDay.size() ) {
            return -1;
        }
        for ( int i = mini; i <= maxi; i++ ) {
            if ( possibleOrNot( bloomDay, i, m, k ) ) {
                return i;
            }
        }
        return 01;
    }
};

// optimal -> binary search

class Solution {
public:

    bool possibleOrNot ( vector<int>& bloomDay, int day, int m, int k ) {
        int bloomedFlowers = 0;
        int noOfBouquets = 0;
        for ( int i = 0; i < bloomDay.size(); i++ ) {
            if ( bloomDay[i] <=  day) {
                bloomedFlowers++;
            } else {
                noOfBouquets+=(bloomedFlowers/k);
                bloomedFlowers = 0;
            }
        }
        noOfBouquets+=(bloomedFlowers/k);
        if ( noOfBouquets >= m ) {
            return true;
        } else return false;
    }

    int minDays(vector<int>& bloomDay, int m, int k) {
        int low = *min_element(bloomDay.begin(), bloomDay.end());
        int high = *max_element(bloomDay.begin(), bloomDay.end());
        if ( (long long)m*k > bloomDay.size() ) {
            return -1;
        }
        int ans = 0;
        while ( low <= high ) {
            int mid = low + (high-low)/2;
            if ( possibleOrNot(bloomDay, mid, m, k) ) {
                ans = mid;
                high = mid-1;
            } else {
                low = mid+1;
            }
        }
        return ans;;
    }
};

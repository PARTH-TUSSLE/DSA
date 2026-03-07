//brute

class Solution {
  public:
    double minMaxDist(vector<int> &stations, int K) {
        int n = stations.size();
        vector<int>howMany(n-1, 0);
        if (n <= 1) return 0.0;
        for ( int gasStations = 0; gasStations < K; gasStations++ ) {
            long double maxSection = -1;
            int maxIdx = -1;
            for ( int i = 0; i < n-1; i++ ) {
                long double diff = (stations[i+1] - stations[i]);
                long double sectionLen = diff/(long double)(howMany[i]+1);
                if ( sectionLen > maxSection ) {
                    maxSection = sectionLen;
                    maxIdx = i;
                }
            }
            howMany[maxIdx]++;
        }   
        
        long double maxAns = -1;
        for ( int i = 0; i < n-1; i++ ) {
            long double diff = (stations[i+1] - stations[i]);
            long double sectionLen = diff/(long double)(howMany[i]+1);
            maxAns = max(maxAns, sectionLen);
        }
        return maxAns;
    }
};

// optimal

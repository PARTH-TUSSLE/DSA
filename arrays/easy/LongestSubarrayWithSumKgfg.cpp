// optimal for (+ve, -ve and 0s), better for only (+ve and 0s)

class Solution {
  public:
    int longestSubarray(vector<int>& arr, int k) {
        map<long long, int>preSumMap;
        long long sum = 0;
        int n = arr.size();
        int maxLen = 0;
        for ( int i = 0; i < n; i++ ) {
            sum+=arr[i];
            if ( sum == k ) {
                maxLen = max(maxLen, i + 1);
            }
            long long rem = sum - k;
            if ( preSumMap.find(rem) != preSumMap.end() ) {
                int len = i - preSumMap[rem];
                maxLen = max(maxLen, len);
            }
            if ( preSumMap.find(sum) == preSumMap.end() ) {
                preSumMap[sum] = i;
            }
        }
        return maxLen;
    }
};

// optmal for only (+ve and 0s) -> two pointer + greedy

int left = 0;
int right = 0;

long long sum = arr[0];
int maxLen = 0;
int n = arr.size();

while ( right < n ) {
  while ( left <= right && sum > k ) {
    sum -= arr[left];
    left++;
  }
  if ( sum == k ) {
    maxLen = max(maxLen, right - left + 1);
  }
  right ++;
  if ( right < n ) sum += arr[right];
}
return maxLen;

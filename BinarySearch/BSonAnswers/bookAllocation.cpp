// brute

class Solution {
  public:
  
    int totalStudents (vector<int> &arr, int pages) {
        int studentCnt = 1;
        int totalPages = 0;
        for ( int i = 0; i < arr.size(); i++ ) {
            if ( totalPages+arr[i] <= pages ) {
                totalPages+=arr[i];
            } else {
                studentCnt++;
                totalPages = arr[i];
            }
        }
        return studentCnt;
    }
  
    int findPages(vector<int> &arr, int k) {
        int maxi = *max_element(arr.begin(), arr.end());
        int sum = 0;
        if ( k > arr.size() ) {
            return -1;
        }
        for ( int i = 0; i < arr.size(); i++ ) {
            sum+=arr[i];
        }
        for ( int i = maxi; i <= sum; i++ ) {
            if ( totalStudents(arr, i) <= k ) {
                return i;
            }
        }
        return -1;
    }
};

// optimal -> binary Search
class Solution {
  public:
  
    int totalStudents (vector<int> &arr, int pages) {
        int studentCnt = 1;
        int totalPages = 0;
        for ( int i = 0; i < arr.size(); i++ ) {
            if ( totalPages+arr[i] <= pages ) {
                totalPages+=arr[i];
            } else {
                studentCnt++;
                totalPages = arr[i];
            }
        }
        return studentCnt;
    }
  
    int findPages(vector<int> &arr, int k) {
        int low = *max_element(arr.begin(), arr.end());
        int high = 0;
        if ( k > arr.size() ) {
            return -1;
        }
        for ( int i = 0; i < arr.size(); i++ ) {
            high+=arr[i];
        }
        while ( low <= high ) {
            int mid = low+ (high-low)/2;
            if ( totalStudents(arr, mid) <= k ) {
                high = mid-1;
            } else {
                low = mid+1;
            }
        }
        return low;
    }
};

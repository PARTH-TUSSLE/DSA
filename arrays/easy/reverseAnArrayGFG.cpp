// Iterative (brute)
class Solution {
  public:
    void reverseArray(vector<int> &arr) {
        vector <int> arr2;
        for ( int i = 0; i < arr.size(); i++ ) {
            arr2.push_back(arr[arr.size()-1-i]);
        }
        for ( int i = 0; i < arr.size(); i++ ) {
            arr[i] = arr2[i];
        }
    }
};

// recursive (swapping)
class Solution {
  public:
    void helper (vector<int>&arr, int l, int r) {
        int temp;
        if(l>=r) return;
        temp = arr[l];
        arr[l] = arr[r];
        arr[r] = temp;
        helper(arr, l+1, r-1);
    }
    void reverseArray(vector<int> &arr) {
        int l = 0;
        int r = arr.size() - 1;
        helper(arr, l, r);
    }
};

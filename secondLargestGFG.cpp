class Solution {
  public:
    int getSecondLargest(vector<int> &arr) {
        
        int largest = arr[0];
        int Slargest = INT_MIN;
        
        for ( int i = 0; i < arr.size(); i++ ) {
            if ( arr[i] > largest ) {
                Slargest = largest;
                largest = arr[i];
            } 
            else if ( arr[i] < largest && arr[i] > Slargest ) {
                Slargest = arr[i] ;
            }
        }
        return Slargest;
    }
};

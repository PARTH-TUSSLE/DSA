class Solution {
public:

    long long power(long long base, int n, int m){
        long long result = 1;

        for(int i = 0; i < n; i++){
            result *= base;

            if(result > m) return result; 
        }
        return result;
    }

    int nthRoot(int n, int m) {

        if(m == 0) return 0;
        if(m == 1) return 1;

        long long low = 1, high = m;

        while(low <= high){
            long long mid = (low + high) / 2;
            long long val = power(mid, n, m);

            if(val == m) return mid;

            else if(val > m)
                high = mid - 1;
            else
                low = mid + 1;
        }

        return -1;
    }
};

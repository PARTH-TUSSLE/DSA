// brute - set
class Solution {
  public:
    vector<int> findUnion(vector<int> &a, vector<int> &b) {
        set<int>st;
        vector<int>v;
        for ( int i = 0; i < a.size(); i++ ) {
            st.insert(a[i]);
        }
        for ( int i = 0; i < b.size(); i++ ) {
            st.insert(b[i]);
        }
        for ( auto it : st ) {
            v.push_back(it);
        }
        return v;
    }
};

// optimal - 2 pointer
class Solution {
  public:
    vector<int> findUnion(vector<int> &a, vector<int> &b) {
        int n1 = a.size();
        int n2 = b.size();
        int i = 0;
        int j = 0;
        vector<int>unionArr;
        while ( i < n1 && j < n2 ) {
            if ( a[i] < b[j] ) {
                if ( unionArr.size() == 0 || unionArr.back() != a[i] ) {
                    unionArr.push_back(a[i]);
                }
                i++;
            } else {
                 if ( unionArr.size() == 0 || unionArr.back() != b[j] ) {
                    unionArr.push_back(b[j]);
                }
                j++;
            }
        }
        while ( j < n2 ) {
            if ( unionArr.size() == 0 || unionArr.back() != b[j] ) {
                    unionArr.push_back(b[j]);
                }
            j++;
        }
        while ( i < n1 ) {
            if ( unionArr.size() == 0 || unionArr.back() != a[i] ) {
                    unionArr.push_back(a[i]);
                }
            i++;
        }
        return unionArr;
    }
};

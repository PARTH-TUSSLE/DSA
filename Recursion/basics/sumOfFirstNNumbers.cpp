// parameterized

#include <iostream>
using namespace std;

void helper ( int n, int sum) {
    if ( n == 0 ) {
        cout << sum;
        return;
    }
    helper( n-1, sum+n );
}

int main() {
    
    helper(10, 0);
    return 0;
}

// functional
#include <iostream>
using namespace std;

int helper ( int n) {
    if ( n == 0 ) {
        return 0;
    }
    return n+helper(n-1);
}

int main() {
    
    int ans = helper(100);
    cout << ans << endl;
    return 0;
}

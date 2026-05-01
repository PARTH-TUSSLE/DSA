#include <iostream>
using namespace std;

void helper ( int cnt, int n ) {
    if( cnt > n )return;
    cout << cnt << endl;
    helper(cnt+1, n);
}

int main() {
    helper(1,5);
    return 0;
}

// backtrack

#include <iostream>
using namespace std;

void helper ( int  n ) {
    if ( n == 0 ) return;
    helper(n-1);
    cout << n << endl;
}

int main() {
    
    helper(5);
    return 0;
}

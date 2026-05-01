#include <iostream>
using namespace std;

void helper ( int n ) {
    if( n == 0 )return;
    cout << n << endl;
    helper(n-1);
}

int main() {
    helper(10);
    return 0;
}

//backtrack

#include <iostream>
using namespace std;

void helper ( int cnt, int  n ) {
    if ( cnt > n ) return;
    helper(cnt+1, n);
    cout << cnt << endl;
}

int main() {
    
    helper(1, 5);
    return 0;
}

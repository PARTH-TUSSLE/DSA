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

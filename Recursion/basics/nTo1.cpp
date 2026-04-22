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

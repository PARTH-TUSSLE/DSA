#include <iostream>
using namespace std;

void helper ( int n, string name ) {
    if ( n == 0 ) return;
    cout << name << endl;
    helper(n-1, name);
}

int main() {
    helper(5, "Parth");
    return 0;
}

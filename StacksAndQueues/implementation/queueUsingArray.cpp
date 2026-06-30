#include <iostream>
using namespace std;


class Q {
    int Queue[10];
    int start= -1;
    int end= -1;
    int currSize = 0;
    int size = sizeof(Queue) / sizeof(Queue[0]);
    public:

    void push (int x) {
        if (currSize == size) {
            cout << "Queue is full" << endl;
            return;
        }
        if ( currSize == 0 ) {
            start = 0;
            end = 0;
        } else {
            end = (end+1)%size;
        }
        Queue[end] = x;
        currSize++;
    }

    void pop () {
        if ( currSize == 0 ) {
            cout << "Queue already empty !" << endl;
            return;
        }
        if ( currSize == 1 ) {
            start = -1;
            end = -1;
            currSize --;
            return;
        }
        start = (start+1)%size;
        currSize --;
    }

    void top () {
        if (currSize == 0) {
            cout << "Queue is empty !" << endl;
            return;
        }
        cout << Queue[start] << endl;
    }

    void returnSize() {
        cout << currSize << endl;
    }

};

int main() {
    
    return 0;
}

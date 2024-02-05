#include <iostream>
#include <fstream>
#include <stack>
using namespace std;

ifstream in("nrpits.in");
ofstream out("nrpits.out");

int main() {
    int N, a;
    in >> N;

    int nrpits = 0;

    stack<int> s;
//    in >> a;
//    s.push(a);
//    N--;
    s.push(1000001);

    while(N--){
        in >> a;

        while(s.top() < a){
            s.pop();

            if (s.size() > 1)
                nrpits++;
        }

        s.push(a);
    }

    out << nrpits;

    return 0;
}

// 12 1 10 3 4 11 5 8 7 9 2 6

// s push 12
// 12

// 12 < 1 F => s push 1
// 12 1

// 1 < 10 A => s pop 1; nrpits = 1
// 12 < 10 F => s push 10
// 12 10

// 10 < 3 F => s push 3
// 12 10 3

// 3 < 4 A => s pop 3; nrpits = 2
// 10 < 4 F => s push 4
// 12 10 4

// 4 < 11 A => s pop 4; nrpits = 3
// 10 < 11 A => s pop 10; nrpits = 4
// 12 < 11 F => s push 11
// 12 11

// 11 < 5 F => s push 5
// 12 11 5

// 5 < 8 A => s pop 5; nrpits = 5
// 11 < 8 F => s push 8
// 12 11 8

// 8 < 7 F => s push 7
// 12 11 8 7

// 7 < 9 A => s pop 7; nrpits = 6
// 8 < 9 A => s pop 8; nrpits = 7
// 11 < 9 F => s push 9
// 12 11 9

// 9 < 2 F => s push 2
// 12 11 9 2

// 2 < 6 A => s pop 2; nrpits = 8
// 9 < 6 F => s push 6
// 12 11 9 6
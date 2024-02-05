#include <iostream>
#include <fstream>
#include <queue>

using namespace std;

ifstream in("cifre4.in");
ofstream out("cifre4.out");

int main() {

    int c[] = {2, 3, 5, 7};

    int T;
    in >> T;

    while (T--) {
        int N, P;
        in >> N >> P;

        vector<int> r;
        r.resize(P + 1, 0);

        queue<long long> q;
        q.push(0);

        int gasit = 0;

        while (!q.empty() && gasit == 0){
            long long x, y;
            x = q.front();
            q.pop();

//            cout << x << endl;

            for (int i = 0; i < 4; i++){
                y = x * 10 + c[i];

                if (r[y % P])
                    continue;

                if (y % P == N) {
                    out << y << endl;
                    gasit = 1;
                }

                r[y % P] = 1;
                q.push(y);
            }
        }

       if (gasit == 0)
           out << -1 << endl;
    }

    return 0;
}

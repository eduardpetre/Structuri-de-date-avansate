#include <iostream>
#include <fstream>
#include <vector>
#include <queue>

using namespace std;

ifstream in("cezar.in");
ofstream out("cezar.out");

vector<vector<int>> g;
vector<int> grad, cost, visited;

int main() {
    int N, K;
    in >> N >> K;

    g.resize(N + 1);
    grad.resize(N + 1, 0);
    cost.resize(N + 1, 1);
    visited.resize(N + 1, 0);

    for (int i = 1; i < N; i++) {
        int x, y;
        in >> x >> y;

        g[x].push_back(y);
        g[y].push_back(x);

        grad[x]++;
        grad[y]++;
    }

    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> q;

//    adaugam frunzele in coada
    for (int i = 1; i <= N; i++)
        if (grad[i] == 1)
            q.push({1, i});

    // cautam n-k-1 muchii de cost minim
    int nod, c, costmin = 0;
    for (int i = 1; i < N - K; i++){
        c = q.top().first;
        nod = q.top().second;

//        cout<<nod<<" "<<c<<endl;

        q.pop();

        visited[nod] = 1;
        costmin += c;

//        cout << nod << " ";
        for (auto i: g[nod]){
            if (visited[i])
                continue;

            grad[i]--;
            cost[i] += cost[nod];

            if (grad[i] == 1)
                q.push({cost[i], i});

        }
    }

    out << costmin;

    return 0;
}
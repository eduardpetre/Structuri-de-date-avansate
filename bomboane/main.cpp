#include <iostream>
#include <fstream>
#include <vector>
#include <queue>

using namespace std;

ifstream in("bomboane.in");
ofstream out("bomboane.out");

int main() {
    int n;
    in >> n;

    vector<int> bomboane(n);
    int totalBomboane = 0;
    for (int i = 0; i < n; i++) {
        in >> bomboane[i];
        totalBomboane += bomboane[i];
    }

//    cout << totalBomboane << endl;

    if (totalBomboane % n != 0) {
        out << -1 << endl;
        return 0;
    }

    int medie = totalBomboane / n;

    priority_queue<pair<int, int>> maxHeap;
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> minHeap;

    for (int i = 0; i < n; ++i) {
        if (bomboane[i] > medie) {
            maxHeap.push({bomboane[i], i});
        } else if (bomboane[i] < medie) {
            minHeap.push({bomboane[i], i});
        }
    }

    vector<pair<pair<int, int>, int>> mutari;

    while (!maxHeap.empty() && !minHeap.empty()) {
        int maxBox = maxHeap.top().second;
        int minBox = minHeap.top().second;
//        cout << maxBox+1 << " " << maxHeap.top().first << " - " << minBox+1 << " " << minHeap.top().first << endl;

        int bomboaneMutate = min(medie - bomboane[minBox], bomboane[maxBox] - medie);

        bomboane[minBox] += bomboaneMutate;
        bomboane[maxBox] -= bomboaneMutate;

        mutari.push_back({{maxBox + 1, minBox + 1}, bomboaneMutate});

        maxHeap.pop();
        if (bomboane[maxBox] > medie) {
            maxHeap.push({bomboane[maxBox], maxBox});
        }

        minHeap.pop();
        if (bomboane[minBox] < medie) {
            minHeap.push({bomboane[minBox], minBox});
        }
    }

    out << mutari.size() << endl;
    for (const auto& mutare : mutari) {
        out << mutare.first.first << " " << mutare.first.second << " " << mutare.second << endl;
    }

    return 0;
}

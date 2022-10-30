#include <iostream>
#include <vector>
#include <list>
using namespace std;

const int N = 1e3;
vector<int> a[N];
class graph {
    int v;
    list<int> *l;
public:
    graph(int v) {
        this->v = v;
        l = new list<int>[v];
    }
    void addEdge(int x, int y) {
        l[x].push_back(y);
        l[y].push_back(x);
    }
    void printList() {
        for (int i = 0; i < v; i++) {
            cout << i << " -> ";
            for (int j : l[i]) {
                cout << j << " , ";
            }
            cout << endl;
        }
    }
};
int main()
{

    int v, e;      // v ->vertices, e -> edges
    cin >> v >> e;
    graph g(v);
    for (int i = 0; i < e; i++) {
        int v1, v2;
        cin >> v1 >> v2;
        g.addEdge(v1, v2);
    }
    g.printList();

    return 0;
}

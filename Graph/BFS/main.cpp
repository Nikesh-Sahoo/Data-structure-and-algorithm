#include <iostream>
using namespace std;

const int MAX = 100;

class Graph {
  int n, e;
  int adj[MAX][MAX], status[MAX];
public:
  void getData() {
    cout << "Enter no of vertices: ";
    cin >> n;
    cout << "Enter no of edges: ";
    cin >> e;
    cout << "Edges which are adjacent to each other:\n";
    for (int k = 1; k <= e; k++) {
      int i, j;
      cin >> i >> j;
      adj[i][j] = 1;
      adj[j][i] = 1; // for undirected graph
    }
  }
  void BFS(int v) {
    int queue[MAX];
    int front = 0, rear = -1;
    queue[++rear] = v;
    status[v] = 1;
    cout << "BFS order of visited vertices: ";
    cout << v << " ";
    while (front <= rear) {
      int j = queue[front++];
      for (int i = 1; i <= n; i++) {
        if (adj[j][i] == 1 && status[i] != 1) {
          queue[++rear] = i;
          status[i] = 1;
          cout << i << " ";
        }
      }
    }
    cout << endl;
  }
};

int main() {
  Graph g;
  g.getData();
  int start;
  cout << "Enter initial vertex to traverse from: ";
  cin >> start;
  g.BFS(start);
  return 0;
}

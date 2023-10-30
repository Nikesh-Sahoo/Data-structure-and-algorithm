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
  void DFS(int v) {
    int stack[MAX];
    int top = -1;
    stack[++top] = v;
    status[v] = 1;
    cout << "DFS order of visited vertices: ";
    cout << v << " ";
    int k = 1;
    while (k < n) {
      int j = stack[top];
      int i;
      for (i = 1; i <= n; i++) {
        if (adj[j][i] == 1 && status[i] != 1) {
          stack[++top] = i;
          status[i] = 1;
          cout << i << " ";
          k++;
          break;
        }
      }
      if (i == n + 1) {
        top--;
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
  g.DFS(start);
  return 0;
}

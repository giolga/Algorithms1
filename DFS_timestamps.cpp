#include <iostream>
#include <vector>
using namespace std;

int v, e, a, b, go;
int d[101], f[101];
vector <int> graph[101];
bool visited[101] = {false};
int cnt = 0;

void dfs(int go) {
   visited[go] = true;
   d[go] = ++cnt;
   // cout << go << " ";

   for(int u : graph[go]) {
      if(d[u] == 0) {
         dfs(u);
      }
   }

   f[go] = ++cnt;
}

int main() {
   cin >> v >> e;
   for(int i = 0; i < e; i++) {
      cin >> a >> b;
      graph[a].push_back(b);
      graph[b].push_back(a);
   }

   cin >> go;

   dfs(go);
   cout << endl;

   // for (int v = 1; v <= e; v++) {
   //    cout << "Adjacent vertices of vertex " << v << ": ";
   //    for (int u : graph[v]) {
   //          cout << u << " ";
   //    }
   //    cout << endl;
   // }

   for(int i = 1; i <= v; i++) {
      cout << d[i] << " " << f[i] << endl;
   }
}
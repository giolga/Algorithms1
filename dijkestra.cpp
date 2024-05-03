#include <bits/stdc++.h>
using namespace std;

vector <pair <int, int> > graph[10000];
priority_queue <pair <int, int>, vector <pair <int, int> >, greater <pair <int, int> > > q;

int dist[10000], parent[10000];
int v,u,w,n,e;

void path(int n) {
   if(n != 1) path(parent[n]);
    cout << n << " ";

    // cout << n << " ";
    // while(n != 1) {
    //     n = parent[n];
    //     cout << n << " ";
    // }
}

void dijkstra() {
    for(int i = 0; i <= n; i++) dist[i] = 100000; 

    dist[1] = 0;
    q.push({0, 1});//distance and vertex

    while(!q.empty()) {
        int vertex = q.top().second;//q.top - shortest distance with its vertex
        q.pop();

        for(int i = 0; i < graph[vertex].size(); i++) {
            int vtx = graph[vertex][i].first;
            int wgh = graph[vertex][i].second;

            if(dist[vertex] + wgh < dist[vtx]) {
                dist[vtx] = dist[vertex] + wgh;
                q.push({dist[vtx],vtx});
                parent[vtx] = vertex;
            }
        }
    }

}

int main() {
    cin >> n >> e;
    //input graph. two vertecies with edge weight
    for(int i = 1; i <= e; i++) {
        cin >> u >> v >> w;
        graph[u].push_back({v,w});
        graph[v].push_back({u,w});
    }

    //seeking for the shortest path
    dijkstra();
    path(n);
}

/*
9 14
1 3 8
1 7 3
1 2 4
3 5 2
2 4 7
7 3 2
7 4 9
4 8 8
5 7 5
5 9 1
9 4 2
9 8 3
8 6 4
6 5 6
*/

/*
8 11
1 3 9
1 8 4
8 5 14
5 4 7
3 7 3
7 4 4
7 5 2
2 1 6
2 3 2
6 2 3
6 4 2*/
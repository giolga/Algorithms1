#include <iostream>
#include <vector>
#include <queue>
using namespace std;

vector <pair <int, int> > graph[10000];
priority_queue <pair <int, int>, vector <pair <int, int> >, greater <pair <int, int> > > q;

bool beenThere[10000];
int parent[10000];
int dist[100000];
int v,u,w,n,e;

void prim(int firstVertex) {
    for(int i = 0; i <= n; i++) dist[i] = 1000000, parent[i] = -1; 

    dist[firstVertex] = 0;
    q.push({0, firstVertex});//distance and vertex

    while(!q.empty()) {
        int currVertex = q.top().second;//q.top - shortest distance with its vertex
	    int currWeight  = q.top().first;
        q.pop();
        beenThere[currVertex] = 1;

        for(int i = 0; i < graph[currVertex].size(); i++) {
            int neighborVertex  = graph[currVertex][i].first;
            int neighborWeight  = graph[currVertex][i].second;

            if(!beenThere[neighborVertex ] && neighborWeight  < dist[neighborVertex ]) {
                   dist[neighborVertex ] = neighborWeight;
                   parent[neighborVertex ] = currVertex;
                   q.push({dist[neighborVertex ],neighborVertex });
            }

        }
    }

}

int main() {
    cin >> n >> e;

    //input graph. two vertecies with edge weight
    for(int i = 1; i <= e; i++) {
        cin >> u >> v >> w;
        graph[u].push_back({v, w});
        graph[v].push_back({u, w});
    }

    prim(1);

    cout << "Edges in the minimum spanning tree:" << endl;
    for (int i = 2; i <= n; i++) {
        cout << parent[i] << " - " << i << " - " << dist[i] << endl;
    }

    return 0;
}

/*
9 16
1 2 4
1 3 8 
2 5 8 
2 3 11
3 7 1 
3 4 7 
5 4 2 
5 8 4 
5 6 7 
7 8 2 
8 9 10
8 6 15
6 5 7 
6 9 9
4 3 7
4 7 6
*/
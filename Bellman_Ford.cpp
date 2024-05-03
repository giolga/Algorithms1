#include <iostream>
#include <vector>
#include <queue>
#include <math.h>
#include <stdio.h>
#include <limits> //INT_MAX
using namespace std;

struct info {
    int first, second, weight;
};

int n, v, u, w, e;
int dist[100000], parent[100000];
vector < info > graph;

priority_queue <pair <int, int>, vector <pair <int, int> >, greater <pair <int, int> > > q;

void Bellman_Ford(int n, int e) {
    for(int i = 1; i <= n; i++) dist[i] = 1000000;

    dist[1] = 0;
    
    for(int i = 0; i < n-1; i++) {
        for(int j = 0; j < e; j++) {
            int first = graph[j].first;
            int second = graph[j].second;
            int wgh = graph[j].weight;

            if(dist[first] != 1000000 &&  dist[first] + wgh < dist[second]) {
                dist[second] = dist[first] + wgh;
                parent[second] = first;
            }
                //cout << first << " - " <<  second << " --- " << dist[second] << endl; 
        }
        //cout << endl;   
    }
   
}

int main() {
    cin >> n >> e;
    for(int i = 0; i < e; i++) {
        cin >> v >> u >> w;
        graph.push_back({v,u,w});
    }
    
    Bellman_Ford(n, e);

    for(int i = 1; i <= n; i++) {
       if(dist[i] != 1000000) cout << dist[i] << " ";
       else cout << 30000 << " ";
    }

    return 0;
}

/*
10 7
1 2 6
1 3 5
1 4 5
2 5 -1
3 2 -2
3 5 1
4 3 -2
4 6 -1
5 7 3
6 7 3

7 10
1 2 6
1 3 5 
1 4 5 
2 5 -1
3 2 -2
3 5 1 
4 3 -2
4 6 -1
5 7 3 
6 7 3 

*/
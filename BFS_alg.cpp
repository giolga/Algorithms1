#include <bits/stdc++.h>
using namespace std;

struct Graph {
    int current;
    int distance;
    int parent;
    bool beenThere = false;
};

int n,m;
int c,c2;

map <int, vector <int> > graph;
map <int, Graph> info;
map<int, Graph> :: iterator it;
queue <Graph> q;
Graph qin,qout;

main() {
    cin >> n;
    for(int i = 0; i < n; i++) {
        cin >> c >> m;
        for(int j = 0; j < m; j++) {
            cin >> c2;
            graph[c].push_back(c2);
        }
    }

    qin.current = 'A';
    qin.distance = 0;
    qin.parent = 'A';
    qin.beenThere = true;
    info[qin.current] = qin;

    q.push(qin);
    //BFS
    while(!q.empty()) {
        qout = q.front();
        q.pop();
        for(int i = 0; i < graph[qout.current].size(); i++) {
            if(!info[graph[qout.current][i]].beenThere) {
                qin.current = graph[qout.current][i];
                qin.distance = qout.distance + 1;
                qin.parent = qout.current;
                qin.beenThere = true;

                q.push(qin);
                info[qin.current] = qin;
            }
        }
    }

    cout << "Alphabet : ";
    for(it = info.begin(); it != info.end(); it++) {
        pair<int, Graph> p = *it;
        cout << p.second.current << '\t';
    }
    cout << endl << "Distance : ";

    for(it = info.begin(); it != info.end(); it++) {
        pair<int, Graph> p = *it;
        cout << p.second.distance << '\t';
    }
    cout << endl << "Parent :   ";

    for(it = info.begin(); it != info.end(); it++) {
        pair<int, Graph> p = *it;
        cout << p.second.parent << '\t';
    }
}

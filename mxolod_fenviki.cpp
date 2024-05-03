#include <bits/stdc++.h>
using namespace std;

int n,i,q;
int k,x,y;
long long dif[100001],it;//იტერაციით დავთვლით მასივის ზომას
long long arr[1000001],fenwick[1000001];

void update(int idx, int val, int maxVal) {
    while(idx <= maxVal) {
        fenwick[idx] += val;
        idx += (idx & -idx);
    }
}

int getSum(int idx) {
    int sum = 0;
    while(idx > 0) {
        sum += fenwick[idx];
        idx -= (idx & -idx);
    }
    return sum;
}

main() {
    cin>>n>>q;  
    for(i = 1; i <= n; i++) {
        cin>>arr[i];
        update(i,arr[i],n);
    }

    for(i = 0; i < q; i++) {
        cin>>k>>x>>y;
        if(k == 1) {
            x++;
            update(x,y - arr[x],n);
            arr[x] = y;
        }
        if(k == 2) {
            y++;
            dif[it] = getSum(y) - getSum(x);
            it++;
        }

    }

    for(i = 0; i < it; i++) {
        cout<<dif[i]<<" ";
    }
}
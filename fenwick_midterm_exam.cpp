#include <bits/stdc++.h>
using namespace std;

// int arr[17] = {3,1,2,2,3,3,1,4,2,5,2,2,3,1,0,2};
int arr[15],sum[100];
int tree[17] = {0};
int i,n=16,k;

void update(int idx, int val) {//ინდექსი და საწყისი ელემენტის მნიშვნელობა
    
    while(idx <= n) {//maxVal -> n არის მასივის ზომა, ეს ციკლი იმუშავებს მანამ, სანამ მთელ მასივში არ განაახლებს ჯამს
        tree[idx] += val;
        idx += (idx & -idx);
    }
}

void read(int idx) { //ერთი ინდექსი, რათა პასუხი დააბრუნოს პირველი ინდექსიდან, მოც. ინდექსამდე
    while(idx > 0) {
        sum[k] = idx;
        k++;
        idx -= (idx & -idx);
    }
}

main() {
    // cin >> n;
    // for(i = 1; i <= n; i++) {
    //     cin >> arr[i];
    //     update(i,arr[i]);
    // }
    // for(i = 1; i <= n; i++) {
    //     cout<<tree[i]<<" ";
    // }
    read(195);
    for(i=0; i < k ; i++) {
        cout << sum[i] << " ";
    }

}
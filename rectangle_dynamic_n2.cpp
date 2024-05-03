#include <bits/stdc++.h>
using namespace std;

int arr[1005][1005],n;
int b[1005][1005];

main() {
    cin >> n;
    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= n; j++) {
            cin >> arr[i][j];
            if(i == 1) {
                b[1][j] = b[1][j-1] + arr[1][j];
            }
            if(j == 1 && i > 1) {
                b[i][1] = b[i-1][1] + arr[i][1];
            }
        }
    }

    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= n; j++) {
            b[i][j] = arr[i][j] + b[i-1][j] + b[i][j-1] - b[i-1][j-1];
        }
    }

    cout << "\n";
    for(int i = 1 ; i <= n; i++) {
        for(int j = 1 ; j <= n; j++) {
            cout << b[i][j] << " ";
        }
        cout << "\n";
    }
}
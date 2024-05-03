#include <bits/stdc++.h>
using namespace std;

int arr[1005][1005];
string s1,s2;

void lcs(string frst, string scnd) {
    int n = frst.size(), m = scnd.size();
    for(int i = 0; i <= n; i++) {
        for(int j = 0; j <= m; j++) {
            if(i == 0 || j == 0) arr[i][j] = 0;
            else if(frst[i-1] == scnd[j-1]) {
                arr[i][j] = arr[i-1][j-1] + 1;
            }else {
                arr[i][j] = max(arr[i-1][j],arr[i][j-1]);
            }
        }
    }
}

string showSubsequence(string frst, string scnd,int arr[1005][1005]) {
    int n = frst.size(), m = scnd.size();
    string sequence = "";

    while(1) {
        if(frst[n-1] == scnd[m-1]) {
            sequence = frst[n-1] + sequence;
            n--;
            m--;
        } else if(arr[n][m-1] > arr[n-1][m]) {
            m--;
        } else {
            n--;
        }
        if(arr[n][m] == 0) break;
    }

    return sequence;
}

main() {
    cin >> s1 >> s2;
    lcs(s1,s2);

    for(int i = 0; i <= s1.size(); i++) {
        for(int j = 0; j <= s2.size(); j++) {
            cout << arr[i][j] << " ";
        }
        cout << "\n";
    }

    cout << showSubsequence(s1,s2,arr);

}
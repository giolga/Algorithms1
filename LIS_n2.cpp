#include <bits/stdc++.h>
using namespace std;

int arr[1005],n;
int b[1005], cnt;

main() {
    cin >> n;
    for(int i = 0; i < n; i++) {
        scanf("%d",&arr[i]);
    }
    for(int i = 1; i < n; i++) {
        b[i] = 1;//ეს რიცხვი თვითონაც ქვემიმდევრობააა და მიტო უდრის 1-ს
        for(int j = i -1; j >= 0; j--) {
            if(arr[i] > arr[j]) {
                b[i] = max(b[i], b[j] + 1);
            }
        }
        cnt = max(cnt, b[i]);
    }
    cout << cnt << endl;
}

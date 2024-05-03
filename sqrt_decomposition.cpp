#include <bits/stdc++.h>
using namespace std;

main() {
    int n;
    cin >> n;

    vector <int> a(n);//int a[n];
    for(int i = 0; i < n; i++) {
        cin >> a[i];
    }

    int len = ceil( sqrt(n) );// ceil()
    vector <int> b(len);//int b[3];

    //ვქმნით ფესვნი n ზომის ახალ მასივს და მაგ ბლოკებში ვინახავთ ჯამს
    for(int i = 0; i < n; i++) {
        b[i / len] += a[i];
        // i/len ეს არის ასეთი რაღაც: n=8, len=3, 
        //0,1,2 ეკუთვნის b[0] (b[i/len]),რადგან გაყოფისას 0-ია
        //3,4,5 ეკუთვნის მეორე ბლოკს b[1]
        //ხოლო 6,7,8 ეკუთვნის მესამე ბლოკს
    }
    
    int q;
    // cin >> q;
    //3-17
    // while(q--) {
        int l, r;
        cin >> l >> r;
        
        int sum = 0;
        for(int i = l; i <= r; ) {
            if(i % len == 0 && (i + len) <= r) {//თუ ბლოკი ჯდება მთლიანად შუალედში, მაშინ მთლიან ბლოკს ვჯამავთ
                sum += b[i/len];
                i += len;
            } else {//სხვა მხრივ i-ურ ელემენტს (3%5=3)
                sum += a[i];
                i++;
            }
        }
        cout << sum << endl;
    // }
}



/*
vector <int> a(10000);
int len,l,r;
int n;
vector <int> b(1000);

void update(int idx, int val) {
    int blockNumber = idx / len;
    b[blockNumber] += val - a[idx];
    a[idx] = val;
}

void sqrt_dec(int len) {
    for(int i = 0; i < n; i++) {
        b[i / len] += a[i];
    }
}

int read(int l, int r) {
    int sum = 0;
    for(int i = l; i <= r; ) {
        if(i % len == 0 && (i + len) <= r) {//თუ ბლოკი ჯდება მთლიანად შუალედში, მაშინ მთლიან ბლოკს ვჯამავთ
            sum += b[i/len];
            i += len;
        } else {//სხვა მხრივ i-ურ ელემენტს (3%5=3)
            sum += a[i];
            i++;
        }
    }
    return sum;
}

main() {
    cin >> n;
    for(int i = 0; i < n; i++) {
        cin >> a[i];
    }

    len = ceil( sqrt(n) );// ceil()
    sqrt_dec(len);
    
    cin >> l >> r;
    cout << read(l,r)<<endl;

    update(8,2);
    cout << read(3,17);

}
*/
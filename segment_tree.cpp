#include <bits/stdc++.h>
using namespace std;

const int N = 100000; //max size of tree
int n;//size of array
int tree[N * 2];//2 * N

// int arr[1000];//array of numbers

void build(int arr[]) {//building segment tree from the given array

    for(int i = 0 ; i < n; i++) {//for leafe nodes
        tree[n+i] = arr[i];
    }

    for(int i = n - 1; i > 0; i--) {
        tree[i] = tree[i << 1] + tree[i << 1 | 1];//calculating parent... i = 5, parent(i) = 5 << 1   => 10, 5 << 1 | 1  => 10 or 1 = > 1010 OR 0001 => 1011 = > 11
        
        //test!!!
        // tree[i] = max(tree[i << 1], tree[i << 1 | 1]);
    }
}

int sumOfIntervals(int l, int r) { //sum of range L and R; [L;R)
    int sum = 0;
    for(l += n, r += n; l < r; l >>= 1, r >>= 1) {
        if(l & 1) sum += tree[l++];
        if(r & 1) sum += tree[--r];

        //test!!!
        // if(l & 1) sum = max(sum,tree[l--]);
        // if(r & 1) sum = max(sum, tree[--r]);
    }

    return sum;
}

void update(int k, int x) {//update Kth position to x. 3 => 2
    tree[k + n] = x;
    k += n;
    for(int i = k; i > 1; i >>= 1) {
        tree[i >> 1] = tree[i] + tree[i ^ 1];//xor -> 1010 ^ 0001 = > 1011

        //test!!!
        // tree[i >> 1] = max(tree[i],tree[i ^ 1]);
    }
    
}

main() {
    int arr[] = {2,0,2,0,2,0,0,0};
    n = 8; // size of arr; now let's build the arr

    build(arr);
    cout << sumOfIntervals(0,8) << endl;//let's find the range from 1 to 3;
    // update(5,10);//update fifth position to 10;
    cout << sumOfIntervals(2,6) << endl << endl;
    for(int i = 0; i < n * 2; i++) {
        cout << tree[i] << endl;
    }
}







//p = 5;
// 1 0 1
// 1 0 1 0
//p <<= 1

// l = 3;
// 0 1 1 
// 0 0 1
// 0 0 1 => l = 1;
// l&1


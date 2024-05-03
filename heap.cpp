#include <bits/stdc++.h>
using namespace std;

int arr[100],n,i;

void max_heap(int arr[], int i, int n) {
    int temp, j;
    temp = arr[i];//Temporarily storing arr[i] element for exchanging
    j = i * 2;
    while(j <= n) {
        if(j < n && arr[j+1] > arr[j]) //j<n because of arr[j+1]
            j++;
        if(temp > arr[j]) break;
        else if(temp <= arr[j]) {
            arr[j/2] = arr[j];
            j *= 2;
        }
    }
    arr[j/2] = temp;
}

void build_maxHeap(int arr[], int n) {
    for(int i = n/2; i >= 1; i--)
        max_heap(arr,i,n); 
}

main() {
    cin >> n;
    for(i = 1; i <= n; i++)
        cin >> arr[i];

    build_maxHeap(arr, n);
    for(i = 1; i <= n; i++) cout << arr[i] << " ";
}
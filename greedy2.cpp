#include <bits/stdc++.h>
#include <algorithm>
using namespace std;

int n,i,fine,mx;
pair <int, int> arr[1000000]; 
set <int> st;
set <int> :: iterator it;

main() {
    cin >> n;
    for(i = 0; i < n; i++) {
        cin >> arr[i].second;//day,fine
        mx = max(mx, arr[i].second);
    }
    for(i = 0; i < n; i++) {
        cin >> arr[i].first;
    }
    sort(arr,arr + n); reverse(arr,arr + n);

    for(i = 0; i <= mx; i++) {//ათვლა ნულიდანაა საჭირო if-ის გამო ქვემოთ რომაა
        st.insert(i);
    }

    for(i = 0; i < n; i++) {
        it = st.lower_bound(arr[i].second);//day
        
        if(it == st.begin()) {
            fine += arr[i].first;
            continue;
        }

        it--;
        st.erase(it);
    }
    cout << fine << endl;
}
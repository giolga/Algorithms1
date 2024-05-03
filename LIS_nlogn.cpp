#include <bits/stdc++.h>
using namespace std;

int n,i,a;
set <int> st;
set <int> :: iterator it;

main() {
    cin >> n;
    for(i = 0; i < n; i++) {
        cin >> a;
        it = st.lower_bound(a);

        if(it == st.end()) st.insert(a);//ქვემიმდევრობა თუ ცარიელია ეგრევე შეგვაქ.
        else {//თუ რაიმე პატარა რიცხვი შემოდის ეგრევე ვშლით მიმდევრობაში არსებულ ბოლო რიცხვს და მაგ ახალ რიცხვს ვამატებთ
            st.erase(it);
            st.insert(a);
        }
    }

    cout << st.size() << endl;
}
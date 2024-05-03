#include<bits/stdc++.h>
using namespace std;
int i,n,maxtime,res;
pair<int,int> p[1000005];
set<int>s;
set<int> :: iterator it;
main(){
cin>>n;
for(i=0;i<n;i++){
    scanf("%d",&p[i].second);
    maxtime=max(maxtime,p[i].second);}
for(i=0;i<n;i++){
    scanf("%d",&p[i].first);}
sort(p,p+n);
reverse(p,p+n);
for(i = 0 ; i < n; i++) {
    cout << p[i].second << " " << p[i].first << endl;
}
// for(i=0;i<=maxtime;i++){
//     s.insert(i);}
// for(i=0;i<n;i++){
//     it =s.lower_bound(p[i].second);
//     if(it==s.begin()) { res+=p[i].first; continue; }
//     it--;
//     s.erase(it);}
cout<<res;
}

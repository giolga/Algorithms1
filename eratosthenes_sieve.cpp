#include <bits/stdc++.h>
using namespace std;

long long i,n,j,num[1000001];

// main() {
//     cin>>n;
//     for(i=2;i<=n;i++) {
//         if(num[i]==1) continue;//პროგრამა გადადის ციკლის ბოლოში და მომდევნო რიცხვს ამოწმებს
//             else {//ეს რიცხვი მარტივია და ეკრანზე იბეჭდება
//                 cout<<i<<" ";
//                 for(j=i*i;j<=n;j+=i) {//ხდება მონიშვნა ყველა იმ რიცხვისა რომელიც i-ზე უნაშთოდ იყოფა
//                     num[j]=1;
//                 }//შიდა ციკლი i*i-ით უნდა დავიწყოთ, მანამდე კი i-ზე პატარა რიცხვით იქნებო მონიშნული შედგენილი რიცხვი;
//                 //მაგ. 11, შიდა ციკლი 121-ით დაიწყება, მასზე პატარა რიცხვები კი რომლებიც 11-ზე უნაშთოდ იყოფა მონიშნულია 2,3,5 ან 7-ის მიერ
//             }
//     }
// }

main() {
    cin>>n;
    for(i=2;i<=n;i++) {
        if(num[i]==1) continue;//პროგრამა გადადის ციკლის ბოლოში და მომდევნო რიცხვს ამოწმებს
            else {//ეს რიცხვი მარტივია და ეკრანზე იბეჭდება
                for(j=i*i;j<=n;j+=i) {//ხდება მონიშვნა ყველა იმ რიცხვისა რომელიც i-ზე უნაშთოდ იყოფა
                    if(num[j]==0) {
                        num[j]=i;
                    }
                }
               //140 მნიშ 2... 140/2=70, 70-ის მნიშ 2...70/2 =35, მნიშ 5, 35/5=7, 7-ის მნიშ 0,პროცესი შევწყვიტოტ
            }//პახოდუ მნიშვნელობებს ვბეჭდავთ და ვიღებთ 2 2 5 7 --> 140 დაიშალა მარტივ ნამრავლებად
    }
    while (num[n]!=0) {
        cout<<num[n]<<" ";
        n=n/num[n];//140 მნიშ 2... 140/2=70, 70-ის მნიშ 2...70/2 =35, მნიშ 5, 35/5=7, 7-ის მნიშ 0,პროცესი შევწყვიტოტ
    }//პახოდუ მნიშვნელობებს ვბეჭდავთ და ვიღებთ 2 2 5 7 --> 140 დაიშალა მარტივ ნამრავლებად
    cout<<n;//7
}
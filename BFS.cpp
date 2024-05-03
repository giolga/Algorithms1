#include <bits/stdc++.h>
using namespace std;

int n,m;
struct ugra{ int r,c,step; };
queue <ugra> q;

ugra qin, qout;
int dr[8]={-2, -1, 1, 2,  2,  1, -1, -2};
int dc[8]={ 1,  2, 2, 1, -1, -2, -2, -1};

int dapa[101][101];

int r1,c1,r2,c2;
int rowz,colz,newr,newc,stepz;

main() {
    //cin>>n>>m;
    n=m=8;
    cin>>r1>>c1>>r2>>c2;
    for(int i=1;i<=n;i++) {
        for(int j=1;j<=m;j++) {
            dapa[i][j]=-1; //მატრიცაში ვწერთ -1-ს რათა, როცა გადავალთ ცხენით სადღაცას, მაგ i,j პოზიციაზე უნდა გამოვიყენოთ ნუმერაცია
        }//გადავალთ მაშინ, თუ i,j არის -1;
    }
    /*
    for(int i=1;i<=n;i++) {
        for(int j=1;j<=m;j++) {
            cout<<dapa[i][j]<<" ";
        }
        cout<<endl;
    }
    */
    dapa[r1][c1]=0; //0 ნიშნავს დასაწყისს(ნუმერაცია, რომელიც მოიმატებს სათითაოდ)
    qin.r=r1; qin.c=c1; qin.step=0;//ვწერთ ადგილ-მდებარეობას, step-ში 0;
    q.push(qin);

    while(q.size()>0) {
        qout=q.front(); //qout-ში ვინახავთ რიგის პირველ წევრს და ვშლით რიგს
        q.pop();
        stepz=qout.step+1;//??  რიგში ნუმერაციას ვზრდით (0-დან დაიწყო, ხდება 1,2,3...)
        rowz=qout.r; colz=qout.c;//ჩავაგდეთ დაფაში, მერე რიგში
        for(int i=0;i<8;i++) {//dr,dc მასივის მნიშვნელები
            newr=rowz+dr[i]; newc=colz+dc[i];
            if(newr>=1 && newr<=n && newc>=1 && newc<=m) {
                if(dapa[newr][newc]==-1) {
                    dapa[newr][newc]=stepz;//რადგანაც ცარიელია ჩავწერ steps, ერთით გავზრდით;
                    qin.r=newr; qin.c=newc; qin.step=stepz;
                    q.push(qin);
                }
            }
        }
    }
    /*
    for(int i=1;i<=8;i++) {
        for(int j=1;j<=8;j++) {
            cout<<dapa[i][j]<<" ";
        }
        cout<<endl;
    }
    */
    cout<<dapa[r2][c2]<<endl;
}
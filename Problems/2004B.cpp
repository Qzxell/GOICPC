#include<bits/stdc++.h>
#define ln '\n'
#define pb push_back
#define vii vector<pair<int,int>>  
#define vi vector<int>  
#define fi first
#define se second
using namespace std;

void so(){
    int l,r,ll,rr;
    cin >> l >> r >> ll >> rr;
    if (r < ll ) {
        cout << 1 << ln; 
        return;
    }
    if (rr < l ) {
        cout << 1 << ln; 
        return;
    }
    vi v(101,0);
    for (int i = l; i <= r; ++i) {
        v[i]++;   
    }
    for (int i = ll; i <= rr; ++i) {
        v[i]++; 
    }
    int c= 0 ;
    int ind = 0;
    int f = 100;
    for(int i =1 ; i <= 100 ; i++){
        if (v[i] == 2) {
            if (c == 0) {
                ind = i; 
            }
            c++; 
            f = i;
        } 
    }
    c--;
    if (ind > 1 and v[ind-1] == 1) {
        c++; 
    }
    if (f < 100 and v[f+1] == 1) {
        c++; 
    }
    cout <<c << ln;
}
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int tt;
    cin >> tt;
    while(tt--){
        so();
    }
    return 0;
}


#include<bits/stdc++.h>
#define ln '\n'
#define ll long long
#define pb push_back
#define vii vector<pair<int,int>>  
#define vll vector<ll>  
#define vi vector<int>  
#define fi first
#define se second
using namespace std;

void so(){
    int n,k;
    cin >> n >> k;
    vll v(n);
    for(int i = 0; i < n ; i++){
        cin >> v[i];
    }
    sort(v.begin(),v.end());
    ll dif = 0;
    for(int i = (n&1 ? 1 : 0); i < n ; i+= 2){
        dif += v[i+1] - v[i];
    }
    ll A = 0,B=0;
    for(int j = (n&1 ? 0 : 1) ; j < n ; j+= 2){
        A += v[j];
    }
    for(int j = (n&1 ? 1 : 0) ; j < n ; j+= 2){
        B += v[j];
    }
    ll res = A - B;
    if(k > 0){
        ll dec = min(dif,(ll) k);
        res -= dec;
    }
    cout << res << ln;
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


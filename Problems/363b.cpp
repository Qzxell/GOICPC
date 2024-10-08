#include<bits/stdc++.h>
#define ln '\n'
#define pb push_back
#define vii vector<pair<int,int>>  
#define vi vector<int>  
#define fi first
#define se second
using namespace std;

void so(){
    int n,t,p;
    cin >> n  >> t >> p;
    vi v(n);
    for(int i = 0;i < n;i++){
        cin >> v[i] ;
    }
    sort(v.begin(),v.end());
    reverse(v.begin(),v.end());
    cout << max(0,t - v[p-1]);
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int tt;
    tt = 1;
    while(tt--){
        so();
    }

    return 0;
}

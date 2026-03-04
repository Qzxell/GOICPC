#include<bits/stdc++.h>
#define ln '\n'
#define ll long long
#define pb push_back
#define vii vector<pair<int,int>>  
#define vi vector<int>  
#define fi first
#define se second
using namespace std;

void so(){
    int n,m;
    cin >> n >> m;
    vii v(n);
    ll ans = 0;
    for (int i = 0; i < n; ++i) {
        int x;
        cin >> x ;
        v[i].fi = x;
        v[i].se = i+1;
        ans += 2*v[i].fi;
    }
    sort(v.begin(),v.end());
    if (n == 2 or m < n) {
        cout << -1 << ln;
        return;
    }
    int c = m - n;
    int au = v[1].fi + v[0].fi;
    ans += c*1ll * au;
    cout << ans << ln;

    for (int i = 0; i < n; ++i) {
        cout << i+1 << ' ' << (i+2 == n+1 ? 1: i+2) << ln;    
    }
    for(int i = 0 ; i < c ; i++){
        cout << v[0].se << ' ' << v[1].se << ln;
    }
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


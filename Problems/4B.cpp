#include<bits/stdc++.h>
#define all(c) (c).begin(), (c).end()
#define ln '\n'
#define ll long long
#define pb push_back
#define ii pair<int,int>
#define vii vector<ii>  
#define vi vector<int>  
#define fi first
#define se second
using namespace std;

void so(){
    int n,to;
    cin >> n >> to;
    vii v(n);
    int mi,ma;
    mi = ma = 0;

    for(int i = 0 ; i<n;i++){
        cin >> v[i].fi >> v[i].se;
        mi += v[i].fi;
        ma += v[i].se;
    }
    if (mi <= to and to <= ma) {
        cout << "YES\n"; 
    }else {
        cout << "NO\n";
            return;
    }
    int x = 0;
    vi ans(n);
    int rema=0;
    for(int i = 0 ; i<n ;i++){
        ans[i] = v[i].fi;
        rema += v[i].fi;
    }
    to -= rema;
    for(int i = 0 ; i<n ;i++){
        int x = min(v[i].se - v[i].fi ,to) ;
        ans[i] += x;
        to -= x;
    }
    for(int x : ans) cout << x << ' ';
}
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int tt = 1;
    while(tt--){
        so();
    }
    return 0;
}


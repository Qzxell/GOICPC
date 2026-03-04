#include <bits/stdc++.h>

using namespace std;

#define sz(v) ((int)(v).size())
#define all(v) (v).begin(),(v).end()
#define rall(v) (v).rbegin(),(v).rend()
#define ln '\n'
#define ll long long
#define pb push_back
#define ii pair<int,int>
#define vii vector<ii>  
#define vi vector<int>  
#define fi first
#define se second


void so(){
    int n;
    cin >> n;
    vi a(n),b(n);
    for(int i = 0 ;i < n; i++) cin >> a[i];
    for(int i = 0 ;i < n; i++) cin >> b[i];
    sort(all(a));
    sort(rall(b));
    ll ma ,mi;
    mi = 1e10;
    ma = 0;
    
    for(int i = 0 ;i < n; i++){
        ma = max(ma,a[i]+0ll+b[i]);
        mi = min(mi,a[i]+0ll+b[i]);
    }
    cout << ma - mi;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int tt = 1;
    while (tt--){
        so();
    }
    return 0;
}

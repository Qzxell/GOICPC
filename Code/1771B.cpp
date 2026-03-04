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
    int mi = n;
    vi cer(m);
    vi pos(n+1,0);
    for(int i = 0 ; i < m ; i++){
        int a,b;
        cin >> a >> b;
        if (a > b) {
            swap(a,b) ;
        }
        cer[i] = b;
        pos[b] = max(pos[b], a);
    }
    sort(cer.begin(),cer.end());
    ll ans = 0;
    int po = 0;
    for (int i = 1; i <= n; ++i) {
        while (po < m and i > pos[cer[po]]) {
            po++; 
        }
        if (po == m) {
            ans += n - i + 1; 
            continue;
        }
        ans += cer[po] - i;
    }
    cout << ans << ln;
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

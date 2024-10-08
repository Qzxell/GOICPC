#include<bits/stdc++.h>
#define sz(v) ((int)(v).size())
#define all(v) (v).begin(),(v).end()
#define ln '\n'
#define ll long long
#define pb push_back
#define ii pair<int,int>
#define vii vector<ii>  
#define vi vector<int>  
#define fi first
#define f(i, a, b) for(ll i = (ll)a; i < (ll)b; i++)
#define fr(i, a, b) for(ll i = (ll)a; i >= (ll)b; i--)
#define se second
using namespace std;

map<int,int> frea;
map<int,int> freb;

void so(){
    frea.clear();
    freb.clear();
    int n;
    cin >> n;
    for (int i = 0 ; i < n ; i++){
        int x;
        cin >>  x;
        frea[x] ++;
    }
    for (int i = 0 ; i < n ; i++){
        int x;cin >> x; 
        if (frea.count(x) > 0 and frea[x] > 0) {
            frea[x]--; 
            continue;
        }
        freb[x]++;
    }
    vi fa(11,0);
    vi fb(11,0);
    auto fu = [&](int x){
        int cont = 0;
        while(x > 0 ){
            cont++;
            x/=10;
        }
        return cont;
    };
    ll ans = 0;
    for (auto cur : frea){
        if (cur.fi >= 10) {
            fa[fu(cur.fi)] += cur.se;        
            ans += cur.se;
        } else fa[cur.fi] += cur.se;
    }
    for (auto cur : freb){
        if (cur.fi >= 10) {
            fb[fu(cur.fi)] += cur.se;        
            ans += cur.se;
        } else fb[cur.fi] += cur.se;
    }
    fr(i , 9, 2){
        int dif = 0;
        if (fa[i] > fb[i]) {
            dif =  fa[i] - fb[i] ; 
            ans += dif;
        }else if (fa[i] < fb[i]) {
             dif = fb[i] - fa[i]; 
            ans += dif;
        }
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


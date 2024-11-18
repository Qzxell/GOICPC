#include <bits/stdc++.h>

using namespace std;

#define sz(v) ((int)(v).size())
#define all(v) (v).begin(),(v).end()
#define ln '\n'
#define ll long long
#define pb push_back
#define ii pair<int,int>
#define vii vector<ii>  
#define vi vector<int>  
#define fi first
#define se second
#define f(i, a, b) for(ll i = (ll)a; i < (ll)b; i++)
#define fer(i, b, a) for(ll i = (ll)a - 1; i >= (ll)b; i--)

void so(int test){
    ll a,b,c;
    ll x = 0;
    ll owo= 0;
    ll aw = 0;
    auto ga = [&](ll mask, int pos){
        bool yes = ((mask>>pos)&1);
        return yes;
    };
    cin >> a >> b >> c;
    for(int i = 0 ; i < 61;i++){
        if (not(ga(a,i)) and ga(b,i)) {
            owo += (1ll<<i); // los posiciones prendidas siempre seran nulas
        }
        if (ga(a,i) and not(ga(b,i))) {
            aw += (1ll<<i); // en la posicion i siempre estara prendida
            //c -= (1ll<<i) ;
        }
        if (not(((a>>i)&1) ^(1&(b>>i)))) {
            x += (1ll<<i); // las posiciones i, pueden estar prendidas y apagadas
        }
    }
    ll ans = 0;
    for(int i = 0 ; i < 61;i++){
        if (ga(c,i) and ga(owo,i)) {
            cout << -1<< ln;
            return;
        }
        if (ga(aw,i) and !ga(c,i)) {
            cout << -1<< ln;
            return;
        }
    }
    for(int i = 0 ; i < 61;i++){
        // posible bit -> se debe apagar segun c
        if (ga(x,i) and not(ga(c,i))) {
            if (ga(a,i)) {
                ans += (1ll<<i);
            } 
        }
        if (ga(c,i) ) {
            if (not(ga(a,i)) ) {
                ans += (1ll<<i); 
            } 
        }
    }
    ll jj = (1ll<<61);
    if ((a | jj ) - (b & jj) == c) {
        cout << jj << ' ' ;
        return;
    }
    if (ans > (1ll<<61)) {
        cout << -1 << ln;
        return;
    }
    cout << ans << ln;

}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int tt = 1;
    cin >> tt;
    int test = 1;
    while (tt--){
        so(test++);
    }
    return 0;
}


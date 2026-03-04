#include <bits/stdc++.h>

using namespace std;

using ii = pair<int,int>;
using vii = vector<ii>  ;
using vi = vector<int>  ;
#define ln  '\n'
#define ll long long
#define pb push_back
#define fi first
#define se second
#define sz(v) ((int)(v).size())
#define all(v) (v).begin(),(v).end()
#define f(i, a, b)  for(ll i = (ll)a; i < (ll)b; i++)
#define fer(i, b, a)  for(ll i = (ll)a - 1; i >= (ll)b; i--)

void so(int test){
    int n;
    cin >> n;
    int l,r,c;
    ll price = 0;
    int IN = 1e9 + 1;
    int ma = 0;
    int mi = IN;
    vi cost(n);
    int eti1,eti2;
    int etil , etir  ;
    auto ga = [&](int one, int two){
        if (one == two) {
            return cost[one] ;
        }
        return cost[one] + cost[two];
    };
    f(i,0,n){
        cin >> l >> r >> c;
        cost[i] = c;
        if(i == 0 ){
            ma = r;
            mi = l;
            eti1 = eti2 = i;
            etir = etil = i;
            cout << c << ln;
            continue;
        }
        if (l < mi) {
            mi = l;
            eti1 = etil =  i;
        }
        if (r > ma) {
            ma = r;  
            eti2 = etir = i;
        }
        if (l == mi ) etil = i; 
        if (r == ma ) etir = i; 
        int mii = IN;
        int ld,rd;
        int ls,rs;
        if (ga(eti1,eti2) < mii) {
            ld = eti1; rd = eti2; 
            ls = etil; rs = etir; 
            mii = ga(eti1,eti2);
        }
        if (ga(eti1,etir) < mii) {
            ld = eti1; rd = etir; 
            ls = etil; rs = eti2; 
            mii = ga(eti1,etir);
        }
        if (ga(etil,eti2) < mii) {
            ld = etil; rd = eti2; 
            ls = eti1; rs = etir; 
            mii = ga(etil,eti2);
        }
        if (ga(etil,etir) < mii) {
            ld = etil; rd = etir; 
            ls = eti1; rs = eti2; 
            mii = ga(etil,etir);
        }
        eti1 = ld; eti2 = rd;
        etil = ls ; etir = rs;
        cout << eti1 << ' ' << eti2 << ' ' << etil << ' ' << etir << ' ';
        cout << mii << ln;


    }
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

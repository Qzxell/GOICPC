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
#define rall(v) (v).rbegin(),(v).rend()
#define f(i, a, b)  for(ll i = (ll)a; i < (ll)b; i++)
#define fer(i, b, a)  for(ll i = (ll)a - 1; i >= (ll)b; i--)
#define point complex<long long>

void so(int test){
        int n,x;
        cin >> n >> x;
        ll ans = 0;
        vi v;
        vi res;
        f(i,0,n){
                int nu;
                cin >> nu;
                if(nu == x){
                        ans += x;
                        res.pb(x);
                } else v.pb(nu);
        }
        sort(all(v));
        if(sz(v) <= 1){
                cout << ans << ln;
                for(auto nu : res)cout << nu << ' ';
                if(sz(v) == 1)cout << v[0] << ' ';
                cout << ln;
                return;
        }
        int acu = 0;
        int lo = 0;
        int ind = 0;
        int lf = sz(v) - 1;
        acu += v[lf];
        while(ind < lf){
                acu += v[ind];
                if(acu >= x){
                        acu -= x;
                        for(int i = lo ; i <= ind ; i++){
                                cout << v[i] << ' ';
                        }
                        lf--;
                        acu += v[lf];
                        if(acu >= x){

                        }
                }
                ind++;
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




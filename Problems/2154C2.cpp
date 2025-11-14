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
#define re real()

const int N = 1e6 + 5;
vector<vi> fact(N);
vector<int> comp(N,0);
vi exi(N,0);

void so(int test){ 
        int n;
        cin >> n; 
        vi a(n),b(n);
        vii wasa(n);
        f(i,0,n) cin >> a[i];
        f(i,0,n) cin >> b[i];

        f(i,0,n) wasa[i] = {b[i],a[i]};
        sort(all(wasa));

        f(i,0,n){
                a[i] = wasa[i].se ;
                b[i] = wasa[i].fi ;
        }

        ll ans = INT_MAX;
        unordered_set<int> s;
        int lon = 0;
        f(i,0,n){
                for(auto x : fact[a[i]]){
                        if(s.count(x)){
                                cout << 0 << ln;
                                return;
                        }
                        s.insert(x);
                }
        }
        int ind = -1;
        f(i,0,n){
                for(auto x : fact[a[i]]){
                        s.erase(x);
                }
                for(auto x : fact[a[i]+1]){
                        if(s.count(x)){
                                ans = min<ll>(ans,b[i]);
                                ind = i;
                        }
                }
                for(auto x : fact[a[i]]){
                        s.insert(x);
                }
                if(ind != -1)break;
        }
        if(ind == 0){// case i i i i i i i P i i i
                     // case i(select) i i i i i i i i i i
                     // case P(select) i i i i i i i i i i
                cout << ans << ln;
                return;
        }
        if(a[0]&1){
                ans = min<ll>(ans, b[0] + b[1]);
        }

        ll cost = 0;
        bool ok = 0;
        int num = a[0];
        for(auto x : fact[num])s.erase(x);

        while(cost + b[0] <= ans){
                bool ono = 0;
                cost += b[0];
                num++;
                for(auto x : fact[num]){
                        if(s.count(x)){
                                ono = 1;
                                break;
                        }
                }
                if(ono){
                        ok = 1;
                        break;
                }
        }
        if(ok)ans = min(ans,cost);
        cout << ans << ln;
}

int main() {
        ios::sync_with_stdio(false);
        cin.tie(0);

        f(i,2,N){
                if(comp[i])continue;
                for(int j = i; j < N ; j += i){
                        comp[j] = 1;
                        fact[j].pb(i);
                }
        }
        int tt = 1;
        cin >> tt;
        int test = 1;
        while (tt--){
                so(test++);
        }
        return 0;
}

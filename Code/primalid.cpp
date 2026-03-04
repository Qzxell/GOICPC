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

const int N = 1e7 + 1;
bitset<N> comp;
bitset<N> vis;
vector<vi> dp(N);
vi primes;

void init(){
        comp[1] = 1;
        int n = N;
        f(i,2,n+1){
                if(!comp[i])primes.emplace_back(i);
                for (int j = 0; j < sz(primes) && i *1ll*primes[j]  <= n; j ++) {
                        comp[i*primes[j]] = 1;
                        if(i % primes[j] == 0)break;
                }
        }
}

vi rec(int n){
        vi ret;
        if(n == 1)return ret;
        if(vis[n])return dp[n];
        vis[n] = 1;
        if(!comp[n]){
                ret.pb(n);
                return dp[n] = ret;
        }
        for(auto &pri : primes){
                if(pri > n)break;
                if(n % pri == 0){
                        vi aux = rec(n/pri);
                        aux.pb(pri);
                        return dp[n] = aux;
                        break;
                }
        }
        return dp[n] = ret;
}

void so(int test){
        int n;
        cin >> n;
        int sq = sqrt(n);
        int ind = lower_bound(all(primes),sq) - primes.begin();
        f(i,0,ind+1){
                while(n % primes[i] == 0){
                        cout << primes[i] << ' ';
                        n /= primes[i];
                }
        }
        if(n > 1)cout << n << ' ';
        cout << ln;
}

int main() {
        ios::sync_with_stdio(false);
        cin.tie(0);

        init();
        int tt = 1;
        cin >> tt;
        int test = 1;
        while (tt--){
                so(test++);
        }
        return 0;
}




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

vi primes;

void init(int num){
        vi vis(num,0);
        f(i,2,num){
                if(!vis[i]){
                        vis[i] = i;
                        primes.pb(i);
                }
                for(auto p : primes){
                        if(p > vis[i] or p*i >= num)break;
                        vis[p*i]  = p;
                }
        }
        return;
}

void so(int test){
        int n;
        cin >> n;
        ll ans = 0;
        f(i,1,n+1){
                int lo = 0,lf = sz(primes);
                while(lo < lf){
                        int mid = (1+ lo+lf)/2;
                        ll nu = (mid == 0 ? mid : i*1ll*primes[mid-1]);
                        if(nu <= n){
                                lo = mid;
                        }else lf = mid - 1;
                }
                ans += lo;
        }
        cout << ans << ln;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	int tt = 1;
        int N = 1e7 + 2;
        init(N);
	cin >> tt;
	int test = 1;
	while (tt--){
		so(test++);
	}
	return 0;
}

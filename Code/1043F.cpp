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

const int N = 3e5 + 5;
const int mod = 1e9 + 7;

int fac[N];
int inv[N];

int fp(int a, int e){
        int b = a;
        int ret = 1;
        while(e){
                if(e&1){
                        ret = (ret * 1ll* b)%mod;
                }
                b = (b *1ll*b )%mod;
                e >>= 1;
        }
        return ret;
}

int comb(int a,int b){
        return (((fac[a]*1ll*inv[b])%mod)*1ll*inv[a-b])%mod;
}
void init(){
        fac[0] = 1;
        f(i,1,N){
                fac[i] = (fac[i-1]*1ll*i)%mod;
        }
        inv[N-1] = fp(fac[N-1],mod-2);
        for(int i = N-1 ; i >= 1; i--){
                inv[i-1] = (inv[i]*1ll*i)%mod;
        }
        return;
}

void so(int test){
        int n;
        cin >> n;
        vi cnt(N,0);
        vi v(n);
        int gc = 0;
        f(i,0,n){
                cin >> v[i];
                gc = gcd(v[i],gc);
                cnt[v[i]]++;
        }
        if(gc != 1){
                cout << -1 << ln;
                return; 
        }
        for(int i = 1; i < N; i++){
                for(int j = i + i ; j < N ;j += i){
                        cnt[i] += cnt[j];
                }
        }
        vi dp(N,0);
        f(i,1,10){
                for(int j = N-1 ; j > 0 ;j--){
                        dp[j] = comb(cnt[j],i);
                        for(int k = j + j ; k < N ; k+=j){
                                dp[j] = (dp[j] + mod - dp[k])%mod;
                        }
                        if(dp[1]){
                                cout << i << ln;
                                return;
                        }
                }
        }
        assert(false);
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

        init();
	int tt = 1;
	int test = 1;
	while (tt--){
		so(test++);
	}
	return 0;
}

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

const ll MOD = 1e9 + 7;
const int N = 2e5 + 5;
vector<ll> fac(N);
void init(){
        fac[0] = 1;
        f(i,1,N){
                fac[i] = fac[i-1]*1ll*i%MOD;
        }
}
ll fp(ll a,ll b){
        ll ans = 1;
        while (b) {
                if (b & 1) {
                        ans = 1LL * ans * a % MOD;
                }
                a = 1LL * a * a % MOD;
                b >>= 1;
        }
        return ans;
}
ll inv(ll nu){
        return fp(nu,MOD-2);
}
ll comb(int n,int a){
        return fac[n]*inv(fac[a])%MOD*inv(fac[n-a])%MOD;
}
void so(int test){
        int n,m;
        cin >> n >> m;
        vector<vi> v(31,vi(n+2,0));
        vector<vi> fi(31,vi(n+2,1));
        ll ans = 0;
        f(i,0,m){
                int l,r,x;
                cin >> l >> r >> x;
                f(j,0,31)if(((x>>j)&1) == 0){
                        v[j][l]++;
                        v[j][r+1]--;
                }
        }
        f(bit,0,31){
                f(i,1,n+1){
                        v[bit][i] += v[bit][i-1];
                        if(v[bit][i] >= 1)fi[bit][i] = 0;
                        //cout << fi[bit][i] << ' ';
                }
                int un = 0;
                int cer;
                f(i,1,n+1){
                        un += fi[bit][i];
                }
                cer = n - un;
                ll acu = 0;
                ll conj = fp(2,cer);
                for(int i = 1;i <= un; i+=2){
                        acu = (acu + comb(un,i)*1ll*conj%MOD)%MOD;
                }
                //cout << bit << ' ' << acu << ln;
                ans = (ans + acu*fp(2,bit)%MOD)%MOD;
        }
        cout << ans << ln;
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

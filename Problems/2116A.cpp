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

ll mod = 998244353;

ll fp(ll base, ll exp) {
    ll result = 1;
    base %= mod;
    while (exp > 0) {
        if (exp & 1) result = (result * base) % mod;
        base = (base * base) % mod; 
        exp >>= 1; 
    }
    return result;
}

void so(int test){
        int n;
        cin >> n;
        vi p(n),q(n);
        vi ans(n);
        f(i,0,n)cin >> p[i];
        f(i,0,n)cin >> q[i];

        int mp=-1,mq = -1;
        int ind_p = -1,ind_q = -1;

        f(i,0,n){
                if(mp < p[i]){
                        mp = p[i];
                        ind_p = i;
                }
                if(mq < q[i]){
                        mq = q[i];
                        ind_q = i;
                }
                ii pr1 = {max(p[ind_p],q[i-ind_p]),min(p[ind_p],q[i-ind_p])};
                ii pr2 = {max(q[ind_q],p[i-ind_q]),min(q[ind_q],p[i-ind_q])};
                ll cal1 = (fp(2,p[ind_p]) + fp(2, q[i - ind_p]))%mod;
                ll cal2 = (fp(2,q[ind_q]) + fp(2, p[i - ind_q]))%mod;
                if(pr1 >= pr2){
                        ans[i] = cal1;
                }else{
                        ans[i] = cal2;
                }
                cout << ans[i] << ' ';
        }
        cout << ln;
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

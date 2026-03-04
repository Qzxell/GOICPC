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

ll lon(ll n){
        if(n <= 1)return  1;
        return 2*1ll*lon(n/2) + 1;
}
ll su(ll n){
        if(n <= 1)return n;
        return 2*1ll*su(n/2) + (n%2);
}
ll qu(ll n, ll ind){
        if(ind == 0){
                return 0;
        }
// se encuentra en este segmento>
        if(n == 1){
                return 1;
        }
        ll wasa = lon(n/2);
        ll ret = 0;
        if(ind <= wasa){
                return qu(n/2,ind);        
        }
        if(wasa < ind){
                ret += su(n/2);
                ind -= wasa;
        }
        if(ind == 1){
                return (n%2) + ret;
        }else{
                return (n%2) + ret+ qu(n/2,ind-1);
        }
}


void so(int test){
        ll n,l,r;	
        cin >> n >> l >> r;
        if(n <= 1){
                cout << n << ln;
                return;
        }
        ll ans = qu(n,r) - qu(n,l-1);
        cout << ans;
        
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	int tt = 1;
	int test = 1;
	while (tt--){
		so(test++);
	}
	return 0;
}

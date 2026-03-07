#include<bits/stdc++.h>

using namespace std;

using ll = long long;

#define forn(i,n) for(int i=0 ;i<int(n);i++)
#define forsn(i,s,n) for(int i=int(s);i<int(n);i++)

#define vi vector<int>
#define vl vector<ll>
#define ii pair<int,int>
#define vii vector<ii>
#define fi first
#define se second
#define all(v) (v).begin(),(v).end()
#define rall(v) (v).rbegin(),(v).rend()
#define sz(v) (int)(v).size()

const ll INF = (1ll<<62);

ll mul(ll a, ll b){
	if(a > b)swap(a,b);
	if(a == 0)return 0;
	if(a == INF or b == INF)return INF;
	if(a <= INF/b)
		return a*b;
	return INF;
}

ll add(ll a, ll b){
	if(a == INF or b == INF)return INF;
	return min(a+b,INF);
}

ll fp(ll b,ll e){
	ll ret = 1;
	while( e > 0){
		if( e&1){
			ret = mul(ret,b);
		}
		b = mul(b,b);
		e >>= 1;
	}
	return ret;
}

void so(int test){
	string s;
	cin >> s;
	int q;
	ll t,k;
	cin >> q;

	auto fu = [&](ll pos)->bool{
		if(pos == -1)return false;
		return k <= mul(pos+1,fp(2,t));
	};
	vi G[3];
	G[0] = {1,2};
	G[1] = {2,0};
	G[2] = {0,1};
	forn(_,q){
		cin >> t >> k;
		ll lo = - 1, lf = sz(s),mid;//FFFFVVVV
		while(lf - lo > 1){
			mid = lo + (lf-lo)/2;
			if(fu(mid))lf = mid;
			else lo = mid;
		}
		k -= mul(lf,fp(2,t));

		int R = lf;

		ll tot = t;
		//cout << __builtin_ctzll(8) << '\n'; -> 3
		int op = 0;
		for(;op < 63;op++) if((1ll<<op) >= k)
				break;

		ll cur = ((t - op)%3 + s[R] - 'A')%3;

		while(op > 0){
			ll mi = (1ll<<(op-1));
			int m1 = G[cur][0],m2 = G[cur][1];
			cur = m1;
			if(k > mi){
				k -= mi;
				cur = m2;
			}
			op--;
		}
		cout << char((cur)%3+ 'A') << '\n';
	}
}

int main(){
        ios::sync_with_stdio(false);
        cin.tie(0);
        int tt = 1;
        int test = 1;
        while(tt--) so(test++);
        return 0;
}


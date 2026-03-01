#include<bits/stdc++.h>

using namespace std;

using ll = long long;

#define forn(i,n) for(int i=0 ;i<int(n);i++)
#define forsn(i,s,n) for(int i=int(s);i<int(n);i++)
#define dforn(i,n) for(int i=int(n)-1;i>=0;i--)
#define dforsn(i,s,n) for(int i=int(n)-1;i>=int(s);i--)

#define vi vector<int>
#define vl vector<ll>
#define ii pair<int,int>
#define vii vector<ii>
#define fi first
#define se second
#define all(v) (v).begin(),(v).end()
#define rall(v) (v).rbegin(),(v).rend()
#define sz(v) (int)(v).size()


const int N = 2e5 + 5;
ll ft[N];

void updt(int pos,ll mod){
	while(pos < N){
		ft[pos] += mod;
		pos += pos & -pos;
	}
}

ll query(int pos){
	ll ret = 0;
	while(pos > 0){
		ret += ft[pos];
		pos -= pos & -pos;
	}
	return ret;
}
void so(int test){
	int n,k;
	cin >> n >> k;
	fill(ft,ft+N,0);
	map<int,vii> seg;
	forn(i,n){
		int l,r;
		cin >> l >> r;
		updt(l,1);
		updt(r+1,-1);
		seg[l].push_back({r,i+1});
	}
	for(auto &[nu,vec]:seg)
		sort(all(vec));

	vi ans;
	for(auto [nu,vec]:seg){
		ll va = query(nu);
		while(va > k and !vec.empty()){
			updt(nu,-1);
			updt(vec.back().fi +1,1);
			ans.push_back(vec.back().se);
			vec.pop_back();
			va--;
		}
	}
	cout << sz(ans) << '\n';
	sort(all(ans));
	for(auto x : ans)cout << x << ' ';
	cout << '\n';
}

int main(){
        ios::sync_with_stdio(false);
        cin.tie(0);
        int tt = 1;
        int test = 1;
        while(tt--) so(test++);
        return 0;
}

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
#define pb push_back
#define imp(v) {for(auto x:v)cout<<x<<' ';cout<<'\n';}


void so(int test){
	int n,f;
	cin >> n >> f;
	set<array<int,3>> s;// l,r,id;
	vector<array<int,3>> remain;
	forn(i,n){
		int l,r;
		cin >> l >> r;
		if( r < f){
			remain.push_back({l,r,i});
			continue;
		}
		s.insert({l,r,i});
	}
	ll ans = 0;
	int pos = f, reach = f;

	vi res;

	for(auto [l,r,id] : s){
		if(reach < l){

			ans += l - reach;
			ans += r -l ;

			pos = l;
			reach = r;

			res.push_back(id);
			continue;
		}
		if(r > reach){
			pos = l;
			reach = r;
			ans += r - l;
			res.push_back(id);
		}else{
			remain.push_back({l,r,id});
		}
	}
	sort(all(remain),[](auto a, auto b){
			auto [l1,r1,id1] = a;
			auto [l2,r2,id2] = b;
			return r1 > r2;
			});
	for(auto [l,r,id] : remain){
		res.push_back(id);
		ans += r - l;
	}
	cout << ans << '\n';
	forn(i,n)
		cout << res[i] + 1 << ' ';
	cout << '\n';
	//cout << "====== test " << test << '\n';
	//cout << sz(remain) << ' ' << sz(s) << '\n';
	//cout << ans << '\n';
}

int main(){
        ios::sync_with_stdio(false);
        cin.tie(0);
        int tt = 1;
	cin >> tt;
        int test = 1;
        while(tt--) so(test++);
        return 0;
}


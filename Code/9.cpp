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

void so(int test){
	int n,m;
	cin >> n ;
	set<array<int,4>> s;// l,r,center,id
	forn(i,n){
		int x,ra;
		cin >> x >> ra;
		int l = x - ra, r = x + ra;
		s.insert({l,r,x,i});
	}
	cin>> m;
	vi ans(n,-1);
	auto che = [&](int x, int y, int r , int center){
		return y*1ll*y + (x-center)*1ll*(x-center) <= r*1ll*r ;
	};
	forn(i,m){
		int x,y;
		cin >> x >> y;
		auto it = s.upper_bound({x,(1<<30),-1,-1});
		if(it == s.begin()) continue;
		it--;
		auto [l,r,center,id] = *it;
		if(x > r)continue;
		if(x < l)continue;
		if(che(x,y,r - center,center) and ans[id] == -1){
			ans[id] = i + 1;
		}
		if(it == s.begin())
			continue;
		it--;
		auto [uu,vv,cc,id_] = *it;
		l = uu;
		r = vv;
		id = id_;
		center = cc;
		if(x > r)continue;
		if(x < l)continue;
		if(che(x,y,center - l,center) and ans[id] == -1){
			ans[id] = i + 1;
		}
	}
	int co = 0;
	forn(i,n)co += ans[i] != -1;
	cout << co << '\n';
	forn(i,n){
		cout << ans[i] << ' ';
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


#include<bits/stdc++.h>

using namespace std;

using ll = long long;

#define forn(i,n) for(int i=0 ;i<int(n);i++)
#define forsn(i,s,n) for(int i=int(s);i<int(n);i++)

#define vi vector<int>
#define vl vector<ll>
#define ii pair<ll,ll>
#define vii vector<ii>
#define fi first
#define se second
#define all(v) (v).begin(),(v).end()
#define rall(v) (v).rbegin(),(v).rend()
#define sz(v) (int)(v).size()

void so(int test){
	int n,m;
	cin >> n>> m;
	multiset<ii> s;
	forn(i,n){
		int e,r;
		cin >> e >> r;
		s.insert({e,r});
	}
	multiset<ii> siu;
	auto f= [&](ll energy)->bool{
		int ele = 0;
		ll acu = 0;
		for(auto it = s.rbegin(); it != s.rend(); it++){
			auto [e,r] = *it;
			if(r >= ele){
				siu.insert({r,e});
				acu += e;
				ele++;
			}
			for(auto it2 = siu.begin();it2 != s.end();){
				auto [ri,ei] = *it2;
				if (ri < ele -1 ){
					it2 = siu.erase(it2);
					acu -= ei;
					continue;
				}
				it2++;
			}
			if(r >= ele){
				siu.insert({r,e});
				acu += e;
				ele++;
			}
			if(acu >= energy)return true;
		}
		if(acu >= energy)return true;
		return false;
	};
	forn(i,m){
		int e,r;
		cin >> e >> r;
		s.insert({e,r});
		ll lo = 0, lf = (1ll<<60),mid;
		while(lf - lo > 1){
			mid = lo + (lf-lo)/2;
			if(f(mid))lo = mid;
			else lf = mid;
		}
		cout << lo << ' ';
		s.erase(s.find({e,r}));
	}
	cout << '\n';
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


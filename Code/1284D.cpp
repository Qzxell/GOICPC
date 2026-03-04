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
#define all(v) (v).begin(),(v).end()
#define rall(v) (v).rbegin(),(v).rend()
#define sz(v) (int)(v).size()

void so(int test){
	int n;
	cin >> n;
	vector<array<int,3>> sa(n),sb(n);

	vi uwu;
	forn(i,n){
		int l1,r1,l2,r2;
		cin >> l1 >> r1 >> l2 >> r2;
		uwu.push_back(l1);
		uwu.push_back(l2);
		uwu.push_back(r1);
		uwu.push_back(r2);
		sa[i] = {l1,r1,i};
		sb[i] = {l2,r2,i};
	}
	sort(all(uwu));
	uwu.erase(unique(all(uwu)),uwu.end());
	int tot = sz(uwu);
	auto get = [&](int nu){
		return lower_bound(all(uwu),nu) - uwu.begin();
	};
	for(auto &[l,r,id] :sa){
		l = get(l);
		r = get(r);
	}
	for(auto &[l,r,id] :sb){
		l = get(l);
		r = get(r);
	}
	auto solve = [&](auto s1, auto s2)->bool{
		sort(all(s1));
		set<array<int,3>> sl,sr;
		vi in[tot+4];
		vi ou[tot+4];
		for(auto [l,r,id] : s1){
			in[l].push_back(id);
			ou[r+1].push_back(id);
		}
		for(int i = 0 ; i < tot + 4; i++){
			for(auto id : ou[i]){
				auto [li,ri,id_] = s2[id];
				sl.erase(sl.find(s2[id]));
				sr.erase(sr.find({ri,li,id_}));
			}
			for(auto id : in[i]){
				auto [li,ri,id_] = s2[id];
				if(sl.empty()){
					sl.insert(s2[id]);
					sr.insert({ri,li,id_});
					continue;
				}
				auto [lb,rb,_] = *sl.rbegin();
				//auto [le,re,__] = *sl.rbegin();
				auto [re,le,ide] = *sr.begin();
				if(ri < lb || re < li){
					return false;
				}
				sl.insert(s2[id]);
				sr.insert({ri,li,id_});
			}
		}
		return true;
	};
	cout << (solve(sa,sb) && solve(sb,sa) ? "YES\n" : "NO\n" ) ;
}

int main(){
        ios::sync_with_stdio(false);
        cin.tie(0);
        int tt = 1;
        int test = 1;
        while(tt--) so(test++);
        return 0;
}


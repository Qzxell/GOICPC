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

void so(int test){
	string s;
	cin >> s;
	reverse(all(s));
	map<char,set<int>> m;
	int id = 0;
	for(auto x : s){
		m[x].insert(id);
		id++;
	}
	vector<vi> ans;
	string pal = "CPCI";
	while(true){
		int ind = -1;
		bool ok = 1;
		vi res;
		for(auto x : pal){
			auto ind2 = m[x].lower_bound(ind);
			if(ind2 == m[x].end()){
				ok = 0;
				break;
			}
			res.push_back(*ind2);
			ind = *ind2;
		}
		if(!ok)break;
		forn(i,4){
			auto it = m[pal[i]].find(res[i]);
			if(it != m[pal[i]].end())
				m[pal[i]].erase(it);
		}
		ans.push_back(res);
	}

	cout << sz(ans) << '\n';
	for(auto x : ans){
		reverse(all(x));
		for(auto u : x){
			cout << sz(s) - u  << ' ' ;
		}
		cout << '\n';
	}
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


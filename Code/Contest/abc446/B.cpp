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
	cin >> n >> m;
	vector<vi> w(n);
	forn(i,n){
		int tm;
		cin >> tm;
		vi uwu(tm);
		forn(j,tm)cin >> uwu[j];
		reverse(all(uwu));
		w[i] = uwu;
	}
	set<int> s;
	forn(i,m)s.insert(i+1);
	vi ans(n,0);
	forn(i,n){
		while(!w[i].empty() and s.count(w[i].back()) == 0){
			w[i].pop_back();
		}
		if(sz(w[i]) > 0){
			ans[i] = w[i].back();
			auto it = s.find(ans[i]);
			s.erase(it);
		}
	}
	forn(i,n)cout << ans[i] << '\n';
}

int main(){
        ios::sync_with_stdio(false);
        cin.tie(0);
        int tt = 1;
        int test = 1;
        while(tt--) so(test++);
        return 0;
}


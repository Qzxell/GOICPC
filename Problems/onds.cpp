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
vector<vi> divisor(N);
int vis[N];

void so(int test){
	int n;
	cin >> n;
	vi v(n);
	fill(vis,vis+N,0);
	set<int> s;
	forn(i,n){
		int x ;
		cin >> x;
		v[i] = x;
		vis[x] = 1;
	}
	int ans = *max_element(all(v));
	sort(all(v));
	v.erase(unique(all(v)),v.end());
	vi del;

	for(auto x : v){
		for(auto divi : divisor[x]){
			if(vis[divi]){
				auto it = s.find(divi);
				if(it != s.end()){
					s.erase(it);
					del.push_back(divi);
				}
			}
		}
		int uwu1 = (sz(s) > 0 ? *s.rbegin() : 0);
		for(auto divi : divisor[uwu1]){
			if(vis[divi]){
				auto it = s.find(divi);
				if(it != s.end()){
					s.erase(it);
					del.push_back(divi);
				}
			}
		}
		int uwu2 = (sz(s) > 0 ? *s.rbegin() : 0);
		ans = max(ans,x + uwu1 + uwu2);
		while(!del.empty()){
			s.insert(del.back());
			del.pop_back();
		}
		s.insert(x);
	}
	cout << ans << '\n';

}

void init(){
	forsn(i,2,N){
		for(int j = i ; j < N ; j+= i){
			divisor[j].push_back(i);
		}
	}
}

int main(){
        ios::sync_with_stdio(false);
        cin.tie(0);
        int tt = 1;
	init();
	cin >> tt;
        int test = 1;
        while(tt--) so(test++);
        return 0;
}

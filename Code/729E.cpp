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
	int n,s;
	cin >> n >> s;
	s--;
	vi v(n);
	forn(i,n)cin >> v[i];
	int ans  = 0;
	if(v[s] != 0)ans = 1;

	vi vis(n+1,0),gar(n+1,0),sob(n+1,0),huecos(n+1,0);
	forn(i,n)if(i != s){
		if(v[i] == 0){
			ans++;
			continue;
		}
		vis[v[i]]++;
	}
	forsn(i,n+1)
		sob[i] = sob[i-1] + max(v[i]-1,0)
	for(int i = n - 1; i >= 0; i--)
		gar[i] = gar[i+1] + vis[i];
}

int main(){
        ios::sync_with_stdio(false);
        cin.tie(0);
        int tt = 1;
        int test = 1;
        while(tt--) so(test++);
        return 0;
}


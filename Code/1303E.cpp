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
	string s,t;
	cin >> s >> t;
	int n =sz(s);
	int n_t =sz(t);

	int ind = 0;
	forn(i,n) if(ind < n_t and s[i] == t[ind]) ind++;
	if(ind == n_t){
		cout << "YES\n";
		return;
	}

	int INF = (1<<30);

	vi m[26];
	vector<vi> vis(n+1,vi(n+1,0));
	vector<vi> dp(n+1,vi(n+1,INF));

	forn(i,sz(s))
		m[s[i]-'a'].push_back(i);

	int in2 = -1;
	int in1= -1;
	auto rec = [&](auto && self,int l1,int l2)->int{
		if( l1 < 0 and l2 < in2) return -1;
		if(vis[l1+1][l2+1])return dp[l1+1][l2+1];

		vis[l1+1][l2+1] = 1;

		int ind1,ind2,r1,r2,ret_ind1 = INF,ret_ind2 = INF;

		if(l1 >= 0){
			ind1 = self(self, l1-1 , l2);
			r1 = upper_bound(all(m[t[l1]-'a']),ind1) - m[t[l1]-'a'].begin();
			ret_ind1 = (r1 == sz(m[t[l1] - 'a']) ? INF : m[t[l1]-'a'][r1]);
		}
		if(l2 >= in2){
			ind2 = self(self, l1, l2-1);
			r2 = upper_bound(all(m[t[l2]-'a']),ind2) - m[t[l2]-'a'].begin();
			ret_ind2 = (r2 == sz(m[t[l2] - 'a']) ? INF : m[t[l2]-'a'][r2]);
		}

		return dp[l1+1][l2+1] = min(ret_ind1, ret_ind2);
	};
	auto can = [&](int in)->bool{
		forn(i,n+1) forn(j,n+1)vis[i][j] = 0;
		in2 = in+1;
		in1 = 0;
		return rec(rec,in, n_t-1) < n;
	};

	forsn(i,0,n_t-1) if(can(i)){
		cout << "YES\n";
		return;
	}
	cout << "NO\n";
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


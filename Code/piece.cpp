#include<bits/stdc++.h>

using namespace std;

using ll = long long;

#define forn(i,n) for(int i=0 ;i<int(n);i++)
#define forsn(i,s,n) for(int i=int(s);i<int(n);i++)

#define vi vector<int>
#define vl vector<ll>
#define all(v) (v).begin(),(v).end()
#define sz(v) (int)(v).size()

const int N = 305;
int w[N];
vector<int> dp(N*N,0),n_dp;

pair<int,int> fun(string s){
	int n = sz(s);
	stack<char> q;
	forn(i,n){
		if(q.empty()){
			q.push(s[i]);
			continue;
		}
		if(q.top() == '(' && s[i] == ')'){
			q.pop();
			continue;
		}
		q.push(s[i]);
	}
	int se = 0, fi = 0;
	while(!q.empty()){
		if(q.top() == '(')se++;
		else fi++;
		q.pop();
	}
	return {fi,se};
}

void so(int test){
	int n;
	cin >> n ;
	string s;
	vector<pair<int,int>> v(n);
	vector<int> pos,neg,tot;
	forn(i,n){
		cin >> s;
		v[i] = fun(s);
		if(v[i].second - v[i].first >= 0)
			pos.push_back(i);
		else
			neg.push_back(i);
		w[i] = sz(s);
	}
	sort(all(pos), [&](auto u, auto t){ return v[u].first < v[t].first; });
	sort(all(neg), [&](auto u, auto t){
		int v1 = v[u].first + max(0,v[t].first - v[u].second);
		int v2 = v[t].first + max(0,v[u].first - v[t].second);
		return v1 < v2;
			});
	for(auto x : pos)
		tot.push_back(x);
	for(auto x : neg)
		tot.push_back(x);

	forn(j,300*n)dp[j] = -1;
	dp[0] = 0;
	forn(i,n){
		auto [a,b] = v[tot[i]];
		int apo = b - a;
		n_dp = dp;
		forn(j,300*n)if(dp[j] != -1 && j + apo >= 0 && j >= a){
			n_dp[j + apo] = max(n_dp[j + apo], dp[j] + w[tot[i]]);
		}
		swap(n_dp,dp);
	}
	int ans = dp[0];
	cout << ans << '\n';
}

int main(){
        ios::sync_with_stdio(false);
        cin.tie(0);
        int tt = 1;
        int test = 1;
        while(tt--) so(test++);
        return 0;
}


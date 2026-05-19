#include<bits/stdc++.h>

using namespace std;

using ll = long long;

#define forn(i,n) for(int i=0 ;i<int(n);i++)
#define forsn(i,s,n) for(int i=int(s);i<int(n);i++)

#define all(v) (v).begin(),(v).end()
#define sz(v) (int)(v).size()

const int MOD = 998244353;

int mul(int a, int b){
	return a*1ll*b%MOD;
}

void so(int test){
	int n,k;
	cin >> n >> k;
	int m = 1;
	vector<int> v(n);
	forn(i,n)
		cin >> v[i];
	sort(all(v));
	stack<int> qu;
	forn(i,n)
		qu.push(v[i]);
	int ans = v[n-1];
	while(sz(qu) >= k){
		int u = 1;
		bool ok = 0;
		forn(i,k){
			int nu = qu.top();qu.pop();
			if(nu == 0) ok = 1;
			u = mul(u, nu);
		}
		if(ok)break;
		ans = u;
		qu.push(u);
	}
	cout << ans << '\n';

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


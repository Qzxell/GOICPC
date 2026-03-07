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
	int n;
	cin >> n;
	vector<vi> v(n+1);
	vi a(n);
	forn(i,n){
		int x;
		cin >> x;
		a[i] = x;
		v[x].push_back(i);
	}
	ll ans = 0;
	for(auto vec : v){
		for(int i = 0 ; i < sz(vec) - 1; i++){
			int cnt = vec[i+1] - vec[i] - 1 ;
			ans += cnt *1ll* (sz(vec) - 1 - i)*(i+1);
		}
	}
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


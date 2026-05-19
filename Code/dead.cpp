#include<bits/stdc++.h>

using namespace std;

using ll = long long;

#define forn(i,n) for(int i=0 ;i<int(n);i++)
#define forsn(i,s,n) for(int i=int(s);i<int(n);i++)

#define vi vector<int>
#define vl vector<ll>
#define all(v) (v).begin(),(v).end()
#define sz(v) (int)(v).size()


void so(int test){
	int n;
	cin >> n;
	vector<pair<int,int>> v(n);
	for(auto &[a,d] : v)
		cin >> a >> d;
	sort(all(v));
	ll cnt = 0;
	ll ans = 0;
	for(auto [a,d] : v){
		cnt += a;
		ans += d - cnt;
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


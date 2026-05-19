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
	ll n,k;
	cin >> n >> k;
	multiset<ll> q,r;
	forn(i,n){
		ll x;
		cin >> x;
		q.insert(x);
	}
	forn(i,n){
		ll x;
		cin >> x;
		r.insert(x);
	}
	int ans = 0;
	forn(i,n){
		auto it = r.begin();
		ll y = *it + 1;
		ll lim_s = (k-*it)/y;
		r.erase(it);
		auto it2 = q.upper_bound(lim_s);
		if(it2 != q.begin()){
			it2--;
			//cout << *it2 << ' ' << y  << '\n';
			q.erase(it2);
			ans++;
		}
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


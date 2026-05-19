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
	int n,k;
	cin >> n >> k;
	if(n == 1){
		int u;
		cin >> u;
		if(k <= u){
			cout << k - 1 << '\n';
			return;
		}
		cout << k  << '\n';
		return;
	}
	int gc = 0;
	forn(i,n){
		int x;
		cin >> x;
		gc= gcd(gc,x);
	}
	if(gc == 1){
		cout << n + k - 1 << '\n';
		return;
	}
	ll lo = 0, lf = 2e9, mid;

	auto f = [&](ll nu)->int{
		ll cnt = nu/gc + 1;
		return nu + 1 - min<ll>(n,cnt);
	};

	while(lf - lo > 1){
		mid = (lo+lf)/2;
		if(f(mid) >= k)
			lf = mid;
		else 
			lo = mid;
	}
	cout << lf << '\n';
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


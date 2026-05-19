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


const ll INF = (1e18) + 5;

set<ll> num;

void init(){
	int lim = 1e6 + 1;
	forsn(B,2,lim){
		ll pot = 1;
		ll su = 0;
		int ord = 0;
		while(true){
			su += pot;

			if(ord >= 2)
				num.insert(su);

			ord++;
			if(pot <= INF/B)
				pot *= B;
			else break;
		}
	}
}

void so(int test){
	ll n;
	cin >> n;
	if(num.count(n)){
		cout << "YES\n";
		return;
	}
	auto fu = [&](ll nu)->ll{
		return nu*nu + nu + 1;
	};
	ll lo = 0 ,lf = 1e9 + 1, mid;
	while(lf - lo > 1){
		mid = (lf+lo)/2;
		if(fu(mid) >= n)lf = mid;
		else lo = mid;
	}
	if(fu(lf) == n && lf >= 2){
		cout << "YES\n";
		return;
	}
	cout << "NO\n";
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


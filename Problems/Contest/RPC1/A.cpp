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
	int n,k;
	cin >> n >> k;
	vi v(n);
	forn(i,n)cin >> v[i];

	int ma = *max_element(all(v)) ;
	ll lo = ma - 1,lf = 2e9 ,mid;
	auto f = [&](ll ans){
		int co = 1;
		ll acu = 0;
		forn(i,n){
			if(v[i] > ans)return false;
			if(acu == 0){
				acu = v[i];
			}else if(acu + 1 + v[i] <= ans){
				acu += 1 + v[i];
			}else{
				co++;
				acu = v[i];
			}
		}
		return co <= k;
	};
	while(lf- lo > 1){
		mid = ( lo + lf)/2;
		if(f(mid)) lf = mid;
		else lo = mid;
	}
	cout << lf << '\n';
}

int main(){
        ios::sync_with_stdio(false);
        cin.tie(0);
        int tt = 1;
        int test = 1;
        while(tt--) so(test++);
        return 0;
}


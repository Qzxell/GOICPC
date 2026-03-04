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
	int n,h,k;
	cin >> n >> h >> k;
	vi v(n);
	vl ps(n+1,0);
	forn(i,n)cin >> v[i],ps[i+1] = ps[i] + v[i];
	ll acu = accumulate(all(v),0ll);
	ll ans = (h / acu)*n + k*max<ll>(0,(h / acu) - 1);
	ll sob = h % acu;
	if(sob == 0){
		cout << ans << '\n';
		return;
	}
	if((h/acu) > 0)
		ans += k;
	ll sob1 = sob;
	ll ans1 = ans;
	forn(i,n){
		ans1++;
		sob1 -= v[i];
		if(sob1 <= 0)break;
	}
	int lo = -1, lf = n-1,mid;
	auto f = [&](int ind){
		if(ind == n-1){
			return acu >= sob;
		}
		ll uwu = ps[ind+1] - *min_element(v.begin(),v.begin()+ind+1) + *max_element(v.begin()+ind+1,v.end());
		return (uwu >= sob or ps[ind+1] >= sob);
	};

	while(lf - lo > 1){
		mid = (lo+lf)/2;
		if(f(mid)) lf = mid;
		else lo = mid;
	}
	cout << min(ans1, ans + lf + 1) << '\n';
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


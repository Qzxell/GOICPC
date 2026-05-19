#include<bits/stdc++.h>

using namespace std;

using ll = long long;

#define forn(i,s,n) for(int i=int(s);i<int(n);i++)

#define all(v) (v).begin(),(v).end()
#define rall(v) (v).rbegin(),(v).rend()
#define sz(v) (int)(v).size()

void so(int test){
	int n;
	cin >> n;
	int ga = n * sqrt(n) * (__lg(n));
	vector<int> a(n),b(n),gc(n);
	forn(i,0,n)cin >> a[i];
	forn(i,0,n)cin >> b[i];

	forn(i,0,n-1){
		gc[i] = gcd(a[i],a[i+1]);
	}
	int ans = 0;
	forn(i,0,n){
		if(i == 0){
			if(a[i] > gc[i])
				ans++;
			continue;
		}
		if(i == n - 1){
			if(a[i] > gc[n-2])
				ans++;
			continue;
		}
		if(lcm(gc[i-1],gc[i]) < a[i]){
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


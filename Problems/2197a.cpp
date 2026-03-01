#include<bits/stdc++.h>

using namespace std;

using ll = long long;

#define forn(i,n) for(int i=0 ;i<int(n);i++)
#define forsn(i,s,n) for(int i=int(s);i<int(n);i++)
#define dforn(i,n) for(int i=int(n)-1;i>=0;i--)
#define dforsn(i,s,n) for(int i=int(n)-1;i>=int(s);i--)

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
	vi v(n);
	forn(i,n)
		cin >> v[i];
	ll ans = 0;
	forn(i,n){
		forn(j,sqrt(n)+3){
			if(j > v[i])continue;
			ll dis = v[i]*1ll*j;
			if(dis > n)continue;
			if(i + dis < n and v[i+dis] == j)
				ans++;
			if(j != v[i] and i - dis >= 0 and v[i-dis] == j)
				ans++;
		}
	}
	cout << ans << '\n';
	
}

int main(){
        ios::sync_with_stdio(false);
        cin.tie(0);
        int tt = 1;
	cin >>  tt;
        int test = 1;
        while(tt--) so(test++);
        return 0;
}

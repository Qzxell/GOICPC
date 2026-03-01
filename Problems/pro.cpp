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
	vector<vi> pos_nu(n+1);
	forn(i,n){
		int nu;
		cin >> nu;
		if(nu > n)continue;
		pos_nu[nu].push_back(i);
	}
	ll ans = 0;
	forsn(i,1,sqrt(n)+2){
		for(int j = 1 ; j *1ll*i <= n ; j++){
			if(j < i)continue;
			int ind = 0;
			int dis = i*j;
			for(auto id : pos_nu[i]){
				while(ind < sz(pos_nu[j])){
					if(pos_nu[j][ind] - id >= dis)
						break;
					ind++;
				}
				if(ind < sz(pos_nu[j]))
					if(pos_nu[j][ind] - id == dis)
						ans++;

			}
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

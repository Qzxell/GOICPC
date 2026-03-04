#include<bits/stdc++.h>

using namespace std;

using ll = long long;

#define forn(i,n) for(ll i=0 ;i<ll(n);i++)
#define forsn(i,s,n) for(int i=int(s);i<int(n);i++)

#define vi vector<int>
#define vl vector<ll>
#define ii pair<ll,ll>
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
	vi m(n);
	vi ord(n);
	forn(i,n)cin >> v[i];
	int co = 0;
	forn(i,n){
		if(i % k == 0 )co++;
		m[i] = co;
		ord[i] = i;
	}
	sort(all(v));
	ll acu = 0;
	for(int i = 0; i < n;i++){
		cout << v[i] *m[i] << '\n';
		acu += v[i]*m[i] ;
		//cout << acu << ' ';
	}
	cout << acu << '\n';
	cout << '\n';
}

int main(){
        ios::sync_with_stdio(false);
        cin.tie(0);
        int tt = 1;
        int test = 1;
        while(tt--) so(test++);
        return 0;
}


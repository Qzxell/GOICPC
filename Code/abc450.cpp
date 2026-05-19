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

const ll INF = 1e18 + 100;

ll sum(ll a, ll b){
	if(a >= INF or b >= INF)
		return INF;
	return min(a + b,INF);
}

string x,y;
const int N = 1e4 + 5;
ll fibo[26][101];
ll psx[26][N];
ll psy[26][N];
ll fi_lon[101];
vi frex(26,0),frey(26,0);

void init(){
	forn(i,26){
		fibo[i][0] = frex[i];
		fibo[i][1] = frey[i];
		forsn(j,2,101)
			fibo[i][j] = sum(fibo[i][j-1] , fibo[i][j-2]);
	}
	fi_lon[0] = sz(x);
	fi_lon[1] = sz(y);
	forsn(j,2,101)
		fi_lon[j] = sum(fi_lon[j-1] , fi_lon[j-2]);
	forn(i,26){
		forn(j,sz(x)){
			psx[i][j] = (j-1 >= 0 ? psx[i][j-1] : 0) + (x[j] == (char)('a' + i));
		}
		forn(j,sz(y)){
			psy[i][j] = (j-1 >= 0 ? psy[i][j-1] : 0) + (y[j] == (char)('a' + i));
		}
	}
}

ll query(ll l,int esimo ,int ch){
	if(l < 1)
		return 0;
	if(esimo == 0){
		return psx[ch][l-1];
	}
	if(esimo == 1){
		return psy[ch][l-1];
	}
	ll ret = 0;
	ll l1 = fi_lon[esimo-1];
	ll l2 = fi_lon[esimo-2];
	if( l > l1){
		ret = sum(ret,fibo[ch][esimo-1]);
		l -= l1;
		ret = sum(ret,query(l,esimo - 2,ch));
		return ret;
	}
	return query(l,esimo - 1,ch);
}
ll cnt(ll l, ll r,int ch){
	l -= 1;
	return query(r,100,ch) - query(l,100,ch);
}


void so(int test){
	cin >> x >> y;

	for(auto a: x)
		frex[a - 'a']++;
	for(auto a: y)
		frey[a - 'a']++;
	init();

	int q;
	cin >> q;
	forn(i,q){
		ll l,r;
		char c;
		cin >> l >> r >> c;
		int e = 0;
		while(fi_lon[e] < l) e++;
		ll ans = cnt(l,r,c-'a');
		cout << ans << '\n';
	}
}


int main(){
        ios::sync_with_stdio(false);
        cin.tie(0);
        int tt = 1;
	// cin >> tt;
        int test = 1;
        while(tt--) so(test++);
        return 0;
}


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

const int mod = 1e9 + 7;

ll binpow(int b,int e){
	ll ret = 1;
	while( e > 0){
		if( e&1){
			ret = ret * b %mod;
		}
		b = b *1ll* b%mod;
		e >>= 1;
	}
	return ret;
}
void so(int test){
	int a,b,c;
	cin >> a >> b >> c;
	forn(i,31) if((c>>i)&1){
		a = binpow(a,
	}
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


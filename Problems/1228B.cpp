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

const int MOD = 1e9 + 7;

ll fp(int b, int e){
	ll ret = 1;
	while( e > 0){
		if( e&1){
			ret = ret * 1ll * b %MOD;
		}
		b = b *1ll* b  %MOD;
		e >>= 1;
	}
	return ret;
}

void so(int test){
	int h,w,x;
	cin >> h >> w;
	vector<vi> ma(h,vi(w,0));
	vi H(h,0),W(w,0);
	forn(i,h){
		cin >> x;
		H[i] = x;
		forn(j,min(x,w))
			ma[i][j] = 1;
	}
	forn(i,w){
		cin >> x;
		W[i] = x;
		forn(j,min(x,h))
			ma[j][i] = 1;
	}
	forn(i,h){
		int acu = 0;
		forn(j,w){
			if(ma[i][j] == 1)
				acu += ma[i][j];
			else 
				break;
		}
		if(acu != H[i]){
			cout << 0 << '\n';
			return;
		}
	}
	forn(j,w){
		int acu = 0;
		forn(i,h){
			if(ma[i][j] == 1)
				acu += ma[i][j];
			else 
				break;
		}
		if(acu != W[j]){
			cout << 0 << '\n';
			return;
		}
	}
	forn(i,h){
		forn(j,min(H[i]+1,w))
			ma[i][j] = 1;
	}
	forn(i,w){
		forn(j,min(W[i]+1,h))
			ma[j][i] = 1;
	}
	ll acu = 0;
	forn(i,h) forn(j,w) acu += 1 - ma[i][j];
	cout << fp(2,acu) << '\n';
}

int main(){
        ios::sync_with_stdio(false);
        cin.tie(0);
        int tt = 1;
        int test = 1;
        while(tt--) so(test++);
        return 0;
}

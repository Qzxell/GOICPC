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

const int N = 32;
ll dp[N][3][2][2];// dp[pos][estado][ganan en x][ganan en y]
	       // aca estoy donde propago

void so(int test){
	ll x,y;
	cin >> x >> y;

	forn(i,32) forn(est,3) forn(g1,2)forn(g2,2)
	{
		int b1,b2;
		b1 = ((x>>i)&1);
		b2 = ((y>>i)&1);
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


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

const int MOD = 1e9 + 7;

int mul(int a, int b){
	return a*1ll*b%MOD;
}

int add(int a, int b){
	return (a+0ll+b)%MOD;
}

ll fp(int b,int e){
	ll ret = 1;
	while( e > 0){
		if( e&1){
			ret = mul(ret , b);
		}
		b = mul(b , b);
		e >>= 1;
	}
	return ret;
}

int solve (int l, int r,int k){
	ll u1 = 0,u2 = 0;
	for(int i = l ;i <= r;i++)u1+=i;
	u2 = r-l+1;
	int ans = mul(mul(u1,fp(u2,k-1)),(fp(10,k)+MOD-1)%MOD);
	ans = mul(ans,fp(9,MOD-2));
	return ans;
}

void so(int test){
	cout << solve(1,4,2) << '\n';
}

int main(){
        ios::sync_with_stdio(false);
        cin.tie(0);
        int tt = 1;
        int test = 1;
        while(tt--) so(test++);
        return 0;
}


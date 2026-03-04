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

const int MX = 650;
const int off = 2e5 + 10000;
const int X = 2*off + 5;

bitset<X> dp[MX];

int n;
int x;
//int dp[X][MX];

//bool rec(int acu, int pos){
	//if(pos == n + 1)return acu == x;
	//if(~dp[acu + off][pos])return dp[acu + off][pos];
	//bool ret = 0;
	//ret |= rec(acu + pos,pos+1);
	//ret |= rec(acu - pos,pos+1);
	//return dp[acu + off][pos] = ret;
//}

vi ans ;
void buil(int acu, int pos){
	if(pos == 1)return ;
	//if(~dp[acu + off][pos])return dp[acu + off][pos];
	if(dp[pos-1][acu + pos + off]){
		ans.push_back(-pos);
		return buil(acu + pos , pos-1);
	}
	ans.push_back(pos);
	return buil(acu - pos , pos-1);
}

void so(int test){
	ans.clear();
	cin >> x;
	n = 1;
	ll lim_s,lim_i;
	auto f =[&](int nu)->bool{
		lim_s = (nu*1ll*(nu+1))/2;
		lim_i = -(nu*1ll*(nu+1))/2 + 2;
		if(x == lim_s - 2 )return false;
		if(x == lim_i + 2 )return false;
		return lim_i <= x and x <= lim_s and ((lim_s&1) == (x&1));
	};
	while(!f(n)){
		n++;
	}
		//cout << lim_i << ' ' << lim_s  << '\n';
	//200000return;
	int lim = max(lim_s,abs(lim_i)) + 5;

	dp[1][1+off] = 1;

	//forsn(i,1,n){//pos
	for(int i = 2; i <= n ;i++){
		dp[i] = ((dp[i-1]<<i) | (dp[i-1] >> i) );
	}

	//cout << "=====================\n";
	////assert(rec(1,2));
	//forn(j,n+1) {
		//cout << j << '\n';
		//for(int i = -lim;i <= lim ; i++)
			//cout << i << " " << dp[j][i+off]  <<" \n  ";
		//cout << '\n';
		//cout << '\n';
	//}
	buil(x,n);
	cout << n << '\n';
	ans.push_back(1);
	reverse(all(ans));
	for(auto x : ans){
		if(x > 0 and x != 1)cout << "+";
		cout << x ;
	}
	forn(j,n+1){
		dp[j].reset();
	}
	cout << '\n';
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

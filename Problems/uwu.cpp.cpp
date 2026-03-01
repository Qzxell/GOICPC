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

const int N = 1e6 + 5;
int lim;
int ft[N];

int query(int pos){
	int ret = -1;
	while(pos > 0){
		ret = max(ret,ft[pos]);
		pos -= pos & - pos;
	}
	return ret;
}
void updt(int pos,int modi){
	while(pos <= lim){
		ft[pos] = max(ft[pos],modi);
		pos += pos & - pos;
	}
}

void so(int test){
	int n;
	cin >> n;
	lim = n + n + 5;
	forn(i,lim)ft[i] = -1;

	vii seg(n);
	vi com;

	for(auto &[a,b]:seg){
		cin >> a >> b;
		com.push_back(a);
		com.push_back(b);
	}
	sort(all(com));
	com.erase(unique(all(com)),com.end());

	for(auto &[a,b]:seg){
		a = lower_bound(all(com),a) - com.begin();
		b = lower_bound(all(com),b) - com.begin();
	}
	auto ga = [&](ii a , ii b)->bool{
		if(a.fi == b.fi)
			return a.se > b.se;
		return a < b;
	};
	sort(all(seg),ga);
	vi dp(n+1,1);
	vi prev(n+n+2,-1);
	forn(i,n){
		auto [a,b] = seg[i];
		int ma = query(b-1);
		prev[i] = ma;
		updt(b,i);
	}
	forn(i,n) if(prev[i] != -1){
		dp[i] += dp[prev[i]];
	}
	int ans = *max_element(all(dp));
	cout << ans << '\n';
}

int main(){
        ios::sync_with_stdio(false);
        cin.tie(0);
        int tt = 1;
        int test = 1;
        while(tt--) so(test++);
        return 0;
}


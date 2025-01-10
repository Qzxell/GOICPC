#include <bits/stdc++.h>

using namespace std;

using ii = pair<int,int>;
using vii = vector<ii>  ;
using vi = vector<int>  ;
#define ln  '\n'
#define ll long long
#define pb push_back
#define fi first
#define se second
#define sz(v) ((int)(v).size())
#define all(v) (v).begin(),(v).end()
#define rall(v) (v).rbegin(),(v).rend()
#define f(i, a, b)  for(ll i = (ll)a; i < (ll)b; i++)
#define fer(i, b, a)  for(ll i = (ll)a - 1; i >= (ll)b; i--)

void so(int test){
	int n,m;
	cin >> n >> m;
	vii bl;
	vii whi;
	f(i,0,m){
		int x,y;
		char c;
		cin >> x >> y >> c;
		if(c == 'B'){
			bl.pb({x,y});	
		}else whi.pb({x,y});
	}
	sort(all(bl));
	int le = sz(bl);
	if(bl.empty()){
		cout << "Yes";
		return;
	}
	if(le >= 2 ){
		for(int i = le - 2 ; i >= 0; i--){
			if(i + 1 < le and bl[i+1].se > bl[i].se)bl[i].se = bl[i+1].se;
		}
	}
	f(i,0,sz(whi)){
		int lo = 0 ,lf =  le -1;
		int x = whi[i].fi ;
		int y = whi[i].se;
		int mid;
		while(lo<lf){
			mid = (1+lo+lf)/2;
			if(bl[mid].fi <= x){
				lo = mid ;
			}else lf = mid-1;
		}

		if(bl[lo].se >= y){
			cout << "No";
			return;
		}
	}
	cout << "Yes" ;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	int tt = 1;
	int test = 1;
	while (tt--){
		so(test++);
	}
	return 0;
}

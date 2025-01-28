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
	int n;
	cin >> n;
	vi v(n);
	vi fre(n+1);
	vii pos(n+1);
	bool ans = 0;
	vi vis(n+3,0);
	f(i,0,n){
		cin >> v[i];
		fre[v[i]]++;
		vis[v[i]] = 1;
		if(fre[v[i]] == 1){
			pos[v[i]].fi = i;
		}else{
			pos[v[i]].se = i;
		}
		if(fre[v[i]] > 2){
			ans = 1;
		}
	}
	if(ans){
		cout << "NO" << ln;
		return;
	}
	vi per1(n);
	vi per2(n);
	int mex = 1;
	bool yes = 1;
	f(i,1,n+1){
		if(fre[i] == 1){
			per1[pos[i].fi] = per2[pos[i].fi] = i;
			vis[i] = 1;
		}else if(fre[i] == 2){
			int u1,u2;
			u1 = pos[i].fi;
			u2 = pos[i].se;
			while(vis[mex]){
				mex++;
			}
			if(mex >= i){
				yes = 0;
				break;
			}
			vis[mex] = 1;
			per1[u1] = i;
			per2[u1] = mex;
			per2[u2] = i;
			per1[u2] = mex;

		}
	}
	if(!yes ){
		cout << "NO" << ln;
		return;
	}
		cout << "YES" << ln;
	f(i,0,n)cout << per1[i] << ' ';
	cout << ln;
	f(i,0,n)cout << per2[i] << ' ';
	cout << ln;



}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	int tt = 1;
	cin >> tt;
	int test = 1;
	while (tt--){
		so(test++);
	}
	return 0;
}

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
	vi ga(n,0);
	f(i,0,n)ga[i] = i+1;
	int ma = 0;
	do{
		int pu = 0;
		f(i,0,n){
			f(j,i,n){
				int mi = 1e9;
				f(k,i,j+1){
					mi = min(mi,ga[k]);
				}
				pu += mi;
			}
		}
		ma = max(ma,pu);
	}while(next_permutation(all(ga)));
	vi ans(n);
	f(i,0,n)ans[i] = i+1;
	int  c=  0;
	do{
		int pu = 0;
		f(i,0,n){
			f(j,i,n){
				int mi = 1e9;
				f(k,i,j+1){
					mi = min(mi,ans[k]);
				}
				pu += mi;
			}
		}
		if(pu == ma)c++;
		if(c==m){
			f(i,0,n)cout << ans[i] << ' ';
			return;
		}
	}while(next_permutation(all(ans)));
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

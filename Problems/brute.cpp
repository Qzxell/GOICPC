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
#define sz(v) = ((int)(v).size())
#define all(v) = (v).begin(),(v).end()
#define f(i, a, b)  for(ll i = (ll)a; i < (ll)b; i++)
#define fer(i, b, a)  for(ll i = (ll)a - 1; i >= (ll)b; i--)
mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int tet ;
	cin >> tet;
	while(tet--){
		int n,m;
		cin >> n >> m;
		int tot = n + m + 1;
		vi a(tot);
		vi b(tot);
		f(i,0,tot)cin >> a[i];
		f(i,0,tot)cin >> b[i];
		f(i,0,tot){	
			int ign = i;
			int sn = n;
			int sm = m; 
			ll punt = 0;
			f(j,0,tot)if(j != ign){
				if(a[j] > b[j]){
					if(sn > 0){
						punt += a[j];
						sn--;
					}else {
						punt += b[j];
						sm--;
					}
				}else{
					if(sm > 0){
						punt += b[j];
						sm--;
					}else {
						punt += a[j];
						sn--;
					}
				}
			}
			cout << punt << ' ';
		}
		cout << ln;
	}

	return 0;
}


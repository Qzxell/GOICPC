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
	string pat; cin >> pat;
	ll M[n][m];
	ll ps[n+1][m+1];
	ll x = 50;

	f(i,0,n){
		f(j,0,m){
			cin >> M[i][j];
		}
	}
	f(i,0,n+1){
		f(j,0,m+1){
			ps[i][j] = 0;
		}
	}
	f(i,1,n+1){
		f(j,1,m+1){
			   ps[i][j] = ps[i-1][j] + ps[i][j-1] - ps[i-1][j-1] + M[i-1][j-1];
		}
	}
	int xi,yi;
	xi = yi = 0;
	ll car = 0;
	if(pat[0] == 'D'){
		car = ps[xi+1][n] - ps[xi][n];
		M[xi][yi] = x - car;
	}else{
		car = ps[n][yi+1] - ps[n][yi];
		M[xi][yi] = x - car;
	}
	ll acu = M[xi][yi];
	ll aux = 0;

	f(i,0,sz(pat)-1){
		if(pat[i] == pat[i+1]){
			ll cur = M[xi][yi];
			if(pat[i] == 'R'){
				M[xi][yi + 1] = 2*x - (ps[n][yi+2] - ps[n][yi] + cur);
				yi++;
			}else{
				M[xi + 1][yi] = 2*x - ( ps[xi+2][n] - ps[xi][n] +  cur);
				xi++;
			}
			acu += M[xi][yi];
		}else{
			if(pat[i] == 'R'){
				ll wasa = ps[xi+1][n] - ps[xi][n] + acu;
				M[xi][++yi] = x - wasa;
				acu += M[xi][yi];
				cout << acu << ln;
				f(h,0,n){
					f(u,0,m){
						cout << M[h][u] << ' ';
					}
					cout << ln;
				}
				//return;
			}else {
				ll wasa = ps[n][yi+1] - ps[n][yi] + acu;
				M[++xi][yi] = x - wasa;
				acu += M[xi][yi];
			}
		}
	}
	f(i,0,n){
		f(j,0,m){
			cout << M[i][j] << ' ' ;
		}
		cout << ln;
	}

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

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

int dx[] = {1,0,-1,0};
int dy[] = {0,1,0,1};

const int N =3e5 + 5;
int n;
ll m[2][N];
ll ps[2][N+1];
ll def1[2][N+1];
ll def2[2][N+1];
int r1[2][N];
int r2[2][N];
int r3[2][N];

void build(){
	forn(i,n)
		r1[0][i] = i;
	int co = n;
	for(int i = n-1; i >= 0 ; i--)
		r1[1][i] = co++;

	int x = 0,y = 0;
	int ind = 0;
	co = 0;
	forn(i,n+n){
		r3[x][y] =co++;
		x += dx[ind];
		y += dy[ind];
		ind = (ind+1)%4;
	}
	forn(i,n)
		r2[1][i] = i;
	co = n;
	for(int i = n-1; i >= 0 ; i--)
		r2[0][i] = co++;

	forn(i,2)forn(j,n){
		ps[i][j+1] = ps[i][j] + m[i][j];
		def1[i][j+1] = def1[i][j] + m[i][j] * r1[i][j];
		def2[i][j+1] = def2[i][j] + m[i][j] * r2[i][j];
	}
	//cerr << "this is a M ====\n";
	//forn(i,2)forn(j,n)
		//cerr << m[i][j] << " \n"[j==n-1];
	//cerr << "==================\n";
	//forn(i,2)forn(j,n)
		//cerr << r1[i][j] << " \n"[j==n-1];
	//cerr << '\n';
	//forn(i,2)forn(j,n)
		//cerr << r2[i][j] << " \n"[j==n-1];
	//cerr << '\n';
	//forn(i,2)forn(j,n)
		//cerr << r3[i][j] << " \n"[j==n-1];
	//cerr << '\n';
	//forn(i,2)forsn(j,1,n+1)
		//cerr << def1[i][j] << " \n"[j==n];
	//cerr << '\n';
	//forn(i,2)forsn(j,1,n+1)
		//cerr << def2[i][j] << " \n"[j==n];
	//cerr << '\n';
}

void so(int test){
	cin >> n;

	forn(i,2)forn(j,n)
		cin>> m[i][j];
	build();

	ll ans = 0;

	auto fun = [&](int x, int y,int tim)->ll{
		ll uwu = ps[1][n] - ps[1][y+1] + ps[0][n] - ps[0][y];
		if(x == 0){
			uwu = ps[0][n] - ps[0][y+1] + ps[1][n] - ps[1][y];
			return def1[x][n] - def1[x][y+1] + def1[1][n] - def1[1][y] +
				(tim - r1[x][y])*1ll*uwu;
		}
		return def2[x][n] - def2[x][y+1] + def2[0][n] - def2[0][y] +
							(tim - r2[x][y])*1ll*uwu;
	};
	ans = max(def1[0][n] + def1[1][n] , ans);
	//cerr << def1[0][n] + def1[1][n]  << '\n';
	int x = 0,y = 0, ind = 0;
	ll acu = 0;
	forn(i,n+n){
		acu += r3[x][y]*m[x][y];
		if(i%2 == 0){
			//cerr << "Time : " << i << '\n';
			//cerr << '\t' << acu + fun(x,y,i) << '\n';
			ans = max(ans, acu + fun(x,y,i));
		}
		x += dx[ind];
		y += dy[ind];
		ind = (ind+1)%4;
	}
	cout << max(ans,acu) << '\n';

}

int main(){
        ios::sync_with_stdio(false);
        cin.tie(0);
        int tt = 1;
        int test = 1;
        while(tt--) so(test++);
        return 0;
}


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

const int N = 4e3 + 5;
int n,m;

ll ft[N][N];
ll a[N],b[N];

void updt(int pos,int modi,int row){
	while( pos < n+1 ){// !!!!!URGENT limit
		ft[pos][row] += modi;
		pos = pos | (pos+1);
	}
}
ll query(int pos,int row){
	ll ret = 0;
	while(pos >= 0 ){
		ret += ft[pos][row];
		pos = (pos & (pos+1))  - 1;
	}
	return ret;
}

void clean(){
	forn(i,n+2)
	forn(j,m+2)
	ft[i][j] = 0;
}

void so(int test){
	cin >> n >> m;
	clean();
	forsn(i,1,n+1) cin >> a[i];
	forsn(i,1,m+1) cin >> b[i];

	updt(0,1,0);
	updt(1,-1,0);

	for(int j = 0 ; j < m ;j++){
		for(int i = 0 ; i <= n ;i++){
			ll cur = query(i,j);
			//cout << cur << " \n"[i == n];
			if(cur == 0)continue;
			if(a[i+1] == b[j+1]){
				updt(i+1,1,j+1);
				updt(i+2,-1,j+1);
			}
			if(i + b[j+1] <= n)
				updt(i+b[j+1],1,j+1);
		}
	}
	cout << (query(n,m) > 0 ? "YES\n" : "NO\n") ;

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


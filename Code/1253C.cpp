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

void so(int test){
	int n,k;
	cin >> n >> k;
	vi v(n);
	forn(i,n)cin >> v[i];
	sort(all(v));
	vl ps(n+1,0);
	vl ans(n+1,0);
	for(int i = 1 ; i <= n ;i++){
		ps[i] += v[i-1];
		if(i - k >= 0)
			ps[i] += ps[i-k] ;
	}
	for(int i = 1 ; i <= n ;i++){
		ans[i] = ans[i-1] + ps[i];
		cout << ans[i] << ' ';
	}
	cout << '\n';
}

int main(){
        ios::sync_with_stdio(false);
        cin.tie(0);
        int tt = 1;
        int test = 1;
        while(tt--) so(test++);
        return 0;
}


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
	int n;
	cin >> n;
	vi v(n+n);
	vi im,pa;
	forn(i,n+n){
		cin >> v[i];
		if(v[i]&1)
			im.push_back(i+1);
		else 
			pa.push_back(i+1);
	}
	int o = 0;
	for(int i = 0 ; i + 1 < sz(im); i+= 2){
		if(o == n-1) break;
		cout << im[i] << ' ' << im[i+1] << '\n';
		o++;
	}
	for(int i = 0 ; i + 1 < sz(pa); i+= 2){
		if(o == n-1) break;
		cout << pa[i] << ' ' << pa[i+1] << '\n';
		o++;
	}
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


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

#define x real()
#define y imag()

using pt = complex<ll>;

ll dot(pt a, pt b) { return real(conj(a) * b); }
ll cross(pt a, pt b) { return imag(conj(a) * b); }

pt read() {
	int p,q;
	cin >> p >> q;
	return pt(p, q);
}

void so(int test){
	int n;
	cin >> n;
	vector<pt> v(n);
	forn(i,n){
		v[i] = read();
	}
	int ans = 0;
	int r = 1;
	pt prev = v[1] - v[0];

	for(int l = 0; l < n ;l++){
		r = max(r, l+1);
		while(r + 1 < n){
			pt nex = v[r+1] - v[r];
			pt cur = v[r] - v[r-1];
			if(cross(v[l] - v[r+1], v[l+1] - v[l]) < 0 && cross(cur,nex) < 0 && cross(nex,v[l] - v[r+1])< 0){
				r++;
			}else{
				break;
			}
		}
		ans = max(ans,r-l+1);
	}
	if(ans < 3 )ans = 0;
	cout << ans << '\n';
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



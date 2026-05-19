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


const int N = 8005;
int a[N],c[N];

vi compres;
int n;

ll ft[N];

void updt(int pos,ll modi){
	while( pos <= n ){
		ft[pos] = max(ft[pos],modi);
		pos += pos&-pos;
	}
}

ll query(int pos){
	ll ret = 0;
	while(pos > 0 ){
		ret = max(ret,ft[pos]);
		pos -= pos & -pos;
	}
	return ret;
}

void so(int test){
	cin >> n;
	compres.clear();
	forn(i,n+1)ft[i] = 0;
	forn(i,n)cin >> a[i],compres.push_back(a[i]);
	forn(i,n)cin >> c[i];
	sort(all(compres));
	compres.erase(unique(all(compres)),compres.end());
	auto get = [&](int nu)->int{
		return lower_bound(all(compres),nu) - compres.begin() + 1;
	};
	forn(i,n)a[i] = get(a[i]);

	//forn(i,n)cout << a[i] << ' ';
	//cout << '\n';

	ll tot = accumulate(c,c+n,0ll);
	ll ans = 0;
	forn(i,n){
		ll qu = query(a[i]);
		updt(a[i],qu + c[i]);
		ans = max(ans,query(a[i]));
	}
	cout << tot - ans << '\n';


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




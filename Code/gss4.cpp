#include<bits/stdc++.h>

using namespace std;

using ll = long long;

#define forn(i,n) for(int i=0 ;i<int(n);i++)
#define forsn(i,s,n) for(int i=int(s);i<int(n);i++)

#define all(v) (v).begin(),(v).end()
#define sz(v) (int)(v).size()

const int N = 1e5 + 5;
int lim;
ll ft[N];

ll query(int pos){
	ll ret = 0;
	while(pos > 0){
		ret += ft[pos];
		pos -= pos & -pos;
	}
	return ret;
}

void updt(int pos, ll add){
	while(pos <= lim){
		ft[pos] += add;
		pos += pos & -pos;
	}
}

int test = 1;
void so(int n){
	cout << "Case #" << test++ <<":\n";
	set<int> s;
	lim = n;
	forn(i,n+1)
		ft[i] = 0;
	vector<ll> v(n + 1);
	forn(i,n){
		ll nu;
		cin >> nu;
		v[i+1] = nu;
		if(nu > 1)
			s.insert(i + 1);
		updt(i+1, nu);
	}
	int q;
	cin >> q;

	forn(i,q){
		int op,x,y;
		cin >> op >> x >> y;
		if(x > y)
			swap(x,y);
		if(op == 0){// upd
			auto it = s.lower_bound(x);
			vector<int> era;
			for(;it != s.end();){
				auto posi = *it;
				if(posi > y)
					break;
				ll sq = sqrtl(v[posi]);
				updt(posi, sq - v[posi]);
				v[posi] = sq;
				if(sq <= 1){
					it = s.erase(it);
					continue;
				}
				it = next(it);
			}
		}else{// query
			cout << query(y) - query(x-1) << '\n';
		}
	}
	cout << '\n';

}

int main(){
        ios::sync_with_stdio(false);
        cin.tie(0);
        cout.tie(0);
	int n;
        while(cin >> n) so(n);
        return 0;
}


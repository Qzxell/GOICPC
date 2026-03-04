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

const int N = 1e5 + 2;
int n;
vector<int> ft(N, 0);

void update(int pos,int add){ //sumo a[pos] += add
			      // 1-index
	while(pos <= n){
		ft[pos] += add;
		pos += (pos & -pos);
	}
}
int query(int pos){ //retorna la suma de a[1:pos]
	int sum = 0;
	while(pos > 0){
		sum += ft[pos];
		pos &= (pos-1);
	}
	return sum;
}
void so(int test){
	int m;
	cin >> n >> m;
	vii seg(m);
	f(i,0,m){
		cin >> seg[i].fi >> seg[i].se;
	}
	vector<int> vis(n+1,0);
	int q; cin >>q;
	vi qu(q);
	f(i,0,q) cin >> qu[i];
	int ind = -1;
	auto fu = [&](int pos){
		if(ind < pos ){
			f(i,ind+1,pos+1){
				if(vis[qu[i]] == 0){
					update(qu[i],1);
					vis[qu[i]]++;
				}
			}
		} else {
			f(i,pos+1,ind+1){
				if(vis[qu[i]] == 1){
					update(qu[i],-1);
					vis[qu[i]]--;
				}
			}
		}
		ind = pos;
		f(i,0,m){
			int l,r;
			l = seg[i].fi;
			r = seg[i].se;
			int len = r - l + 1;
			int unos = query(r) - query(l-1);
			int ceros = len - unos;
			if(unos > ceros)return true;
		}
		return false;

	};
	int lo = 0, lf = q - 1,mid;
	while(lo < lf){
		mid = (lo + lf)/2;
		if(fu(mid)){
			lf = mid;
		}else lo = mid + 1;
	}
	if(!fu(lo))cout << -1 << ln;
	else cout << lo + 1 << ln;
	f(i,0,n+1)ft[i] = 0;
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

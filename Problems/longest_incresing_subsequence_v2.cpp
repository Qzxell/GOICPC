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
vector<int> ft(N, 0);
void update(int pos,int maz){ //sumo a[pos] += add
	while(pos <= N){
		ft[pos] = max(ft[pos],maz);
		pos += (pos & (-pos));
	}
}
int query(int pos){ //retorna la suma de a[0:pos]
	int ret = 0;
	while(pos > 0){
		ret = max(ret,ft[pos]);
		pos -= (pos & (-pos));
	}
	return ret;
}
void so(int test){
	int n;
	cin >> n;
	map<int,int> m;//int -> color
	vi v(n);

	f(i,0,n){
		cin >> v[i];
		m[v[i]] = i;
	}

	int count = 1;
	for(auto &[a,b] : m) b = count++; 

	f(i,0,n) v[i] = m[v[i]];

	f(i,0,n){
		update(v[i],query(v[i]-1)+1);
	}
	cout << query(n) << ln;
}


int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	int tt = 1;
	int test = 1;
	while (tt--){
		so(test++);
	}
	return 0;
}

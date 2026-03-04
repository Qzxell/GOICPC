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
	int n,q;
	cin >> n >> q;
	vi v(n+1,0);
	vi m(n+1,0);
	vi m_(n+1,0);
	f(i,1,n+1)m[i] = i;
	f(i,1,n+1)m_[i] = i;
	f(i,1,n+1)v[i] = i;
	f(i,0,q){
		int op;
		cin >>op;
		if(op == 1){
			int a,b;
			cin >> a >> b;
			v[a] = m_[b];
		}
		if(op == 2){
			int a,b;
			cin >> a >> b;
			int aa = m_[a];
			int bb = m_[b];
			m[aa] = b;
			m[bb] = a;
			m_[b] = aa;
			m_[a] = bb;
		}
		if(op==3){
			int x;
			cin >> x;
			cout << m[v[x]] << ln;
		}
	}
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

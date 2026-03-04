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
	for(; pos < n  ; pos += pos & -pos){
		ft[pos] += add ;
	}
}
int query(int pos){ //retorna la suma de a[0:pos]
	int ans=0;
	for(; pos>0 ; pos &= pos-1) ans+=ft[pos];
	return ans;
}

void so(int test){
	update(1,1);
	update(2,1);
	f(i,1,5)cout << query(i) << ' ';
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

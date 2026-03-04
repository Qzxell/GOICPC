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
	multiset<int> s;	
	int n;
	cin >> n;
	vi v(n);
	f(i,0,n) cin >> v[i]; 
	int in,fi;
	in = fi = 0;
	f(i,0,n){
		if(i == 0){
			s.insert(v[i]);
			fi = 0;
			continue;
		}
		int mi = *s.begin();
		int ma = *s.rbegin();
		if(max(ma,v[i]) - min(mi,v[i]) <= 1){
			s.insert(v[i]);
			fi = i;
		}else break;
	}
	int ans = fi - in + 1;
	while(in + 1 < n){
		s.erase(s.find(v[in++]));
		if( *s.rbegin() - *s.begin() == 0){
			while(fi + 1 < n ){
				int qu = v[fi+1];	
				int mi = *s.begin();
				int ma = *s.rbegin();
				if(max(ma,qu) - min(mi,qu) <= 1){
					s.insert(qu);
					fi++;
				}else{
					ans = max(ans,fi-in+1);
					break;
				}

			}
		}
		int mi = *s.begin(); int ma = *s.rbegin();
		if(ma - mi <= 1 )ans = max(ans,fi-in+1);
	}
	int mi = *s.begin();
	int ma = *s.rbegin();
	if(ma - mi <= 1)ans = max(ans,fi - in + 1);
	cout << ans << ln;

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

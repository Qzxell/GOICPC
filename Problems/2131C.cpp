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
        int n,k;
        cin >> n >> k;
        map<int,int> m;
        map<int,int> m_;
        f(i,0,n){
                int x;
                cin >> x;
                m[x%k]++;
        }
        f(i,0,n){
                int x;
                cin >> x;
                m_[x%k]++;
        }
        for(auto [a,b] : m){
                m[abs(a-k)] += m[a];
                m[a] = 0;
        }
        for(auto [a,b] : m_){
                m_[abs(a-k)] += m_[a];
                m_[a] = 0;
        }
        cout << (m == m_ ? "YES" : "NO") << ln;
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

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
        int a,b,x,y;
        cin >> a >> b >> x >> y;
        if(x < a or y < b){
                cout << "NO"<< ln;
                return;
        }
        x -= a;
        y -= b;
        if(max(a,b) <= 2*min(a,b) + 2 and max(x,y) <= min(x,y)*2 + 2){
                cout << "YES" << ln;
                return;
        }
                cout << "NO" << ln;
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



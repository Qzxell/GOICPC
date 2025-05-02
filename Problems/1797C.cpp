#include <bits/stdc++.h>

using namespace std;

using ii = pair<int,int>;
using vii = vector<ii>  ;
using vi = vector<int>  ;
#define ll long long
#define ln '\n'
#define pb push_back
#define fi first
#define se second
#define sz(v) ((int)(v).size())
#define all(v) (v).begin(),(v).end()
#define rall(v) (v).rbegin(),(v).rend()
#define f(i, a, b)  for(ll i = (ll)a; i < (ll)b; i++)
#define fer(i, b, a)  for(ll i = (ll)a - 1; i >= (ll)b; i--)

void so(int test){
        int n,m;
        cin >> n >> m;
        cout << "? " << 1 << ' ' << 1 << ln ;
        int dis1;
        cin >> dis1 ;
        if(dis1 + 1 <= n and 1 + dis1 <= m){
                cout << '?' << ' '<< dis1 + 1 << ' ' << 1 << ln ;
                int dis2;
                cin >> dis2;
                cout << '?'<< ' ' << 1 << ' ' << dis1 + 1 << ln ;
                int dis3;
                cin >> dis3;
                if(dis2 <= dis3){
                        cout << "! " << dis1 + 1 << ' ' << dis2 + 1 << ln;
                }else{
                        cout << "! " << dis3 + 1<< ' ' << dis1 +1<< ln;
                }
                return;
        }
        if(dis1 + 1 <= n){
                cout << '?' << ' '<< dis1 + 1 << ' ' << 1 << ln ;
                int dis2;
                cin >> dis2;
                cout << "! " << dis1 + 1 << ' ' << dis2 + 1 << ln;
        }else{
                cout << '?' << ' '<< 1 << ' ' << dis1 + 1 << ln ;
                int dis3;
                cin >> dis3;
                cout << "! " << dis3 + 1 << ' ' << dis1 + 1 << ln;
        }
}

int main() {
	int tt = 1;
	cin >> tt;
	int test = 1;
	while (tt--){
		so(test++);
	}
	return 0;
}

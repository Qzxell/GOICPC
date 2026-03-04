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
        int rot = 0;
        vi fin(n+1,0);
        vi vis(n+1,0);
        set<int> leders;
        f(i,0,q){
                int a,b;
                cin >> a >> b;
                a--;b--;
                a = (a - rot + 2*n)%n;
                b = (b - rot + 2*n)%n;
                if(a > b)swap(a,b);
                if(i == 0){
                        rot = a;
                        a = (a - rot + 2*n)%n;
                        b = (b - rot + 2*n)%n;
                        leders.insert(a+1);
                        leders.insert(b+1);
                        vis[a] = 1;
                        vis[b] = 1;
                        fin[a+1] = b-1;
                        fin[b+1] = n-1;
                        cout << "Yes" << ln;
                        continue;
                }
                if(vis[a] or vis[b]){
                        cout << "No" << ln;
                        continue;
                }
                int led = *prev(leders.upper_bound(a));
                if(b > fin[led]){
                        cout << "No" << ln;
                        continue;
                }
                leders.insert(a+1);
                leders.insert(b+1);
                fin[a+1] = b-1;
                fin[b+1] = fin[led];
                fin[led] = a-1;
                cout << "Yes" << ln;
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

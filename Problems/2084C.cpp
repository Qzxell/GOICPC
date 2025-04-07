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
        int n;
        cin >> n;
        vi tr(n+1,0);
        vi ind(n+1,0);
        vi ind_(n+1,0);
        vi a(n),b(n);
        f(i,0,n){
                cin >> a[i]; 
                ind[a[i]] = i;
                ind_[i] = a[i];
        }
        f(i,0,n) cin >> b[i]; 
        int c = 0;
        int mid ;
        f(i,0,n){
                tr[a[i]] = b[i];
                if(a[i] == b[i]){
                        c++;
                        mid = a[i];
                }
        }
        if( (n&1) and c != 1){
                cout << -1 << ln;
                return;
        }
        if( n%2==0 and c > 0){
                cout << -1 << ln;
                return;
        }
        f(i,1,n+1){
                if(i != tr[tr[i]]){
                        cout << -1 << ln;
                        return;
                }
        }
        vii ans;
        if((n&1) and ind[mid] != n/2){
                int po = ind[mid];
                int lle = n/2;
                int who = ind_[lle];
                ans.pb({po+1,lle+1});
                ind[po] = lle;
                ind_[lle] = po;
                ind[who] = po;
                ind_[po] = who;
        }
        f(i,0,n/2){
                int pos1 = ind[a[i]];
                int pos2 = ind[tr[a[i]]];
                int lle = n-pos1-1;
                if(pos2 == lle)continue;
                int who = ind_[lle];
                ans.pb({pos2+1,lle+1});
                ind[tr[a[i]]] = lle;
                ind_[lle] = tr[a[i]];
                ind[who] = pos2;
                ind_[pos2] = who;
        }
        cout << sz(ans) << ln;
        for(auto [aa,bb] : ans){
                cout << aa << ' ' << bb << ln;
        }

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

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
#define point complex<long long>

const int N = 1e5 + 5;
int n;
ll ft[N];
void update(int pos, int add){
        while(pos <= n){
                ft[pos] += add;
                pos += (-pos)&pos;
        }
}
ll sum(int pos){
        ll res = 0;
        while(pos > 0){
                res += ft[pos];
                pos &= pos-1;
        }
        return res;
}
ll query(int l ,int r){
        return sum(r) - sum(l-1);
}

void so(int test){
        int q;
        cin >> n >> q;
        vi v(n+1);
        f(i,1,n+1){
                int x;cin >> x;
                v[i] = x;
                update(i,x);
        }
        f(i,0,q){
                int op;
                cin >> op;
                if(op == 0){
                        int x,y;
                        cin >> x >> y;
                        cout << query(x,y) << ln;
                        continue;
                }
                int pos,mod;
                cin >> pos >> mod;
                update(pos, mod - v[pos]);
                v[pos] = mod;
        }
}

int main() {
        freopen("rsq.in","r",stdin);
        freopen("rsq.out","w",stdout);

        int tt = 1;
        int test = 1;
        while (tt--){
                so(test++);
        }
        return 0;
}




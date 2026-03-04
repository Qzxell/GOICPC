#include <bits/stdc++.h>

using namespace std;

#define sz(v) ((int)(v).size())
#define all(v) (v).begin(),(v).end()
#define ln '\n'
#define ll long long
#define pb push_back
#define ii pair<int,int>
#define vii vector<ii>  
#define vi vector<int>  
#define fi first
#define se second
#define f(i, a, b) for(ll i = (ll)a; i < (ll)b; i++)
#define fer(i, b, a) for(ll i = (ll)a - 1; i >= (ll)b; i--)

const int N = 2e5 + 1;
const int LOG = 19;
int a[N];
int sp[N][LOG];

int query(int l, int r){
    int len = r-l + 1;
    int c = 0;
    while((1<<(c+1)) <= len){
        c++;
    }
    return gcd((int)sp[l][c],(int)sp[r-(1<<c) + 1][c]);
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int tt = 1;
    cin>> tt;
    int test = 1;
    
    while (tt--) {
        int n, q;
        cin >> n >> q;
        
        vi v(n);
        f(i, 0, n){
             cin >> v[i];
        }
        f(i, 0, n-1){
             sp[i][0] = v[i+1] -v[i];
        }
        n--;

        f(k,1,LOG){
            for(int i = 0; i + (1<<k) - 1< n;i++){
                sp[i][k] = gcd(sp[i][k-1] , sp[i+(1<<(k-1))][k-1]);
            }
        }
        while(q--){
            int l,r;
            cin >> l >> r;
            if(l==r)cout << 0 << ' ';
            else cout << query(l-1,r-2) << ' ';
        }
        cout << ln;
    }
    return 0;
}

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

void so(int test){
    int n,k,q;
    cin >> n >> k >> q;
    vector<vi> a(n,vi(k));
    vector<vi> b(k,vi(n));
    int x;
    f(i,0,n){
        f(j,0,k){
            cin >> a[i][j];
        }
    }
    f(i,0,k){
        int mas = 0;
        f(j,0,n){
            int x = a[j][i];
            b[i][j] = (mas|x);
            mas = (mas|x);
        }
    }
    f(i,0,q){
        int m;
        cin >> m;
        int mi = 0;
        int ma = n-1;

        f(j,0,m){
            int r,c;
            char les;
            cin >>r >> les >> c;
            r--;
            int uwu = upper_bound(all(b[r]),c) - b[r].begin();
            int owo = lower_bound(all(b[r]),c) - b[r].begin();

            while(b[r][owo] >= c and owo >=0)owo--;

            if (les == '>') {
                mi = max(mi,uwu) ;
            }else{
                ma = min(ma,owo);
            }
        }
        if (mi <= ma) {
            cout << mi+1 << ln;

        }else cout << -1 << ln;
        
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

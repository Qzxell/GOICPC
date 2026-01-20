#include<bits/stdc++.h>
using namespace std;

using ll = long long;

#define forn(i,n) for(int i=0 ;i<int(n);i++)
#define forsn(i,s,n) for(int i=int(s);i<int(n);i++)
#define dforn(i,n) for(int i=int(n)-1;i>=0;i--)
#define dforsn(i,s,n) for(int i=int(n)-1;i>=int(s);i--)

#define vi vector<int>
#define vl vector<ll>
#define ii pair<int,int>
#define vii vector<ii>
#define fi first
#define se second
#define all(v) (v).begin(),(v).end()
#define rall(v) (v).rbegin(),(v).rend()
#define sz(v) (int)(v).size()


ll comb(int n, int k) {
        if(k > n) return 0;
        k = min(k, n-k);  
        ll res = 1;
        for(int i = 1; i <= k; i++) {
                res = res * (n - k + i) / i;
        }
        return res;
}

void so(int test){
        int n,k;
        cin >> n >> k;
        int ga = __lg(n);
        ll ans = 0;
        forn(i,ga){
                forn(j,min(k-i,i+2)){
                        ans += comb(i,j);
                }
        }
        if(ga+1 <= k)ans++;
        cout << n - ans << '\n';
}

int main(){
        ios::sync_with_stdio(false);
        cin.tie(0);
        int tt = 1;
        cin >> tt;
        int test = 1;
        while(tt--) so(test++);
        return 0;
}



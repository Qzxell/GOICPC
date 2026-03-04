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
#define sz(v) (int)(v).size()

void so(int test){
        int n,m,k;
        cin >> n >> m >> k;
        if(k <= 1){
                cout << "NO\n";
                return;
        }
        if(m < n-1 or (n*1ll*(n-1))/2 < m) {
                cout << "NO\n";
                return;
        }
        if(k == 2){
                if(n == 1)cout << "YES\n";
                else cout << "NO\n";
                return;
        }
        if(k == 3){
                cout << ( (n*1ll*(n-1))/2 != m  ? "NO" : "YES") << '\n';
                return;
        }
        cout << "YES" << '\n';
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



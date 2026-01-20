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

void so(int test){
        int n;
        cin >> n;
        string s;
        cin >> s;
        vi v(n+1,0);
        map<int,int> m;
        forsn(i,1,n+1){
                v[i] = v[i-1] + (s[i-1] == 'A' ? 1 : s[i-1] == 'B' ? -1 : 0);
        }
        forsn(i,1,n+1){
                m[v[i]]++;
        }
        ll cur = 0;
        for(auto [nu,va] : m){
                if(nu > 0 )cur += va;
        }
        ll ans = 0;
        int piv = 0;
        forn(i,n){
                ans += cur;
                if(v[i+1] > piv)cur--;
                m[v[i+1]]--;
                if(s[i] == 'A'){
                        cur -= m[piv+1];
                        piv++;
                }
                if(s[i] == 'B'){
                        cur += m[piv];
                        piv--;
                }
        }
        cout << ans << '\n';
}

int main(){
        ios::sync_with_stdio(false);
        cin.tie(0);
        int tt = 1;
        int test = 1;
        while(tt--) so(test++);
        return 0;
}



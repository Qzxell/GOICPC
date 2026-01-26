#include<bits/stdc++.h>

using namespace std;

using ll = unsigned long long;

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
        ll k;
        cin >> k;
        ll ci = 9;
        int dig = 1;
        while(true){
                if( k - ci*1ll*dig <= 0)break;
                k -= ci;
                ci *= 10;
                dig++;
        }
        ll fi = 1;
        forn(i,dig-1)fi*=10;
        ll gru = (k + dig -1 )/dig;


}

int main(){
        ios::sync_with_stdio(false);
        cin.tie(0);
        int tt = 1;
        init();
        forn(i,N)cout << v[i] << ' ';
        cout << '\n';
        cin >> tt;
        int test = 1;
        while(tt--) so(test++);
        return 0;
}

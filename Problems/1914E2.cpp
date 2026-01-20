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
        int a[n],b[n],ord[n];
        forn(i,n)cin >> a[i];
        forn(i,n)cin >> b[i],ord[i] = i;
        auto ga = [&](int ind1, int ind2)->bool{
                return a[ind1] - b[ind2] < a[ind2] - b[ind1];
        };
        sort(ord,ord+n,ga);
        reverse(ord,ord+n);
        ll sa,sb;
        sa = sb = 0;
        forn(i,n)if(i&1){
                sb += b[ord[i]] - 1;
        }else{
                sa += a[ord[i]] - 1;
        }
        cout << sa - sb << '\n';
}

int main(){
        ios::sync_with_stdio(false);
        cin.tie(0);
        int tt = 1;
        int test = 1;
        cin >> tt;
        while(tt--) so(test++);
        return 0;
}



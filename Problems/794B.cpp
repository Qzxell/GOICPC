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
        int n,h;
        cin >> n >> h;
        forsn(i,1,n){
                double ans = sqrt((double)i/n)*h;
                cout << ans << ' ';
        }
}

int main(){
        ios::sync_with_stdio(false);
        cin.tie(0);
        cout << fixed << setprecision(9) ;
        int tt = 1;
        int test = 1;
        while(tt--) so(test++);
        return 0;
}



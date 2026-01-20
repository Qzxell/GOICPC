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
        ll ans = 0;
        vi v;
        forn(i,n){
                int x;
                cin >> x;
                if(x%2==0){
                        if(x > 0)ans += x;
                }else{
                        v.push_back(x);
                }
        }
        sort(rall(v));
        if(v[0] < 0){
                ans += v[0];
                cout << ans << '\n';
                return;
        }
        ans += v[0];
        for(int i = 1 ; i < sz(v) ; i += 2)if(i+1 < sz(v)){
                if(v[i] + v[i+1] > 0){
                        ans += v[i] + v[i+1];
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



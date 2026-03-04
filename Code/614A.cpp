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
        ll l,r,k;
        cin >> l >> r >> k;
        ll b = 1;
        vl ans;
        while(true){
                if( l <= b and b <= r){
                        ans.push_back(b);
                }
                if(r/k < b)break;
                b *= k;
        }
        if(sz(ans) ==0)
                cout << -1<< '\n';
        for(auto x : ans)cout << x << ' ';
}

int main(){
        ios::sync_with_stdio(false);
        cin.tie(0);
        int tt = 1;
        int test = 1;
        while(tt--) so(test++);
        return 0;
}

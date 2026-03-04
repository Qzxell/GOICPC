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
        ll n,k;
        cin >> n >>k;
        if(k&1){
                cout << "No\n";
                return;
        }
        ll lim = 0;
        vi v(n);
        for(int i = 1,j = n; i <= n ; i++,j--){
                lim += abs(j - i);
                v[i-1] = i;
        }
        if( k > lim){
                cout << "No\n";
                return;
        }
        ll su = 0;
        forn(i,n/2){
                int ind = n - i - 1;
                if(2*(ind-i) + su <= k){
                        su += 2*(ind-i);
                        swap(v[i],v[ind]);
                }else{
                        int dif = k - su;
                        su = k;
                        swap(v[i],v[i+dif/2]);
                        break;
                }
        }
        if(su != k){
                cout << "No\n";
                return;
        }
        cout << "Yes\n";
        forn(i,n)cout << v[i] << " \n"[i == n-1];

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



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

int n;
int masc;
ll ans = 0;
map<int,int> m;

void ga(int pos , int a, int b){
    if(pos == 18){
        if((a^b) == masc ){
            if(a == b){
                ans += (m[a]*1ll*(m[a]-1));
            }else ans += ( m[a]*1ll*m[b]);
        }
        return;
    }
    if((masc>>pos) & 1 ){
        ga(pos +1 , a , b + (1<<pos));
        ga(pos +1 , a + (1<<pos), b );
    }else{
        ga(pos +1 , a , b);
        ga(pos +1 , a + (1<<pos), b + (1<<pos));
    }
}

void so(int test){
    cin >> n >> masc;
    f(i,0,n){
        int x;
        cin >> x;
        m[x]++;
    }
    ga(0,0,0);
    cout << ans/2 << ln;


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

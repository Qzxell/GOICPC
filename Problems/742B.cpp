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

<<<<<<< HEAD
int masc;
const int N = 1e5 + 1;
map<int,int> m;
int ans = 0;

void dep(int pos , int a, int b){
    if(pos == 18){
        ans += m[a]*m[b];
        return;
    }
    if (masc&1) {
        dep(pos+1 , a + (1<<pos), b) 
    }

}

void so(int test){
    int n;
=======
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
>>>>>>> 27de873c3364637765b335a924dcd21513dc15aa
    cin >> n >> masc;
    f(i,0,n){
        int x;
        cin >> x;
        m[x]++;
    }
<<<<<<< HEAD
=======
    ga(0,0,0);
    cout << ans/2 << ln;

>>>>>>> 27de873c3364637765b335a924dcd21513dc15aa

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

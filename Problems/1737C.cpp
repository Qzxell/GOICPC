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

void so(int test){
    int n;
    cin >> n;
    vii wasa(3);
    f(i,0,3){
        cin >> wasa[i].fi >> wasa[i].se;
        wasa[i].fi--;
        wasa[i].se--;
    }
    int mx,my;
    cin >> mx >> my;
    mx--;my--;
    vector<vii> owo = {
        {{1,0},{0,0},{0,1}},
        {{1,n-1},{0,n-1},{0,n-2}},
        {{n-1,1},{n-1,0},{n-2,0}},
        {{n-2,n-1},{n-1,n-1},{n-1,n-2}}
    };
    sort(all(wasa));
        
    do{
        f(i,0,4){
            if(wasa == owo[i]){
                if(owo[i][1].fi == mx or owo[i][1].se == my ){
                    cout << "YES" << ln;
                }else cout << "NO" << ln;
                return;
            }
        }
    }while(next_permutation(all(wasa)));

    f(i,0,3){
        if( (mx&1) == (wasa[i].fi & 1) and (my&1) == (wasa[i].se & 1)){
            cout << "YES" << ln;
            return;
        }
    }
    cout << "NO" << ln;


}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int tt = 1;
    cin >> tt;
    int test = 1;
    while (tt--){
        so(test++);
    }
    return 0;
}

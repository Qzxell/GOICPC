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
    cin >> n >> masc;
    f(i,0,n){
        int x;
        cin >> x;
        m[x]++;
    }

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

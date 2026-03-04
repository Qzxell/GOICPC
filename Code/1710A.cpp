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
    int n,m,k;
    cin >> n >> m >> k;
    
    vi v(k);
    f(i,0,k)cin >> v[i];
    sort(v.rbegin(),v.rend());
    // case 1 : vertical
    int dis = m;
    int s = 0;
    int remain = 0;
    f(i,0,k){
        int cur = v[i];
        int dif = cur/n;
        if(dif >= 2){
            s += 2;
            remain =dif-2;
        }
    }
    if(s >= dis and dis%2==0){
            cout << "Yes\n";
            return;
    }else if(s >= dis and dis%2 == 1 and remain > 0){
            cout << "Yes\n";
            return;
    }
    if(s < dis and s + remain >= dis){
            cout << "Yes\n";
            return;
    }
    // case 2 : vertical
    dis = n;
    s = 0;
    remain = 0;
    f(i,0,k){
        int cur = v[i];
        int dif = cur/m;
        if(dif >= 2){
            s += 2;
            remain =dif-2;
        }
    }
    if(s >= dis and dis%2==0){
            cout << "Yes\n";
            return;
    }else if(s >= dis and dis%2 == 1 and remain > 0){
            cout << "Yes\n";
            return;
    }
    if(s < dis and s + remain >= dis){
            cout << "Yes\n";
            return;
    }
    cout << "No\n";
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

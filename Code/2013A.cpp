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


void so(){
    int x,y;
    int n;
    cin >> n;
    cin >> x >> y;
    int u = (y/x)*x;
    if (u == 0) {
        u = y; 
    }
    int ti = u/x;
    ti = max(ti,1);
    if (n%u == 0) {
        cout << ti*(n/u) << ln; 
    }else {
        cout << ti*(n/u )+ (n%u + x - 1)/x << ln; 
    }


}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int tt = 1;
    cin >> tt;
    while (tt--){
        so();
    }
    return 0;
}

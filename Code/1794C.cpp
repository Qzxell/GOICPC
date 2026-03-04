#include<bits/stdc++.h>
#define ln '\n'
#define pb push_back
#define vii vector<pair<int,int>>  
#define vi vector<int>  
#define fi first
#define se second
using namespace std;

void so (){
    int n;
    cin >> n;
    vi v(n);
    for (int i = 0; i < n; ++i) {
        cin >> v[i];
    }

    for (int i = 0; i < n; ++i) {
        int lo = 0 , lf = i, mid; 
        while(lo < lf){
            mid = (lo+lf)/2;
            if (v[mid] < (i+1 - mid)  ) {
                lo = mid + 1;
            }else lf = mid;
        }
        //cout << lo << ' ';
        cout << i - lo + 1 << ' ';
    }
    cout << ln;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int tt;
    cin >> tt;
    while(tt--){
        so();
    }
    return 0;
}

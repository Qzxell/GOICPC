#include<bits/stdc++.h>
#define all(c) (c).begin(), (c).end()
#define ln '\n'
#define ll long long
#define pb push_back
#define ii pair<int,int>
#define vii vector<ii>  
#define vi vector<int>  
#define fi first
#define se second
using namespace std;


void so(){
    int n,k;
    cin >> n >> k;
    vi v(n);
    for(int i = 0 ; i < n ; i++){
        cin >> v[i];
    }
    vi ans(n,1);
    ans[n-1] = 0;
    while(ans != v){
        ans[n-1] ++;
        int cur = n-1;
        while(cur > 0 and ans[cur] == v[cur] + 1){
            ans[cur] = 1;
            if (cur > 0) {
                ans[cur-1] ++; 
            }
            cur--;
        }
        int sum = 0;
        for(int i = 0; i < n ; i++){
            sum += ans[i];
        }
        if (sum % k == 0) {
            for(int i = 0; i < n ; i++){
                cout << ans[i] << ' ';
            } 
            cout << ln;
        }

    }
}
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int tt = 1;
    while(tt--){
        so();
    }
    return 0;
}


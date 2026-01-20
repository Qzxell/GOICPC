#include<bits/stdc++.h>

using namespace std;

const int N = 262149;
int A[N];
int vis[N];

bool ret = 1;
int solve(int l , int r, int mi){
        int lon = r - l + 1;
        if(lon == 1){
                return 0;
        }
        for(int i = l ; i < l + lon/2; i++){
                vis[A[i]] = 1;
        }
        bool ok1 = 1,ok2 = 1;
        for(int i = mi ; i < mi + lon/2; i++){
                if(!vis[i])ok1 = 0;
                if(!vis[i+lon/2])ok2 = 0;
        }
        if(!ok1 and !ok2){
                ret = 0;
                return 1;
        }
        for(int i = l ; i < l + lon/2; i++){
                vis[A[i]] = 0;
        }
        if(ok1){
                return solve(l,l+lon/2-1,mi) + solve(l+lon/2,r,mi+lon/2);
        }
        return 1 +solve(l,l+lon/2-1,mi+ lon/2) + solve(l+lon/2,r,mi);
}

void so(){
        int n;
        cin >> n;
        ret = 1;
        for(int i = 0 ; i < n ; i++){
                cin >> A[i];
        }
        int ans = solve(0,n-1,1);
        if(!ret){
                cout << -1 << '\n';
                for(int i = 0 ; i < n ; i++){
                        vis[A[i]] = 0;
                }
                return;
        }
        cout << ans << '\n';
        for(int i = 0 ; i < n ; i++){
                vis[A[i]] = 0;
        }
}

int main(){
        int tt;
        cin >> tt;
        while(tt--)so();
        return 0;
}

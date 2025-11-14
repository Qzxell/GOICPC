#include<bits/stdc++.h>

using namespace std;

const int N = 503;
int A[N];
void so(){
        int n,x;
        cin >> n >> x;
        for(int i = 0 ;i < n ;i++)cin >> A[i];
        vector<int> v;
        int co = 0;
        int ans = 0;
        int pu,u;
        pu = u = -1;
        for(int i = 0 ;i < n ;i++){
                if(int(v.size()) == 0){
                        v.push_back(A[i]);
                        if(A[i] > x){
                                co++;
                                pu = x;
                                u = A[i];
                        }
                        continue;
                }
                if(A[i] < v.back()){
                        if(co == 0){
                                cout << -1 << '\n';
                                return;
                        }
                        if(A[i] >= pu){
                                v.push_back(A[i]);
                                ans += co;
                                co = 0;
                                x = u;
                                u = pu = -1;
                        }else{
                                cout << -1 << '\n';
                                return;
                        }
                }else{
                        if(A[i] > x){
                                if(A[i] != v.back())co++;
                                if( u == -1){
                                        pu = x;
                                        u = A[i];
                                }else{
                                        pu = u;
                                        u = A[i];
                                }
                        }
                        v.push_back(A[i]);
                }

        }
        cout << ans << '\n';
}


int main(){
        int tt;
        cin >> tt;
        while(tt--)so();
        return 0;
}

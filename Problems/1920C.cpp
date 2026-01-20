#include<bits/stdc++.h>

using namespace std;

const int N = 2e5 + 5;
int A[N];

void so(){
        int n;
        cin >> n;
        for(int i = 0 ; i < n ; i++)cin >> A[i];
        vector<int> div;
        for(int i = 1 ; i <= n ; i++)if(n%i == 0)div.push_back(i);
        int ans = 0;
        for(auto x : div){
                int gc = 0;
                for(int i = 0 ; i < x ; i++){
                        for(int j = i ; j+x < n;j += x){
                                gc = gcd(gc,abs(A[j] - A[j+x]));
                        }
                }
                if(gc > 1 or gc == 0){
                        ans++;
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

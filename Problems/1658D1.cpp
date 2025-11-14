#include<bits/stdc++.h>

using namespace std;

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
        int tt;
        cin >> tt;
        while(tt--){
                int l,r;
                cin >> l >> r;
                vector<int> v((2<<17)+1,0);
                int a[r+1];
                int s_t = 0;
                int s_i = 0;
                for(int i = 0 ; i <= r; i++){
                        int x;
                        cin >> x;
                        a[i] = x;
                        v[x] = 1;
                        s_i ^= i;
                        s_t ^= x;
                }
                if(r%2 == 0){
                        cout << (s_t^s_i) << '\n';
                        continue;
                }
                for(int i = 0 ; i <= r; i++){
                        int temp = (s_t ^ a[i]);
                        int res = (temp^s_i);
                        if(v[res]){
                                cout << res << '\n';
                                break;
                        }
                }
        }
}

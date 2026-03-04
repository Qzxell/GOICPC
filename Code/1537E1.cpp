#include<bits/stdc++.h>

using namespace std;

void so(){
        int n,k;
        cin >> n >> k;
        string s,t,aux;
        cin >> s;
        t += s[0];

        auto fun = [&](int &ind) -> bool{
                int lo = ind;
                for(; ind < n && ind - lo < t.size();ind++){
                        if(s[ind] == t[ind-lo])continue;
                        return s[ind] < t[ind-lo];
                }
                return t.size() < (n - lo);
        };

        for(int i = 1; i < n; i++){
                if(s[i] < t[0]){
                        t += s[i];
                }else{
                        int ind = i;
                        bool ok = fun(ind);
                        if(!ok){
                                break;
                        }
                        for(int j = i; j < ind && j < n;j++){
                                t += s[j];
                        }
                        i = ind -1;
                }
        }
        while(k > (int)(t.size())){
                t = t + t;
        }
        for(int i = 0 ; i < k ; i++)cout << t[i] ;

}

int main(){
        ios::sync_with_stdio(false);
        cin.tie(0);
        int tt = 1;
        while(tt--)so();
        return 0;
}

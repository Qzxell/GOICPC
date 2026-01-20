#include<bits/stdc++.h>

using namespace std;

using ll = long long;

#define forn(i,n) for(int i=0 ;i<int(n);i++)
#define forsn(i,s,n) for(int i=int(s);i<int(n);i++)
#define dforn(i,n) for(int i=int(n)-1;i>=0;i--)
#define dforsn(i,s,n) for(int i=int(n)-1;i>=int(s);i--)

void so(int test){
        int n;
        string s;
        cin >> s;
        n = s.size();
        vector<int> v;
        vector<int> ans(n,0);
        int co = 0,ca = 0;
        for(auto x : s){
                if(x == 'R'){
                        if(ca)v.push_back(ca);
                        ca = 0;
                        co++;
                }else{
                        if(co)v.push_back(co);
                        co = 0;
                        ca++;
                }
        }
        if(ca)v.push_back(ca);

        int pos = 0;
        for(int i = 0;  i < v.size() ;i += 2){
                ans[pos + v[i]] += v[i]/2;
                ans[pos + v[i]-1] += v[i] - v[i]/2;
                ans[pos + v[i]] += v[i+1] - v[i+1]/2;
                ans[pos + v[i]-1] += v[i+1]/2;
                pos += v[i] + v[i+1];
        }
        forn(i,n){
                cout << ans[i] << ' ';
        }
        cout << '\n';

}

int main(){
        ios::sync_with_stdio(false);
        cin.tie(0);
        int tt = 1;
        int test = 1;
        while(tt--) so(test++);
        return 0;
}



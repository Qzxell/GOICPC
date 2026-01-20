#include<bits/stdc++.h>

using namespace std;

#define ll long long

int dx[] = {0,0,1,-1};
int dy[] = {1,-1,0,0};

void so(){
        int n;
        cin >> n;
        ll ans = 0;
        vector<int> v(n);
        for(int i = 0 ; i < n; i++)cin >>v[i];

        for(int i = 0 ; i < n; i++)
        for(int j = i+1 ; j < n; j++)
        {
                int ind = lower_bound(v.begin() + j + 1, v.end(),v[i]+v[j]) - v.begin();
                int ind2 = upper_bound(v.begin() + j + 1, v.end(),v[n-1]-v[i]-v[j]) - v.begin();

                ans += max(ind- ind2,0);
        }
        cout << ans << '\n';
}

int main(){
        ios::sync_with_stdio(false);
        cin.tie(0);
        int tt = 1;
        cin >> tt;
        while(tt--)so();
        return 0;
}

#include <bits/stdc++.h>
using namespace std;

const int INF = 1e9 + 7;

int main() {
	vector<int>v = {1,1,2,2};
	auto g =unique(v.begin(),v.end());
	v.erase(g,v.end());
	for(auto x : v)cout << x << ' ';

    return 0;
}

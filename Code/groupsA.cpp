#include <bits/stdc++.h>

using namespace std;

#define sz(v) ((int)(v).size())
#define all(v) (v).begin(), (v).end()
#define ln '\n'
#define ll long long
#define pb push_back
#define ii pair<int, int>
#define vii vector<ii>
#define vi vector<int>
#define fi first
#define se second

const int ma = 11;
int n, m;
vector<string > grid(ma);

int dx[] = {-1, 1, 0, 0};
int dy[] = {0, 0, -1, 1};

string orig = "YOKOHAMA";

int backtrack(int x, int y, int pos) {
    if (pos == sz(orig) - 1) return 1; 

    int count = 0;
    char curr = grid[x][y];

    for (int dir = 0; dir < 4; ++dir) {
        int nx = x + dx[dir];
        int ny = y + dy[dir];

        if (nx >= 0 && nx < n && ny >= 0 && ny < m && grid[nx][ny] == orig[pos + 1]) {
            count += backtrack(nx, ny, pos + 1);
        }
    }

    return count;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> m;

    for (int i = 0; i < n; ++i) {
        cin >> grid[i];
    }

    int c = 0;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            if (grid[i][j] == 'Y') { 
                c += backtrack(i, j, 0); 
            }
        }
    }

    cout << c << ln;

    return 0;
}

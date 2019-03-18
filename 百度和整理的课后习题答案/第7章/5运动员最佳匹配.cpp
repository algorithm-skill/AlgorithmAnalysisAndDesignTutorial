//Ô­ÎÄ£ºhttps://blog.csdn.net/Matrix97/article/details/80794959
#include <iostream>

using namespace std;
int n, a[22][22], b[22][22], vis[22], pre[22], ans;

void dfs(int x, int s) {
    if (x > n) {
        ans = max(ans, s);
        return;
    }
    if (s + pre[n] - pre[x - 1] < ans)
        return;
    for (int i = 1; i <= n; i++)
        if (!vis[i]) {
            vis[i] = 1;
            dfs(x + 1, s + a[x][i] * b[i][x]);
            vis[i] = 0;
        }
}

int main() {
    cin >> n;
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++)
            cin >> a[i][j];
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++)
            cin >> b[i][j];
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++)
            pre[i] = max(pre[i], a[i][j] * b[j][i]);
        pre[i] += pre[i - 1];
    }
    dfs(1, 0);
    cout << ans << endl;
    return 0;
}
 
int m = 1;
while (n - 1 > (m % 2 == 1 ? m * (m + 1) / 2 : m * m / 2 + 1)) {
    m++;
}
// finding the m -> no of edges 
std::vector<int> cur(2 * n);
std::vector<bool> vis(n);
auto dfs = [&](this auto &&self, int x) -> void {
    for (int &j = cur[x]; j < adj[x].size(); j++) {
        auto [y, i] = adj[x][j];
        if (!vis[i]) {
            vis[i] = true;
            self(y);
            ans.push_back(i);
        }
    }
};
dfs(s);
// c++23 
// cur[i] = prevents re-scanning edges → O(n) total
// must have exactly two vertex with odd degrees(more than 2 --> euler path not possible)
// we always start at one of the odd degee vertex and it ends on the other one .
// if no odd degree vertex start at any vertex 


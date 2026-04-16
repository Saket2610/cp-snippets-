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

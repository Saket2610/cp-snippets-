 // marking all the nodes that are on cycle 
vector<vector<int>> g;
vector<bool> used;
vector<int> depth;
vector<int> up;
vector<bool> on_cycle;
 
void dfs(int v, int p) {
    used[v] = true;
    up[v] = depth[v];
    for (int to: g[v]) {
        if (to == p) {
            continue;
        }
        if (!used[to]) {
            depth[to] = depth[v] + 1;
            dfs(to, v);
            up[v] = min(up[v], up[to]);
            if (up[to] != depth[to]) {
                on_cycle[to] = on_cycle[v] = true;
            }
        } else {
            up[v] = min(up[v], depth[to]);
            on_cycle[to] = on_cycle[v] = true;
        }
    }
}
for (int i = 0; i < n; i++) {
    if(!used[i]) {
        dfs(i, -1);
    }
}
// finding the cycle of a certain vertex v 
vector<int> cycle;
 
bool find_cycle(int v, int p, int st) {
    used[v] = true;
    for (int to: g[v]) {
        if (to == p) {
            continue;
        }
        if (to == st || !used[to] && find_cycle(to, v, st)) {
            cycle.push_back(v);
            on_cycle[v] = true;
            return true;
        }
    }
    return false;
}
find_cycle(v, -1, v);




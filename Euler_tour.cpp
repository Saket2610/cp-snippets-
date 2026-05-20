std::vector<int> in(n), out(n), id(n);
    int timeStamp = 0;
    std::function<void(int)> dfs1 = [&](int u) {
        in[u] = timeStamp++;
        id[in[u]] = u;
        for (auto v : e[u]) {
            dfs1(v);
         }
        out[u] = timeStamp;
};
dfs1(0);
// u is an ancestor of v in tree B if and only if in[u] <= in[v] < out[u]

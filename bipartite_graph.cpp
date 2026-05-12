std::vector<int> color(n, -1);
    std::vector<std::vector<int>> cp;
    std::vector<int> cnt;
    for (int i = 0; i < n; ++i) {
        if (color[i] != -1)
            continue;
        color[i] = 0;
        std::queue<int> que;
        que.push(i);
        cp.emplace_back();
        int c0 = 0;
        while (!que.empty()) {
            int u = que.front();
            que.pop();
            cp.back().push_back(u);
            c0 += color[u];
            for (auto v : e[u]) {
                if (color[v] == -1) {
                    que.push(v);
                    color[v] = color[u] ^ 1;
                } else if (color[u] == color[v]) {
                    std::cout << "NO\n";
                    return 0;
                }
            }
        }
        cnt.push_back(c0);
    }

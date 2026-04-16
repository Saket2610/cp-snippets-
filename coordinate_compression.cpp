std::vector<int> v(n), p(n);
for (int i = 0; i < n; i++) {
    std::cin >> v[i] >> p[i];
}
auto vs = v, ps = p;
std::sort(vs.begin(), vs.end());
    std::sort(ps.begin(), ps.end());
    
for (int i = 0; i < n; i++) {
    v[i] = std::lower_bound(vs.begin(), vs.end(), v[i]) - vs.begin();
    p[i] = std::lower_bound(ps.begin(), ps.end(), p[i]) - ps.begin();
}
    

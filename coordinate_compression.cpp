std::vector<int> v(n);
for (int i = 0; i < n; i++) {
    std::cin >> v[i] ;
}
auto vs = v;
std::sort(vs.begin(), vs.end());
    
for (int i = 0; i < n; i++) {
    v[i] = std::lower_bound(vs.begin(), vs.end(), v[i]) - vs.begin();
}

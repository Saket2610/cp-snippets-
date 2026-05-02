priority_queue<tuple<long long, int, int>, vector<tuple<long long, int, int>>, greater<tuple<long long, int, int>>> pq;
  pq.push(make_tuple(0, 0, 0));


long long dd = get<0>(pq.top());
    int v = get<1>(pq.top());
    int p = get<2>(pq.top());
////


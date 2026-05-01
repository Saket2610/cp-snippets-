/**
 * Tarjan's Strongly Connected Components (SCC) Algorithm
 * -------------------------------------------------------
 * Finds all SCCs in a directed graph in O(V + E).
 *
 * Key variables:
 *   dfn[v]  - discovery time of node v (-1 = unvisited)
 *   low[v]  - lowest dfn reachable from v's subtree
 *   bel[v]  - which SCC node v belongs to (-1 = not finalized)
 *   stk     - DFS stack
 *   cnt     - global DFS timer
 *   comp    - SCC counter (0-indexed)
 *
 * After running:
 *   bel[v]  tells you which SCC node v is in
 *   comp    is the total number of SCCs
 *
 * To get the condensation DAG:
 *   For each edge (u -> v), if bel[u] != bel[v], it's a cross-SCC edge.
 *   SCCs with in-degree 0 in the DAG are "source" components.
 *   The graph has a single reachable root iff exactly 1 SCC has in-degree 0.
 */
 
#include <bits/stdc++.h>
using namespace std;
 
// ─── Tarjan's SCC ────────────────────────────────────────────────────────────
 
int n;                              // number of nodes (0-indexed)
vector<vector<int>> adj;            // adjacency list
 
int  cnt  = 0;                      // DFS timer
int  comp = 0;                      // SCC count
vector<int> dfn, low, bel, stk;    // dfn/low/component/stack
 
void dfs(int x) {
    stk.push_back(x);
    dfn[x] = low[x] = cnt++;
 
    for (int y : adj[x]) {
        if (dfn[y] == -1) {
            // Tree edge: recurse, then propagate low
            dfs(y);
            low[x] = min(low[x], low[y]);
        } else if (bel[y] == -1) {
            // Back edge (y still on stack): update low with dfn
            low[x] = min(low[x], dfn[y]);
        }
        // Cross/forward edges to already-finalized SCCs are ignored
    }
 
    // x is a root of an SCC → pop stack until we reach x
    if (dfn[x] == low[x]) {
        int y;
        do {
            y = stk.back();
            bel[y] = comp;
            stk.pop_back();
        } while (y != x);
        comp++;
    }
  
    vector<int> deg(comp);
    for (int i = 0; i < n; i++) {
        for (auto j : adj[i]) {
            if (bel[i] != bel[j]) {
                deg[bel[j]]++;
            }
        }
    }
  // the above code find the in-degree of each scc
  // its like we shrink the scc into a super node
  // [SCC0] ──→ [SCC1] ──→ [SCC2]

}
 
void tarjan() {
    dfn.assign(n, -1);
    low.resize(n);
    bel.assign(n, -1);
 
    for (int i = 0; i < n; i++) {
        if (dfn[i] == -1) dfs(i);   // handles disconnected graphs
    }
}
 

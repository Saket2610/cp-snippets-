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
vector<vector<int>> adj(n);            // adjacency list
 
int  cnt  = 0;                      // DFS timer
int  comp = 0;                      // SCC count
vector<int> dfn(n, -1), low(n), bel(n, -1), stk;    // dfn/low/component/stack


// auto dfs = [&](auto self, int x) -> void 
void dfs(int x) {
    stk.push_back(x);
    dfn[x] = low[x] = cnt++;
 
    for (auto y : adj[x]) {
        if (dfn[y] == -1) {
            // Tree edge: recurse, then propagate low
            dfs(y);
         // self(self,y);
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
}

// Returns in-degree of each SCC node in the condensation DAG.
// Exactly 1 SCC with in-degree 0  →  unique reachable root exists.
 // [SCC0] ──→ [SCC1] ──→ [SCC2]

vector<int> condensation_indegree() {
    vector<int> deg(comp, 0);
    for (int u = 0; u < n; u++) {
        for (int v : adj[u]) {
            if (bel[u] != bel[v]) {
                deg[bel[v]]++;
            }
        }
    }
    return deg;
    // returns a vector where the deg of scc is there 
}

 
void tarjan() {
    dfn.assign(n, -1);
    low.resize(n);
    bel.assign(n, -1);
 
    for (int i = 0; i < n; i++) {
        if (dfn[i] == -1) dfs(i);   // handles disconnected graphs
    }
}
 

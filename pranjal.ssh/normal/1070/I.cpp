#include <bits/stdc++.h>
using namespace std;
#define cerr cout
#define F first
#define S second
#define FOR(i,a,b) for (auto i = (a); i <= (b); ++i)
#define NFOR(i,a,b) for(auto i = (a); i >= (b); --i)
#define all(x) (x).begin(), (x).end()
#define sz(x) int(x.size())
typedef long long ll; typedef pair <int, int> ii; typedef vector <int> vi; const int inf = 1e9 + 7;
string to_string(string s) { return '"' + s + '"';}
string to_string(char s) { return string(1, s);}
string to_string(const char* s) { return to_string((string) s);}
string to_string(bool b) { return (b ? "true" : "false");}
template <typename A> string to_string(A);
template <typename A, typename B>string to_string(pair<A, B> p) {return "(" + to_string(p.first) + ", " + to_string(p.second) + ")";}
template <typename A> string to_string(A v) {bool f = 1; string r = "{"; for (const auto &x : v) {if (!f)r += ", "; f = 0; r += to_string(x);} return r + "}";}
void debug_out() { cerr << endl; }
template <typename Head, typename... Tail> void debug_out(Head H, Tail... T) {cerr << " " << to_string(H); debug_out(T...);}
#define pr(...) cerr << "[" << #__VA_ARGS__ << "]:", debug_out(__VA_ARGS__)

struct DinicFlow {
    struct edge {
        int x, y, cap, flow;
    };
    vector <edge> e;
    vector <int> cur, d;
    vector < vector <int> > adj;
    int n, source, sink;

    DinicFlow() {}

    DinicFlow(int v) {
        n = v;
        cur = vector <int> (n + 1);
        d = vector <int> (n + 1);
        adj = vector < vector <int> > (n + 1);
    }

    void addEdge(int from, int to, int cap) {
        edge e1 = {from, to, cap, 0};
        edge e2 = {to, from, 0, 0};
        adj[from].push_back(e.size()); e.push_back(e1);
        adj[to].push_back(e.size()); e.push_back(e2);
    }

    int bfs() {
        queue <int> q;
        for (int i = 0; i <= n; ++i) d[i] = -1;
        q.push(source); d[source] = 0;
        while (!q.empty() and d[sink] < 0) {
            int x = q.front(); q.pop();
            for (int i = 0; i < (int)adj[x].size(); ++i) {
                int id = adj[x][i], y = e[id].y;
                if (d[y] < 0 and e[id].flow < e[id].cap) {
                    q.push(y); d[y] = d[x] + 1;
                }
            }
        }
        return d[sink] >= 0;
    }

    int dfs(int x, int flow) {
        if (!flow) return 0;
        if (x == sink) return flow;
        for (; cur[x] < (int)adj[x].size(); ++cur[x]) {
            int id = adj[x][cur[x]], y = e[id].y;
            if (d[y] != d[x] + 1) continue;
            int pushed = dfs(y, min(flow, e[id].cap - e[id].flow));
            if (pushed) {
                e[id].flow += pushed;
                e[id ^ 1].flow -= pushed;
                return pushed;
            }
        }
        return 0;
    }

    int maxFlow(int src, int snk) {
        this->source = src; this->sink = snk;
        int flow = 0;
        while (bfs()) {
            for (int i = 0; i <= n; ++i) cur[i] = 0;
            while (int pushed = dfs(source, inf)) {
                flow += pushed;
            }
        }
        return flow;
    }
};
int main()
{
    ios::sync_with_stdio(0); cin.tie(0);

    int t; cin >> t; while (t--) {
        int n, m, k; cin >> n >> m >> k;
        DinicFlow G(2+n+m);
        vi d(n);
        int src = n+m, snk = n+m+1;
        FOR (i, 0, m - 1) {
            int x, y; cin >> x >> y; --x, --y;
            G.addEdge(i, m + x, 1);
            G.addEdge(i, m + y, 1);
            G.addEdge(src, i, 1);
            d[x]++, d[y]++;
        }
        bool can = true;
        int demand = 0;
        FOR (i, 0, n - 1) {
            if (d[i] > 2*k) {
                can = false;
            } else if (d[i] > k) {
                G.addEdge(m + i, snk, 2 * (d[i] - k));
                demand += 2 * (d[i] - k);
            }
        }
        can &= G.maxFlow(src, snk) == demand;
        vi col(m);
        int ctr = 1;
        if (can) {
            vector<vi> at(n);
            for (auto e: G.e) {
                if (e.flow > 0 and e.x < m) {
                    at[e.y - m].push_back(e.x);
                }
            }
            FOR (i, 0, n - 1) {
                for (int j = 0; j < sz(at[i]); j += 2) {
                    col[at[i][j]] = col[at[i][j+1]] = ctr++;
                }
            }
            FOR (i, 0, m - 1) if (col[i] == 0) col[i] = ctr++;
        }

        for (int i: col) cout << i << " ";
        cout << "\n";
    }
    
    return 0;
}
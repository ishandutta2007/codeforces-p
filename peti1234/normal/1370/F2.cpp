#include <bits/stdc++.h>

using namespace std;
const int c=1002;
int w, n, dist[c][c], d[c], ert, p, x, y, db;
vector<int> sz[c], s;
string q;
bool v[c];
void kerd() {
    db++;
    cout << "? " << s.size() << " ";
    for (int i=0; i<s.size(); i++) cout << s[i] << " ";
    cout.flush() << "\n";
    s.clear();
}
void val(int x, int y) {
    cout << "! " << x << " " << y;
    cout.flush() << "\n";
    cin >> q;
}
void dfs(int a) {
    v[a]=true;
    for (int i=0; i<sz[a].size(); i++) {
        int x=sz[a][i];
        if (!v[x]) {
            dfs(x);
            dist[a][x]=1;
            for (int i=1; i<=n; i++) if (dist[x][i]) dist[a][i]=dist[x][i]+1;
        }
    }
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin >> w;
    while(w--) {
        cin >> n;
        for(int i=1; i<=n; i++) {
            s.push_back(i);
            sz[i].clear(), v[i]=0, d[i]=0, db=0;
            for (int j=1; j<=n; j++) dist[i][j]=0;
        }
        for (int i=1; i<n; i++) {
            int a, b;
            cin >> a >> b;
            sz[a].push_back(b), sz[b].push_back(a);
        }
        kerd();
        cin >> p >> ert, x=p;
        dfs(p);
        for (int i=1; i<=n; i++) for (int j=1; j<=n; j++) d[i]=max(d[i], dist[i][j]);
        for (int i=256; i>=1; i/=2) {
            for (int j=1; j<=n; j++) if (dist[x][j]==i && i+d[j]<512) s.push_back(j);
            if (s.size()>0) {
                kerd();
                int a, b;
                cin >> a >> b;
                if (b==ert) x=a;
            }
        }
        if (p==x) {
            for (int i=1; i<=n; i++) if (dist[p][i]==ert) s.push_back(i);
            kerd();
            cin >> y >> p;
        }
        else if (dist[p][x]==ert) y=p;
        else {
            for (int i=1; i<=n; i++) if (dist[p][i]+dist[p][x]==ert && dist[i][x]==0 && dist[x][i]==0 && x!=i) s.push_back(i);
            kerd();
            cin >> y >> p;
        }
        val(x, y);
    }
    return 0;
}
/*
1 8
2 4
1 8
5 6
5 7
8 2
3 7
7 4
*/
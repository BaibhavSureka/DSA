class DisjointSet {
public:
    vector<int> rank, parent, size;
    DisjointSet(int n) {
        rank.resize(n + 1, 0);
        parent.resize(n + 1);
        size.resize(n + 1);
        for (int i = 0; i <= n; i++) {
            parent[i] = i;
            size[i] = 1;
        }
    }

    int find(int x) {
        if (x == parent[x])
            return x;
        return parent[x] = find(parent[x]);
    }

    void unionByRank(int u, int v) {
        int a = find(u);
        int b = find(v);
        if (a == b) return;
        if (rank[a] < rank[b]) {
            parent[a] = b;
        }
        else if (rank[b] < rank[a]) {
            parent[b] = a;
        }
        else {
            parent[b] = a;
            rank[a]++;
        }
    }

    void unionBySize(int u, int v) {
        int a = find(u);
        int b = find(v);
        if (a == b) return;
        if (size[a] < size[b]) {
            parent[a] = b;
            size[b] += size[a];
        }
        else {
            parent[b] = a;
            size[a] += size[b];
        }
    }
};

class Solution {
public:
    int makeConnected(int n, vector<vector<int>>& edges) {
          DisjointSet ds(n);
        int cnt = 0;
        for(auto it : edges){
            int u = it[0];
            int v = it[1];
            if(ds.find(u) == ds.find(v)){
                cnt++;
            }
            else{
                ds.unionBySize(u,v);
            }
        }
        int cntc = 0;
        for(int i = 0 ; i < n ; i++){
            if(ds.parent[i]== i) cntc++;
        }
        int ans = cntc -1;
        if(cnt >= ans) return ans;
        return -1;
    }
};
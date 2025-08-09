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

    int findUPar(int node) {
        if (node == parent[node])
            return node;
        return parent[node] = findUPar(parent[node]);
    }

    void unionBySize(int u, int v) {
        int a = findUPar(u);
        int b = findUPar(v);
        if (a == b) return;
        if (size[a] < size[b]) {
            parent[a] = b;
            size[b] += size[a];
        } else {
            parent[b] = a;
            size[a] += size[b];
        }
    }
};

class Solution {
public:
    vector<vector<string>> accountsMerge(vector<vector<string>>& accounts) {
        int n = accounts.size();
        DisjointSet ds(n);
        unordered_map<string, int> mapmailnodes;

        for (int i = 0; i < n; i++) {
            for (int j = 1; j < accounts[i].size(); j++) { 
                string mail = accounts[i][j];
                if (mapmailnodes.find(mail) == mapmailnodes.end()) {
                    mapmailnodes[mail] = i;
                } else {
                    ds.unionBySize(i, mapmailnodes[mail]);
                }
            }
        }

        vector<vector<string>> mergemail(n);
        for (auto it : mapmailnodes) {
            string mail = it.first; 
            int node = ds.findUPar(it.second);
            mergemail[node].push_back(mail);
        }

        vector<vector<string>> ans;
        for (int i = 0; i < n; i++) {
            if (mergemail[i].empty()) continue;

            sort(mergemail[i].begin(), mergemail[i].end());
            vector<string> temp;
            temp.push_back(accounts[i][0]);
            temp.insert(temp.end(), mergemail[i].begin(), mergemail[i].end());

            ans.push_back(temp);
        }
        return ans;
    }
};

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    unordered_map<TreeNode*, vector<TreeNode*>> graph;
    
    void buildGraph(TreeNode* node, TreeNode* parent) {
        if (!node) return;
        if (parent) {
            graph[node].push_back(parent);
            graph[parent].push_back(node);
        }
        buildGraph(node->left, node);
        buildGraph(node->right, node);
    }

    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        buildGraph(root, nullptr);

        unordered_set<TreeNode*> visited;
        queue<TreeNode*> q;
        q.push(target);
        visited.insert(target);
        int currDist = 0;

        while (!q.empty()) {
            int size = q.size();
            if (currDist == k) break;
            while (size--) {
                TreeNode* node = q.front(); q.pop();
                for (auto neighbor : graph[node]) {
                    if (!visited.count(neighbor)) {
                        visited.insert(neighbor);
                        q.push(neighbor);
                    }
                }
            }
            currDist++;
        }
        vector<int> result;
        while (!q.empty()) {
            result.push_back(q.front()->val);
            q.pop();
        }
        return result;
    }
};

/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/

class Solution {
    unordered_map<int, Node*> mp;
    unordered_set<int> vis;

public:
    Node* cloneGraph(Node* node) {
        if(!node) return NULL;
        return dfs(node);
    }

private:
    Node* dfs(Node* node) {
        if(vis.count(node -> val)) return getNode(node);
        Node* curr = getNode(node);
        vis.insert(node -> val);
        for(auto neighbor: node -> neighbors) {
            curr -> neighbors.push_back(dfs(neighbor));
        }

        return curr;
    }

    Node* getNode(Node* node) {
        if(mp.find(node -> val) == mp.end()) {
            mp[node -> val] = new Node(node -> val);
        }
        return mp[node -> val];
    }
};
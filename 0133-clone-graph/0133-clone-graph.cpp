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
public:
    Node* cloneGraph(Node* node) {
        if(!node) return node;
        unordered_map<Node*, Node*> mp;
        queue<Node*> q;
        q.push(node);
        auto parentCopyNode = new Node(node->val);
        mp[node] = parentCopyNode;
        while(!q.empty()) {
            auto parent = q.front();
            q.pop();
            for(auto child: parent->neighbors) {
                if(mp.count(child) == 0) {
                    q.push(child);
                    auto copyNode = new Node(child->val);
                    mp[child] = copyNode;
                }
                mp[parent]->neighbors.push_back(mp[child]);
            }
        }
        
        return parentCopyNode;
    }
};
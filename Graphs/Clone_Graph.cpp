#include <unordered_map>
#include <vector>
#include <queue>
using namespace std;

// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;

    Node() : val(0), neighbors({}) {}

    Node(int _val) : val(_val), neighbors({}) {}

    Node(int _val, vector<Node*> _neighbors) : val(_val), neighbors(_neighbors) {}
};

class Solution {
public:
    Node* cloneGraph(Node* node) {
        if (!node) return nullptr;

        unordered_map<Node*, Node*> visited; // Original -> Clone
        queue<Node*> q;

        // Clone the first node and put it in the map
        visited[node] = new Node(node->val);
        q.push(node);

        while (!q.empty()) {
            Node* current = q.front();
            q.pop();

            for (Node* neighbor : current->neighbors) {
                // If neighbor not visited, clone and queue it
                if (visited.find(neighbor) == visited.end()) {
                    visited[neighbor] = new Node(neighbor->val);
                    q.push(neighbor);
                }
                // Add cloned neighbor to current cloned node
                visited[current]->neighbors.push_back(visited[neighbor]);
            }
        }

        return visited[node];
    }
};

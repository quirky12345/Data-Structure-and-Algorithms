#include<bits/stdc++.h>
using namespace std;
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
Node* cloneGraph(Node* src) {
        if(!src)return NULL;
        map<Node*, Node*> m;
        queue<Node*> q;

        // Enqueue src node
        q.push(src);
        Node *node;

        // Make a clone Node
        node = new Node(src->val);
        //node->val = src->val;

        // Put the clone node into the Map
        m[src] = node;
        while (!q.empty())
        {
            //Get the front node from the queue
            //and then visit all its neighbours
            Node *u = q.front();
            q.pop();
            vector<Node *> v = u->neighbors;
            int n = v.size();
            for (int i = 0; i < n; i++)
            {
                // Check if this node has already been created
                if (m[v[i]] == NULL)
                {
                    // If not then create a new Node and
                    // put into the HashMap
                    node = new Node(v[i]->val);
                    //node->val = v[i]->val;
                    m[v[i]] = node;
                    q.push(v[i]);
                }

                // add these neighbours to the cloned graph node
                m[u]->neighbors.push_back(m[v[i]]);
            }
        }

        // Return the address of cloned src Node
        return m[src];
}
int main(){
    //make your own graph as per your convinience
    return 0;
}
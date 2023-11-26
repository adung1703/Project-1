#include <bits/stdc++.h>
using namespace std;

struct Node {
    int id;
    vector<Node*> children;
    Node(int val) : id(val) {}
};

Node* makeRoot(int u) {
    return new Node(u);
}

void findNode(Node* root, int id, Node*& result) {
    if (!root) return;
    if (root->id == id) {
        result = root;
        return;
    }
    for (Node* child : root->children) {
        findNode(child, id, result);
    }
}


void insert(int u, int v, Node* root) {
    Node* node = nullptr;
    findNode(root, v, node);
    if (node) {
        Node* new_node = new Node(u);
        node->children.push_back(new_node);
    }
}

void preOrder(Node* root) {
    if (!root) return;
    cout << root->id << " ";
    for (Node* child : root->children) {
        preOrder(child);
    }
}

void inOrder(Node* root) { 
    if (!root) return;
    if (root->children.size() > 1) inOrder(root->children[0]);
    cout << root->id << " ";
    if (root->children.size() > 1) {
    	for (int i = 1; i < root->children.size(); i++) inOrder(root->children[i]);
	}
}

void postOrder(Node* root) {
    if (!root) return;
    for (Node* child : root->children) {
        postOrder(child);
    }
    cout << root->id << " ";
}

int main() {
    Node* root = makeRoot(0); 
    string s;

    while (cin >> s) {
        if (s == "MakeRoot") {
            int u;
            cin >> u;
            root->id = u;
        } else if (s == "Insert") {
            int u, v;
            cin >> u >> v;
            insert(u, v, root);
        } else if (s == "PreOrder") {
            preOrder(root);
            cout << endl;
        } else if (s == "InOrder") {
            inOrder(root);
            cout << endl;
        } else if (s == "PostOrder") {
            postOrder(root);
            cout << endl;
        } else if (s == "*") {
            break;
        }
    }

    return 0;
}


#include <bits/stdc++.h>
using namespace std;

typedef struct node{
	int key;
	struct node *leftchild;
	struct node *rightchild;
} Node;

int getNum(string s) {
	int i = 0;
	while (s[i] != ' ') i++;
	string x = s.substr(i+1, s.length()-i-1);
	return stoi(x);
}

Node* makeNewNode (int key) {
	Node *x = (Node*)malloc(sizeof(Node)); 
	x->key = key;
	x->leftchild = NULL;
	x->rightchild = NULL;
	return x;
}

void preOrder(Node *p) {
	if (p == NULL) return;
	cout << p->key << " ";
	preOrder(p->leftchild);
	preOrder(p->rightchild);
}

void insert(Node *root, int key) {
	if (root == NULL) {
		root->key == key;
		return;
	}
	
	if (key < root->key) { //Nut con nho hon nut cha
		if (root->leftchild == NULL) {
			root->leftchild = makeNewNode(key);
			return;
		} else insert(root->leftchild, key);
		
	} else if (key > root->key) {
		if (root->rightchild == NULL) { //Nut con lon hon nut cha
			root->rightchild = makeNewNode(key);
			return;
		} else insert(root->rightchild, key);
	}
}

int main(){
	string s;
	getline(cin, s);
	int n = getNum(s);
	Node *root = makeNewNode(n);
	
	while (s != "#") {
		getline(cin, s);
		if (s.substr(0,6) == "insert") {
			int n = getNum(s);
			insert(root, n);
		}
	}
	
	preOrder(root);

}

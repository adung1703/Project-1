#include <bits/stdc++.h>
using namespace std;

typedef struct Node{
	int key;
	struct Node* next;
}Node;

Node* makeNode(int X){
	Node* p=NULL;
	p = (Node*)malloc(sizeof(Node));
	p->key=X;
	p->next=NULL;
	return p;
}

void print(Node *head){
	Node *p=head;
	while(p!=NULL){
		cout << p->key << " ";
		p=p->next;
	}
	cout << endl;
}

Node* find(Node* head, int key) {
	Node *p;
	p = head;
	while (p != NULL) {
		if (p->key == key) break;
		p = p->next;
	}
	return p;
}

Node* findNext(Node* head, int key) {
	Node *p;
	p = head;
	while (p != NULL) {
		if (p->next->key == key) break;
		p = p->next;
	}
	return p;
}

void addlast (Node *head, int key){
	if (find(head, key) != NULL) return;
	Node *p = head;
	while (p->next != NULL) p = p->next;
	p->next = makeNode(key);
}

Node* addfirst (Node *head, int key){
	if (find(head, key) != NULL) return head;
	Node *p = makeNode(key);
	p->next = head;
	return p;
}

void addafter(Node *head, int u, int v){
	if (find(head, u) != NULL) return;
	Node *q = find(head, v);
	if (q == NULL) return;
	Node *t = makeNode(u);
	t->next = q->next;
	q->next = t;
}

void addbefore(Node *head, int u, int v){
	if (find(head, u) != NULL) return;
	Node *q = findNext(head, v);
	if (q == NULL) return;
	Node *t = makeNode(u);
	t->next = q->next;
	q->next = t;
}

void remove(Node* head, int k){
	if (head == NULL) return;
	if (head->key == k) {
		Node *t = head;
		head = head->next;
		free(t);
		return;
	}
	Node *p = head;
	while (p->next != NULL) {
		if(p->next->key == k) {
			Node *t = p->next;
			p->next = p->next->next;
			free(t);
			return;
		}
		p = p->next;
	}
}

Node* reverse(Node *head) {
	if ((head == NULL)||(head->next == NULL))  return head;
	if(head->next->next == NULL){
		head->next->next = head;
		Node *tmp = head->next;
		head->next=NULL;
		return tmp;
	}
	else{
		Node *p=reverse(head->next);
		head->next->next = head;
		head->next = NULL;
		return p;
	}
}

int main(){
	Node *old_p ,*p, *head=NULL;
	int i, n;
	cin >> n;
	for(i = 0; i < n; i++){
		int a;
		cin.ignore();
		cin >> a;
		p = makeNode(a);
		if(i == 0){
			head=p;
		}
		else{
			old_p->next=p;
		}
		old_p=p;
	}
	
	string s;
	cin.ignore();
	cin >> s;
	while (s != "#") {
		if(s == "addlast") {
			int k;
			cin >> k;
			addlast(head, k);
		}
		else if(s == "addfirst") {
			int k;
			cin >> k;
			head = addfirst(head, k);
		}
		else if(s == "addafter") {
			int u, v;
			cin >> u >> v;
			addafter(head, u, v);
		}
		else if(s == "addbefore") {
			int u, v;
			cin >> u >> v;
			addbefore(head, u, v);
		}
		else if(s == "remove") {
			int k;
			cin >> k;
			remove(head, k);
		}
		else if(s == "reverse") {
			reverse(head);
		}
		cin.ignore();
		cin >> s;
	}
	print(head);

	
	return 0;
}

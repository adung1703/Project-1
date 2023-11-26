#include <bits/stdc++.h>

using namespace std;

int main() {
    int n;
    cin >> n;
    
    list<int> linkedList;
    
    for (int i = 0; i < n; i++) {
        int a;
        cin >> a;
        linkedList.push_back(a);
    }
    
    while (1) {
        string s;
        cin >> s;
        if (s == "addlast") {
        	int k;
	        cin >> k;
	        bool h = false;
	        for (auto a : linkedList) {
	        	if (a == k) {
	        		h = true;
	        		break;
				}
			}
        	if(!h) linkedList.push_back(k);
            
        } else if (s == "addfirst") {
            int k;
            cin >> k;
            bool h = false;
            for (auto a : linkedList) {
	        	if (a == k) {
	        		h = true;
	        		break;
				}
			}
        	if(!h) linkedList.push_front(k);
            
        } else if (s == "addafter") {
            int u, v;
            cin >> u >> v;
            bool h = false;
            for (auto a : linkedList) {
	        	if (a == u) {
	        		h = true;
	        		break;
				}
			}
			auto it = find(linkedList.begin(), linkedList.end(), v);
            if (!h && it != linkedList.end()) {
                advance(it, 1);
                linkedList.insert(it, u);
            }
            
        } else if (s == "addbefore") {
            int u, v;
            cin >> u >> v;
            bool h = false;
            for (auto a : linkedList) {
	        	if (a == u) {
	        		h = true;
	        		break;
				}
			}
            auto it = find(linkedList.begin(), linkedList.end(), v);
            if (!h && it != linkedList.end()) {
                linkedList.insert(it, u);
            }
            
        } else if (s == "remove") {
            int k;
            cin >> k;
            linkedList.remove(k);
            
        } else if (s == "reverse") {
            linkedList.reverse();
            
        } else if (s == "#") {
            break;
        }
    }
    
    for (int a : linkedList) { 
        cout << a << " ";
    }
    
    return 0;
}


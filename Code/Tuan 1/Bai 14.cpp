//C/C++ 
#include <bits/stdc++.h> 
using namespace std;

int main() {
    
    string P1, P2, T;
    getline(cin, P1);
    getline(cin, P2);
    getline(cin, T);

    int found = T.find(P1);
    while (found != string::npos) {
        T.replace(found, P1.length(), P2);
        found = T.find(P1, found + P2.length());
    }

    cout << T << endl;

    return 0;
}


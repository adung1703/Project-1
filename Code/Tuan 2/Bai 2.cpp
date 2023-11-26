#include <bits/stdc++.h>
using namespace std;

void gen(int n, string s) {
    if (n == 0) {
        cout << s << endl;
    } else {
        gen(n - 1, s + '0');
        gen(n - 1, s + '1');
    }
}

int main() {
    int n;
    cin >> n;
    string s = "";
    gen(n, s);

    return 0;
}


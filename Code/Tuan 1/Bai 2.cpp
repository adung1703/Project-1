//C/C++ 
#include <bits/stdc++.h> 
using namespace std;

int main() 
{ 
int n, m;
cin >> n;
if (100%n == 0) m = 100/n;
else m = 100/n+1;
for (int i = m; i <= 999/n; i++) cout << i*n << " ";
return 0;
}

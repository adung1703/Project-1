//C/C++ 
#include <bits/stdc++.h> 
using namespace std;

int main() { 
	float a, b, c;
	cin >> a >> b >> c;
	float delta = b*b - 4*a*c;
	if (delta < 0) cout << "NO SOLUTION";
	else if (delta == 0) cout << setprecision(2) << fixed << -b/(2*a);
	else {
		cout << setprecision(2) << fixed << (-b-sqrt(delta))/(2*a) << " " <<
		setprecision(2) << fixed << (-b+sqrt(delta))/(2*a);
	}
}

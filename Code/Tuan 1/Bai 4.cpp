#include <iostream>
#include <cctype>
using namespace std;

int main() {
	string text;
	while (getline(cin,text)){

    for (char &c : text) {
        c = toupper(c);
    }

    cout << text << std::endl;
	}
    return 0;
}


#include <iostream>
using namespace std;

int main() {
    string line, s;

    while (getline(cin, line)){
        if (line.empty()) break;
        s.append(line);
    }

    cout<<s;
}
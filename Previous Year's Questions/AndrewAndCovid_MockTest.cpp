#include <iostream>
#include <unordered_map>
using namespace std;

int Solution(string s) {
    int n = s.length();
    int countOfCovid = INT_MAX;
    unordered_map<char, int> freq;

    for (int i = 0; i < n; i++) {
        if (s[i] == 'c' || s[i] == 'o' || s[i] == 'v' || s[i] == 'i' || s[i] == 'd') freq[s[i]]++;
    }

    if (freq.size() == 5) {
        for (const auto &itr : freq) countOfCovid = min(countOfCovid, itr.second);
        return countOfCovid;
    }

    return 0;
}

int main(){
    string line, s;

    cout<<"Enter the string : ";
    while (getline(cin, line)){
        if (line.empty()) break;
        s.append(line);
    }

    cout<<"Maximum number of times Andrew can form covid from the given string is : "<<Solution(s);

    return 0;
}
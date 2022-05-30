#include <iostream>
#include <unordered_map>
using namespace std;

int Solution(string s) {
    int n = s.length();
    int i = 0, j = 0;
    int ls = 0;
    unordered_map<char, int> freq;

    while (j < n) {
        freq[s[j]]++;
        
        if (freq.size() == j - i + 1) {
            ls = max(ls, j - i + 1);
            j++;
        }

        else if (freq.size() < j - i + 1) {
            while (freq.size() < j - i + 1) {
                freq[s[i]]--;
                if (freq[s[i]] == 0) freq.erase(s[i]);
                i++;
            }
            j++;
        }
    }

    return ls;
}

int main(){
    string s;
    cout<<"Enter the string : "; cin>>s;
    cout<<"\nThe longest substring of non repeating characters is of size : "<<Solution(s);
    return 0;
}
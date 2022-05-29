#include <iostream>
#include <map>

using namespace std;


int CountAnagrams (string s, string p) {
    int n = s.length(), k = p.length();
    map<char, int> freq;
    int Count = 0, nAnagrams = 0;

    for (auto &i : p) {
        freq[i]++;
    }

    Count = freq.size();
    int i = 0, j = 0;

    while (j < n) {
        if (freq.find(s[j]) != freq.end()) {
            freq[s[j]]--;
            if (freq[s[j]] == 0) Count--;
        }

        if (j - i + 1 < k) j++;

        else if (j - i + 1 == k) {
            if (Count == 0) nAnagrams++;

            if (freq.find(s[i]) != freq.end()) {
                freq[s[i]]++;
                if (freq[s[i]] == 1) Count++;
            }

            i++; j++;
        }
    }

    return nAnagrams;
}


int main() {
    string s;
    string p;
    cout<<"Enter the string : "; cin>>s;
    cout<<"\nEnter the pattern : "; cin>>p;
    cout<<"\nNumber of anagrams of pattern in string is : "<<CountAnagrams(s, p);

    return 0;
}
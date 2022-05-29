#include <iostream>
#include <map>
using namespace std;

int LongestSubstring(string s, int k) {
    int n = s.length();
    int i = 0, j = 0;
    int ls = 0;
    map<char, int> freq;

    while (j < n) {
        freq[s[j]]++;

        if (freq.size() == k) ls = max(ls, (j - i + 1));

        else if (freq.size() > k) {
            while (freq.size() > k) {
                freq[s[i]]--;
                if (freq[s[i]] == 0) freq.erase(s[i]);
                i++;
            }
            freq[s[j--]]--;
        }

        j++;
    }

    return ls; 
}


int main() {
    string s;
    cout<<"Enter the string : "; cin>>s;

    int k;
    cout<<"\nEnter the number of unique characters to be present in the substring : "; cin>>k;

    cout<<"\nThe longest substring of "<<k<<" unique characters is of size : "<<LongestSubstring(s, k);

    return 0;
}
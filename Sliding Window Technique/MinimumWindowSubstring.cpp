#include <iostream>
#include <unordered_map>

using namespace std;


int Solution(string s, string p) {
    int n = s.length();
    int m = p.length();
    int i = 0, j = 0;
    int Count = INT_MAX;
    int l = INT_MAX;
    unordered_map<char, int> freq;

    for (int i = 0; i < m; i++) freq[p[i]]++;
    Count = freq.size();

    if (m < n) {
        while (j < n) {
            if (freq.find(s[j]) != freq.end()) {
                freq[s[j]]--; 
                if (freq[s[j]] == 0) Count--;
            }

            if (Count > 0) j++;

            if (Count == 0) {
                l = min(l, j - i + 1);
                while (Count == 0 && i <= j){
                    if (freq.find(s[i]) != freq.end()){
                        freq[s[i]]++;
                        if (freq[s[i]] == 1) {
                            l = min(l, j - i + 1);
                            Count++;
                        }
                    }
                    i++;
                }
                j++;
            }
        }
        
        return l;
    }

    else return -1;
}

int main() {
    string s;
    string p;
    cout<<"Enter the string : "; cin>>s;
    cout<<"\nEnter the pattern : "; cin>>p;
    cout<<"\nThe length of Minimum Window Substring is : "<<Solution(s, p);

    return 0;
}
//Problem Statement 

/*
Limak likes palindromes and recently he came across a simple problem in which he was given a string and he had to report the total number of unique palindromes of length 3 which can be formed by using the characters of the string. Also, he was supposed to list out in lexicographical order all the palindromes of length 3 with each palindrome in a separate line.

Input Format

The first line of input contains the length of the string and it is followed by a string of the above mentioned length.

Constraints

1 <= length of string <= 100000
The string consists of lowercase alphabets

Output Format

The first line of input should be an integer which is the total number of unique palindromes of length 3 which can be formed by using the characters in the string. The following lines consist of all unique palindromes of length 3 which are arranged in lexicographical order and can be formed using the characters in the string.

SAMPLE INPUT : 
4
aabc


SAMPLE OUTPUT :
2
aba
aca

Explanation 0

In this sample test case, we can form two palindromes of length 3 by using the characters in the string. When printed in lexicographical order, aba and aca is printed.
*/



//SOLUTION : 

#include<iostream>
#include <cstring>
#include <map>
using namespace std;


int main() {
//Step 1 : 
    //Input 1 : size of string
    int n;
    cin>>n;
    cin.ignore(); //for taking the string input on nextline

    //Input 2: the string or character array of length n
    char s[n+1];
    cin.getline(s, n+1);



//Step 2 : 
    //using a map to store the frequencies of each character in sorted form. Using map instead of unordered_map, because map sorts the keys whereas unordered_map doesnt.
    map<char, int> freq;

    //iterating over the caracter array to get their frequencies
    for (int i = 0; i < n  ; i++) {
        freq[s[i]] += 1;
    }

    //printing the frequency map and its size
    cout<<"size : " << freq.size()<<"\n";

    for (const auto &x : freq) {
        cout<<"["<<x.first<<" : "<<x.second<<"]"<<"\n";
    }
    



//Step 3:
    //the count variable is used to get the number of possible palindromes of length 3 from the given character array/ string 
    static int count = 0;
    for (const auto &i : freq) {
        if (i.second == 2) {
            count += freq.size() - 1;
        }

        else if (i.second >= 3) {
            count += freq.size();
        }
    }

    //printing the no. of possible palindromes of length 3
    cout<<"\nNumber of possible palindromes of length 3 in given string : "<<count<<"\n";
   


//Step 4: 
   //printing all the possible palindromes of length 3 in lexicographical order
    for (const auto &p : freq) {
        if (p.second >= 2) {
            for (const auto &q : freq) {
                if (p.second == 2 && q.first != p.first) {
                    cout<<p.first<<q.first<<p.first<<"\n";
                }

                else if (p.second >= 3) {
                    cout<<p.first<<q.first<<p.first<<"\n";
                } 
            }
        }
    }


    return 0;
}
#include <bits/stdc++.h>
using namespace std;

int main() {
    //1st Example
    char s1[100] = "Today is a rainy day!";
    char *ptr1 = strtok(s1, " "); //takes 2 args string itself and the delimeter, in this case delimeter is whitespace; while we print this only the first token will be printed as we passed s which contains the address of the 1st token. In order to print all the tokens according the the delimeter condition we can use while loop
    cout<<ptr1<<"\n";
    while (ptr1 != NULL) {
        ptr1 = strtok(NULL, " ");
        cout<<ptr1<<"\n"; 
    }


    //2nd Example 
    char s2[100] = "It-is-raining-cats-&-dogs!";
    char *ptr2 = strtok(s2, "-"); //delimeter in this case is '-'
    cout<<ptr2<<"\n";
    while (ptr2 != NULL) {
        ptr2 = strtok(NULL, "-");
        cout<<ptr2<<"\n";
    }

    return 0;
}
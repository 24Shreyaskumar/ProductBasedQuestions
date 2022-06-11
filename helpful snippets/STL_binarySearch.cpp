#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    int n; cin>>n;
    vector<int> arr;
    for (int i= 0; i < n; i++) {
        int x; cin>>x; arr.push_back(x);
    }
    int key; cin>>key;

    bool isPresent = binary_search(arr.begin(), arr.end(), key);

    if (isPresent) {
        auto lowerBound = lower_bound(arr.begin(), arr.end(), key);
        cout<<key<<" found at index : "<<(lowerBound - arr.begin())<<"\n";
    }

    else cout<<key<<" not found!\n";

    return 0;
}

//note : in order to find the occurences of an element in a sorted array we can use lower_bound and upper_bound functions , e.g. : int occurences = upper_bound(arr, arr + n, key) - lower_bound(arr, arr + n, key); return occurences;
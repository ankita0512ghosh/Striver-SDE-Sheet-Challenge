#include <iostream>
#include <queue>
#include <vector>
using namespace std; 

#define NO_OF_CHARS 256

bool areAnagram(string &str1, string &str2){
    int hash[NO_OF_CHARS] = { 0 };
    int i;

    int n1 = str1.length();
    int n2 = str2.length();
    if (n1 != n2){
       return false;
    }
    for (i = 0; i < n1; i++){
        hash[str1[i]]++;
        hash[str2[i]]--;
    }

    for (i = 0; i < NO_OF_CHARS; i++){
        if (hash[i]){
            return false;
        }
    }
    return true;
}
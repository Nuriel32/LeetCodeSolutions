// you can use includes, for example:
// #include <algorithm>

// you can write to stdout for debugging purposes, e.g.
// cout << "this is a debug message" << endl;
#include<String>
int solution(String &S) {
    
    int maxLength = -1;
     int start = 0;
     int N = S.length();
 
     if(N == 0)
     {
         return 0;
     }
 
     for (int i = 0; i <= N; i++) {
         if (i == N || S[i] == ' ') {
             int wordLen = i - start;
             if (wordLen > 0) {
                 string word = S.substr(start, wordLen);
 
                 bool isAlnum = true;
                 int letterCount = 0;
                 int digitCount = 0;
 
                 for(char c : word) {
                     if (!((c >= '0' && c <= '9') ||
                           (c >= 'A' && c <= 'Z') ||
                           (c >= 'a' && c <= 'z'))) {
                         isAlnum = false;
                         break;
                     }
 
                     if ((c >= 'A' && c <= 'Z') || (c >= 'a' && c <= 'z'))
                         letterCount++;
                     else if (c >= '0' && c <= '9')
                         digitCount++;
                 }
 
                 if (isAlnum &&
                     letterCount % 2 == 0 &&
                     digitCount % 2 == 1) {
                     maxLength = max(maxLength, wordLen);
                 }
             }
 
             start = i + 1;
         }
     }
 
     return maxLength;
 }
 
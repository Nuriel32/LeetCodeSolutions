/ you can use includes, for example:
// #include <algorithm>

// you can write to stdout for debugging purposes, e.g.
// cout << "this is a debug message" << endl;
/*A non-empty array A consisting of N integers is given. The unique number is the number that occurs exactly once in array A.

For example, the following array A:

  A[0] = 4
  A[1] = 10
  A[2] = 5
  A[3] = 4
  A[4] = 2
  A[5] = 10
contains two unique numbers (5 and 2).

You should find the first unique number in A. In other words, find the unique number with the lowest position in A.

For above example, 5 is in second position (because A[2] = 5) and 2 is in fourth position (because A[4] = 2). So, the first unique number is 5.

Write a function:*/

#include <unordered_map>
 int solution(vector<int> &A) {
     if(A.size() == 0){return -1;}
    unordered_map<int, int> count;

    for (auto& num : A) {
        count[num]++;
    }

    for (auto&  num : A) {
        if (count[num] == 1) return num;
    }

    return -1;
}

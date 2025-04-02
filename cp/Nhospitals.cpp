/*There are N hospitals, numbered from 0 to N−1. You are given a schedule of work in each of the hospitals for the following M days.
 The schedule is provided in the form of a two-dimensional array A containing N rows, each row representing the schedule of one hospital,
  and M columns, each column representing one day. Integer A[K][L] (for K within the range [0..N−1] and L within the range [0..M−1])
  represents the ID of the doctor working at hospital K on day L. 
  Note that sometimes an individual doctor may work at more than one hospital even on the same day.

Write a function:*/
#include <iostream>
#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <cstdlib>     // for srand, rand
#include <ctime>       // for time
#include <utility>     // for pair
using namespace std;


int solution(const vector<vector<int>>& A)
{
    int N = A.size();
    if (N == 0) return 0;
    int M = A[0].size();
    if (M == 0) return 0;


    unordered_map<int, unordered_set<int>> doctor_map;

    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < M; ++j) {
            doctor_map[A[i][j]].insert(i);
        }
    }

    int count = 0;
    for (auto it = doctor_map.begin(); it != doctor_map.end(); ++it) {
        const int& doctor = it->first;
        const unordered_set<int>& hospitals = it->second;
        if (hospitals.size() > 1)
            count++;
    }
    
    return count;
}
// The function takes a 2D vector A as input, where A[i][j] represents the ID of the doctor working at hospital i on day j.

//test case generator  



int main() {
    srand(time(0));
    
    vector<pair<int, int>> sizes = {
        {1, 1}, {2, 2}, {5, 5}, {10, 10}, {100, 100}, {500, 100}, {1000, 1}, {50, 1000}, {1000, 1000}
    };

    for (auto [N, M] : sizes) {
        cout << "Testing N = " << N << ", M = " << M << "...\n";
        vector<vector<int>> testMatrix = generateMatrix(N, M);
        int result = solution(testMatrix);
        cout << "Result: " << result << "\n\n";
    }

    return 0;
}
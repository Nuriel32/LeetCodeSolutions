#include <algorithm>
#include <vector>
#include <unordered_map>
using namespace std;

int solution(vector<int> &A, int X) {

    if(A.size() < 2 )
    {
        return 0;
    }
    //creating a map to count for each element how many we have 
    unordered_map<long,long> count_map;

    for(auto& num : A)
    {
        count_map[num]++;
    }
    //creating a vector array of uniqe elements we have in the array A
    vector<long long > lengths;
    long long  counter=0;//count how many diffrent rectangles we can create.

    for (auto& entry : count_map) {
        if (entry.second >= 2) {
            lengths.push_back(entry.first);
            if(entry.second >= 4 && (long long)entry.first * entry.first >= X)
                counter++;
        }
    }
    //Sorting the array in order to progress 2 poitners search.
    sort(lengths.begin(), lengths.end());

    long left= 0, right = lengths.size() -1 ;//pointers to the array.

    while (left <= right) {
        long long a = lengths[left];
        long long b = lengths[right];

        if (a * b >= X) {
            counter += (right - left);
            right--;
        } else {
            left++;
        }

        if(counter > 1000000000){return -1;}
    }

    return (int)counter;
}
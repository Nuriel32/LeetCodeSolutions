#include <vector>
#include <unordered_set>
using namespace std;

int solution(vector<int> &A) {
    unordered_set<int> nums;
    
    for (int num : A) {
        if (num > 0) {
            nums.insert(num);
        }
    }

    for (int i = 1; i <= A.size() + 1; i++) {
        if (nums.find(i) == nums.end()) {
            return i;
        }
    }

    return 1; 
}
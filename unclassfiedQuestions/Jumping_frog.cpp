#include <vector>
#include <unordered_set>
using namespace std;

//to 

int solution(int X, const vector<int>& A) {
    unordered_set<int> positions;
    
    for (int time = 0; time < A.size(); ++time) {
        int pos = A[time];
        
        // אם זו הפעם הראשונה שיש עלה במיקום הזה
        if (pos <= X && positions.find(pos) == positions.end()) {
            positions.insert(pos);
        }
        
        // אם כל העמדות מכוסות — נחזיר את הזמן
        if (positions.size() == X) {
            return time;
        }
    }

    return -1; // הצפרדע לא תוכל לעבור לעולם
}

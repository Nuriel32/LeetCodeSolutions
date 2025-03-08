#include <iostream>
#include <stack>
using namespace std;
class MinStack {

    private:
    stack<int> regstk;
    stack<int> minstack;

    public:
        MinStack() {}
        
        void push(int val) {


            regstk.push(val);
            if(minstack.empty() || val <= minstack.top())
            {
                minstack.push(val);
            }

        }
        
        void pop() {
            if(minstack.top() == regstk.top())
            {
                minstack.pop();
            }
            regstk.pop();
            
        }
        
        int top() {
            return regstk.top();
            
        }
        
        int getMin() {
           return minstack.top();
            
        }
    };
    
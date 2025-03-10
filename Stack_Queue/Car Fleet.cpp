using namespace std;
#include<algorithm>
#include <iostream>
#include <stack>
#include<vector>
class Solution {
struct Car {
    int position; 
    int speed;     
};


public:
static bool compare(const Car &a, const Car &b) {
    return a.position < b.position;  
}
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
    
    vector<Car> cars;
    stack<double            > fltCars;
    for(int i= 0; i < position.size();i++ )
    {
        cars.push_back({position[i], speed[i]});

    }
    if (cars.empty()) return 0;

    sort(cars.begin(),cars.end(),compare);
     double timeforfirstcar = (target-cars[0].position)/cars[0].speed;
     fltCars.push(timeforfirstcar);
    for(int i = 1;i<cars.size();i++)
    {
    double timecurcar = (double)(target - cars[i].position) / cars[i].speed;
     if(timecurcar <fltCars.top())
        {
            fltCars.push(timecurcar);
        }
    }

    int response =0;
    while (!fltCars.empty()) {
    response++;
    fltCars.pop();
}
        return response;
    }
};

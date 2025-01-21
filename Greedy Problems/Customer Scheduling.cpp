#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int calculateWaitingTime(vector<int> &serviceTimes){

    int totalWaitingTime = 0, currTime = 0;
    int sz = serviceTimes.size();
    for(int i=0;i<sz;i++){
        totalWaitingTime+=currTime;
        currTime+=serviceTimes[i];
    }
    return totalWaitingTime;
}

int main(){

    vector<int> serviceTimes = {4,3,1,2};

    int unSortedWaitingTime = calculateWaitingTime(serviceTimes);
    sort(serviceTimes.begin(), serviceTimes.end());

    int sortedWaitingTime = calculateWaitingTime(serviceTimes);

    cout<<"Unsorted waiting time: "<<unSortedWaitingTime<<"\n Sorted waiting time: "<<sortedWaitingTime<<"\n";

    return 0;
}
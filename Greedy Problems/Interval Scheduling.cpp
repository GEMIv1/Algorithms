#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct interval {
    int start, end;

    interval(int s, int e) : start(s), end(e) {}
};

bool compare(interval& a,  interval& b) {
    return a.end < b.end;
}

int main() {
    vector<interval> intervals = {
        {4, 5},
        {0, 2},
        {2, 7},
        {1, 3},
        {0, 4}
    };

    sort(intervals.begin(), intervals.end(), compare);

    int count = 0;  
    int end = 0;    
    vector<interval> answer; 

    for (const auto& i : intervals) {
        if (end <= i.start) {
            end = i.end;
            count++;     
            answer.push_back(i);
        }
    }

    cout << "The maximum events a person can attend is: " << count << endl;
    cout << "List of intervals in which person will attend events: [";
    for (int i = 0; i < answer.size(); ++i) {
        cout << "(" << answer[i].start << ", " << answer[i].end << ")";
        if (i < answer.size() - 1) cout << ", ";
    }
    cout << "]" << endl;

    return 0;
}

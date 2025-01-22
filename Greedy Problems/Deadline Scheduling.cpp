#include <iostream>
#include <algorithm>
using namespace std;

struct Job {
    char id;    
    int dead;   
    int profit; 
};

bool comparison(Job a, Job b) {
    return (a.profit > b.profit);
}

void JobScheduling(Job arr[], int n) {
    sort(arr, arr + n, comparison); 
    
    bool slot[n] = {false}; 
    char result[n] = {0};
    
    for (int i = 0; i < n; i++) {
        if(slot[arr[i].dead] == false) {
            result[i] = arr[i].id; 
            slot[arr[i].dead] = true; 
        }
    }

     for (int i = 0; i < n; i++) {
        if (slot[arr[i].dead]) {   // If the slot was filled
            if(result[i] != 0) cout << result[i] << " "; 
        }
    }


}

int main(){

        Job arr[] = { {'a', 2, 100}, 
                  {'b', 1, 19}, 
                  {'c', 2, 27}, 
                  {'d', 1, 25}, 
                  {'e', 3, 15} };

        JobScheduling(arr, 5);
        
    return 0;
} 
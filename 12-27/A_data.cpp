#include <iostream>
#include <vector>
#include <ctime>
#include <cstdlib>

using namespace std;

int main() {
    srand(time(0)); 

    int id = 1;
    int n = rand() % 100 + 1; 
    
    cout << id << " " << n << endl;
    for (int i = 0; i < n; i++) {
        
        
        int val = rand() % (n + 2); 
        if (val >= n) val = n - 1; 
        cout << val << (i == n - 1 ? "" : " ");
    }
    cout << endl;

    return 0;
}
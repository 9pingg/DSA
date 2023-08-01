#include <bits/stdc++.h>
using namespace std;

// atomic<int> x;

// void task(){
//     const int N = 1e7;
//     for(int i = 0 ; i < N ; i++){
//        x++; // tries to complete in 1 cycle instead of 2
//        x = x+1; // this cannot be calc in 1 cycle so atomic doesnt help here
//     }
// }

pthread_mutex_t a; //lock variable which should reside in shared memory
int x;
void task(){
    const int N = 1e7;
    for(int i = 0 ; i < N ; i++){
        pthread_mutex_lock(&a);
            x++;
        pthread_mutex_unlock(&a);
    }
}
int main(){
    thread t1(task);
    thread t2(task);
    t1.join();
    t2.join();
    cout << x;
    return 0;
}
#include<iostream>
#include<vector>
using namespace std;
int main(){

}
// Input: 
// pid =  [1, 3, 10, 5]
// ppid = [3, 0, 5, 3]
// kill = 5
// Output: [5,10]
// Explanation: 
//            3
//          /   \
//         1     5
//              /
//             10
// Kill 5 will also kill 10.
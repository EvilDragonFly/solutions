#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    bool canPlaceFlowers(vector<int>& flowerbed, int n) {
        //贪心算法，一个一个种，结果能全部种上，就是成功的
        int len= flowerbed.size();
        for(int i=0; i<len; i++){
            if( flowerbed[i]==0 && (i-1<0||flowerbed[i-1]==0) && (i+1>=len||flowerbed[i+1]==0)){
                flowerbed[i]=1;         //注意得将符合的地方标记已种上花
                n--;
            }
        }
        if (n<=0){
            return true;
        }else{
            return false;
        }
    }
};
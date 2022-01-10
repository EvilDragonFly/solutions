#include<algorithm>
using namespace std;
class Solution {
public:
    int computeArea(int ax1, int ay1, int ax2, int ay2, int bx1, int by1, int bx2, int by2) {
        int area1 = (ax1-ax2)*(ay1-ay2);
        int area2 = (bx1-bx2)*(by1-by2);
        if (ax1>=bx2 || ax2<=bx1 || ay1>=by2 || ay2<=by1){      //以矩形为中心，分析不重合的四个情况
            return area1 + area2;
        }
        int topx = min(ax2, bx2);
        int topy = min(ay2,by2);
        int bottomx = max(ax1,bx1);
        int bottomy = max(ay1,by1);
        int area3 = (topx-bottomx)*(topy-bottomy);
        // 处理包容情况
        return area1-area3+area2;       //int_max = 21亿, area_max = 4亿

    }
};
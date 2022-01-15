#include <iostream>
#include <map>
#include <vector>
#include <algorithm>
using namespace std;
int main()
{
    int count;
    cin >> count;
    map<int, int> m;
    while (count--)
    {
        int index, value;
        cin >> index >> value;
        // if (m.count(index) == 1)                //find或者count来check key是否存在map中。contains属于C++20
        //     m[index] += value;
        // else                                    // map来记录数据，查找比vector简单高效
        //     m[index] = value;
        m[index] += value;          //直接使用+=,如果对应key不存在，map会插入指定key并且对应的value会初始化为m<key_type,value_type>中value_type指定类型的defalt value
    }
    vector<pair<int, int>> v(m.begin(), m.end());               //不能对map排序，故借助vector来进行排序
    sort(v.begin(), v.end());
    for (auto p : v)
    {
        cout << p.first << " " << p.second << endl;
    }
}
//合并表记录 输出按照key值升序进行输出
// 输入：
// 4
// 0 1
// 0 2
// 1 2
// 3 4
// 复制
// 输出：
// 0 3
// 1 2
// 3 4
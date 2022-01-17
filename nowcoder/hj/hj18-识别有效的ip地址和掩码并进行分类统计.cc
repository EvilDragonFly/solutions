#include <iostream>
#include <string>
#include <sstream>
#include <vector>
using namespace std;

bool judge_ip(string ip)
{
    int j = 0;
    istringstream iss(ip);
    string seg;
    while (getline(iss, seg, '.'))
        if (++j > 4 || seg.empty() || stoi(seg) > 255)
            return false;
    return j == 4;
}

bool is_private(string ip)
{
    istringstream iss(ip);
    string seg;
    vector<int> v;
    while (getline(iss, seg, '.'))
        v.push_back(stoi(seg));
    if (v[0] == 10)
        return true;
    if (v[0] == 172 && (v[1] >= 16 && v[1] <= 31))
        return true;
    if (v[0] == 192 && v[1] == 168)
        return true;
    return false;
}

bool is_mask(string ip)
{
    istringstream iss(ip);
    string seg;
    unsigned b = 0;
    while (getline(iss, seg, '.'))
        b = (b << 8) + stoi(seg);
    if (!b)
        return false;
    b = ~b + 1;
    if (b == 1)
        return false;
    if ((b & (b - 1)) == 0) //掩码必须满足前面是1，后面是0
        return true;
    return false;
}

int main()
{
    string input;
    int a = 0, b = 0, c = 0, d = 0, e = 0, err = 0, p = 0;
    while (cin >> input)
    {
        istringstream is(input);
        string add;
        vector<string> v;
        while (getline(is, add, '~'))
            v.push_back(add);
        if (v[0].substr(0, v[0].find_first_of('.')) == "0" || v[0].substr(0, v[0].find_first_of('.')) == "127") // 排除不属于任一类别的ip
            continue;
        if (!judge_ip(v[1]) || !is_mask(v[1])) // 对mask进行两次judge
            err++;
        else
        {
            if (!judge_ip(v[0]))
                err++;
            else
            {
                int first = stoi(v[0].substr(0, v[0].find_first_of('.')));
                if (is_private(v[0]))
                    p++;
                if (first > 0 && first < 127)
                    a++;
                else if (first > 127 && first < 192)
                    b++;
                else if (first > 191 && first < 224)
                    c++;
                else if (first > 223 && first < 240)
                    d++;
                else if (first > 239 && first < 256)
                    e++;
            }
        }
    }
    cout << a << " " << b << " " << c << " " << d << " " << e << " " << err << " " << p << endl;
    return 0;
}

// 请解析IP地址和对应的掩码，进行分类识别。要求按照A/B/C/D/E类地址归类，不合法的地址和掩码单独归类。

// 所有的IP地址划分为 A,B,C,D,E五类

// A类地址1.0.0.0~126.255.255.255;

// B类地址128.0.0.0~191.255.255.255;

// C类地址192.0.0.0~223.255.255.255;

// D类地址224.0.0.0~239.255.255.255；

// E类地址240.0.0.0~255.255.255.255

// 私网IP范围是：

// 10.0.0.0-10.255.255.255

// 172.16.0.0-172.31.255.255

// 192.168.0.0-192.168.255.255

// 子网掩码为二进制下前面是连续的1，然后全是0。（例如：255.255.255.32就是一个非法的掩码）
// （注意二进制下全是1或者全是0均为非法子网掩码）

// 注意：
// 1. 类似于【0.*.*.*】和【127.*.*.*】的IP地址不属于上述输入的任意一类，也不属于不合法ip地址，计数时请忽略
// 2. 私有IP地址和A,B,C,D,E类地址是不冲突的

// 判断IP地址是否合法，如果满足下列条件之一即为非法地址
//      数字段数不为4
//      存在空段，即【192..1.0】这种
//      某个段的数字大于255
// 判断子网掩码是否合法，如果满足下列条件之一即为非法掩码
//      不是一个合格的IP地址
//      在二进制下，不满足前面连续是1，然后全是0
//      在二进制下，全为0或全为1
// 如何判断一个掩码地址是不是满足前面连续是1，然后全是0？
//      将掩码地址转换为32位无符号整型，假设这个数为b。如果此时b为0，则为非法掩码
//      将b按位取反后+1。如果此时b为1，则b原来是二进制全1，非法掩码
//      如果b和b-1做按位或运算后为-1，则说明是合法掩码，否则为非法掩码
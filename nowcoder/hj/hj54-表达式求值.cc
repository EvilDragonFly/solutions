#include <iostream>
#include <string>
#include <stack>
#include <sstream>
#include <cctype>
using namespace std;
//比较运算符优先级
bool priority(char oper1, char oper2) // 判断需要运算后面再计算前面的conditions
{
    if (oper2 == '(')
        return false;
    else if ((oper1 == '+' || oper1 == '-') && (oper2 == '*' || oper2 == '/'))
        return false;
    return true;
}
void compute(stack<int> &opernums, stack<char> &opertors)
{
    int a = opernums.top();
    opernums.pop();
    int b = opernums.top();
    opernums.pop();
    char oper = opertors.top();
    opertors.pop();
    if (oper == '+')
        opernums.emplace(a + b); //将计算结果保存到stack中
    if (oper == '-')
        opernums.emplace(a - b);
    if (oper == '*')
        opernums.emplace(a * b);
    if (oper == '/')
        opernums.emplace(a / b);
}
int main()
{
    string str;
    getline(cin, str);
    str = str + ")"; //为了能最后清空stack
    stack<int> opernums;
    stack<char> opertors;
    opertors.emplace('(');                          //防止空栈调用top产生未定义结果
    stringstream ss; //记录数字
    for (auto c : str)
    {
        //判断是否操作符
        if (!isdigit(c))
        {
            if (!ss.str().empty())                  // 将数字压入栈
            {
                int num;
                ss >> num;
                ss.str("");
                ss.clear();                         // 必须清空该stream的EOF状态
                opernums.emplace(num);
            }
            if (c == ')')
            {
                //将括号内的数据全部计算完毕
                while (opertors.top() != '(')
                    compute(opernums, opertors);
                opertors.pop();                     //将(弹出
                continue;
            }
            if (priority(opertors.top(), c))        //栈中存储的都是优先级比较低的式子，如果碰到优先级比栈中还低，将栈中式子计算
             //先计算栈中的数据
                compute(opernums, opertors);
            opertors.emplace(c);
        }
        else
            //数字
            ss << c;
        
    }
    cout << opernums.top();
}

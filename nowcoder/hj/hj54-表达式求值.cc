#include <iostream>
#include <string>
#include <stack>
#include <sstream>
#include <cctype>
using namespace std;
// 3+2*{1+2*[-4/(8-6)+7]} 25
//比较运算符优先级
bool shallcompute(char oper1, char oper2) // 判断需要运算后面再计算前面的conditions
{
    if (oper1 == '(' || oper2 == '(') //其中一个是左括号就不对栈中数据进行运算
        return false;
    else if ((oper1 == '+' || oper1 == '-') && (oper2 == '*' || oper2 == '/'))
        return false;
    return true;
}
void compute(stack<int> &opernums, stack<char> &opertors)
{
    int b = opernums.top(); //注意栈中操作数的位置
    opernums.pop();
    int a = opernums.top();
    opernums.pop();
    char oper = opertors.top();
    opertors.pop();
    if (oper == '+')
        opernums.emplace(a + b); //将计算结果保存到stack中
    else if (oper == '-')
        opernums.emplace(a - b);
    else if (oper == '*')
        opernums.emplace(a * b);
    else if (oper == '/')
        opernums.emplace(a / b);
}
int main()
{
    string str;
    getline(cin, str);
    str += ")"; //为了能最后清空stack
    stack<int> opernums;
    stack<char> opertors;
    opertors.emplace('('); //防止空栈调用top产生未定义结果
    stringstream ss;       //记录数字
    bool flag = true;      // true表示上一个字符是除右括号之外的操作符
    for (auto c : str)
    {
        //判断是否操作符
        if (!isdigit(c))
        {
            if (flag && (c == '+' || c == '-'))         //除右括号之外的操作符紧接着的+和-被视作正负号
            {
                ss << c;
                flag = false;
                continue;
            }
            if (!ss.str().empty()) // 将数字压入栈
            {
                int num;
                ss >> num;
                ss.str("");
                ss.clear(); // 必须清空该stream的EOF状态
                opernums.emplace(num);
            }
            if (c == ')')
            {
                //将括号内的数据全部计算完毕
                while (opertors.top() != '(')
                    compute(opernums, opertors);
                opertors.pop(); //将(弹出
                continue;
            }
            while (shallcompute(opertors.top(), c)) //栈中存储的都是优先级比较低的式子，如果碰到优先级比栈中还低，将栈中式子计算
                                                    //先计算栈中的数据
                compute(opernums, opertors);
            opertors.emplace(c);
            flag = true;
        }
        else
        {
            ss << c;
            flag = false;
        }
    }
    cout << opernums.top();
}
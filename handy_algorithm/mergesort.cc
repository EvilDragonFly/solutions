#include <iostream>
#include <vector>
#include <algorithm>

using std::cout; using std::endl;
using std::string; using std::vector;

template<typename T>
void printVector(const vector<T> &vec) {
    for (auto &i : vec) {
        cout << i << "; ";
    }
    cout << endl;
}

//将两个有序的向量合并
template<typename T>
void merge(vector<T> &vec, vector<T> &v1, vector<T> &v2) {
    auto siz1 = v1.size();
    auto siz2 = v2.size();
    size_t p1 = 0;
    size_t p2 = 0;

    while (p1 < siz1 && p2 < siz2) {
        if (v1.at(p1) < v2.at(p2))
            vec.push_back(v1.at(p1++));
        else
            vec.push_back(v2.at(p2++));
    }

    while (p1 < siz1) vec.push_back(v1.at(p1++));
    while (p2 < siz2) vec.push_back(v2.at(p2++));
}

//基于归并和递归方式实现将无序向量进行有序排列
template<typename T>
void mergeSort(vector<T> &vec) {
    if (vec.size() <= 1)
        return;

    auto iter = vec.begin() + vec.size() / 2;
    vector<T> v1(vec.begin(), iter);
    vector<T> v2(iter, vec.end());

    mergeSort(v1);
    mergeSort(v2);

    vec.clear();
    merge(vec, v1, v2);
    // std::merge(v1.begin(), v1.end(), v2.begin(), v2.end(), std::back_inserter(vec));//可以用stl的merge方法来简化
}

int main()
{
    vector<int> vec1 = { 43, 5, 123, 94, 359, -23, 2, -1 };

    printVector(vec1);
    mergeSort(vec1);
    printVector(vec1);

    return EXIT_SUCCESS;
}
//归并排序算法
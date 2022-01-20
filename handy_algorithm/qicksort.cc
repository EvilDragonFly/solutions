// 快排算法
#include <iostream>
#include <vector>
using namespace std;
void swap(vector<int> &nums, int i, int j)
{ // 类似换值可参考python的a,b=b,a;C++类似实现可以参考c++11的tuple和最新版c++
    int tmp = nums[i];
    nums[i] = nums[j];
    nums[j] = tmp;
}
int Partition(vector<int> &nums, int start, int end)
{
    // pick a element as a target
    int target = nums[start];
    int left = start, right = end;
    while (left < right)
    {
        while (right > left && nums[right] > target) // 必须先从后面遍历，因为start是从左边选的
            right--;

        while (left < right && nums[left] <= target) //必须能跳过start
            left++;
        if (left < right)
            swap(nums, left, right);
    }
    swap(nums, start, left);
    return left;
}

void quicksort(vector<int> &nums, int i, int j)
{
    int mid = Partition(nums, i, j);
    if (mid - 1 > i)
        quicksort(nums, i, mid - 1);
    if (mid + 1 < j)
        quicksort(nums, mid + 1, j);
}
int main()
{
    int count;
    cin >> count;
    vector<int> nums(count);
    for (auto &n : nums)

        cin >> n;

    quicksort(nums, 0, count - 1);
    cout << "----------------" << endl;
    for (auto n : nums)

        cout << n << " ";
}

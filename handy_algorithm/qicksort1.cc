#include <iostream>
#include <vector>
using namespace std;
void swap(vector<int> &nums, int i, int j)
{
    int tmp = nums[i];
    nums[i] = nums[j];
    nums[j] = tmp;
}
int partition(vector<int> &nums, int start, int end)
{
    int target = nums[start];
    int left = start;
    int right = end;
    while (left < right)
    {
        while (left < right && nums[right] > target)
            right--;
        while (left < right && nums[left] <= target)
            left++;

        if (left < right)
            swap(nums, left, right);
    }
    swap(nums, start, left);
    return left;
}
void quicksort(vector<int> &nums, int start, int end)
{
    int mid = partition(nums, start, end);
    if (mid - 1 > start)
        quicksort(nums, start, mid - 1);
    if (mid + 1 < end)
        quicksort(nums, mid + 1, end);
}
int main()
{
    int count;
    cin >> count;
    vector<int> nums(count);
    for (auto &n : nums)
        cin >> n;
    quicksort(nums, 0, count - 1);
    cout << "--------------------" << endl;
    for (auto n : nums)
        cout << n << " ";
}
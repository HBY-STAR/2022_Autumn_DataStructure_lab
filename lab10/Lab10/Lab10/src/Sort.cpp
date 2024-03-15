#include <iostream>
#include <vector>

using namespace std;

class Sort
{
public:
    // 插入排序
    void insertSort(vector<int> &arr)
    {
        for (int p = 1; p < arr.size(); ++p)
        {
            int temp = std::move(arr[p]);

            int j;
            for (j = p; j > 0 && temp < arr[j - 1]; --j)
                arr[j] = std::move(arr[j - 1]);
            arr[j] = std::move(temp);
        }
    }

    // 快速排序内部执行三数中值分割的代码
    const int &median3(vector<int> &a, int left, int right)
    {
        int center = (left + right) / 2;

        if (a[center] < a[left])
            std::swap(a[left], a[center]);
        if (a[right] < a[left])
            std::swap(a[left], a[right]);
        if (a[right] < a[center])
            std::swap(a[right], a[center]);

        // 将枢纽元置于right-1处
        std::swap(a[center], a[right - 1]);
        return a[right - 1];
    }

    // 快速排序
    void quickSort(vector<int> &arr, int left, int right)
    {
        if (left + 10 <= right) // 数组较大时才调用快速排序
        {
            // 选取枢纽元
            const int &pivot = median3(arr, left, right);

            // 开始分割
            int i = left, j = right - 1;
            for (;;)
            {
                while (arr[++i] < pivot)
                {
                }
                while (pivot < arr[--j])
                {
                }
                if (i < j)
                    std::swap(arr[i], arr[j]);
                else
                    break;
            }

            // 恢复枢纽元
            std::swap(arr[i], arr[right - 1]);

            // 分别对左右的两个数组进行递归
            quickSort(arr, left, i - 1);
            quickSort(arr, i + 1, right);
        }
        else
            insert_sort(arr, left, right); // 数组较小时进行插入排序
    }

    // 快速排序内部用到的插入排序
    template <typename Comparable>
    void insert_sort(vector<Comparable> &a, int left, int right)
    {
        for (int p = left + 1; p <= right; ++p)
        {
            Comparable temp = std::move(a[p]);

            int j;
            for (j = p; j > left && temp < a[j - 1]; --j)
                a[j] = std::move(a[j - 1]);
            a[j] = std::move(temp);
        }
    }
};
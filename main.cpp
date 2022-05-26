#include <iostream>
#include <vector>

void insertion_sort(std::vector<int> &arr) {
    for (auto i=1; i<arr.size(); i++) {
        auto j=i;
        while (j>0 && arr[j] < arr[j-1]) {
            if (arr[j] < arr[j-1]) {
                auto temp = arr[j];
                arr[j] = arr[j-1];
                arr[j-1] = temp;
                j--;
            }
        }
    }
}

// TODO: Have merge and merge_sort work in-place on the array
std::vector<int> merge(std::vector<int> arr1, std::vector<int> arr2) {
    auto count = arr1.size() + arr2.size();
    arr1.push_back(INT_MAX);
    arr2.push_back(INT_MAX);

    std::vector<int> merged = {};
    int i = 0, j = 0;
    while(merged.size() < count) {
        if (arr1[i] < arr2[j]) {
            merged.push_back(arr1[i]);
            i++;
        } else {
            merged.push_back(arr2[j]);
            j++;
        }
    }

    return merged;
}

std::vector<int> merge_sort(std::vector<int> arr) {
    if (arr.size() > 1) {
        std::vector<int> arr1;
        std::vector<int> arr2;
        auto mid = arr.size() / 2;
        for (auto i=0; i<arr.size(); i++) {
            if (i<mid) arr1.push_back(arr[i]);
            else arr2.push_back(arr[i]);
        }

        auto a = merge_sort(arr1);
        auto b = merge_sort(arr2);
        return merge(a, b);
    }

    return arr;
}

int main() {
    std::vector<int> arr = {3, 1, 2};

    insertion_sort(arr);
    for (auto x : arr) {
        std::cout << x << std::endl;
    }

    std::cout << std::endl;

    arr = {2, 1, 5, 3, 4};
    auto mergesort_arr = merge_sort(arr);
    for (auto x : mergesort_arr) {
        std::cout << x << std::endl;
    }
    return 0;
}

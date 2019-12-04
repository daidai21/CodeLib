/* =============================================================================
> File Name: quick_sort.cpp
> Author: DaiDai
> Mail: daidai4269@aliyun.com
> Created Time: Wed 04 Dec 2019 09:43:20 PM CST
============================================================================= */


#include <iostream>
#include <vector>

using namespace std;


void quick_sort_(vector<int>& arr, int start, int end) {
	if (start >= end)
		return ;
	int temp = arr[start];
	int left = start + 1, right = end;
	while (left < right) {
		while (arr[left] < temp && left < right)
			left++;
		while (arr[right] >= temp && left < right)
			right--;
		swap(arr[left], arr[right]);
	}
	if (arr[right] <= temp)
		swap(arr[right], arr[start]);
	else
		right++;
	quick_sort_(arr, start, left - 1);
	quick_sort_(arr, left, end);
}

void quick_sort(vector<int> &A) {
	quick_sort_(A, 0, A.size() - 1);
}

int main() {
	vector<int> vec = {5, 3124, 2345, 56, 67, 45, 34};
	quick_sort(vec);
	for (const int& n : vec)
		cout << n << " ";
	cout << endl;
}


#include <vector>

// change to template
void quick_sort_(std::vector<int>& arr, int start, int end) {
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
		std::swap(arr[right], arr[start]);
	else
		right++;
	quick_sort_(arr, start, left - 1);
	quick_sort_(arr, left, end);
}

void quick_sort(std::vector<int> &A) {
	quick_sort_(A, 0, A.size() - 1);
}


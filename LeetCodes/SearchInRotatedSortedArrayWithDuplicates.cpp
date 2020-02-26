#include "SearchInRotatedSortedArrayWithDuplicates.h"
using namespace std;

int SearchInRotatedSortedArrayWithDuplicates::findPivot(vector<int>& nums, int low, int high)
{
	if (high < low)
	{
		return -1;
	}
	if (high == low)
	{
		return low;
	}

	int mid = (low + high) / 2;

	if (mid < high && nums[mid] > nums[mid + 1])
	{
		return mid;
	}
	if (mid > low && nums[mid] < nums[mid - 1])
	{
		return (mid - 1);
	}

	if (nums[low] > nums[mid])
		return findPivot(nums, low, mid - 1);

	return findPivot(nums, mid + 1, high);
}

bool SearchInRotatedSortedArrayWithDuplicates::binarySearch(vector<int>& nums, int low, int high, int target)
{
	if (high < low) return false;

	int mid = (low + high) / 2;

	if (nums[mid] == target)
	{
		return true;
	}

	if (target > nums[mid])
	{
		return binarySearch(nums, mid + 1, high, target);
	}

	return binarySearch(nums, low, mid - 1, target);
}

bool SearchInRotatedSortedArrayWithDuplicates::search(vector<int>& nums, int target)
{
	if (nums.empty()) return false;

	if (nums.size() == 1) return (nums[0] == target) ? true : false;

	//this is the index to the greatest int in the array.
	int pivot = findPivot(nums, 0, nums.size() - 1);

	//if no pivot found it means the array is not rotated. do binary search directly
	if (pivot == -1)
	{
		return binarySearch(nums, 0, nums.size() - 1, target);
	}

	if (nums[pivot] == target) return true;

	if (nums[0] <= target)
		return binarySearch(nums, 0, pivot - 1, target);

	return binarySearch(nums, pivot + 1, nums.size() - 1, target);
}
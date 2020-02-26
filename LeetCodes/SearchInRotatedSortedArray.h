#pragma once
#include <vector>

class SearchInRotatedSortedArray
{
public:
	int search(std::vector<int>& nums, int target);

private:
	int findPivot(std::vector<int>& nums, int low, int high);
	int binarySearch(std::vector<int>& nums, int low, int high, int target);
};


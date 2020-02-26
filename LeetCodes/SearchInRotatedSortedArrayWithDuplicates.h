#pragma once
#include <vector>

class SearchInRotatedSortedArrayWithDuplicates
{
public:
	bool search(std::vector<int>& nums, int target);

private:
	int findPivot(std::vector<int>& nums, int low, int high);
	bool binarySearch(std::vector<int>& nums, int low, int high, int target);
};


#include "LongestSubstringWithoutRepeatingCharacters.h"
#include <map>
#include <algorithm>

using namespace std;

int LongestSubstringWithoutRepeatingCharacters::lengthOfLongestSubstring(string s)
{
	std::map<char, int> charIndexMap;
	int result = 0;

	//using the sliding window technique to find the longest substring in the given string
	//we move the rightIndex till the char at rightIndex is not present in the map. Once the 
	//char is found in the hashset we have a substring without any repeating characters.
	for (int rightIndex = 0, leftIndex = 0; rightIndex < s.length(); ++rightIndex)
	{
		std::map<char, int>::iterator it = charIndexMap.find(s[rightIndex]);
		if (it != charIndexMap.end())
		{
			leftIndex = std::max(it->second, leftIndex);
		}

		result = std::max(result, (rightIndex - leftIndex + 1));
		if (it == charIndexMap.end())
		{
			charIndexMap.emplace(s[rightIndex], rightIndex + 1);
		}
		else
		{
			charIndexMap[s[rightIndex]] = rightIndex + 1;
		}
	}
	return result;
}
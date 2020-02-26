#pragma once
#include <string>
#include <vector>
#include <tuple>

class LongestPalindromicSubstring
{
public:
	LongestPalindromicSubstring();
	std::string longestPalindrome(std::string s);

private:
	std::tuple<int, int> checkForPalindrome(std::string s, int midLeft, int midRight);

};


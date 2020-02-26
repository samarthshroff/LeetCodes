#include "LongestPalindromicSubstring.h"
#include <iostream>

using namespace std;

LongestPalindromicSubstring::LongestPalindromicSubstring()
{
}

std::string LongestPalindromicSubstring::longestPalindrome(std::string s)
{
	if (s.empty()) return "";

	int currIndex = 0;
    int palindromeStartIndex = 0;
    int palindromeLen = 1;

    while (currIndex < s.length()-1)
	{
        if (s[currIndex] == s[currIndex + 1])
        {
            auto [startIndex,length] = checkForPalindrome(s, currIndex, currIndex + 1);

            if (length > palindromeLen)
            {
                palindromeStartIndex = startIndex;
                palindromeLen = length;
            }
        }
        if (s[currIndex] == s[currIndex + 2])
        {
           auto [startIndex, length] = checkForPalindrome(s, currIndex + 1, currIndex + 1);

           if (length > palindromeLen)
           {
               palindromeStartIndex = startIndex;
               palindromeLen = length;
           }
        }
        currIndex++;
	}
	return s.substr(palindromeStartIndex, palindromeLen);
}

std::tuple<int, int> LongestPalindromicSubstring::checkForPalindrome(std::string s, int midLeft, int midRight)
{
    int index = 0;
    while (((midLeft - index) >= 0 && (midRight + index) < s.length()))
    {
        if (s[midLeft - index] != s[midRight + index]) break;
        index++;
    }

    return { (midLeft - index + 1) , (midRight + index) - (midLeft - index + 1) };
}

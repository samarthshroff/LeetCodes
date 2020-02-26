#include "ZigZagConversion.h"
using namespace std;

ZigZagConversion::ZigZagConversion()
{
}

string ZigZagConversion::convert(string s, int numRows)
{	
	if (numRows == 1) return s;

	int length = s.length();
	char* zigzagArray = new char[length];
	int row = 0;
	int j = 2;//because we don't have to jump for characters that are at the start and end of one column
	int hopIndex = 0;
	int index = 0;

	zigzagArray[0] = s[0];

	for (int i = 1; i < length; ++i)
	{
		int hop1 = numRows + (numRows - j);
		int hop2 = numRows + (numRows - 2) - hop1;

		hopIndex = (hopIndex == hop1) ? hop2 : hop1;
		if (row == 0)
		{
			hopIndex = hop1;
		}
		else if (row == numRows - 1)
		{
			hopIndex = hop2;
		}

		index = index + hopIndex;

		if (index >= length)
		{
			row++;
			j += 2;
			index = row;
			hopIndex = 0;

			index = index + hopIndex;
		}

		zigzagArray[i] = s[index];
	}

	string zigZagString(zigzagArray,length);

	return zigZagString;
}

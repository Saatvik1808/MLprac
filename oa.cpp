#include <iostream>
#include <string>
using namespace std;
int CountPalindromeCenters(string str, int left, int right)
{
    int count = 0;
    int n = str.size();

    while (left >= 0 && right < n && str[left] == str[right])
    {
        ++count;
        --left;
        ++right;
    }

    return count;
}

int MagicalStringCount(string str)
{
    int count = 0;
    int n = str.size();

    for (int i = 0; i < n; ++i)
    {

        count += CountPalindromeCenters(str, i, i);

        count += CountPalindromeCenters(str, i, i + 1);
    }

    return count;
}

int main()
{
    string input = "zabbacd";
    int result = MagicalStringCount(input);
    cout << "Output: " << result << endl;

    return 0;
}

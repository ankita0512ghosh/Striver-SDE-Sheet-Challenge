#include <iostream>
#include <queue>
#include <vector>
using namespace std; 

vector<int> calculateLPSArray(string str)
{
    int m = str.length();
    vector<int> lps(m);

    int len = 0;

    lps[0] = 0;

    int i = 1;
    while (i < m)
    {
        if (str[i] == str[len])
        {
            len++;
            lps[i] = len;
            i++;
        }
        else
        {
            if (len != 0)
            {
                len = lps[len - 1];
            }
            else
            {
                lps[i] = 0;
                i++;
            }
        }
    }

    return lps;
}

string reverse(string s)
{

    int n = s.length();

    for (int i = 0; i < n / 2; i++)
    {
        char temp = s[i];
        s[i] = s[n - i - 1];
        s[n - i - 1] = temp;
    }

    return s;
}

int minCharsforPalindrome(string str)
{
    string revStr = reverse(str);

    string concat = str + "$" + revStr;

    vector<int> lps = calculateLPSArray(concat);

    return (str.length() - lps[lps.size() - 1]);
}
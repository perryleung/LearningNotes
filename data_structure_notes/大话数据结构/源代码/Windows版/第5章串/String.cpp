#include <string>


int Index(string s, string t, int pos)
{
    int n, m, i;
    string sub;
    if(pos > 0)
    {
        n = StrLength(s);
        m = StrLength(t);
        i = pos;
        while (i <= n - m + i)
        {
            SubString(sub, s, i, m); // 取s的第i个位置的m个字符组成串赋给sub
            if(StrCompare(sub, t) != 0)
                i++;
            else
                return i;
        }
    }
    return 0;
}
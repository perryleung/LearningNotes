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
            SubString(sub, s, i, m); // ȡs�ĵ�i��λ�õ�m���ַ���ɴ�����sub
            if(StrCompare(sub, t) != 0)
                i++;
            else
                return i;
        }
    }
    return 0;
}
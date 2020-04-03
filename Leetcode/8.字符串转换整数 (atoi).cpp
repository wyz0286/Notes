//8.字符串转换整数 (atoi)
#include <iostream>
#include <vector>
#include <string>

using namespace std;

int isNum(char ch)
{
    if (ch <= '9' && ch >= '0')
    {
        return 1;
    }
    else return 0;
}

int myAtoi(string str) {
    int len = str.length();
    int ans = 0;
    int sign = 1;
    for (int i = 0; i < len; i++)
    {
        if (i == 0)
        {
            while (str[i] == ' ')i++;
            if (str[i] == '+')
            {
                sign = 1; i++;
            }
            else if (str[i] == '-')
            {
                sign = 0; i++;
            }
            //else if (!isNum(str[i]))return 0;
        }

        if (isNum(str[i]))
        {
            /*if (ans == 214748364 && sign && str[i] >= '7')return INT32_MAX;
            if (ans == 214748364 && !sign && str[i] >= '8')return INT32_MIN;
            if (ans > 214748364 && sign)return INT32_MAX;
            if (ans > 214748364 && !sign)return INT32_MIN;*/
            if (ans > INT32_MAX / 10 || (ans == INT32_MAX / 10 && str[i] > '7'))
                return sign == 1 ? INT32_MAX : INT32_MIN;
            ans = 10 * ans + (str[i] - '0');
        }
        else
        {
            if (!sign)ans = -ans;
            return ans;
        }
    }
    if (!sign)ans = -ans;
    return ans;
}

int main()
{
    cout << myAtoi("    -42") << endl;
    cout << myAtoi("4193 with words") << endl;
    cout << myAtoi("words and 987") << endl;
    cout << myAtoi("-91283472332") << endl;
    cout << myAtoi(" -0012a42") << endl;
    return 0;
}
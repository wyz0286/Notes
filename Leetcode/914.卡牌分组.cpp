//914.卡牌分组
//给定一副牌，每张牌上都写着一个整数
//
//此时，你需要选定一个数字 X，使我们可以将整副牌按下述规则分成 1 组或更多组
//
//每组都有 X 张牌
//组内所有的牌上都写着相同的整数
//仅当你可选的 X >= 2 时返回 true

#include<iostream>
#include<vector>
#include<string>
#include<unordered_map>

using namespace std;

int gcd(int a, int b)
{
    if (b == 0)return a;
    else return gcd(b, a % b);
}

bool hasGroupsSizeX(vector<int>& deck) {
    int len = deck.size();
    unordered_map<int, int> a;
    for (int i = 0; i < len; i++)
    {
        a[deck[i]]++;
    }
    //cout << max << endl;
    unordered_map<int, int>::iterator it;
    int x = a.begin()->second;
    for (it = a.begin(); it != a.end(); it++)
    {
        x = gcd(it->second, x);
    }
    if (x >= 2)return true;
    else return false;
}

int main()
{
    vector<int> a{ 1, 2, 3, 4, 4, 3, 2, 1 };
    vector<int> b{ 1,1,1,2,2,2,3,3 };
    cout << hasGroupsSizeX(a)<< endl;
    cout << hasGroupsSizeX(b)<< endl;
    return 0;
}
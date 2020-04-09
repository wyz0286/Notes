//478.在圆内随机生成点

//给定圆的半径 r 和圆心的 x、y 坐标，写一个在圆中产生均匀随机点的函数 randPoint

#include <iostream>
#include <random>
#include <vector>
#include <algorithm>
#include <string>
#include <random>

using namespace std;

class Solution {
    double r, x, y;
public:
    Solution(double radius, double x_center, double y_center): r(radius),x(x_center),y(y_center){ }

    //直角坐标系
    /*vector<double> randPoint() {
        while (1)
        {
            double rx = (double)rand() / RAND_MAX * 2 * r - r ;
            double ry = (double)rand() / RAND_MAX * 2 * r - r;
            if (rx * rx + ry * ry <= r * r)return { x + rx,y + ry };
        }
    }*/

    //极坐标系(R/必须sqrt)(注意线性放大概率为平方级)(PI*2*2/PI*1*1)(内环概率1/4、外环3/4)
    vector<double> randPoint() {
        double R = sqrt((double)rand() / RAND_MAX) * r;
        double angle = (double)rand() / RAND_MAX * 2 * std::_Pi;
        return { x + R * sin(angle),y + R * cos(angle) };
    }
};

int main()
{
    cout << acos(-1) << endl;
    cout << (double)std::_Pi << endl;
    return 0;
}
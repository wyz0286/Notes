//207.课程表
//
//你这个学期必须选修 numCourse 门课程，记为 0 到 numCourse - 1 
//
//在选修某些课程之前需要一些先修课程。 例如，想要学习课程 0 ，你需要先完成课程 1 ，我们用一个匹配来表示他们：[0, 1]
//
//给定课程总量以及它们的先决条件，请你判断是否可能完成所有课程的学习？
//
//示例 1:
//
//输入: 2, [[1, 0]]
//输出 : true
//解释 : 总共有 2 门课程。学习课程 1 之前，你需要完成课程 0。所以这是可能的
//示例 2 :
//
//输入 : 2, [[1, 0], [0, 1]]
//输出 : false
//解释 : 总共有 2 门课程。学习课程 1 之前，你需要先完成​课程 0；并且学习课程 0 之前，你还应先完成课程 1。这是不可能的

#include <iostream>
#include <vector>
#include <set>
#include <algorithm>
#include <string>
#include <stack>
#include <queue>

using namespace std;

//拓扑排序
//bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
//    vector<int> degrees(numCourses);//记录所有顶点的入度,未初始化的为0
//    vector<vector<int>> adjacents(numCourses); //邻接表
//    queue<int> zero;//零入度的顶点
//
//    int num = numCourses;
//
//    for (int i = 0; i < prerequisites.size(); i++)
//    {
//        int a = prerequisites[i][0];
//        int b = prerequisites[i][1];
//        degrees[a]++;
//        adjacents[b].push_back(a);
//    }
//    for (int i = 0; i < numCourses; i++)
//    {
//        if (degrees[i] == 0)
//        {
//            zero.push(i);
//            num--;
//        }
//    }
//    while (!zero.empty())
//    {
//        int cur = zero.front();
//        zero.pop();
//        for (int i = 0; i < adjacents[cur].size(); i++)
//        {       
//            if (--degrees[adjacents[cur][i]] == 0)
//            {
//                zero.push(adjacents[cur][i]);
//                num--;
//            }
//        }
//    }
//    if (num == 0)
//        return true;
//    else
//        return false;
//}

bool DFS(int x, vector<vector<int>>& adjacenies, vector<int>& record)
{
	if (record[x] == 1)
	{
		return false;
	}
	if (record[x] == 2)
	{
		return true;
	}
	record[x] = 1;
	for (auto n : adjacenies[x])
	{
		if (!DFS(n, adjacenies, record))
		{
			return false;
		}
	}
	record[x] = 2;
	return true;
}
bool canFinish(int numCourses, vector<vector<int>>& prerequisites)
{
	vector<vector<int>> adjacenies(numCourses);		//邻接表，a->b
	/*初始化邻接表*/
	for (auto v : prerequisites)
	{
		adjacenies[v[1]].push_back(v[0]);
	}
	/*0:未被访问
	1:被当前节点的DFS访问过
	2:被其他节点DFS访问过*/
	vector<int> record(numCourses, 0);

	for (int i = 0; i < numCourses; ++i)
	{
		if (!DFS(i, adjacenies, record))
		{
			return false;
		}
	}
	return true;
}

int main()
{
    vector<vector<int>> a =
    {
        {1,0},
        {0,1}
    };
    vector<vector<int>> b =
    {
        {1,0}
    };
    cout << canFinish(2, a) << endl;
    cout << canFinish(2, b) << endl;
	return 0;
}
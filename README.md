# Notes
-----------------------------------------

1. Linux/Unix网络编程里面的文件会出现LF、CRLF格式问题，Windows下为CRLF， Linux/Unix为LF；

2. 
````C++
//使用remove和erase去除字符串中指定字符
string s1;
s1.erase(std::remove(s1.begin(), s1.end(), 'X'), s1.end());
````

3. 
````C++
//完美转发
void f(int v1, int& v2)
{
	std::cout << v1 << " " << ++v2 << std::endl;
}

void g(int&& v1, int& v2)
{
	std::cout << v1 << " " << ++v2 << std::endl;
}

template <typename F, typename T1, typename T2>
void flip(F f, T1&& t1, T2&& t2)
{
	f(std::forward<T2>(t2), std::forward<T1>(t1));
}

int main()
{
	int j = 0;
	flip(f, j, 42);
	flip(g, j, 42);
}
//output
//42 1
//42 2
````

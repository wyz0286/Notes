# Notes
-----------------------------------------

1. Linux/Unix网络编程里面的文件会出现LF、CRLF格式问题，Windows下为CRLF， Linux/Unix为LF；

2. 
````C++
bool canTransform(string start, string end) {
    //使用remove和erase去除字符串中指定字符
    s1.erase(std::remove(s1.begin(), s1.end(), 'X'), s1.end());
    s2.erase(std::remove(s2.begin(), s2.end(), 'X'), s2.end());
    if (s1 != s2)return false;
    //...
}
````

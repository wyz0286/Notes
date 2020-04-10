# Notes
-----------------------------------------

1. Linux/Unix网络编程里面的文件会出现LF、CRLF格式问题，Windows下为CRLF， Linux/Unix为LF；

2. 
````C++
    //使用remove和erase去除字符串中指定字符
    string s1;
    s1.erase(std::remove(s1.begin(), s1.end(), 'X'), s1.end());
````

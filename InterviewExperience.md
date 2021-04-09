# Interview Experience 
--------------------------------

### NowCoder面经+gdb/dlv

1. [C++后台开发面试宝典](https://www.nowcoder.com/tutorial/93/0cf933dc97be4913b3f5d012eba1e875)

2. [gdb调试](https://blog.csdn.net/niyaozuozuihao/article/details/91802994)

3. [有用的面经--计网](https://www.cnblogs.com/wangxf2019/p/12089149.html)

4. [有用的面经--C++](https://www.cnblogs.com/wangxf2019/p/12089119.html)

5. [有用的面经--OS](https://www.cnblogs.com/wangxf2019/p/12089563.html)

6. [圈复杂度CC](http://kaelzhang81.github.io/2017/06/18/%E8%AF%A6%E8%A7%A3%E5%9C%88%E5%A4%8D%E6%9D%82%E5%BA%A6/)

### C++

1. [C++11新标准特性](https://blog.csdn.net/qq_40421919/article/details/91049264)

2. [C++11新特性--auto和decltype的区别和联系](https://blog.csdn.net/y1196645376/article/details/51441503?depth_1-utm_source=distribute.pc_relevant.none-task&utm_source=distribute.pc_relevant.none-task)

3. [override和final](https://www.cnblogs.com/jimodetiantang/p/9736737.html)

4. [如何将template实现放在cpp文件中](https://blog.csdn.net/big_bit/article/details/77878000)

5. [STL：二级空间配置器浅谈](https://blog.csdn.net/dandelion_gong/article/details/51353918)

6. [STL——配接器、仿函数、空间配置器、算法、容器、迭代器](https://www.cnblogs.com/tp-16b/p/9186826.html) 主要看图

7. [C++智能指针循环引用导致的内存泄漏](https://blog.csdn.net/qq_42673507/article/details/91159367)

8. [extern "C"的作用](https://www.cnblogs.com/xiangtingshen/p/10980055.html)

9. [C语言函数调用是怎么样一个过程？](https://blog.csdn.net/weixin_42462202/article/details/88317097)
   [图解](https://baijiahao.baidu.com/s?id=1637118531261462083&wfr=spider&for=pc)
   [C语言函数调用过程](https://blog.csdn.net/H_Strong/article/details/80040378)

10. >C++函数栈空间的最大值默认大小为1MB，但是和平台有关，windows为2MB，MacOS为8MB
    >在 linux 下可以通过 ```ulimit -a ```来查看，我的ubuntu双系统8MB

11. ***exec函数***
    >fork函数是用于创建一个子进程，该子进程几乎是父进程的副本，而有时我们希望子进程去执行另外的程序，exec函数族就提供了一个在进程中启动另一个程序执行的方法。
    >它可以根据指定的文件名或目录名找到可执行文件，并用它来取代原调用进程的数据段、代码段和堆栈段，在执行完之后，原调用进程的内容除了进程号外，其他全部被新程序的内容替换了。
    >另外，这里的可执行文件既可以是二进制文件，也可以是Linux下任何可执行脚本文件。
12. [C++之类内定义引用成员](https://blog.csdn.net/weixin_42579072/article/details/102618771?depth_1-utm_source=distribute.pc_relevant.none-task-blog-BlogCommendFromBaidu-1&utm_source=distribute.pc_relevant.none-task-blog-BlogCommendFromBaidu-1)

13. [在 main() 执行之前先运行其它函数在](https://www.cnblogs.com/zpcoding/p/10805639.html)
```C++
#include <iostream> 
using namespace std;
//全局(static)变量的初始化在程序初始阶段，先于main函数的执行
int test1(){
    cout << "before main 1" << endl;
    return 54;
}
  
static int i = test1();
  
int main(int argc, char** argv) {
  
    cout << "main function." <<endl;
    return 0;
}
```
14. >对于局部常量，存放在栈区
    >对于全局常量存放在全局/静态存储区
    >字面值常量，比如字符串，放在常量区

15. [C++11为什么引入nullptr而不继续使用null](https://www.cnblogs.com/xinxue/archive/2016/05/04/5415139.html)

16. #### 红黑树

> + [深入了解红黑树](https://www.jianshu.com/p/0b68b992f688)  
> + [红黑树与AVL树，各自的优缺点总结](https://www.jianshu.com/p/37436ed14cc6)
> + 红黑树任何不平衡都会在3次旋转之内解决，查询仅较相同内容的AVL多比较一次，RBTree读取慢、插入删除收敛快。
> + 查找 效率最好情况下时间复杂度为O(logN)，但在最坏情况下比AVL要差一些，但也远远好于BST;  
插入和删除操作改变树的平衡性的概率要远远小于AVL（RBT不是高度平衡的）。因此需要的旋转操作的可能性要小，而且一旦需要旋转，插入一个结点最多只需要旋转2次，删除最多只需要旋转3次(小于AVL的删除操作所需要的旋转次数)。虽然变色操作的时间复杂度在O(logN)，但是实际上，这种操作由于简单所需要的代价很小。

17.   
>可以定义一个``vector<int>:: iterator ``到int的map 吗?``list<int>::iterator``到int的map呢?对于两种情况，如果不能，解释为什么。
>理解关联容器对关键字类型的要求。
>由于有序容器要求关键字类型必须支持比较操作<，因此
```C++
map<vector<int>::iterator, int> m1；
```

>是可以的，因为vector的迭代器支持比较操作。而

```C++
map<list<int>::iterator, int> m2；
```

>是不行的，因为list的元素不是连续存储，其迭代器不支持比较操作。

18. **emplace_back()和push_back()的区别**:就在于底层实现的机制不同。push_back() 向容器尾部添加元素时，首先会创建这个元素，然后再将这个元素拷贝或者移动到容器中（如果是拷贝的话，事后会自行销毁先前创建的这个元素）；而 emplace_back() 在实现时，则是直接在容器尾部创建这个元素，省去了拷贝或移动元素的过程。)

19. [STL详解及常见面试题](https://blog.csdn.net/daaikuaichuan/article/details/80717222)

20. [C++11之lambda函数的详细使用](https://blog.csdn.net/lixiaogang_theanswer/article/details/80905445)

21. [C++构造函数的default和delete](https://blog.csdn.net/qq_29996285/article/details/84851745?depth_1-utm_source=distribute.pc_relevant.none-task-blog-BlogCommendFromBaidu-5&utm_source=distribute.pc_relevant.none-task-blog-BlogCommendFromBaidu-5)

22. [inline函数必须在头文件中定义?](https://blog.csdn.net/chenlei0630/article/details/45720913)

23. [C++ STL swap](https://blog.csdn.net/iwts_24/article/details/79487501)

24. [C++原子操作 atomic的使用及效率](https://blog.csdn.net/yzf279533105/article/details/90605172)

   [实现原理：总线锁、缓存锁实现](https://blog.csdn.net/en_joker/article/details/84305565?depth_1-utm_source=distribute.pc_relevant.none-task-blog-BlogCommendFromBaidu-7&utm_source=distribute.pc_relevant.none-task-blog-BlogCommendFromBaidu-7)

25. [在栈上new出一个对象](https://blog.csdn.net/xzx_kag/article/details/52956396)
    [C++中placement new操作符(经典)](https://blog.csdn.net/zhangxinrun/article/details/5940019)
--------------------------------

### 计算机网络

1. [公钥私钥](https://www.cnblogs.com/shenkebky/p/8461841.html)   [数字签名](http://www.ruanyifeng.com/blog/2011/08/what_is_a_digital_signature.html)

2. [TCP的三次握手与四次挥手理解及面试题（很全面）](https://blog.csdn.net/qq_38950316/article/details/81087809) 
   
   >1. [TCP第三次握手可以附带数据吗？](https://www.zhihu.com/question/66407996?sort=created) 
   >RFC表明可以，HTTP的浏览器请求报文就是第三次握手发送
   >如果有携带数据，下次客户端发送的报文，seq=服务器发回的ACK号。如果没有携带数据，那么第三次握手的报文不消耗seq
   >下次客户端发送的报文，seq序列号还是和第三次握手的报文的seq一样
   >这是因为，seq和报文中的数据在整条数据流流中的位置是一一对应的,如果报文没有携带数据，那么seq当然也不会更新
   >2. 有人会困惑为什么要进行三次握手呢（两次确认）？
   >这主要是为了防止已失效的请求连接报文忽然又传送到了，从而产生错误
   >假定A向B发送一个连接请求，由于一些原因，导致A发出的连接请求在一个网络节点逗留了比较多的时间
   >此时A会将此连接请求作为无效处理 又重新向B发起了一次新的连接请求，B正常收到此连接请求后建立了连接，数据传输完成后释放了连接
   >如果此时A发出的第一次请求又到达了B，B会以为A又发起了一次连接请求，如果是两次握手：此时连接就建立了，B会一直等待A发送数据，从而白白浪费B的资源
   >如果是三次握手：由于A没有发起连接请求，也就不会理会B的连接响应，B没有收到A的确认连接，就会关闭掉本次连接

3. [从输入url到页面加载完成发生了什么详解](https://www.cnblogs.com/liutianzeng/p/10456865.html)

   [HTTP协议详解](https://www.cnblogs.com/ranyonsue/p/5984001.html)

   [HTTP和HTTPS的区别](https://www.jianshu.com/p/14cd2c9d2cd2)

   [http断点续传](https://www.cnblogs.com/findumars/p/5745345.html):服务端在收到续传请求时，通过If-Range中的内容(Etag|Last-Modified)进行校验，校验一致时返回206的续传回应，不一致时服务端则返回200回应，回应的内容为新的文件的全部数据

   [BS架构与CS架构详解](https://www.cnblogs.com/qqinhappyhappy/p/11741054.html):BS架构与操作系统无关的意思是windows、linux下都可以打开同一个网页

4. [DNS同时占用UDP和TCP53端口，更多使用UDP](https://blog.csdn.net/ldw662523/article/details/79564884)

   [CNAME作用详解](https://www.jianshu.com/p/65757b5c0762)

   > 比如www.baidu.com，这个二级域名解析到的是一个服务器的IP地址，比如8.8.8.8，而CNAME是将新域名，比如：a.www.baidu.com解析到另外一个域名，比如：www.baidu.com。
   > 当新域名产生后都指向CNAME域名后，在发生服务器需要更换或者迁移时，就只需要把www.baidu.com这个域名做重新设置就可以了，这样就减少了很多工作量。

   DNS资源记录:Linux/Unix网络编程6.2

5. [可重入和不可重入函数](https://www.cnblogs.com/didiaoxiaoguai/p/10765285.html)

   基本上下面的函数是不可重入的:
   > 函数体内使用了静态的数据结构
   > 函数体内调用了malloc()或者free()函数
   > 函数体内调用了标准I/O函数

6. >***gethostbyaddr***无法通过IP地址查询百度的域名地址，由于：
   >gethostbyname可以通过DNS服务器通过域名获取IP地址等信息。
   >但是gethostbyaddr输入参数时IP地址，这样无需经过DNS转换，无法获取域名等信息，但是可以在hosts文件中增加一个映射，它应该会检查hosts文件。

7. >***阻塞IO*** ：餐厅中，每张桌子一个“服务员”，在桌子上有人吃饭时，那么这个“服务员”就不能离开，必须要一直待到旁边，不管“客人”是否需要它，one2one的服务。
   >***非阻塞IO*** ：餐厅改变服务方式，“客人”通过大门进入餐厅后，服务员安排他们到对应的桌子，然后就离开，客人自己通过“点餐”设备向餐厅下单，下单完毕之后，服务员检查订单处，是否已有订单，服务员接单之后，又离开去为其他“客人”服务

8. [UDP没有发送缓冲区](https://blog.csdn.net/qq_22660775/article/details/88408337)

9. [进程 、进程组、会话、控制终端之间的关系](https://blog.csdn.net/yh1548503342/article/details/41891047)

10. [select、poll、epoll之间的区别](https://www.cnblogs.com/creazylinux/p/7364685.html)

    [epoll原理](https://baijiahao.baidu.com/s?id=1641172494287388070&wfr=spider&for=pc)

11. [Reactor模型简介](https://blog.csdn.net/weixin_43243916/article/details/89108887)
    [单Reactor单线程和单Reactor多线程的区别是：单线程负责事务处理，而多线程把处理工作交给线程池。在并发百万客户端连接请求时，一个NIO线程(单Reactor)可能存在性能不足的问题,所以使用主从Reactor](https://blog.csdn.net/weixin_43326401/article/details/104202424)
    

### 操作系统
1. [软连接和硬连接](https://www.jianshu.com/p/dde6a01c4094)
2. 死锁产生的必要条件：
>1.互斥条件：一个资源每次只能被一个进程使用。
>2.请求与保持条件：一个进程因请求资源而阻塞时，对已获得的资源保持不放。
>3.不剥夺条件:进程已获得的资源，在末使用完之前，不能强行剥夺。
>4.循环等待条件:若干进程之间形成一种头尾相接的循环等待资源关系。
3. 锁包括：互斥锁、读写锁、自旋锁、条件变量、RCU
4. 进程间通信方式：管道(普通管道、命名管道)、消息队列、信号量、信号、共享内存、套接字socket
5. 线程间通信方式：临界区、互斥量、信号量、事件(信号)
6. [协程](https://www.jianshu.com/p/6dde7f92951e)
7. 用户态切换到内核态的3种方式:系统调用、异常、外围设备的中断
8. [Linux内核时钟系统和定时器实现(主要看看图)](https://blog.csdn.net/anonymalias/article/details/52022787?depth_1-utm_source=distribute.pc_relevant.none-task-blog-BlogCommendFromBaidu-10&utm_source=distribute.pc_relevant.none-task-blog-BlogCommendFromBaidu-10)
9. [vfork和fork的区别](https://www.jianshu.com/p/6a83ac98e77a)
10. [使用多级页表的意义](https://blog.csdn.net/ibless/article/details/81275009)
    [多级页表如何节约内存](https://www.jianshu.com/p/83cca28be71d)
>###### 速览
>多级页表优势：
>1.可以离散存储页表
>2.在某种意义上节省页表内存空间
>多级页表劣势：
>增加寻址次数，从而延长访存时间
11. [条件变量+互斥锁](https://blog.csdn.net/qq_39736982/article/details/82380689) 
    [条件变量](https://www.cnblogs.com/biglucky/p/4635163.html)
>pthread_cond_wait函数中在进入wait状态前首先进行解锁，然后接收到信号后会再加锁
>相较于mutex而言，条件变量可以减少竞争
>如直接使用mutex，除了生产者、消费者之间要竞争互斥量以外，消费者之间也需要竞争互斥量，但如果汇聚（链表）中没有数据，消费者之间竞争互斥锁是无意义的
>有了条件变量机制以后，只有生产者完成生产，才会引起消费者之间的竞争。提高了程序效率
12. [CPU访问非对齐的内存时为何需要多次(一般为2次)读取再拼接](https://blog.csdn.net/u010536615/article/details/98748100)
13. 操作系统页式管理和段式管理的区别：PPT第6章 主存管理 Page68 速览：
|  页式管理  | 段式管理  |
|  ---  | --- |
| 用户不可见 | 用户可见  |
| 信息的物理划分 | 信息的逻辑划分  |
| 页的大小是固定的  | 段长是可变的 |
| 段内位移字段的溢出将加入到页号中 | 段内位移字段的溢出将产生越界中断  |
14. [Linux内核的同步机制part1](https://www.ibm.com/developerworks/cn/linux/l-synch/part1/)
    [Linux内核的同步机制part2](https://www.ibm.com/developerworks/cn/linux/l-synch/part2/)
15. [进程同步的四种方法:临界区、互斥量、信号量、事件](https://blog.csdn.net/zxx901221/article/details/83006453)

### 数据库
|  sql  | nosql  |
|  ---- | ---    |
| MySQL | mongodb(文档存储)|
|       | redis(key-value存储)   |
|       | memcached(key-value存储)|
1. [MySQL索引背后的数据结构及算法原理](http://blog.codinglabs.org/articles/theory-of-mysql-index.html)
2. [Redis->HyperLogLog](https://www.jianshu.com/p/f008ae58336a)
   [Redis->Pre-Sharding扩容问题+单点故障问题](https://blog.csdn.net/rosanu_blog/article/details/68066756)
   [Redis 缓存雪崩、击穿、穿透](https://mp.weixin.qq.com/s?__biz=MzAxODQxMDM0Mw==&mid=2247485801&idx=1&sn=a76b8594cfbe3fcdc34e878a5ab35314&chksm=9bd7f761aca07e77b4a10fdab824b103ea220529455bae8341a6d778a17f4c5d29835751556e&mpshare=1&scene=1&srcid=0710laSRE4WcivD9IcUVGAju&sharer_sharetime=1594371625848&sharer_shareid=7e04195f334429938a8db0f4c3463f9f#rd)
   [Redis基础](https://mp.weixin.qq.com/s?__biz=MzAwNDA2OTM1Ng==&mid=2453140867&idx=2&sn=5c573be40ff3e897bed2ede542ef8c34&chksm=8cf2d700bb855e166f6c8db7d89185b26139ace92ef70484084ce2abd9a6c9e66eb0f84b9695&mpshare=1&scene=1&srcid=0711lywgMZDqpw8qNiVARk0i&sharer_sharetime=1594437708507&sharer_shareid=7e04195f334429938a8db0f4c3463f9f&key=fd82000ac0805293e2464f0ff31a5837d5af1315d265e5ac9179d6e969093b55b1fc71998555d8875cb9482382f257a959d38fd31d777fc16329a4ff488ee079ee07769fb65772254f6143d590f1f811&ascene=1&uin=MTcxNjk3NjQwNw%3D%3D&devicetype=Windows+7+x64&version=62090070&lang=zh_CN&exportkey=AzajvZ2eITA4GvUSitAm05o%3D&pass_ticket=aNEGdwEAPPz64xHSOxJMu0pNKhvEZ7Y8deppO4yetYYO1AC4pOEsiQUUje%2BjDRmR)
3. mongostat:insert/delete/query/update(支持查询增删查改性能)  
   mongotop:read/write(支持查询读写性能)
4. [Redis、Memcache和MongoDB的区别](https://www.cnblogs.com/tuyile006/p/6382062.html)


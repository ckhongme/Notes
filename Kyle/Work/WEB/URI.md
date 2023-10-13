### 统一资源标识符 URI
全称Uniform Resource Identifier；
**作用**：标识某一互联网资源；在互联网上就是通过URI来访问互联网上的资源的；
Web上可用的每种资源，例如html文档，图像，视频，程序等都是由一个URI来定位的；

![[URI.png]]
URI由两个主要的子集 [[URL]] 和 [[URN]]构成：
***



[http://user:pass@www.example.com:80/home/index.html?age=11#mask](http://user:pass@www.example.com:80/home/index.html?age=11#mask)
协议方案名：http
登录信息（认证）：user:pass
服务器地址（域名）：[www.example.com](http://www.example.com)
端口号：80
文件路径：/hone/index.html
查询字符串：age=11
片段标识符：mask
***
协议方案名：http:、https:、ftp:等，在获取资源时要指定协议类型。
登录信息(认证)：指定用户名和密码作为从服务器端获取资源时必要的登录信息，此项是可选的。
服务器地址：使用绝对URI必须指定待访问的服务器地址。
服务器端口号：指定服务器连接的网络端口号，此项是可选的。
路径：指定服务器上的文件路径来定位特定资源。格式为: /home/index.html
参数：为应用程序提供访问资源所需的附加信息。例如：[ftp://127.27.27.27/pub/pic;type=d](ftp://127.27.27.27/pub/pic;type=d)
查询字符串：针对已指定的文件路径内的资源，可以使用查询字符串传入任意参数，此项是可选的。
片段标识符：通常可标记出以获取资源中的子资源(文档内的某一个位置)，此项是可选的。
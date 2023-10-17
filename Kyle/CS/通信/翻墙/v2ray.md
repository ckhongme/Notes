[新 V2Ray 白话文指南](https://guide.v2fly.org/)

经过合理的配置，V2Ray 可以识别并区分需要代理和不需要代理的流量，直连的流量不需要绕路
***
V2Ray 需要配置至少一个入站协议（Inbound）和一个出站协议（Outbound）才可以正常工作

入站协议负责与客户端（如浏览器）通信；
出站协议负责将数据发给服务器；
### 运行
在 Windows 和 macOS 中，配置文件通常是 V2Ray 同目录下的 `config.json` 文件。直接运行 `v2ray` 或 `v2ray.exe` 即可
Proxy (代理)、Direct (直连)、Block (阻止)
### 路由规则
**预定义域名列表 geosite:**
以 geosite: 开头，后面是一个预定义域名列表名称，如 geosite:google ，意思是包含了Google旗下绝大部分域名；或者 geosite:cn，意思是包含了常见的大陆站点域名
常见名称及域名列表
    ```
    category-ads：包含了常见的广告域名。
    category-ads-all：包含了常见的广告域名，以及广告提供商的域名。
    cn：相当于 geolocation-cn 和 tld-cn 的合集。
    apple：包含了 Apple 旗下绝大部分域名。
    google：包含了 Google 旗下绝大部分域名。
    microsoft：包含了 Microsoft 旗下绝大部分域名。
    facebook：包含了 Facebook 旗下绝大部分域名。
    twitter：包含了 Twitter 旗下绝大部分域名。
    telegram：包含了 Telegram 旗下绝大部分域名。
    geolocation-cn：包含了常见的大陆站点域名。
    geolocation-!cn：包含了常见的非大陆站点域名，同时包含了 tld-!cn。
    tld-cn：包含了 CNNIC 管理的用于中国大陆的顶级域名，如以 .cn、.中国 结尾的域名。
    tld-!cn：包含了非中国大陆使用的顶级域名，如以 .hk（香港）、.tw（台湾）、.jp（日本）、.sg（新加坡）、.us（美国）.ca（加拿大）等结尾的域名。
    ```
**域名 domain:**
domain代表子域名；
由 domain: 开始，后面是一个域名。例如 domain:baiyunju.cc ，匹配 [www.baiyunju.cc](http://www.baiyunju.cc/) 、[baiyunju.cc](http://baiyunju.cc/)，以及其他baiyunju.cc主域名下的子域名。
**完整匹配 full:**
由 full: 开始，后面是一个域名。例如 full:baiyunju.cc 只匹配 [baiyunju.cc](http://baiyunju.cc/)，但不匹配 [www.baiyunju.cc](http://www.baiyunju.cc/) 。
***
### pac.txt
"||[example.com](http://example.com)", 意思是所有example.com域名下的网址都走代理
##### 例外规则
"@@||[example.com](http://example.com)",意思是所有example.com域名下的网址都不走代理
##### 起止规则
"|http://example.com、example.com|", 匹配地址开始和结尾，意思是以http://example.com开始和以example.com结束的地址都走代理
设置好了之后，将v2rayN设置为disable，再重新打开Pac模式即可；
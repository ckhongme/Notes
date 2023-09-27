### 配置SSH[[密钥]]
##### 检查密钥
```bash
# 找个文件夹，右键 git bash here，输入 
$ ~/.ssh 
# 如果出现以下回复，就表示已经有 SSH Key 
bash: /c/Users/XX/.ssh: Is a directory
```
##### 创建密钥
```bash
# 需要填上你自己的邮箱
$ ssh-keygen -t rsa -C user@email.com
```
保存到默认的位置就好，push文件的时候，我们也不希望每次都输入密码，所以一直回车确认即可，不需要输入什么；
然后在电脑C盘的User目录下找到.ssh目录，查看里面是否有 id_rsa（私钥）和id_rsa.pub（公钥）；
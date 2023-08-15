截至2020/6/1
***
全称Windows Mixed Reality；
开发没有单独的 SDK，使用 Visual Studio 和 Windows 10 SDK：[混合现实官方的开发文档](https://docs.microsoft.com/zh-cn/windows/mixed-reality/development)

[[Hololens]]
Unity的开发工具包：[[MRTK]] 
[[WMR+SteamVR]]
***
### 开发环境

**Windows设置**
1.通过“设置”>“更新和安全”>“对于开发人员”在电脑上启用开发人员模式；（注意：“N”版本不支持 WMR头显设备）
2.如果插入WMR设备没有反应，需要更新windows版本，安装混合现实门户Mixed Reality Portal；

**VS设置**
使用 Visual Studio 来编写代码、调试、测试和部署
- 使用 C++ 的桌面开发
- 通用 Windows 平台 (UWP) 开发
确保更新到VS2019 16.2或更高版本；

**Windows SDK**
- 如果仅针对桌面 Windows Mixed Reality 头戴显示设备或 HoloLens（第 1 代）开发应用程序，则可以使用 Visual Studio 2017 安装的 Windows SDK；
- 若要生成 HoloLens 2 应用，必须安装 Windows SDK 内部版本 18362 或更高版本； [ Windows SDK 官网](https://developer.microsoft.com/en-us/windows/downloads/windows-10-sdk/)

**电脑硬件**
如果没有全尺寸 HDMI 和/或 USB 3.0 端口，则需要适配器才能连接头戴显示设备；
##### PC桌面和混合现实之间的切换
在Windows设置中：将自动切换改成手动切换；
![[wmr1.png]] -> ![[wmr2.png]] -> ![[wmr3.png]] -> ![[wmr4.png]]
##### 无法启动Windows混合现实 
错误代码：14-2
到设备管理器中，找到混合显示设备，把多余的虚拟头显卸载掉
![[wmr5.png]]

***
### WMR 头显

HP WMR头显| Reverb G1头显 | Reverb G2头显
--|-- |--
摄像头：2个180度的<br> Tracking：采用微软的Hololens跟踪技术<br>FOV：95度<br>双LCD面板：单眼1440x1440|两个摄像头<br>需要的显卡：GTX 1080 | 价格：600美元<br>摄像头：4个<br>需要的显卡：GTX 1080<br>双LCD面板：单眼2160x2160<br>Tracking比G1有所提升，但比起 Quest和Rifts，跟踪区域还是偏小<br>新的WMR手柄

[WMR模拟器](https://docs.microsoft.com/zh-cn/windows/mixed-reality/using-the-windows-mixed-reality-simulator)

**设置**
Win菜单 -> 设置 -> 更新和安全 -> 开发者选项 -> 使用开发者人员功能 -> 选择“开发者模式”

**启用WMR模拟器**
混合现实门户 -> 开发者选项 -> 打开头戴显示设备 -> 启用键盘模拟 和 鼠标模拟
![[混合显示门户.png]] ![[wmr模拟器开关.png]] ![[wmr输入设置.png]]

**配对MR控制器**
前提：PC需要支持蓝牙4.0
1.在蓝牙设置中，将已经识别的运动控制器删除；
2.打开控制器的电源，进入控制器的配对状态；（按住电池盒旁的按键，直至Led开始闪烁）
3.匹配蓝牙列表中的“Motion controller - Right”和“Motion controller - Left”；
![[Motion controller.png]]

[运动控制器](https://docs.microsoft.com/zh-cn/windows/mixed-reality/motion-controllers#setup)
[如何在 Unity 中动态加载控制器模型](https://docs.microsoft.com/zh-cn/windows/mixed-reality/gestures-and-motion-controllers-in-unity#rendering-the-motion-controller-model-in-unity)

***

##### 打不开Microsoft Store
一、调整网络连接
建议您先尝试更换网络连接，比如连接个人手机热点，再使用 Microsoft Store 进行尝试。如果您连接了 VPN 或下载了第三方防火墙应用，建议断开 VPN，卸载第三方防火墙应用。
按 “Windows 徽标键+X”，启动 “Windows PowerShell（管理员）”，输入以下命令，回车后重启设备：
netsh winsock reset

二、更改 DNS
1. 右键网络连接图标，选择 “打开网络和共享中心”。
2. 点击现在连接的网络名称，打开网络状态窗口，点击 “属性”，在网络属性窗口中双击 “Internet 协议版本4 (TCP / IPv4)”。
3. 将 DNS 服务器手动设置为“4.2.2.1” 和 “4.2.2.2”，确定后重试。

三、清理应用商店的缓存
按 “Windows 徽标键+R”，在运行窗口中，键入“WSReset.exe” 并点击 “运行”。

四、重置应用商店
打开 设置>应用>应用和功能>在左边的列表中找到应用商店选中>高级选项>重置。
  
五、调整 Internet 选项
打开 IE 浏览器，点击设置，打开 Internet 选项，点击高级，并勾选 “使用SSL 3.0”、”使用 TLS 1.0“、”使用 TLS 1.1“、”使用 TLS 1.2“，应用后重启电脑，查看能否解决问题。

六、重新部署应用商店
在打开的 “Windows Powershell（管理员）” 窗口中输入以下命令（慎用）：
get-appxpackage *store* | remove-Appxpackage
再次安装：
add-appxpackage -register "C:\Program Files\WindowsApps\*Store*\AppxManifest.xml" -disabledevelopmentmode
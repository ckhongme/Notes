适用于[[Unity]] 的 Microsoft 混合现实工具包 (MRTK)  
一款面向混合现实应用程序的开源跨平台开发套件；
旨在加快面向 Microsoft [[Hololens]]、[[WMR]]头戴显示设备和 [[OpenVR]] 平台的应用程序的开发；
##### 下载MRTK
下载地址：[https://github.com/Microsoft/MixedRealityToolkit-Unity/releases](https://github.com/Microsoft/MixedRealityToolkit-Unity/releases)
Microsoft.MixedReality.Toolkit.Unity.XXX
其中 Foundation 跟 Tools 是必须要下载的；
#### 导入MRTK
MSBuild for Unity 可能不支持你将使用的所有 SDK，在启用它后再禁用它可能比较困难。 因此，强烈建议不要启用 MSBuild for Unity；
![[MSBuild for Unity.png]]
##### 添加MRTK到场景中
![[添加MRTK到场景中.png]]
- Mixed Reality Toolkit - 工具包本身，为整个框架提供中央配置入口点。
- MixedRealityPlayspace - 头显的父对象，可确保在场景中正确管理头显/控制器和其他所需系统。

请勿将主摄像机（或MixedRealityPlayspace）从场景原点（0,0,0）移开；
如果需要设置用户的起点，请移动场景内容而不是相机

##### MRTK的设置文件
默认情况下，MRTK 配置文件不可编辑。 这是一些默认的配置文件模板，必须先克隆再编辑；
![[MRTK的设置文件.png]]
Diagnostics 可以显示或关闭数据信息的框；

##### 错误处理
- D3D11: Failed to create rendertexture primary DSV (error 0x80070057)
在Unity的Quality Setting中，将Anti Aliasing（MSAA）设置为 Disabled 即可

 - Failed to complete start recognition system (hr = 0x80070005)
需要打开麦克风权限：
Windows设置 -> 隐私 -> 麦克风 -> 打开麦克风访问权限
![[MRTK的麦克风权限.png]]
用了 MRTK 的 Input module 后，不能使用 Standard Input module，会报错：
***

[MRTK中文文档(一)：开始使用MRTK](https://connect.unity.com/p/mrtkzhong-wen-wen-dang-yi-kai-shi-shi-yong-mrtk)
[对着色器进行 SinglePassInstanced 的设置](https://docs.unity3d.com/Manual/SinglePassStereoRenderingHoloLens.html)
[How to maximize AR and VR performance with advanced stereo rendering](https://blogs.unity3d.com/2017/11/21/how-to-maximize-ar-and-vr-performance-with-advanced-stereo-rendering/)


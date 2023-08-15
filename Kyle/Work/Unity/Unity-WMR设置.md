1.切换到UWP平台
![[Unity的UWP平台.png]]

2.勾选VR支持：在XR Settings中勾选 Virtual Reality Supported，添加 Windows Mixed Reality
![[Unity的WMR支持.png]]
启动深度缓存共享，并且将深度格式设置为 16bit，减少带宽需求；
![[WMR的深度缓存共享.png]]

3.在Publishing Settings中设置
为了使应用能够使用空间映射数据，需要开启SpatialPerception；
![[Unity开启SpatialPerception.png]]

Unity 错误
currently selected scripting backend(il2cpp) is not installed
![[currently selected scripting backend(il2cpp) is not installed.png]]
需要下载该版本Unity的 Windows Build Support（IL2CPP）模块
![[Unity的 Windows Build Support（IL2CPP）模块.png]]

***
1.运行平台是否 UWP；
2.是否打开了虚拟现实门户；
3.Unity是否开启了虚拟现实支持；
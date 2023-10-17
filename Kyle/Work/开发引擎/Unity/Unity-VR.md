[[VR]]
### 移动VR-高通骁龙
截至2020/6/24

[https://www.qualcomm.cn/](https://www.qualcomm.cn/news/releases-2019-05-21)
系统要求：
装有LA 2.0（1463+）CRM的安卓 7.1或者以上

Unity设置
- 2017以前使用32bit版本，2018以后使用64bit版本；
- 导入SDK后建议重启一次Unity；

安卓平台
PlayerSettings：
- Resoulution and Presentation -> Default Orientation -> Landscape Left for 845 & Landscape Right for 835；
- XRSettings -> Virtual Reality Supported -> 不勾选；
- OtherSettings -> Multithreaded Rendering -> 不勾选；

Project Setting -> Quality：
- Anisotropic Textures ：各向异性纹理设置成 PerTexture
- Anti Aliasing：抗锯齿设置成 Disable（抗锯齿功能可以在 SvrCamera 的属性中启用，注意要先禁用HDR）
- V Sync Count：同步计数设置成不同步 Don't Sync

Unity编辑模式下，出现 Camera No Renderering 是正常的，可以忽略；
尽量不要在编辑模式下给SvrCamera对象增加子物体，而是通过 SvrManager.Instance 获取head 和 gaze进行同步；



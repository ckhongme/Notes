截至2020/6/10
不建议，很容易奔溃
***
[如何在steamVR上同时使用WMR头显和vive手柄](https://www.bilibili.com/video/BV1zW411A7of?from=search&seid=3127566985066486602)
##### 修改设置
找到Steam/config/steamvr.vrsettings文件，
打开后找到“steamvr”，在括号里添加一行“activateMultipleDrivers":true,
##### 连接设备
1.连接 Vive头显
2.开启基站，并打开 Window Mixed Reality for SteamVR
3.
方式1：连接Vivei头显，并断开HDMI线，打开HTC Vive手柄；
方式2：先通过USB连接Tracker，当出现灰色图标时，再断开Tracker，通过tracker 的USB接收器来配对Tracker或者手柄；
##### 下载输入仿真器
[OpenVR输入仿真器的Github库](https://github.com/matzman666/OpenVR-InputEmulator)
重新打开SteamVr，并且配对Vive手柄，进入SteamVR界面，点击菜单键，进入设置界面
选中 Device Offsets
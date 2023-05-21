基于时间轴的多轨道动画系统，它支持可视化编辑，实时预览；
用直观的方式来管理场景，轻松创建复杂的交互式场景；

在对Timeline操作时可以点击Timeline右上角🔒状态，锁定界面；
***
### 编辑器轨道 Track
##### 1.显隐 Activation Track
控制物体的显示和隐藏;
若对象本身带有动画，那么隐藏后再显示时，动画会重新播放；
Inspector中的Post-playback state属性：
-   Active：播放结束后设置为显示；
-   Inactive：播放结束后设置为隐藏；
-   Revert：播放结束后，还原到第一帧时的状态；
-   Leave As Is：播放结束，保持最后一帧时的状态；

##### 2.动画 Animation Track
为物体添加动画；
右键Animation Track，选择Add From Animation Clip，或者直接把动画资源拖进clips里，可以添加Animation Clip；

录制动画；
动画效果可以叠加；
可以设置曲线；

##### 3.音频 Audio Track
控制声音；
设置声音的起始时间，结束时间，淡入时间，淡出时间，播放速度，音效混合，循环播放等；

##### 4.控制 Control Track
控制粒子特效；
嵌套子时间轴；
可以在指定的父物体下实例化一个Prefab，并对该prefab中与时间相关的元素进行操作；

##### 5.信号 Signal Track
可以发送信号，触发响应信号的函数调用

##### 6.自定义 Playable Track
可编程摄像头，可以自定义动画效果；

##### 7.Cinemachine Track
镜头剪辑；
触发虚拟摄像机；

#### Track Group
将不同的轨道分类，相当于文件夹；

***
Multiple：可以在一个轨道上放置多个剪辑以创建动画序列。可以使用“轨迹选项”菜单添加“重写”曲目，允许动画分层。
***
### 序列文件 PlayableAsset
是一个外部assets，是Editor的一部分，后缀是.playable；
相关属性：
-   FrameRate：设置每秒钟
-   DurationMode - Based On Clips：按照下面设置好的帧数来播放，播放到指定的最后一帧为止；
-   DurationMode - Fixed Length：按照下面设置好的时间来播放，播放到指定时间位置；
-   Duration：设置指定的播放秒数和帧数；

### PlayableDirector
把Timeline文件拖到对象上时会自动生成，用以控制timeline的时候开始时间，结束时间和怎样进行；
可以通过脚本动态控制；
-   Playable：要播放的序列
-   Update Method：更新方式（播放时间的基准）
-   Play on Awake：是否一开始就播放
-   Wrap Mode：当序列到达终点时会发生什么（None，循环，保持）
-   Initial Time：开始播放时时间轴的初始位置
-   Bindings：对应timeline轨道中绑定的物体；

##### Update Method
a. DspClock：选择用于精确音频采样的样本。 选中后，Timeline实例将使用处理音频的相同时钟源  
b. GameTime： 游戏时间，会受到 TimeScale 的硬性，即当游戏时间被程序缩放时，更新频率也会跟着进行缩放  
c. UnscaledGameTime：不受缩放影响游戏时间，和 GameTime 不同的是不会受到 TimeScale 的影响，即游戏 time 的缩放不会对更新频率产生影响  
d. Manual：手动模式，即需要程序调用更新方法才会更新一次

  




### Mecanim动画系统
##### 状态
每一个动画剪辑（Animation Clip）就是一个状态，黄色表示默认状态；
设置Speed的值为-1，可以进行倒序播放
##### 过渡线
动画之间的切换条件，以箭头表示；
选择箭头，可以添加中间条件；
Animator中动画之间添加连线的是“或者”关系，添加的条件参数是“并且”关系；

##### Animator
新版动画状态机，可以管理多个动画切换的状态
##### Animation Clip
创建：window -> Animation -> 选择一个对象 -> Create
##### AnimatorController
动画控制器，控制动画逻辑
##### Avatar
将角色的骨骼转化为可识别的一般骨骼或者人型骨骼
1.AnimationType选择
2.Avatar配置

Avata Mask
动画遮罩
Layer的概念和组合动画的使用


Blend Tree
混合树

Animation窗口有两种时间轴模式：DopeSheet（涂料表）和 Curves（曲线）；切换按键位于动画属性列表区域底部；
***
##### 模型自带位移的问题
1. 将模型的Animator组件中Apply Root Motion 的勾选去掉；
2. 把相应动画中的Loop Pose 选项勾选上

带动画的3D模型导入Unity中，默认会设置成Animator的新动画系统，要使用Animation的形式播放需要：
1.  找到导入的模型FBX
2.  在Inpector中的Rig中将Animation Type 从Generic 设置成 Legacy；
3.  Apply





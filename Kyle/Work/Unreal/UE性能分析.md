[[stat unit]]
stat unitGraph：可以显示线形图回放
##### Game Thread：计算所有的游戏逻辑
逻辑层面的计算与模拟（生成多少个新actor，每个actor的位置，移动，动画状态等等）
会算出不需要渲染的内容；
瓶颈常见于Tick 和代价昂贵的逻辑实现；

Tick
大量物体同时 Tick 会严重影响 Game Thread 的耗时
**stat game**：显示 Tick 的耗时情况
**dumpticks**：可将所有正在 _tick_ 的 _actor_ 打印到 _log_ 中

复杂逻辑
需要借助 Unreal Frontend Profiler / Unreal Insights 等工具对游戏逻辑中开销较大的代码进行定位

##### Draw Thread




r.VSync=0关闭垂直同步
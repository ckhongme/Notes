使用思路：创建出想要的各种虚拟相机然后调参数；
原理：不创建新相机，通过控制Unity相机来实现多机位的效果；

跟随物体
镜头晃动

### 虚拟相机
跟踪目标：
-   **Follow**指定了相机跟随移动的目标。
-   **Look At**指定了相机瞄准的目标
***
#### Body属性：控制如何移动
-   **Do Nothing**：不移动虚拟相机
-   **Framing Transposer**：在屏幕空间，保持相机和跟随目标的相对位置，可以设置缓动。
-   **Hard Lock to Target**：虚拟相机和跟随目标使用相同位置。
-   **Orbital Transposer**：相机和跟随目标的相对位置是可变的，还能接收用户的输入。常见于玩家控制的相机。
-   **Tracked Dolly**：相机沿着预先设置的轨道移动。
-   **Transposer**：相机和跟随目标的相对位置固定，可以设置缓动

#### Aim属性：控制如何旋转
-   **Composer**：将目标保持在相机镜头内，可以设置多种约束
-   **Group Composer**：将多个目标保持在相机镜头内
-   **Do Nothing**：不旋转相机
-   **POV**：根据用户的输入旋转相机
-   **Same As Follow Target**：将相机的旋转和跟随目标的旋转同步
-   **Hard Look At**：将Look At目标固定在镜头中心的位置
***
##### 镜头构图
-   **Dead zone**：目标在这个区域时，镜头保持不动；
-   **Soft zone**：在这个区域会触发相机运动，将目标重新移回dead zone；（过程快慢取决于**Damping**属性设置）
-   **Screen**：Dead zone区域的中心在屏幕上的位置，可以不在整个游戏屏幕的正中间；
-   **Damping**：设置了目标进入soft zone后相机的反应速度；数值越小，相机反应越快；

勾选组件中的**Game Window Guides**后，可以选中TimeLine的时候，在Game窗口可视化的查看构图区域；

##### 应用：
增加dead zone和soft zone来创建一个对目标运动不敏感的相机
***
### 固定轨道
##### CinemachineSmoothPath
每个waypoint包含XYZ的坐标信息，以及Roll的旋转信息（绕Z轴的旋转）
- Resolution：定义waypoint之间的精度，即被分成多少段；
- Appearance：路径在Scene视图中的显示；
- Looped：是否首尾相连；
- PathLength：路径的总长度；

##### CinemachinePath
waypoint的属性中除了Position和Roll外，还多了**Tangent**属性;

### Tracked Dolly
- Position Units：决定Path Position的单位；
- Path Offset：相对于Path的偏移；
- Camera Up：虚拟相机的up方向；
- Auto Dolly：自动将VirtualCamera移动到Path上最接近Follow目标的位置；

Camera Up | 含义
--|-- 
Default|不修改VirtualCamera的up的值，使用Cinemachine Brain中World Up Override属性代替
Path|使用当前位置Path的up向量
Path No Roll|使用当前位置Path的up向量，但是不受Roll影响
Follow Target|使用Follow目标的tramsform.up
Follow Target No Roll|使用Follow目标的tramsform.up，但是不受Roll影响

Auto Dolly可能出现的问题：
![[Tracked Dolly的Auto Dolly.gif]]

### Cinemachine Dolly Cart
约束物体在路径上移动；
Update Method：速度不为0时，移动Cart的时机（对于普通的组件更新使用Update，若想要同步物理模块，使用Fixed Update）；
Position Units与Position：同[[Cinemachine#Tracked Dolly]]
Speed：Cart的移动速度，同样受到Position Units的影响；
***
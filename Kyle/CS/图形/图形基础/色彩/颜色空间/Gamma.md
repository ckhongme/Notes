### 伽马色彩空间
用于处理图像灰度的[[色彩空间]]；
因为**显示设备的局限性**和**人眼对光线感知的非线性**，图像在显示设备上显示之前会经过[[显示器Gamma]]；
所以保存在硬盘上的图像都是先经过[[Gamma校正]]的，如果要对硬盘上的图像进行光照计算，需要先进行[[显示器Gamma]]；
##### 流程：
正确颜色 -> 传给显示器前进行[[Gamma校正]] -> 显示设备的[[显示器Gamma]] -> 正确颜色
### 什么是Gamma？
Gamma也叫灰度系数，每种显示设备都有自己的Gamma值，各不相同；
### 显示器的光信号采样
让显示设备上的颜色，更接近于人眼感知的颜色；（相比正常的光信号，保留更多的暗部细节）
补偿人眼对自然光亮度的非线性感知；
处理的对象是拍摄的图像，对图像中的光信号进行非线性映射；
##### 1. 数据存储量问题：为什么要压缩图像？
一般的显示设备只能存储亮度域对比为256:1的数据量，而自然光是50000:1；
所以不能以线性的方式进行存储，拍摄的图像需要通过采样进行数据压缩；
##### 2.人眼感知问题：为什么不能进行线性压缩？
亮度对人眼的刺激是非线性的，人眼感觉黑到白的范围“有限”，当亮度到达一定程度后就会趋于一个有限制值；
例子：一间黑屋子中，点亮了一只灯泡A，人眼会感觉照亮整间屋子，持续点亮第2个、第3个……灯泡后，人眼会感觉屋子逐渐变得明亮，此时再点亮第N+1个灯泡，其实人眼没有什么感觉；
如果直接保存光信号线性采样后的数据，会丢失人眼能看到的大部分暗部细节；
![[Gamma矫正1.png]]
##### 3. 压缩原理：非线性映射
在对光信号采样时，通过提高采样次数，然后舍弃部分亮部采样点，保留更多的暗部采样点，从而得到一个相对于人眼而言，亮部和暗部表现均匀的灰阶图；
![[Gamma矫正2.png]]
上图是自然界线性增长的亮度和人心理感觉的灰阶关系图：
当物理亮度达到白色的20%左右的时候，人已经感受到了中灰色（即0.5处）；


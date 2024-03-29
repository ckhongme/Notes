### 什么是 HDR ？
高动态范围（High Dynamic Range）图像，能表现出更大范围的亮度域，能显示的颜色更丰富，在观感上更加自然；
HDR需要专业的显示器（能显示10bit）和专业的显卡（支持10bpc输出）；
### 为什么会有HDR？
[[SDR]]只能表现出256:1的亮度域差别，然而在自然中太阳光下的对比度是50000:1；
HDR能把亮度域差别提高到1024:1;
### 10bit（[[像素#色深]]）
一个像素能表示成  1024 x 1024 x1024 = 1073741824（**10.7亿**）种颜色
### HDR的标准
- HDR 10（基础标准，也是目前使用最广泛的 HDR 标准）
- DOLBY VISION
- HDR10+
- HLG
- HDR Vivid
### HDR 10
HDR 10 采用 Rec. 2020 色域，发布于 2012 年，比起 Rec. 709 色域包含更多的颜色；（[[色彩#色域]]）
![[Rec. 2020 色域.png]]
### 色调映射 tone-mapping
- 传统的显示设备不能完全的显示出HDR，需要通过 tone-mapping 让图像从HDR映射为SDR显示；
- HDR有不同的标准，需要通过tone-mapping来改变动态范围；
***
相片所能表现的亮度范围不足以表现现实世界中的亮度域，如果简单的将真实世界的整个亮度域线性压缩到照片所能表现的亮度域内，则会在明暗两端同时丢失很多细节，所以需要根据所拍摄场景内的整体亮度通过光圈与曝光时间的长短来控制一个合适的亮度域；
人眼是通过瞳孔来调节亮度域的；
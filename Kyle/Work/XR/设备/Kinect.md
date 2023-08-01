截至2018/9/6
***
Kinect一共有3个摄像头，中间一个是RGB摄像头，用来获取640×480的彩色图像，每秒钟最多获取30帧图像；
两边的是两个深度传感器，左侧的是红外线发射器，右侧的是红外线接收器，用来检测玩家的相对位置。
Kinect的两侧是一组四元麦克风阵列，用于声源定位和语音识别；
##### Kinect for Windows SDK
- 骨骼追踪：对在Kinect视野范围内移动的一个或两个人进行骨骼追踪，可以追踪到人体上的20个结点(一般是24个节点)。此外，Kinect还支持更精确的人脸识别。
- 深度摄像头：利用“光编码”技术，通过深度传感器获取到视野内的环境三维位置信息。这种深度数据可以简单地理解为一张利用特殊摄像头获取到的图像，但是其每一个像素的数据不是普通彩色图片的像素值，而是这个像素的位置距离Kinect传感器的距离。由于这种技术是利用Kinect红外发射器发出的红外线对空间进行编码的，因此无论环境光线如何，测量结果都不会受到干扰。
- 音频处理：与Microsoft Speech的语音识别API集成，使用一组具有消除噪音和回波的四元麦克风阵列，能够捕捉到声源附近有效范围之内的各种信息。
##### 文件夹
- KinectScripts       包含了 脚本，接口和过滤器（filters ）
- Resources           包含了所有需要的库和资源,
- Standard Assets     包含Kinect v2的MS包装类，等到Unity检测并编译新复制的资源和脚本
##### 设置Kinect传感器的高度和角度
将KinectManager中的AutoHeightAngle设置成ShowInfoOnly模式，运行几次，并记录对应的高度和角度，选择合适的数值填入Height和Angle，再吧AutoHeightAngle的模式设置成Dont Use；

GPU -> DirectX 11 (required)
3D建模 KinectFusion
### 脚本
KinectManager 是最最通用的组件,需要它与传感器交互以获取底层数据,譬如彩色数据流和深度数据流,以及身体和关节在Kinect空间中的位置（单位：米）。
AvatarController的目的是将检测到的关节位置和旋转传递到一个可操纵骨骼上。
CubemanController效果同上,但是它通过transforms 和线来展现关节和骨骼,以便于定位人体追踪问题；
FacetrackingManager（脸部追踪）用于处理脸部点阵和头/脖子旋转。如果与此同时KinectManager存在且可用的情况下， 它将被KinectManager 内部调用来获得头和脖子更精准的位置和旋转 。
InteractionManager（交互） 用于控制手型光标，同时检测手部的抓取、释放以及点击.
SpeechManager用于识别声控（语言识别控制）

**KinectSensor 物理传感器；**
```
KincetSensor sensor = KinectSensor.GetDefault();
sensor.Open();
sensor.Close();
```

**Sources 数据源：**
```
颜色：sensor.ColorFrameSoruce
红外：sensor.InfraredFrameSource
深度：sensor.DepthFrameSource  （0.5 - 8米）
身体：sensor.BodyFrameSource    （0.5-4.5米）
sensor.BodyIndexFrameSource
音频：sensor.AudioSource
```

**坐标系统**
```c#
ColorSpacePoint               Color
DepthSpacePoint              Depth，Infrared，Bodyindex
CameraSpacePoint            Body
```

**如何获得用户的depth（深度）或color（彩色）相机textures（纹理）：**
首先如果需要深度纹理，确保KinectManager组件的Compute User Map设置被启用即可
如果您需要彩色相机纹理，则KinectManager的Compute Color Map设置启用
```c#
Update()
{
    if(manager && manager.IsInitialized)
    {
        Texture2D depthTex = manager.GetUsersLblTex();
        Texture2D colorTex = manager.GetUsersClrTex();
    }
}
```
**坐标转换**
```
空间坐标转换到深度坐标：public Vector3 MapDepthPointToSpaceCoords(Vector2 posPoint, ushort depthValue, bool bWorldCoords)
空间坐标转换到深度坐标：public Vector2 MapSpacePointToDepthCoords(Vector3 posPoint)
深度坐标转换到彩色坐标：public Vector2 MapDepthPointToColorCoords(Vector2 posPoint, ushort depthValue)
```

**获取画面的深度值和颜色值**
```c#
    private KinectManager _manager;
    private KinectSensor _sensor;
    private DepthFrameReader _reader_D;
    private ushort[] _data_D;
    private ColorFrameReader _reader_C;
    private byte[] _data_C;
    private Texture2D _colorTex;

    void Start ()
    {
        _manager = KinectManager.Instance;
        _sensor = KinectSensor.GetDefault();

        if (_sensor != null)
        {
            _reader_D = _sensor.DepthFrameSource.OpenReader();
            _data_D = new ushort[_sensor.DepthFrameSource.FrameDescription.LengthInPixels];
            _reader_C = _sensor.ColorFrameSource.OpenReader();
            var frameDesc = _sensor.ColorFrameSource.CreateFrameDescription(ColorImageFormat.Rgba);
            _colorTex = new Texture2D(frameDesc.Width, frameDesc.Height, TextureFormat.RGBA32, false);
            _data_C = new byte[frameDesc.BytesPerPixel * frameDesc.LengthInPixels];
        }
    }

    /// <summary>
    /// get depth and color data
    /// </summary>
    void GetData()
    {
        if (_reader_D != null)
        {
            var frame = _reader_D.AcquireLatestFrame();
            if (frame != null)
            {
                frame.CopyFrameDataToArray(_data_D);
                frame.Dispose();
                frame = null;
            }
        }
        if(_reader_C != null)
        {
            var frame = _reader_C.AcquireLatestFrame();
            if (frame != null)
            {
                frame.CopyConvertedFrameDataToArray(_data_C, ColorImageFormat.Rgba);
                _colorTex.LoadRawTextureData(_data_C);
                _colorTex.Apply();
                frame.Dispose();
                frame = null;
            }
        }
    }
    private void OnApplicationQuit()
    {
        if (_reader_C != null)
        {
            _reader_C.Dispose();
            _reader_C = null;
        }
        if(_reader_D != null)
        {
            _reader_D.Dispose();
            _reader_D = null;
        }
        if (_sensor != null)
        {
            if (_sensor.IsOpen)
                _sensor.Close();
            _sensor = null;
        }
    }
```


    
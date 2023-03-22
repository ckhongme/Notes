//
// Created by Kyle on 2023/3/20.
//

#ifndef CS_VR_DEMO_CSVROBJECTEARTH_H
#define CS_VR_DEMO_CSVROBJECTEARTH_H

#include <csvrBase/csvrObject.h>
#include <osgEarth/MapNode>

class csvrObjectEarth: public csvrObject
{
public:
    csvrObjectEarth();
    ~csvrObjectEarth();

    ///初始化地球节点
    void initMapNode(osgEarth::MapNode *pMapNode);
    ///设置经纬度(大地坐标系初始化旋转矩阵*平移矩阵)
    void setPosition(osg::Vec3d pos) override;

    ///获取经纬度
    osg::Vec3d getPostion() override;
    ///获取本地欧拉角
    osg::Vec3f getRotation() override;
    void setTransformMatrix() override;

    void rotateTo(osg::Vec3d to);
    osgEarth::MapNode *pMapNode = nullptr; //地球节点

private:
    ///地理坐标系转世界坐标系矩阵：大地坐标系初始化旋转矩阵（朝北和垂直地心）*平移矩阵
    void Earth2World(const osg::Vec3d& geoPos);
    osg::Vec3d RadianLLH2XYZ(const osg::Vec3d& geoPos);
    osg::Vec3d DegreeLLH2XYZ(const osg::Vec3d& geoPos);
};

#endif //CS_VR_DEMO_CSVROBJECTEARTH_H

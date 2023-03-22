//
// Created by Kyle on 2023/3/13.
//

#ifndef CS_VR_DEMO_CSVROBJECT_H
#define CS_VR_DEMO_CSVROBJECT_H

#include <osg/MatrixTransform>
#include <osg/Geode>
#include <osgEarth/MapNode>
#include <osg/Geometry>

class csvrObject: public osg::Group
{
public:
    csvrObject();
    ~csvrObject();

    //添加可绘制的物体
    void addDrawable(osg::Drawable* pDrawable);

    osg::Geode& getGeode();
    osg::Vec3d getScale();
    void setParent(osg::MatrixTransform parent);

    virtual void setScale(osg::Vec3 size);
    virtual void setRotation(osg::Vec3f rotaiton);
    virtual void setRotation(float angle, osg::Vec3d axis);
    virtual void setPosition(osg::Vec3d pos);
    virtual osg::Vec3d getPostion();
    virtual osg::Vec3f getRotation();

    virtual void setLocalScale(osg::Vec3 localScale);
    virtual void setLocalRotation(osg::Vec3f localRotation);
    virtual void setLocalPosition(osg::Vec3d localPos);
    virtual void setTransformMatrix();

    //欧拉角转成四元数
    osg::Quat Euler2Quat(osg::Vec3d euler);
    osg::Vec3f Quat2Euler(osg::Quat quat);

    osg::Matrix m_positionMt;   // 平移矩阵（世界坐标）
    osg::Matrix m_rotationMt;   // 旋转矩阵（世界坐标）
    osg::Matrix m_scaleMt;      // 缩放矩阵（世界坐标）
    osg::Matrix m_localPositionMt;
    osg::Matrix m_localRotationMt;
    osg::Matrix m_localScaleMt;

    osg::ref_ptr<osg::MatrixTransform> m_transform = nullptr; //变换
    osg::ref_ptr<osg::Geode> m_geode = nullptr;               //几何节点


    //TODO: 有父物体的情况下，设置世界位置自动修改本地坐标（角度，大小同理）
    osg::Vec3d m_position;
    osg::Vec3d m_localPosition;
    osg::Vec3f m_eulerAngle;
    osg::Vec3f m_localEulerAngle;
    osg::Vec3 m_scale;
    osg::Vec3 m_localScale;
};


#endif //CS_VR_DEMO_CSVROBJECT_H

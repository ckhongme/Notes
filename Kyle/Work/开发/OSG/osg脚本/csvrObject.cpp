//
// Created by Kyle on 2023/3/13.
//

#include <osg/ShapeDrawable>
#include "csvrBase/csvrObject.h"

csvrObject::csvrObject()
    : m_positionMt(osg::Matrix::identity())
    , m_rotationMt(osg::Matrix::identity())
    , m_scaleMt(osg::Matrix::identity())
    , m_localPositionMt(osg::Matrix::identity())
    , m_localRotationMt(osg::Matrix::identity())
    , m_localScaleMt(osg::Matrix::identity())
    , m_position(osg::Vec3d(0,0,0))
    , m_eulerAngle(osg::Vec3f(0,0,0))
    , m_transform(new osg::MatrixTransform)
    , m_geode(new osg::Geode)
{
    this->addChild(m_transform.get());
    m_transform->addChild(m_geode.get());
}

csvrObject::~csvrObject()
{
}

void csvrObject::addDrawable(osg::Drawable *pDrawable)
{
    m_geode->addDrawable(pDrawable);
}

osg::Geode &csvrObject::getGeode() {
    return *m_geode;
}

osg::Vec3d csvrObject::getScale(){
    return m_transform->getMatrix().getScale();
}

void csvrObject::setScale(osg::Vec3 scale)
{
    m_scale = scale;
    m_scaleMt = osg::Matrix::scale(scale);
    setTransformMatrix();
}

void csvrObject::setPosition(osg::Vec3d pos)
{
    m_positionMt = osg::Matrix::translate(pos);
    setTransformMatrix();
}

void csvrObject::setRotation(osg::Vec3f rotation)
{
    m_eulerAngle = rotation;
    m_rotationMt = osg::Matrix::rotate(Euler2Quat(rotation));
    setTransformMatrix();
}

void csvrObject::setRotation(float angle, osg::Vec3d axis)
{
    m_rotationMt = osg::Matrix::rotate(osg::DegreesToRadians(angle), axis);
    setTransformMatrix();
}

osg::Vec3d csvrObject::getPostion(){
    return m_transform->getMatrix().getTrans();
}

osg::Vec3f csvrObject::getRotation()
{
    return Quat2Euler(m_transform->getMatrix().getRotate());
}

void csvrObject::setLocalScale(osg::Vec3 localScale){
    m_localScaleMt = osg::Matrix::scale(localScale);
    setTransformMatrix();
}

void csvrObject::setLocalRotation(osg::Vec3f localRotation)
{
    m_localRotationMt = osg::Matrix::rotate(Euler2Quat(localRotation));
    setTransformMatrix();
}

void csvrObject::setLocalPosition(osg::Vec3d localPos)
{
    m_localPositionMt = osg::Matrix::translate(localPos);
    setTransformMatrix();
}

void csvrObject::setTransformMatrix()
{
    m_transform->setMatrix(m_localScaleMt * m_scaleMt * m_localRotationMt * m_localPositionMt * m_rotationMt * m_positionMt);
}

osg::Quat csvrObject::Euler2Quat(osg::Vec3d rotation)
{
    //俯仰角
    double pitch = osg::DegreesToRadians(rotation.x());
    //偏航角
    double heading = osg::DegreesToRadians(rotation.z());
    //横滚角
    double roll = osg::DegreesToRadians(rotation.y());

    osg::Quat quat(heading, osg::Vec3f(0,1,0),
                       pitch, osg::Vec3f(1,0,0),
                       roll, osg::Vec3f(0,0,1));
    return quat;
}

///范围：[-PI/2, PI/2]
osg::Vec3f csvrObject::Quat2Euler(osg::Quat q)
{
    double heading;
    double pitch;
    double roll;

    double test = q.y() * q.z() + q.x() * q.w();
    if (test > 0.4999)
    { // singularity at north pole
        heading = 2.0 * atan2(q.y(), q.w());
        pitch = osg::PI_2;
        roll = 0.0;
        return osg::Vec3d(pitch,roll,heading);
    }
    if (test < -0.4999)
    { // singularity at south pole
        heading = 2.0 * atan2(q.y(), q.w());
        pitch = -osg::PI_2;
        roll = 0.0;
        return osg::Vec3d(pitch,roll,heading);
    }
    double sqx = q.x() * q.x();
    double sqy = q.y() * q.y();
    double sqz = q.z() * q.z();
    heading = atan2(2.0 * q.z() * q.w() - 2.0 * q.y() * q.x(), 1.0 - 2.0 * sqz - 2.0 * sqx);
    pitch = asin(2.0 * test);
    roll = atan2(2.0 * q.y() * q.w() - 2.0 * q.z() * q.x(), 1.0 - 2.0 * sqy - 2.0 * sqx);

    return osg::Vec3d(pitch,roll,heading);
}














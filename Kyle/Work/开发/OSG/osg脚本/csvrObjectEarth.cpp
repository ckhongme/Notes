//
// Created by Kyle on 2023/3/20.
//

#include <osgEarth/GeoMath>
#include "csvrBase/csvrObjectEarth.h"

csvrObjectEarth::csvrObjectEarth(): csvrObject()
{

}

csvrObjectEarth::~csvrObjectEarth() {

}

void csvrObjectEarth::initMapNode(osgEarth::MapNode *pMapNode)
{
    this->pMapNode = pMapNode;
}

void csvrObjectEarth::setPosition(osg::Vec3d pos)
{
    Earth2World(pos);
    m_position = pos;
    setTransformMatrix();
}

osg::Vec3d csvrObjectEarth::getPostion(){
    return m_position;
}

osg::Vec3f csvrObjectEarth::getRotation(){
    return m_eulerAngle;
}

void csvrObjectEarth::setTransformMatrix()
{
    //m_positionMt 和 m_localPositionMt 的顺序不能换
    m_transform->setMatrix(m_localScaleMt * m_scaleMt * m_localRotationMt * m_localPositionMt * m_rotationMt * m_positionMt );
}

void csvrObjectEarth::Earth2World(const osg::Vec3d &geoPos)
{
    if(pMapNode)
    {
        pMapNode->getMapSRS()->getEllipsoid()->computeLocalToWorldTransformFromLatLongHeight(
                osg::DegreesToRadians(geoPos.y()), osg::DegreesToRadians(geoPos.x()), geoPos.z(), m_positionMt);
    }
    else
        std::cout<< "the csvrObject's pMapNode is nullptr" <<std::endl;
}

osg::Vec3d csvrObjectEarth::RadianLLH2XYZ(const osg::Vec3d& geoPos)
{
    osg::Vec3d pos;
    if(pMapNode)
    {
        pMapNode->getMapSRS()->getEllipsoid()->convertLatLongHeightToXYZ(
                geoPos.y(), geoPos.x(), geoPos.z(), pos.x(), pos.y(), pos.z());
    }
    else
    {
        std::cout<< "the csvrObject's pMapNode is nullptr" <<std::endl;
    }
    return pos;
}

osg::Vec3d csvrObjectEarth::DegreeLLH2XYZ(const osg::Vec3d& geoPos)
{
    osg::Vec3d geoRadian(osg::DegreesToRadians(geoPos.x()), osg::DegreesToRadians(geoPos.y()), geoPos.z());
    return RadianLLH2XYZ(geoRadian);
}

void csvrObjectEarth::rotateTo(osg::Vec3d to)
{
//    osg::Matrixd localRotateMt = osg::Matrix::rotate(osg::Vec3d(0,1,0), osg::Vec3d(1, 0, 0));
//    m_rotationMt = m_rotationMt * localRotateMt;

    osg::Quat q;
    q.makeRotate(90, osg::Vec3d(0,1,0));
    m_rotationMt = m_rotationMt * osg::Matrix::rotate(q);
    m_transform->setMatrix(m_rotationMt * m_scaleMt * m_positionMt);

//    auto r = m_rotationMt.getRotate().asVec3();
//    std::cout << "rotate:  " << r.x() << "  " << r.y() << "  "  << r.z() << std::endl;

    //lookAt   eye 物体中心   center 目标位置    up
}


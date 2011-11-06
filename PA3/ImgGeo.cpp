/* 
 * File:   ImgGeo.cpp
 * Author: yanceyo
 * 
 * Created on November 6, 2011
 */

#include "PixelType.h"
#include "ImgGeo.h"
#include "image.h"
#include <cmath>

ImgGeo::ImgGeo()
{
    ctrX = 0;
    ctrY = 0;
    prinMax = 0;
    prinMin = 0;
    axisMax = 0;
    axisMin = 0;
    orienTheta = 0;
    dEccentric = 0;
}

ImgGeo::ImgGeo(PixelType<imageNode> listImg)
{
    ctrX = 0;
    ctrY = 0;
    prinMax = 0;
    prinMin = 0;
    axisMax = 0;
    axisMin = 0;
    orienTheta = 0;
    dEccentric = 0;
    
    setList(listImg);
}

double ImgGeo::getMoment(int p, int q)
{
    // PURPOSE: Calculate image moment with given p and q
    // RETURNS: Sum given by xy coord(pixel list) and p and q
    
    // Init vars
    double dSum = 0;
    imageNode pixelCoord;
    
    // Reset pixel list
    pixImg.ResetList();
    
    // Loop through to do sum of pixel list with p and q
    for(int i=0; i < pixImg.LengthIs(); i++)
    {
        // Get pixel coordinates to sum up
        pixImg.GetNextItem(pixelCoord);
        
        dSum += pow(sqrt((pixelCoord.col - ctrX)),p) * pow(sqrt((pixelCoord.row - ctrY)),q);
    }
    
    return dSum;
}

void ImgGeo::setCentroid()
{
    // PURPOSE: Sets mean x and y - the centroid location
    // RETURNS: None
    
    ctrX = getMoment(1,0)/getMoment(0,0);
    ctrY = getMoment(0,1)/getMoment(0,0);
}

void ImgGeo::setPrincipalMoments()
{
    // PURPOSE: Sets principal moments
    // RETURNS: None
    
    // Init vars
    double o2x = getMoment(2,0);
    double o2y = getMoment(0,2);
    double o1xy = getMoment(1,1);
    
    // Set principal moments
    prinMax = 0.5*(o2x + o2y) + 0.5*sqrt(pow(o2x,2) + pow(o2y,2) - 2*o2x*o2y + 4*pow(o1xy,2));
    prinMin = 0.5*(o2x + o2y) - 0.5*sqrt(pow(o2x,2) + pow(o2y,2) - 2*o2x*o2y + 4*pow(o1xy,2));
}

void ImgGeo::setPrincipalAxes()
{
    // PURPOSE: Set principal axes
    // RETURNS: None
    
    axisMax = sqrt(prinMax/getMoment(0,0));
    axisMin = sqrt(prinMin/getMoment(0,0));
}

void ImgGeo::setOrientation()
{
    // PURPOSE: Set angle of orientation
    // RETURNS: None
    
    // Init vars
    double o2x = getMoment(2,0);
    double o2y = getMoment(0,2);
    double o1xy = getMoment(1,1);
    double tanX,tanY;
    
    tanX = (prinMax - o2x)/o1xy;
    tanY = (prinMax - o2y)/o1xy;
    
    orienTheta = atan2(tanY,tanX);
}

void ImgGeo::setEccentric()
{
    // PURPOSE: Set eccentricity to determine elongation
    // RETURNS: None
    
    dEccentric = axisMax/axisMin;
}

void ImgGeo::getImgGeoInfo()
{
    // PURPOSE: Gets all geometric image info
    // RETURNS: None
    
    setCentroid();
    setPrincipalMoments();
    setPrincipalAxes();
    setOrientation();
    setEccentric();
}

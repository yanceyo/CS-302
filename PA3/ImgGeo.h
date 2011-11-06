/* 
 * File:   ImgGeo.h
 * Author: yanceyo
 *
 * Created on November 6, 2011
 */

#ifndef IMGGEO_H
#define	IMGGEO_H

class ImgGeo
{
    public:
        ImgGeo();
        void setList(PixelType<imageNode> pixList)
        {
            pixImg = pixList;
            getImgGeoInfo();
        }
        double getMoment(int,int);
        double ctrX;
        double ctrY;
        double prinMax;
        double prinMin;
        double axisMax;
        double axisMin;
        double orienTheta;
        double dEccentric;
        
    private:
        PixelType<imageNode> pixImg;
        void getImgGeoInfo();
        void setCentroid();
        void setPrincipalMoments();
        void setPrincipalAxes();
        void setOrientation();
        void setEccentric();

};

#endif	/* IMGGEO_H */


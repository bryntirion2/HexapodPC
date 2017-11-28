#ifndef PERSPECTIVEPROJECTION_H
#define PERSPECTIVEPROJECTION_H

///Rzutowanie perspektywiczne na plaszczyzne ekranu
///Tu jest to opisane i sa wykorzystywane rownania https://en.wikipedia.org/wiki/3D_projection

class PerspectiveProjection
{
	private:
        double f; //ogniskowa
        cv::Point3f angles; // kąty kamery
        cv::Point3f T; //T - pozycja

    public:
        View(double f1, cv::Point3f angles1, cv::Point3f position) : f(f1), angles(angles1), T(position);

        void setF(double f1) {f = f1;};
        void setAngles(cv::Point3f angles1) {angles = angles1;};
        void setPosition(cv::Point3f pos) {T = pos;};

        void rotate(cv::Point3f angles1) {angles += angles1;};
        void translate(cv::Point3f pos) {T += pos;};

        cv::Point2f projectPoint(cv::Point3f point) const; // rzutuje punkt na daną płaszczyznę
};

#endif
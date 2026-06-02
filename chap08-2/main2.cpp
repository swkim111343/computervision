// **********************************************
// 제 목 : 실습과제2
// 날 짜 : 2026년 6월 2일
// 작성자 : 2001485 김선우
// **********************************************
#include <opencv2/opencv.hpp>
#include <iostream>

using namespace cv;
using namespace std;

int main(void)
{
    Mat src = imread("tekapo.bmp");

    if (src.empty()) {
        cerr << "Image load failed!" << endl;
        return -1;
    }

    double mx = 0.3;

    Point2f srcPts[3] = {
        Point2f(0, 0),
        Point2f(src.cols - 1, 0),
        Point2f(0, src.rows - 1)
    };

    Point2f dstPts[3] = {
        Point2f(0, 0),
        Point2f(src.cols - 1, 0),
        Point2f((src.rows - 1) * mx, src.rows - 1)
    };

    Mat M = getAffineTransform(srcPts, dstPts);

    cout << M << endl;

    Mat dst;
    warpAffine(src, dst, M,
        Size(cvRound(src.cols + src.rows * mx), src.rows));

    imshow("src", src);
    imshow("dst", dst);

    waitKey();
    return 0;
}
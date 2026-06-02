// **********************************************
// 제 목 : 실습과제4
// 날 짜 : 2026년 6월 2일
// 작성자 : 2001485 김선우
// **********************************************
#include <opencv2/opencv.hpp>
#include <iostream>

using namespace cv;
using namespace std;

int main()
{
    Mat src = imread("tekapo.bmp");

    if (src.empty()) {
        cerr << "Image load failed!" << endl;
        return -1;
    }

    Point2f srcPts[3] = {
        Point2f(0, 0),
        Point2f(100, 0),
        Point2f(0, 100)
    };

    Point2f dstPts[3] = {
        Point2f(0, 0),
        Point2f(200, 0),
        Point2f(0, 200)
    };

    Mat M = getAffineTransform(srcPts, dstPts);

    cout << "Affine Transform Matrix\n";
    cout << M << endl;

    Mat dst;

    warpAffine(
        src,
        dst,
        M,
        Size(src.cols * 2, src.rows * 2)
    );

    imshow("src", src);
    imshow("dst", dst);

    waitKey();
    return 0;
}
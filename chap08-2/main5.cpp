// **********************************************
// 제 목 : 실습과제5
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

    double sx = 0.5;
    double sy = 0.5;

    double tx = src.cols / 4.0;
    double ty = src.rows / 4.0;

    Mat M = (Mat_<double>(2, 3) <<
        sx, 0, tx,
        0, sy, ty);

    cout << "M = \n" << M << endl;

    Mat dst;

    warpAffine(
        src,
        dst,
        M,
        src.size(),
        INTER_LINEAR,
        BORDER_CONSTANT
    );

    imshow("src", src);
    imshow("dst", dst);

    waitKey();
    return 0;
}
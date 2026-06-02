// **********************************************
// 제 목 : 실습과제3
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

    double mx = 1.0; // tan(45°)

    Mat M = (Mat_<double>(2, 3) <<
        1, mx, 0,
        0, 1, 0);

    Mat dst;

    warpAffine(
        src,
        dst,
        M,
        Size(src.cols + src.rows * mx, src.rows),
        INTER_LINEAR,
        BORDER_REPLICATE
    );

    imshow("src", src);
    imshow("dst", dst);

    waitKey();
    return 0;
}
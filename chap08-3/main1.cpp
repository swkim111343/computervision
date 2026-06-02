// **********************************************
// 제 목 : 실습과제1
// 날 짜 : 2026년 6월 2일
// 작성자 : 2001485 김선우
// **********************************************
#include <opencv2/opencv.hpp>
#include <iostream>

using namespace cv;
using namespace std;

int main()
{
    Mat src = imread("lenna.bmp");

    if (src.empty()) {
        cerr << "Image load failed!" << endl;
        return -1;
    }

    Point2f center(src.cols / 2.0f, src.rows / 2.0f);

    // 중심 기준 시계방향 45도 회전
    Mat M = getRotationMatrix2D(center, -45, 1.0);

    Mat dst;

    warpAffine(
        src,
        dst,
        M,
        src.size(),          // 원본 크기 유지
        INTER_LINEAR,
        BORDER_CONSTANT,     // 빈 영역 채우기
        Scalar(0, 0, 0)      // 검정색
    );

    imshow("src", src);
    imshow("dst", dst);

    waitKey();
    return 0;
}
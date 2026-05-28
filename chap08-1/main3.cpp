// **********************************************
// 제 목 : 실습과제3
// 날 짜 : 2026년 5월 28일
// 작성자 : 2001485 김선우
// **********************************************
#include <opencv2/opencv.hpp>
#include <iostream>

using namespace cv;
using namespace std;

int main(void)
{

    Mat src = imread("tekapo.bmp");
    if (src.empty()) { cerr << "Image load failed!" << endl; return -1; }

    Point2f srcPts[3], dstPts[3];
    // 원본 영상의 3개 점
    srcPts[0] = Point2f(0, 0); // 좌상단
    srcPts[1] = Point2f(src.cols - 1, 0); // 우상단
    srcPts[2] = Point2f(src.cols - 1, src.rows - 1); // 우하단

    // 2배 확대된 목적 점
    dstPts[0] = Point2f(0, 0);

    dstPts[1] = Point2f((src.cols - 1) * 2, 0);

    dstPts[2] = Point2f((src.cols - 1) * 2, (src.rows - 1) * 2);


    // 어파인 변환 행렬 계산
    Mat M = getAffineTransform(srcPts, dstPts);
    cout << M << endl;

    // 영상 변환
    Mat dst;
    warpAffine(src, dst, M, Size(src.cols * 2, src.rows * 2));//size값 입력

    imshow("src", src);
    imshow("dst", dst);

    waitKey();

    return 0;
}
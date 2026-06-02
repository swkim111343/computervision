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
    Mat src = imread("tekapo.bmp");

    if (src.empty()) {
        cerr << "Image load failed!" << endl;
        return -1;
    }

    // 원본 점 3개
    Point2f srcPts[3];
    srcPts[0] = Point2f(0, 0);
    srcPts[1] = Point2f(100, 0);
    srcPts[2] = Point2f(0, 100);

    // 이동 후 점 3개 (오른쪽 150, 아래 100)
    Point2f dstPts[3];
    dstPts[0] = Point2f(150, 100);
    dstPts[1] = Point2f(250, 100);
    dstPts[2] = Point2f(150, 200);

    // Affine 변환 행렬 계산
    Mat M = getAffineTransform(srcPts, dstPts);

    cout << M << endl;

    Mat dst;
    warpAffine(src, dst, M, src.size());

    imshow("src", src);
    imshow("dst", dst);

    waitKey();
    return 0;
}
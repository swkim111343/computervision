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
    Mat src = imread("lenna.bmp");

    if (src.empty()) {
        cerr << "Image load failed!" << endl;
        return -1;
    }

    double angle = 0.0; // 누적 각도

    while (true)
    {
        Point2f center(src.cols / 2.0f, src.rows / 2.0f);

        Mat M = getRotationMatrix2D(center, -angle, 1.0);

        Mat dst;

        warpAffine(
            src,
            dst,
            M,
            src.size(),
            INTER_LINEAR,
            BORDER_CONSTANT,
            Scalar(0, 0, 0)
        );

        imshow("dst", dst);

        char key = (char)waitKey(0); // 키 입력 대기

        if (key == 'r')
        {
            angle += 10;   // 시계방향
        }
        else if (key == 'b')
        {
            angle -= 10;   // 반시계방향
        }
        else if (key == 'q')
        {
            break;
        }
    }

    return 0;
}
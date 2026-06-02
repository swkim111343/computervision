// **********************************************
// 제 목 : 실습과제2
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

    while (true)
    {
        string input;
        double angle;

        cout << "회전각도를 입력하시오: ";
        cin >> input;

        if (input == "q")
            break;

        angle = stod(input);  // 문자열 → 숫자 변환

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

        waitKey(1);
    }

    return 0;
}
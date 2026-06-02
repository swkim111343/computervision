// **********************************************
// 제 목 : 실습과제6
// 날 짜 : 2026년 6월 2일
// 작성자 : 2001485 김선우
// **********************************************
#include <opencv2/opencv.hpp>
#include <iostream>

using namespace cv;
using namespace std;

int main()
{
    VideoCapture cap(1);

    if (!cap.isOpened()) {
        cerr << "Camera open failed!" << endl;
        return -1;
    }

    Mat frame, dst;
    double angle = 0.0;

    while (true)
    {
        cap >> frame;

        if (frame.empty())
            break;

        Point2f center(frame.cols / 2.0f, frame.rows / 2.0f);

        Mat M = getRotationMatrix2D(center, -angle, 1.0);

        warpAffine(
            frame,
            dst,
            M,
            frame.size(),
            INTER_LINEAR,
            BORDER_CONSTANT,
            Scalar(0, 0, 0)
        );

        imshow("camera", dst);

        // ⭐ waitKey는 반드시 1번만
        char key = (char)waitKey(30);

        if (key == 'r')
        {
            angle += 90;   // 시계방향 90도씩 누적
        }
        else if (key == 'q')
        {
            break;
        }
    }

    return 0;
}
// **********************************************
// 제 목 : 과제2
// 날 짜 : 2026년 4월1일
// 작성자 : 2001485 김선우
// **********************************************
// 소스코드 작성
#include <iostream>
#include "opencv2/opencv.hpp"
using namespace std;
using namespace cv;

int main()
{
    VideoCapture cap(1);    //노트북 내장 카메라는(0), 웹캠사용하려면(1),카메라 선택번호

    if (!cap.isOpened()) {
        cerr << "Camera open failed!" << endl;
        return -1;
    }

    Mat frame, bright;

    while (true) {
        cap >> frame;
        if (frame.empty()) {
            cerr << "frame empty!" << endl;
            break;
        }

        // 밝기 증가 (BGR 각각 +100)
        bright = frame + Scalar(100, 100, 100);

        imshow("frame", frame);
        imshow("bright (100증가)", bright);

        if (waitKey(10) == 27) // ESC
            break;
    }

    return 0;
}
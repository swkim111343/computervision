// **********************************************
// 제 목 : 실습과제2
// 날 짜 : 2026년 4월7일
// 작성자 : 2001485 김선우
// **********************************************
// 소스코드 작성
#include <opencv2/opencv.hpp>
#include <iostream>
using namespace cv;
using namespace std;

int main(void)
{
    VideoCapture cap("stopwatch.avi");
    if (!cap.isOpened()) {
        cerr << "Video open failed!" << endl;
        return -1;
    }
    //프레임수 출력
    cout << "Frame width: " << cvRound(cap.get(CAP_PROP_FRAME_WIDTH)) << endl;
    cout << "Frame height:" << cvRound(cap.get(CAP_PROP_FRAME_HEIGHT)) << endl;
    cout << "Frame count: " << cvRound(cap.get(CAP_PROP_FRAME_COUNT)) << endl;

    double fps = cap.get(CAP_PROP_FPS);
    cout << "FPS: " << fps << endl;

    int delay = cvRound(1000 / fps);    //ms로 delay저장

    Mat frame, bright;

    while (true) {
        cap >> frame;
        if (frame.empty()) {
            cerr << "frame error!" << endl;
            break;
        }

        //밝기 증가 (BGR 각각 +100)
        bright = frame + Scalar(100, 100, 100);

        imshow("frame", frame);
        imshow("bright", bright);

        char c = (char)waitKey(delay);
        if (c == 'q' || c == 'Q') break;
    }

    return 0;
}
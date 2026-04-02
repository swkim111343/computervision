// **********************************************
// 제 목 : 과제4
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
    VideoCapture cap(1);

    if (!cap.isOpened()) {
        cerr << "Camera open failed!" << endl;
        return -1;
    }

    Mat frame, cross;

    while (true) {
        cap >> frame;
        if (frame.empty()) {
            cerr << "frame empty!" << endl;
            break;
        }

        //깊은복사로 빨간줄 그을 새로운창 저장(cross)
        cross = frame.clone();

        // 세로선
        for (int i = 0; i < cross.rows; i++) {
            cross.at<Vec3b>(i, cross.cols / 2)[0] = 0;   // B
            cross.at<Vec3b>(i, cross.cols / 2)[1] = 0;   // G
            cross.at<Vec3b>(i, cross.cols / 2)[2] = 255; // R
        }

        // 가로선
        for (int i = 0; i < cross.cols; i++) {
            cross.at<Vec3b>(cross.rows / 2, i)[0] = 0;
            cross.at<Vec3b>(cross.rows / 2, i)[1] = 0;
            cross.at<Vec3b>(cross.rows / 2, i)[2] = 255;
        }

        imshow("frame", frame);
        imshow("cross", cross);

        char key = (char)waitKey(1);
        if (key == 'q') break;
    }

    destroyAllWindows();
    return 0;
}
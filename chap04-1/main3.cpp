// **********************************************
// 제 목 : 과제3
// 날 짜 : 2026년 4월1일
// 작성자 : 2001485 김선우
// **********************************************
// 소스코드 작성
#include <iostream>
#include <opencv2/opencv.hpp>
using namespace std;
using namespace cv;

int main()
{
    VideoCapture cap(1);    //노트북 내장 카메라는(0), 웹캠사용하려면(1),카메라 선택번호

    if (!cap.isOpened()) {
        cerr << "Camera open failed!" << endl;
        return -1;
    }

    Mat frame;
    int count = 0; // 저장 파일 번호

    while (true) {
        cap >> frame;
        if (frame.empty()) break;

        imshow("Camera", frame);

        char key = (char)waitKey(1);

        // 종료 (Q 또는 q)
        if (key == 'q' || key == 'Q')
            break;

        // 저장 (s 누르면)
        if (key == 's') {
            string filename = format("frame%02d.jpg", count++);
            imwrite(filename, frame);
            cout << filename << " saved!" << endl;
        }
    }

    return 0;
}
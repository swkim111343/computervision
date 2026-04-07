// **********************************************
// 제 목 : 실습과제5
// 날 짜 : 2026년 4월7일
// 작성자 : 2001485 김선우
// **********************************************
// 소스코드 작성
#include "opencv2/opencv.hpp"
#include <iostream>
using namespace cv;
using namespace std;

int main() {

    VideoCapture cap(1);
    if (!cap.isOpened()) {
        cerr << "Camera open failed!" << endl;
        return -1;
    }

    int width = cvRound(cap.get(CAP_PROP_FRAME_WIDTH));
    int height = cvRound(cap.get(CAP_PROP_FRAME_HEIGHT));
    double fps = cap.get(CAP_PROP_FPS);
    if (fps == 0) fps = 30;

    VideoWriter writer;
    bool isRecording = false;   //s를 누르고 저장을 시작하기 위해 

    Mat frame;

    while (true) {
        cap >> frame;
        if (frame.empty()) break;

        imshow("Camera", frame);

        //녹화 중이면 저장
        if (isRecording) {
            writer.write(frame);
        }

        char c = (char)waitKey(1);

        //s 누르면 녹화 시작
        if ((c == 's' || c == 'S') && !isRecording) {
            writer.open("실습과제5.avi",
                VideoWriter::fourcc('X', 'V', 'I', 'D'),
                fps, Size(width, height));

            if (!writer.isOpened()) {
                cerr << "VideoWriter open failed!" << endl;
                return -1;
            }

            cout << "녹화 시작!" << endl;
            isRecording = true;
        }

        //e 누르면 녹화 종료 후 프로그램 종료
        if (c == 'e' || c == 'E') {
            if (isRecording) {
                writer.release();
                cout << "녹화 종료!" << endl;
            }
            break;
        }
    }

    cap.release();
    destroyAllWindows();

    return 0;
}
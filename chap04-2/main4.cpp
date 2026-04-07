// **********************************************
// 제 목 : 실습과제4
// 날 짜 : 2026년 4월7일
// 작성자 : 2001485 김선우
// **********************************************
// 소스코드 작성
#include <opencv2/opencv.hpp>
#include <iostream>
using namespace cv;
using namespace std;

int main() {
    VideoCapture cap(1);    //외부 카메라 1번
    if (!cap.isOpened()) {
        cerr << "Camera open failed!" << endl;
        return -1;
    }
    //영상 속성
    int width = cvRound(cap.get(CAP_PROP_FRAME_WIDTH));
    int height = cvRound(cap.get(CAP_PROP_FRAME_HEIGHT));
    double fps = cap.get(CAP_PROP_FPS);

    // 일부 환경에서는 FPS가 0 나올 수 있으므로 기본값 설정
    if (fps == 0) fps = 30;

    cout << "Width: " << width << endl;
    cout << "Height: " << height << endl;
    cout << "FPS: " << fps << endl;

    //동영상 저장
    VideoWriter writer("camera_output.avi",
        VideoWriter::fourcc('X', 'V', 'I', 'D'),
        fps, Size(width, height));

    if (!writer.isOpened()) {
        cerr << "VideoWriter open failed!" << endl;
        return -1;
    }

    Mat frame;

    while (true) {
        cap >> frame;
        if (frame.empty()) break;

        imshow("Camera", frame);

        writer.write(frame);

        char c = (char)waitKey(1);
        if (c == 'q' || c == 'Q') break;
    }

    cap.release();
    writer.release();
    destroyAllWindows();

    return 0;
}
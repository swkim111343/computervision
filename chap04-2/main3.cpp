// **********************************************
// 제 목 : 실습과제3
// 날 짜 : 2026년 4월7일
// 작성자 : 2001485 김선우
// **********************************************
// 소스코드 작성
#include "opencv2/opencv.hpp"
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

    int width = cvRound(cap.get(CAP_PROP_FRAME_WIDTH));
    int height = cvRound(cap.get(CAP_PROP_FRAME_HEIGHT));
    double fps = cap.get(CAP_PROP_FPS);
    int delay = cvRound(1000 / fps);

    //결과 영상 저장
    VideoWriter writer("output.avi",
        VideoWriter::fourcc('X', 'V', 'I', 'D'),
        fps, Size(width, height));

    Mat frame, cross;

    while (true) {
        cap >> frame;
        if (frame.empty()) {
            cerr << "frame error!" << endl;
            break;
        }

        //빨간색 줄을 출력할 새창 cross 깊은 복사
        cross = frame.clone();

        //중앙 좌표
        int cx = width / 2;
        int cy = height / 2;

        //빨간색줄 이므로 0 255 255
        line(cross, Point(0, cy), Point(width, cy), Scalar(0, 0, 255), 2); // 가로
        line(cross, Point(cx, 0), Point(cx, height), Scalar(0, 0, 255), 2); // 세로

        imshow("frame", frame);
        imshow("cross", cross);

        //영상 저장 (처리된 영상)
        writer.write(cross);

        char c = (char)waitKey(delay);
        if (c == 'q' || c == 'Q') break;
    }

    cap.release();
    writer.release();
    destroyAllWindows();

    return 0;
}
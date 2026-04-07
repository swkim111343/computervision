// **********************************************
// 제 목 : 실습과제1
// 날 짜 : 2026년 4월7일
// 작성자 : 2001485 김선우
// **********************************************
// 소스코드 작성
#include "opencv2/opencv.hpp"
using namespace cv;

int main() {
    // 400x400 흰색 영상 생성
    Mat img(400, 400, CV_8UC3, Scalar(255, 255, 255));

    // 사각형 좌표
    Point pt1(100, 100);
    Point pt2(300, 300);

    // 사각형 그리기 (검정색)
    rectangle(img, pt1, pt2, Scalar(0, 0, 0), 1);

    // 대각선 1
    line(img, pt1, pt2, Scalar(0, 0, 0), 1);

    // 대각선 2
    line(img, Point(100, 300), Point(300, 100), Scalar(0, 0, 0), 1);

    // 출력
    imshow("src", img);
    waitKey(0);

    return 0;
}
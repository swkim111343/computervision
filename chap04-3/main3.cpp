// **********************************************
// 제 목 : 실습과제3
// 날 짜 : 2026년 4월7일
// 작성자 : 2001485 김선우
// **********************************************
// 소스코드 작성
#include "opencv2/opencv.hpp"
using namespace cv;

int main() {
    // 400x400 흰색 영상 생성
    Mat img(400, 400, CV_8UC3, Scalar(255, 255, 255));

    // 사각형 좌표 (중앙에 배치)
    Point pt1(100, 100);
    Point pt2(300, 300);

    // 사각형 그리기
    rectangle(img, pt1, pt2, Scalar(0, 0, 0), 1);

    // 원 중심 (사각형 중심)
    Point center(200, 200);

    // 반지름 = 사각형의 절반 길이
    int radius = 100;

    // 원 그리기
    circle(img, center, radius, Scalar(0, 0, 0), 1);

    // 출력
    imshow("src", img);
    waitKey(0);

    return 0;
}
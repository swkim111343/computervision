// **********************************************
// 제 목 : 실습과제5
// 날 짜 : 2026년 4월7일
// 작성자 : 2001485 김선우
// **********************************************
// 소스코드 작성
#include "opencv2/opencv.hpp"
using namespace cv;

int main() {
    // 600x200 영상 생성
    Mat img(200, 600, CV_8UC3);

    // ROI(관심영역) 3등분
    Mat blue = img(Rect(0, 0, 200, 200));
    Mat green = img(Rect(200, 0, 200, 200));
    Mat red = img(Rect(400, 0, 200, 200));

    //각각의 알맞은 배경 색채우기
    blue.setTo(Scalar(255, 0, 0));   // Blue
    green.setTo(Scalar(0, 255, 0));  // Green
    red.setTo(Scalar(0, 0, 255));    // Red

    //도형을그리기 위한 각 부분의 중심 좌표
    Point c1(100, 100);
    Point c2(100, 100);
    Point c3(100, 100);

    //각 관심 영역 도형 그리기
    // 왼쪽 파란색 부분 사각형
    rectangle(blue, Point(40, 40), Point(160, 160), Scalar(255, 255, 255), 2);

    // 가운데 초록색 부분 원
    circle(green, Point(100, 100), 60, Scalar(255, 255, 255), 2);

    // 오른쪽 빨간색 부분 X
    line(red, Point(40, 40), Point(160, 160), Scalar(255, 255, 255), 2);
    line(red, Point(160, 40), Point(40, 160), Scalar(255, 255, 255), 2);

    imshow("img", img);
    waitKey(0);

    return 0;
}
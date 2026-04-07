// **********************************************
// 제 목 : 실습과제4
// 날 짜 : 2026년 4월7일
// 작성자 : 2001485 김선우
// **********************************************
// 소스코드 작성
#include "opencv2/opencv.hpp"
using namespace cv;

int main() {
    Mat img = imread("lenna.bmp");
    if (img.empty()) {
        printf("Image load failed!\n");
        return -1;
    }

    // 중심 좌표(레나의 코를 중심으로 잡음)
    Point center(311, 319);

    // 반지름 (얼굴 크기에 맞게 조절 가능)
    int radius = 130;

    // 파란색 원으로 그리기
    Scalar blue(255, 0, 0);

    // 원 그리기
    circle(img, center, radius, blue, 2);

    // 출력
    imshow("Lenna", img);
    waitKey(0);

    return 0;
}
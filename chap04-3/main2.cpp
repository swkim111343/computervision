// **********************************************
// 제 목 : 실습과제2
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

    int w = img.cols;
    int h = img.rows;

    Scalar white(255, 255, 255);

    // 세로선 3개 (1/4, 2/4, 3/4)
    for (int i = 1; i < 4; i++) {
        int x = w * i / 4;
        line(img, Point(x, 0), Point(x, h), white, 2);
    }

    // 가로선 3개 (1/4, 2/4, 3/4)
    for (int i = 1; i < 4; i++) {
        int y = h * i / 4;
        line(img, Point(0, y), Point(w, y), white, 2);
    }

    imshow("Line", img);
    waitKey(0);

    return 0;
}
// **********************************************
// 제 목 : 실습과제1
// 날 짜 : 2026년 5월6일
// 작성자 : 2001485 김선우
// **********************************************
// 소스코드 작성
#include <opencv2/opencv.hpp>
#include <iostream>

using namespace cv;
using namespace std;

Mat img;

void on_mouse(int event, int x, int y, int flags, void*);

int main(void)
{
    img = imread("lenna.bmp", IMREAD_GRAYSCALE);
    if (img.empty()) { cerr << "Image load failed!" << endl; return -1; }

    namedWindow("img");
    setMouseCallback("img", on_mouse);

    imshow("img", img);
    waitKey();

    return 0;
}

void on_mouse(int event, int x, int y, int flags, void*)
{
    if (event == EVENT_LBUTTONDOWN) {
        img += 10;  
        // 포화 연산(saturation):
        // 각 픽셀 값에 10을 더할 때, 결과가 255를 초과하면 255로 고정됨
        // (예: 250 + 10 → 255)
    }
    else if (event == EVENT_RBUTTONDOWN) {
        img -= 10;  
        // 포화 연산(saturation):
        // 각 픽셀 값에서 10을 뺄 때, 결과가 0보다 작아지면 0으로 고정됨
        // (예: 5 - 10 → 0)
    }

    imshow("img", img);
}
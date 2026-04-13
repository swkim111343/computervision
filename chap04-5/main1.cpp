// **********************************************
// 제 목 : 실습과제1
// 날 짜 : 2026년 4월13일
// 작성자 : 2001485 김선우
// **********************************************
// 소스코드 작성
#include "opencv2/opencv.hpp"
#include <iostream>
using namespace cv;
using namespace std;

int radius = 0; //전역변수 선언(콜백함수,메인함수 사용위해)

void on_change(int pos, void* userdata)
{
    static int i = 0;

    radius = pos;   //전역 변수에 저장

    cout << "트랙바 위치: " << radius << endl;
}

int main(void)
{
    Mat src = imread("lenna.bmp");

    if (src.empty()) {
        cerr << "Image load failed!" << endl;
        return -1;
    }

    namedWindow("src");

    createTrackbar("level", "src", 0, 100, on_change);  //0~100 트랙바 생성

    while (true)
    {
        circle(src, Point(src.cols / 2, src.rows / 2),radius, Scalar(0, 255, 0), 5);

        imshow("src", src); // 1번만 사용

        if (waitKey(30) == 27) break;
    }

    return 0;
}
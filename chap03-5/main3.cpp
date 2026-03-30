// **********************************************
// 제 목 : 과제3
// 날 짜 : 2026년 3월30일
// 작성자 : 2001485 김선우
// **********************************************
// 소스코드 작성
#include "opencv2/opencv.hpp"
using namespace cv;

int main()
{
    //컬러 이미지 저장
    Mat img = imread("lenna.bmp", IMREAD_COLOR);
    if (img.empty()) return -1;

    //선 위치 설정
    int r1 = img.rows / 4;
    int r2 = img.rows / 2;
    int r3 = img.rows * 3 / 4;

    int c1 = img.cols / 4;
    int c2 = img.cols / 2;
    int c3 = img.cols * 3 / 4;

    //세로선
    for (int i = 0; i < img.rows; i++) {
        img.at<Vec3b>(i, c1) = Vec3b(255, 255, 255);
        img.at<Vec3b>(i, c2) = Vec3b(255, 255, 255);
        img.at<Vec3b>(i, c3) = Vec3b(255, 255, 255);
    }

    //가로선
    for (int i = 0; i < img.cols; i++) {
        img.at<Vec3b>(r1, i) = Vec3b(255, 255, 255);
        img.at<Vec3b>(r2, i) = Vec3b(255, 255, 255);
        img.at<Vec3b>(r3, i) = Vec3b(255, 255, 255);
    }

    imshow("LINE", img);
    waitKey(0);

    return 0;
}
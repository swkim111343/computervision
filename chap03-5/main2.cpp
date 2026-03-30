// **********************************************
// 제 목 : 과제2
// 날 짜 : 2026년 3월30일
// 작성자 : 2001485 김선우
// **********************************************
// 소스코드 작성
#include "opencv2/opencv.hpp"
using namespace cv;

int main()
{
    Mat src = imread("lenna.bmp", IMREAD_COLOR);    //레나 이미지 저장
    if (src.empty()) return -1;

    Mat img;
    cvtColor(src, img, COLOR_BGR2GRAY); //레나 이미지 그레이 스케일로 변환

    //선 위치 설정
    int r1 = img.rows / 4;
    int r2 = img.rows / 2;
    int r3 = img.rows * 3 / 4;

    int c1 = img.cols / 4;
    int c2 = img.cols / 2;
    int c3 = img.cols * 3 / 4;

    //세로선
    for (int i = 0; i < img.rows; i++) {
        img.at<uchar>(i, c1) = 255;
        img.at<uchar>(i, c2) = 255;
        img.at<uchar>(i, c3) = 255;
    }

    //가로선
    for (int i = 0; i < img.cols; i++) {
        img.at<uchar>(r1, i) = 255;
        img.at<uchar>(r2, i) = 255;
        img.at<uchar>(r3, i) = 255;
    }

    imshow("LINE", img);
    waitKey(0);

    return 0;
}
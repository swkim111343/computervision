// **********************************************
// 제 목 : 과제2
// 날 짜 : 2026년 3월24일
// 작성자 : 2001485 김선우
// **********************************************
// 소스코드 작성
#include "opencv2/opencv.hpp"
#include <iostream>
using namespace cv;
using namespace std;

int main()
{
    //400x300 크기 이미지 생성 (height, width)
    //CV_8UC3 → unsigned char, 3채널 (컬러 이미지)

    Mat img1(300, 400, CV_8UC3, Scalar(255, 0, 0));   // Blue
    Mat img2(300, 400, CV_8UC3, Scalar(0, 255, 0));  // Green
    Mat img3(300, 400, CV_8UC3, Scalar(0, 0, 255));    // Red

    //화면에 출력
    imshow("Blue", img1);
    imshow("Green", img2);
    imshow("Red", img3);

    waitKey(); // 키 입력 대기

    return 0;
}
// **********************************************
// 제 목 : 실습과제6
// 날 짜 : 2026년 4월8일
// 작성자 : 2001485 김선우
// **********************************************
// 소스코드 작성
#include "opencv2/opencv.hpp"
#include <iostream>
using namespace cv;
using namespace std;

void onMouse(int event, int x, int y, int flags, void* userdata);

Mat img;

int main(void)
{
    //크기 400x200 배경 흰색 설정
    img = Mat(200, 400, CV_8UC3, Scalar(255, 255, 255));

    namedWindow("img");
    setMouseCallback("img", onMouse);

    while (true) {
        imshow("img", img);
        if (waitKey(10) == 'q') break;
    }

    destroyAllWindows();
    return 0;
}

void onMouse(int event, int x, int y, int flags, void* userdata)
{
    if (event == EVENT_LBUTTONDOWN) {   //마우스 왼쪽 r 색
        img.setTo(Scalar(0, 0, 255));
    }
    else if (event == EVENT_RBUTTONDOWN) {  //마우스 오른쪽 b색
        img.setTo(Scalar(255, 0, 0));
    }
}
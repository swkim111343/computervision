// **********************************************
// 제 목 : 실습과제7
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
    //초기 화면 설정300x500 3채널 컬러 배경 흰색
    img = Mat(300, 500, CV_8UC3, Scalar(255, 255, 255));

    //메뉴박스 설정
    rectangle(img, Rect(0, 0, 200, 100), Scalar(0, 0, 0), 2);    
    rectangle(img, Rect(0, 100, 200, 100), Scalar(0, 0, 0),2);
    rectangle(img, Rect(0, 200, 200, 100), Scalar(0, 0, 0), 2);

    // 텍스트
    putText(img, "Red", Point(60, 60), FONT_HERSHEY_SIMPLEX, 1, Scalar(0, 0, 0), 2);
    putText(img, "Green", Point(40, 160), FONT_HERSHEY_SIMPLEX, 1, Scalar(0, 0, 0), 2);
    putText(img, "Blue", Point(50, 260), FONT_HERSHEY_SIMPLEX, 1, Scalar(0, 0, 0), 2);

    namedWindow("img");
    setMouseCallback("img", onMouse);

    while (true) {
        imshow("img", img);
        if (waitKey(10) == 'q') break;
    }

    return 0;
}

void onMouse(int event, int x, int y, int flags, void* userdata)
{
    if (event != EVENT_LBUTTONDOWN) return;


    // 오른쪽 영역 초기화
    rectangle(img, Rect(200, 0, 300, 300), Scalar(255, 255, 255), FILLED);

    // 클릭 위치 판단 후 문자열 출력
    if (x < 200 && y < 100) {
        putText(img, "Red pressed.", Point(230, 150),
            FONT_HERSHEY_SIMPLEX, 1, Scalar(0, 0, 0), 2);
    }
    else if (x < 200 && y < 200) {
        putText(img, "Green pressed.", Point(230, 150),
            FONT_HERSHEY_SIMPLEX, 1, Scalar(0, 0, 0), 2);
    }
    else if (x < 200 && y < 300) {
        putText(img, "Blue pressed.", Point(230, 150),
            FONT_HERSHEY_SIMPLEX, 1, Scalar(0, 0, 0), 2);
    }
}
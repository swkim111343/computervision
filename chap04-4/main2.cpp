// **********************************************
// 제 목 : 실습과제2
// 날 짜 : 2026년 4월8일
// 작성자 : 2001485 김선우
// **********************************************
// 소스코드 작성
#include "opencv2/opencv.hpp"
#include <iostream>
using namespace cv;
using namespace std;

// 이벤트 횟수 변수
int count_down = 0;
int count_up = 0;
int count_move = 0;

// 마우스 콜백 함수
void onMouse(int event, int x, int y, int flags, void* userdata)
{
    if (event == EVENT_LBUTTONDOWN) {   //열거형상수 이용
        count_down++;   //LBUTTONDOWN할때마다 카운트
        cout << "EVEVNT_LBUTTONDOWN: " << count_down << endl;
    }
    else if (event == EVENT_LBUTTONUP) {
        count_up++;
        cout << "EVEVNT_LBUTTONUP " << count_up << endl;
    }
    else if (event == EVENT_MOUSEMOVE) {
        count_move++;
        cout << "EVEVNT_M0USEMOVE: " << count_move << endl;
    }
}

int main(void)
{
    Mat img = imread("lenna.bmp");
    if (img.empty()) {
        cerr << "Image load failed!" << endl;
        return -1;
    }

    imshow("img", img);

    // 마우스 이벤트 등록
    setMouseCallback("img", onMouse);

    while (true) {
        if (waitKey(1) == 'q')
            break;
    }

    destroyAllWindows();
    return 0;
}
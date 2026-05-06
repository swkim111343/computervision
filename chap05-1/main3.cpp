// **********************************************
// 제 목 : 실습과제3
// 날 짜 : 2026년 5월6일
// 작성자 : 2001485 김선우
// **********************************************
// 소스코드 작성
#include <opencv2/opencv.hpp>
#include <iostream>

using namespace cv;
using namespace std;

Mat img;
int mode = 0; // 트랙바 값 (0: 밝기 증가, 1: 밝기 감소)

// 마우스 콜백 함수
void on_mouse(int event, int x, int y, int flags, void*)
{
    if (event == EVENT_LBUTTONDOWN) {
        if (mode == 0) {
            img += 10;
            // 포화 연산: 255 초과 시 255로 고정
        }
        else if (mode == 1) {
            img -= 10;
            // 포화 연산: 0 미만 시 0으로 고정
        }
        imshow("img", img);
    }
}

int main(void)
{
    // 레나 이미지 그레이스케일로 로드
    img = imread("lenna.bmp", IMREAD_GRAYSCALE);
    if (img.empty()) {
        cerr << "Image load failed!" << endl;
        return -1;
    }

    namedWindow("img");

    // 트랙바 생성 (0 또는 1 선택)
    createTrackbar("mode", "img", &mode, 1);

    // 마우스 콜백 등록
    setMouseCallback("img", on_mouse);

    imshow("img", img);
    waitKey();

    return 0;
}
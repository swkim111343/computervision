// **********************************************
// 제 목 : 실습과제4
// 날 짜 : 2026년 5월6일
// 작성자 : 2001485 김선우
// **********************************************
// 소스코드 작성
#include <opencv2/opencv.hpp>
#include <iostream>
using namespace cv;
using namespace std;

Mat img;

// 마우스 이벤트 콜백 함수
void on_mouse(int event, int x, int y, int flags, void*)
{
    // 왼쪽 버튼을 누른 상태에서 마우스를 움직일 때
    if (event == EVENT_MOUSEMOVE && (flags & EVENT_FLAG_LBUTTON)) {

        // 현재 위치 + 상하좌우 좌표 배열
        int dx[5] = { 0, 0, 0, -1, 1 };
        int dy[5] = { 0, -1, 1, 0, 0 };

        for (int i = 0; i < 5; i++) {
            int nx = x + dx[i];
            int ny = y + dy[i];

            // 이미지 범위 체크 (경계 처리)
            if (nx >= 0 && nx < img.cols && ny >= 0 && ny < img.rows) {
                img.at<uchar>(ny, nx) += 100;
                // 포화 연산: 255 초과 시 255로 자동 제한됨
            }
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

    namedWindow("img", WINDOW_NORMAL);
    resizeWindow("img", 512, 512);

    setMouseCallback("img", on_mouse);

    imshow("img", img);
    waitKey();

    return 0;
}
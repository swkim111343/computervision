// **********************************************
// 제 목 : 실습과제9
// 날 짜 : 2026년 4월7일
// 작성자 : 2001485 김선우
// **********************************************
// 소스코드 작성
#include "opencv2/opencv.hpp"
using namespace cv;

int main() {
    Mat img(500, 500, CV_8UC3, Scalar(255, 255, 255));

    // 시작 위치 (중앙)
    Point current(250, 250);

    imshow("src", img);

    while (true) {
        int key = waitKey(0);

        if (key == 'q' || key == 'Q') break;

        Point next = current; // 다음 위치

        // 방향별 이동 (50픽셀)
        if (key == 'l' || key == 'L') next.x -= 50;
        else if (key == 'r' || key == 'R') next.x += 50;
        else if (key == 'u' || key == 'U') next.y -= 50;
        else if (key == 'd' || key == 'D') next.y += 50;

        //선 그리기 (현재 → 다음)
        line(img, current, next, Scalar(0, 0, 0), 2);

        // 현재 위치 업데이트
        current = next;

        imshow("src", img);
    }

    return 0;
}
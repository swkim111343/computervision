// **********************************************
// 제 목 : 과제5
// 날 짜 : 2026년 3월26일
// 작성자 : 2001485 김선우
// **********************************************
// 소스코드 작성
#include "opencv2/opencv.hpp"
#include <iostream>
using namespace cv;
using namespace std;

int main() {
    int width = 600;    //영상 크기 설정
    int height = 200;
    int rectWidth = width / 3;  //사각형 폭 설정 : 영상 1/3
    int rectHeight = height;    //사각형 높이 설정 :영상 전체

    Mat img1(height, width, CV_8UC3);  //8비트 unsigned 3채널(컬러)

    //사각형 x좌표 위치 (왼쪽, 가운데, 오른쪽)
    int positions[] = { 0, rectWidth, 2 * rectWidth };
    int nPos = sizeof(positions) / sizeof(positions[0]);
    int idx = 0;  //현재 위치 인덱스

    while (true) {
        img1.setTo(Scalar(255, 255, 255)); //배경 색 흰색으로 초기화

        // 빨간색 사각형 그리기
        rectangle(img1,
            Point(positions[idx], 0),
            Point(positions[idx] + rectWidth, rectHeight),
            Scalar(0, 0, 255), FILLED); //빨간색 사각형 채우기

        imshow("img1", img1);

        idx = (idx + 1) % nPos;      // 다음 위치로 토글

        if (waitKey(1000) == 'q') break; // 1초 대기, q 입력 시 종료
    }

    return 0;
}
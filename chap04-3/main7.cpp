// **********************************************
// 제 목 : 실습과제7
// 날 짜 : 2026년 4월7일
// 작성자 : 2001485 김선우
// **********************************************
// 소스코드 작성
#include "opencv2/opencv.hpp"
#include <iostream>
using namespace cv;
using namespace std;

int main()
{
    Mat img(300, 300, CV_8UC3);

    int count = 0;          // 0~3 카운트
    bool running = false;   // 시작/정지 상태

    while (true)
    {
        // 배경 흰색으로 초기화
        img.setTo(Scalar(255, 255, 255));

        // 숫자 문자열 변환 (format 사용)
        String text = format("%d", count);
        // 텍스트 크기 구하기
        int baseline = 0;
        Size textSize = getTextSize(text, FONT_HERSHEY_SIMPLEX, 5, 8, &baseline);

        // 중앙 정렬
        int x = (img.cols - textSize.width) / 2;
        int y = (img.rows + textSize.height) / 2;

        // 숫자 출력
        putText(img, text, Point(x, y),
            FONT_HERSHEY_SIMPLEX, 5, Scalar(0, 0, 0), 8);
        imshow("stopwatch", img);

        // 1초 대기 + 키 입력 받기
        int key = waitKey(1000);

        // 키 처리
        if (key == 'q' || key == 'Q') break;
        else if (key == 's' || key == 'S') running = true;
        else if (key == 't' || key == 'T') running = false;
        else if (key == 'r' || key == 'R') {
            count = 0;
            running = false;
        }

        // 카운트 증가 (실행 중일 때만)
        if (running) {
            count = (count + 1) % 4; // 0~3 반복
        }
    }

    return 0;
}
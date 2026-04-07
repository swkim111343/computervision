// **********************************************
// 제 목 : 실습과제8
// 날 짜 : 2026년 4월7일
// 작성자 : 2001485 김선우
// **********************************************
// 소스코드 작성
#include "opencv2/opencv.hpp"
using namespace cv;

int main() {
    int size = 500; //500 픽셀 사이즈 바둑판
    int cell = size / 5;    //셀 크기 설정

    Mat img(size, size, CV_8UC3);   //파란색버튼이므로 3채널 컬러

    int row = 2, col = 2; // 중앙

    while (true) {
        img.setTo(Scalar(255, 255, 255));   //하얀색배경 설정

        //바둑판 그리기
        for (int i = 1; i < 5; i++) {
            line(img, Point(i * cell, 0), Point(i * cell, size), Scalar(0, 0, 0), 1);
            line(img, Point(0, i * cell), Point(size, i * cell), Scalar(0, 0, 0), 1);
        }

        //셀 
        Point p1(col * cell, row * cell);
        Point p2((col + 1) * cell, (row + 1) * cell);
        rectangle(img, p1, p2, Scalar(255, 0, 0), -1);

        imshow("src", img);

        int key = waitKey(0);
        if (key == 'q' || key == 'Q') break;

        int prevRow = row;
        int prevCol = col;
        //움직임 설정
        if (key == 'l' || key == 'L') col--; 
        else if (key == 'r' || key == 'R') col++;
        else if (key == 'u' || key == 'U') row--;
        else if (key == 'd' || key == 'D') row++;

        // 범위 체크
        if (row < 0 || row > 4 || col < 0 || col > 4) {
            row = prevRow;
            col = prevCol;
        }
    }

    return 0;
}
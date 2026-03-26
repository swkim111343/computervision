// **********************************************
// 제 목 : 과제3
// 날 짜 : 2026년 3월26일
// 작성자 : 2001485 김선우
// **********************************************
// 소스코드 작성
#include "opencv2/opencv.hpp"
#include <iostream>
using namespace cv;
using namespace std;

int main() {
    Mat img1 = imread("dog.bmp", IMREAD_COLOR);
    if (img1.empty()) {
        cerr << "Image load failed!" << endl;
        return -1;
    }

    //강아지 얼굴 좌표 관심 영역으로 설정
    Rect roi(96, 34, 100, 100);

    Mat face = img1(roi);    // 얕은 복사
    face = Scalar(255, 0, 0); //관심영역을 파란색으로 변경

    imshow("img1", img1);    
    waitKey(0);             

    return 0;
}
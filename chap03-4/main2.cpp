// **********************************************
// 제 목 : 과제2
// 날 짜 : 2026년 3월26일
// 작성자 : 2001485 김선우
// **********************************************
// 소스코드 작성
#include "opencv2/opencv.hpp"
#include <iostream>
using namespace cv;
using namespace std;

int main() {
    // img1 객체 데이터 값 초기화
    int data[] = { 1,2,3,4,5,
                  6,7,8,9,10,
                  11,12,13,14,15 };
    Mat img1(3, 5, CV_32S, data); // 3행 5열 32비트 정수형 mat 객체 생성

    Rect roi(2, 1, 3, 2); //빨간색 사각형 부분을 관심영역으로 rect class 사용하여 설정 x=2, y=1, width=3, height=2
    Mat img2 = img1(roi); // 얕은 복사

    cout << "img1" << endl << img1 << endl;
    cout << "img2" << endl << img2 << endl;

    return 0;
}
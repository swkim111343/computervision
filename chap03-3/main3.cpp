// **********************************************
// 제 목 : 과제3
// 날 짜 : 2026년 3월24일
// 작성자 : 2001485 김선우
// **********************************************
// 소스코드 작성
#include "opencv2/opencv.hpp"
#include <iostream>
using namespace cv;
using namespace std;

int main()
{
    int b, g, r;

    //초기 흰색으로 설정 (255,255,255)
    Mat img(300, 400, CV_8UC3, Scalar(255, 255, 255));

    //사용자로부터 값 입력
    cout << "B값을 입력하라: ";
    cin >> b;
    cout << "G값을 입력하라: ";
    cin >> g;
    cout << "R값을 입력하라: ";
    cin >> r;

    //입력받은 색으로 변경
    img.setTo(Scalar(b, g, r));

    // 출력
    imshow("img", img);
    waitKey();

    return 0;
}
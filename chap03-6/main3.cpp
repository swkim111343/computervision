// **********************************************
// 제 목 : 과제3
// 날 짜 : 2026년 4월1일
// 작성자 : 2001485 김선우
// **********************************************
// 소스코드 작성
#include "opencv2/opencv.hpp"
#include <iostream>
using namespace cv;
using namespace std;

int main()
{
    Mat img = imread("lenna.bmp", IMREAD_COLOR);
    if (img.empty()) {
        cerr << "Image load failed!" << endl;
        return -1;
    }


    int value;
    cout << "밝기변화량을 입력 : ";
    cin >> value;

    Mat bright;

    // 행렬 연산으로 밝기 조절
    bright = img + value;

    // 결과 출력
    imshow("img(원본)", img);
    imshow("bright(밝기 변화)", bright);

    waitKey(0);
    return 0;
}
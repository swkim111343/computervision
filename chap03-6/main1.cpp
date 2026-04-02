// **********************************************
// 제 목 : 과제1
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
    Mat img1 = imread("cv실습과제1.jpg", IMREAD_COLOR);
    if (img1.empty()) {
        cerr << "Image load failed!" << endl;
        return -1;
    }

    cout << "행의 수: " << img1.rows << endl;
    cout << "열의 수: " << img1.cols << endl;
    cout << "채널 수: " << img1.channels() << endl;

    if (img1.type() == CV_8UC1)
        cout << "타입: CV_8UC1" << endl;
    else if (img1.type() == CV_8UC3)
        cout << "타입: CV_8UC3" << endl;
    else
        cout << "타입: 기타" << endl;

    return 0;
}
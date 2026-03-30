// **********************************************
// 제 목 : 과제1
// 날 짜 : 2026년 3월30일
// 작성자 : 2001485 김선우
// **********************************************
// 소스코드 작성
#include "opencv2/opencv.hpp"
#include <iostream>
using namespace cv;
using namespace std;

int main() {
    Mat src = imread("lenna.bmp", IMREAD_COLOR);

    Vec3b pixel1 = src.at<Vec3b>(50, 50);   //3채널 컬러 영상이므로 vec3b 자료형 사용 해서 50,50 픽셀을 pixel1에 저장
    Vec3b pixel2 = src.at<Vec3b>(100, 100);
    Vec3b pixel3 = src.at<Vec3b>(150, 150);

    cout << "좌표 (50, 50)의 화소값(B,G,R) : ("
        << (int)pixel1[0] << ", " << (int)pixel1[1] << ", " << (int)pixel1[2] << ")" << endl;   //8UC3 -> unsigned char형을 int 형으로 강제 형변환 후 픽셀 출력

    cout << "좌표 (100, 100)의 화소값(B,G,R) : ("
        << (int)pixel2[0] << ", " << (int)pixel2[1] << ", " << (int)pixel2[2] << ")" << endl;

    cout << "좌표 (150, 150)의 화소값(B,G,R) : ("
        << (int)pixel3[0] << ", " << (int)pixel3[1] << ", " << (int)pixel3[2] << ")" << endl;

    return 0;
}
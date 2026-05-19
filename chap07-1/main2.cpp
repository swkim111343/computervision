// **********************************************
// 제 목 : 실습과제2
// 날 짜 : 2026년 5월19일
// 작성자 : 2001485 김선우
// **********************************************
#include <iostream>
#include <opencv2/opencv.hpp>
using namespace cv;
using namespace std;

int main(void)
{
    Mat src = imread("rose.bmp", IMREAD_GRAYSCALE);
    if (src.empty()) {
        cerr << "Image load failed!" << endl;
        return -1;
    }
    //이미지 선명화 (Sharpening)
    //가장자리(Edge)와 디테일을 강조하여 이미지를 더 선명하고 날카롭게 만듦
    //흐릿한 이미지를 또렷하게 만드는 데 주로 사용
    float data[] = {
        -1, -1, -1,
        -1,  9, -1,
        -1, -1, -1
    };

    Mat kernel(3, 3, CV_32FC1, data);

    Mat dst;
    filter2D(src, dst, -1, kernel, Point(-1, -1), 0);  // delta = 0

    imshow("src", src);
    imshow("dst", dst);
    waitKey();
    return 0;
}
// **********************************************
// 제 목 : 실습과제1
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
    //이미지 블러링(Blur) / 평활화(Smoothing)
    //이미지의 잡음(노이즈) 제거
    //이미지를 전체적으로 부드럽게 만드는 효과
    // 모든필터 값이 1/9
    float data[] = {
         1.0 / 9,  1.0 / 9,  1.0 / 9, 1.0 / 9,  1.0 / 9,  1.0 / 9, 1.0 / 9,  1.0 / 9,  1.0 / 9
    };

    Mat kernel(3, 3, CV_32FC1, data);

    Mat dst;
    filter2D(src, dst, -1, kernel, Point(-1, -1), 0);  // delta = 0

    imshow("src", src);
    imshow("dst", dst);
    waitKey();
    return 0;
}
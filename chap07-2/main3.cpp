// **********************************************
// 제 목 : 실습과제3
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

    // 5x5 가우시안 마스크
    float data[5][5] = {
        { 1,  4,  7,  4,  1},
        { 4, 16, 26, 16,  4},
        { 7, 26, 41, 26,  7},
        { 4, 16, 26, 16,  4},
        { 1,  4,  7,  4,  1}
    };

    // 마스크를 Mat 형태로 변환하고 정규화 (1/273)
    Mat kernel(5, 5, CV_32FC1);
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++) {
            kernel.at<float>(i, j) = data[i][j] / 273.0f;
        }
    }

    Mat dstFilter2D;
    // filter2D 함수를 이용한 가우시안 필터 적용
    filter2D(src, dstFilter2D, -1, kernel, Point(-1, -1), 0);


    Mat dstGaussian;
    GaussianBlur(src, dstGaussian, Size(5, 5), 0);   // ksize = 5x5

    putText(dstFilter2D, "filter2D Custom Gaussian 5x5",
        Point(10, 30), FONT_HERSHEY_SIMPLEX, 0.8, Scalar(255), 2);

    putText(dstGaussian, "GaussianBlur(5,5)",
        Point(10, 30), FONT_HERSHEY_SIMPLEX, 0.8, Scalar(255), 2);


    imshow("src (원본)", src);
    imshow("filter2D - Custom Gaussian", dstFilter2D);
    imshow("GaussianBlur - Built-in", dstGaussian);

    waitKey(0);
    return 0;
}
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

    //수평 방향 가장자리(Edge) 검출 필터
    //이미지에서 세로 방향으로 밝기가 급변하는 부분(수평 에지)을 강조
    float data[] = {
        -1,  0,  1,
        -2,  0,  2,
        -1,  0,  1
    };

    Mat kernel(3, 3, CV_32FC1, data);

    Mat dst0, dst128;

    //delta=0 → 결과가 음수와 양수를 포함한 값으로 나와 어두운 배경에 밝고 어두운 선이 나타남
    //delta = 128 → 128을 더해 대부분 양수 값으로 변환->회색 배경에 밝은 선으로 가장자리가 잘 보임(일반적으로 더 보기 좋음)
   
    // delta = 0
    filter2D(src, dst0, -1, kernel, Point(-1, -1), 0);

    // delta = 128
    filter2D(src, dst128, -1, kernel, Point(-1, -1), 128);

    imshow("src (원본)", src);
    imshow("dst - delta=0", dst0);
    imshow("dst - delta=128", dst128);

    waitKey();
    return 0;
}
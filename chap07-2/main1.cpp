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

    imshow("src", src);

    Mat dst;
    for (int ksize = 3; ksize <= 7; ksize += 2)
    {
        // 1. 평균값 필터 커널 생성
        float value = 1.0f / (ksize * ksize);     // 모든 요소가 동일한 값
        Mat kernel = Mat::ones(ksize, ksize, CV_32FC1) * value;

        // 2. filter2D로 평균 필터 적용
        filter2D(src, dst, -1, kernel, Point(-1, -1), 0);

        // 설명 텍스트 추가
        String desc = format("Mean Filter (filter2D): %dx%d", ksize, ksize);
        putText(dst, desc, Point(10, 30), FONT_HERSHEY_SIMPLEX,
            1.0, Scalar(255), 2, LINE_AA);

        imshow("dst", dst);
        waitKey();   // 키 입력 대기 (하나씩 확인)
    }

    waitKey(0);
    return 0;
}
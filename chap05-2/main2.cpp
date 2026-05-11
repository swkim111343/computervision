// **********************************************
// 제 목 : 실습과제2
// 날 짜 : 2026년 5월11일
// 작성자 : 2001485 김선우
// **********************************************
// 소스코드 작성
#include <opencv2/opencv.hpp>
#include <iostream>
using namespace cv;
using namespace std;

int main(void)
{
    // 흑백 영상 읽기
    Mat src = imread("lenna.bmp", IMREAD_GRAYSCALE);

    // 영상 로드 실패 검사
    if (src.empty()) {
        cerr << "Image load failed!" << endl;
        return -1;
    }

    // 결과 영상 생성
    Mat dst(src.rows, src.cols, src.type());

    // 대비 조절 값
    float alpha = 1.f;

    // 모든 픽셀 직접 접근
    for (int y = 0; y < src.rows; y++)
    {
        for (int x = 0; x < src.cols; x++)
        {
            // 원본 픽셀값 읽기
            uchar pixel = src.at<uchar>(y, x);

            // 원래 식:
            // dst = src + (src - 128) * alpha

            int value = pixel + (pixel - 128) * alpha;

            // 포화 연산 처리
            if (value > 255)
                value = 255;

            if (value < 0)
                value = 0;

            // 결과 저장
            dst.at<uchar>(y, x) = (uchar)value;
        }
    }

    // 영상 출력
    imshow("src", src);
    imshow("dst", dst);

    waitKey();

    return 0;
}
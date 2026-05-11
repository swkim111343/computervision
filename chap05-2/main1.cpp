// **********************************************
// 제 목 : 실습과제1
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
    // 흑백 이미지 읽기
    Mat src = imread("lenna.bmp", IMREAD_GRAYSCALE);

    // 이미지 로드 실패 검사
    if (src.empty()) {
        cerr << "Image load failed!" << endl;
        return -1;
    }

    // 결과 영상을 저장할 Mat 객체 생성
    // src와 같은 크기, 같은 타입
    Mat dst(src.rows, src.cols, src.type());

    // 실수 배율
    float s = 2.f;

    // 모든 픽셀에 직접 접근
    for (int y = 0; y < src.rows; y++)
    {
        for (int x = 0; x < src.cols; x++)
        {
            // 원본 픽셀값 읽기
            uchar pixel = src.at<uchar>(y, x);

            // 밝기 증가
            int value = (int)(pixel * s);

            // 포화 연산 처리
            // 255를 넘으면 255로 고정
            if (value > 255)
                value = 255;

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
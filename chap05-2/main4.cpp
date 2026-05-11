// **********************************************
// 제 목 : 실습과제4
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
    // 그레이스케일 영상 읽기
    Mat src = imread("lenna.bmp", IMREAD_GRAYSCALE);

    // 영상 로드 실패 검사
    if (src.empty()) {
        cerr << "Image load failed!" << endl;
        return -1;
    }

    // 영상의 평균 밝기 계산
    // avg[0]에 평균 픽셀값 저장
    Scalar avg = mean(src);

    // 평균값 저장
    float meanValue = (float)avg[0];

    cout << "평균 픽셀값 : " << meanValue << endl;

    // 결과 영상 생성
    Mat dst(src.rows, src.cols, src.type());

    // 대비 조절 값
    float alpha = 1.f;

    // 모든 픽셀 직접 처리
    for (int y = 0; y < src.rows; y++)
    {
        for (int x = 0; x < src.cols; x++)
        {
            // 원본 픽셀값 읽기
            uchar pixel = src.at<uchar>(y, x);

            // 기존의 128 대신 평균값 사용
            int value = pixel + (pixel - meanValue) * alpha;

            // 포화 연산
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
// **********************************************
// 제 목 : 실습과제2
// 날 짜 : 2026년 5월19일
// 작성자 : 2001485 김선우
// **********************************************
#include <iostream>
#include <opencv2/opencv.hpp>
#include <chrono>                    // C++ 표준 시간 측정
using namespace cv;
using namespace std;

int main(void)
{
    // 이미지 로드
    Mat src = imread("rose.bmp", IMREAD_GRAYSCALE);
    if (src.empty()) {
        cerr << "Image load failed!" << endl;
        return -1;
    }

    cout << "평균값 필터 실행시간 비교 (3x3, 10x10, 30x30)\n" << endl;

    // 측정할 마스크 크기
    vector<int> sizes = { 3, 10, 30 };

    for (int ksize : sizes)
    {
        float value = 1.0f / (ksize * ksize);                    // 모든 픽셀에 동일한 가중치
        Mat kernel = Mat::ones(ksize, ksize, CV_32FC1) * value;  // 평균 필터 마스크

        Mat dst;

        cout << ksize << " x " << ksize << " 필터 실행 시간 측정..." << endl;

        // TickMeter 사용 
        TickMeter tm;
        tm.start();
        filter2D(src, dst, -1, kernel, Point(-1, -1), 0);
        tm.stop();

        // std::chrono 사용
        auto start = chrono::steady_clock::now();
        filter2D(src, dst, -1, kernel, Point(-1, -1), 0);
        auto end = chrono::steady_clock::now();

        float chronoTime = chrono::duration<float, milli>(end - start).count();

        cout << "   → TickMeter : " << tm.getTimeMilli() << " ms" << endl;
        cout << "   → chrono    : " << chronoTime << " ms" << endl;
        cout << "   -------------------------------------" << endl;
    }

    return 0;
}
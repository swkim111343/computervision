// **********************************************
// 제 목 : 실습과제４
// 날 짜 : 2026년 5월19일
// 작성자 : 2001485 김선우
// **********************************************
#include <iostream>
#include <opencv2/opencv.hpp>
#include <chrono>
using namespace cv;
using namespace std;

int main(void)
{
    Mat src = imread("rose.bmp", IMREAD_GRAYSCALE);
    if (src.empty()) {
        cerr << "Image load failed!" << endl;
        return -1;
    }

    cout << "=== GaussianBlur sigma별 실행시간 측정 ===\n" << endl;

    Mat dst;

    for (int sigma = 1; sigma <= 5; sigma++)
    {
        TickMeter tm;
        tm.start();                                     // 시간 측정 시작

        // GaussianBlur 적용 (ksize = 0으로 자동 결정)
        GaussianBlur(src, dst, Size(0, 0), (double)sigma);

        tm.stop();                                      // 시간 측정 종료

        auto start = chrono::steady_clock::now();
        GaussianBlur(src, dst, Size(0, 0), (double)sigma);
        auto end = chrono::steady_clock::now();

        float chronoTime = chrono::duration<float, milli>(end - start).count();

        cout << "sigma = " << sigma
            << "  →  TickMeter: " << tm.getTimeMilli() << " ms"
            << "   |   chrono: " << chronoTime << " ms" << endl;

        String desc = format("GaussianBlur sigma = %d", sigma);
        putText(dst, desc, Point(10, 30), FONT_HERSHEY_SIMPLEX,
            0.8, Scalar(255), 2, LINE_AA);

        imshow("dst", dst);
        waitKey(300);        // 0.3초 대기
    }

    cout << "\n모든 sigma에 대한 실행시간 측정 완료!" << endl;
    waitKey(0);
    return 0;
}
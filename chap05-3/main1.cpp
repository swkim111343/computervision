// **********************************************
// 제 목 : 실습과제1
// 날 짜 : 2026년 5월13일
// 작성자 : 2001485 김선우
// **********************************************
// 소스코드 작성
#include <iostream>
#include <opencv2/opencv.hpp>
using namespace std;
using namespace cv;

int main() {
    Mat img = imread("lenna.bmp", IMREAD_GRAYSCALE);

    if (img.empty()) {
        cout << "Image load failed!" << endl;
        return -1;
    }

    // 전체 픽셀 수
    int totalPixels = img.rows * img.cols;

    // 최소값, 최대값
    double minVal, maxVal;
    Point minPos, maxPos;

    minMaxLoc(img, &minVal, &maxVal, &minPos, &maxPos);

    // 히스토그램(빈도수) 계산
    int hist[256] = { 0 };

    for (int y = 0; y < img.rows; y++) {
        for (int x = 0; x < img.cols; x++) {
            int pixel = img.at<uchar>(y, x);
            hist[pixel]++;
        }
    }

    // 가장 빈도수가 많은 픽셀값 찾기
    int maxFreq = hist[0];
    int maxPixel = 0;

    for (int i = 1; i < 256; i++) {
        if (hist[i] > maxFreq) {
            maxFreq = hist[i];
            maxPixel = i;
        }
    }

    cout << "영상의 전체 픽셀수 :" << totalPixels << endl;
    cout << "영상에서 픽셀값의 최소값:" << minVal << endl;
    cout << "영상에서 픽셀값의 최대값:" << maxVal << endl;
    cout << "빈도수가 가장 많은 픽셀값과 빈도수:" << maxPixel << "," << maxFreq << endl;
    cout << "픽셀값 80의 빈도수:" << hist[80] << endl;

    return 0;
}
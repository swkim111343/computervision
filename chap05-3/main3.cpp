// **********************************************
// 제 목 : 실습과제3
// 날 짜 : 2026년 5월13일
// 작성자 : 2001485 김선우
// **********************************************
// 소스코드 작성
#include <iostream>
#include <opencv2/opencv.hpp>
using namespace std;
using namespace cv;

// 히스토그램 계산 함수
Mat mycalcGrayHist(const Mat& img)
{
    Mat hist = Mat::zeros(1, 256, CV_32SC1);

    for (int y = 0; y < img.rows; y++) {
        for (int x = 0; x < img.cols; x++) {

            int pixel = img.at<uchar>(y, x);

            hist.at<int>(pixel)++;
        }
    }

    return hist;
}

// 히스토그램 그래프 영상 생성 함수
Mat mygetGrayHistImage(const Mat& hist)
{
    // 히스토그램 영상 크기
    int hist_w = 256;
    int hist_h = 100;

    // 흰색 배경 생성
    Mat histImg(hist_h, hist_w, CV_8UC1, Scalar(255));

    // 히스토그램 최대값 찾기
    double maxVal;
    minMaxLoc(hist, 0, &maxVal);

    // 정규화된 높이 저장
    int normHist[256];

    for (int i = 0; i < 256; i++) {

        normHist[i] =
            (int)((double)hist.at<int>(i) / maxVal * hist_h);
    }

    // 선 그래프 그리기
    for (int i = 0; i < 255; i++) {

        Point p1(i, hist_h - normHist[i]);
        Point p2(i + 1, hist_h - normHist[i + 1]);

        line(histImg, p1, p2, Scalar(0));
    }

    return histImg;
}

int main()
{
    // 영상 읽기
    Mat img = imread("lenna.bmp", IMREAD_GRAYSCALE);

    if (img.empty()) {
        cout << "Image load failed!" << endl;
        return -1;
    }

    // 히스토그램 계산
    Mat hist = mycalcGrayHist(img);

    // 히스토그램 영상 생성
    Mat histImg = mygetGrayHistImage(hist);

    imshow("Image", img);
    imshow("Histogram", histImg);

    waitKey();

    return 0;
}
// **********************************************
// 제 목 : 실습과제5
// 날 짜 : 2026년 5월13일
// 작성자 : 2001485 김선우
// **********************************************
// 소스코드 작성
#include <opencv2/opencv.hpp>
#include <iostream>

using namespace cv;
using namespace std;

// 히스토그램 계산 함수
Mat calcGrayHist(const Mat& img)
{
    CV_Assert(img.type() == CV_8UC1);

    Mat hist;

    int channels[] = { 0 };
    int dims = 1;

    const int histSize[] = { 256 };

    float graylevel[] = { 0,256 };
    const float* ranges[] = { graylevel };

    calcHist(&img, 1, channels,
        noArray(),
        hist,
        dims,
        histSize,
        ranges);

    return hist;
}

// 히스토그램 그래프 함수
Mat getGrayHistImage(const Mat& hist)
{
    CV_Assert(hist.type() == CV_32FC1);
    CV_Assert(hist.size() == Size(1, 256));

    double histMax;
    minMaxLoc(hist, 0, &histMax);

    Mat imgHist(200, 256, CV_8UC1, Scalar(255));

    for (int i = 0; i < 256; i++) {

        line(imgHist,
            Point(i, 200),
            Point(i,
                200 - cvRound(hist.at<float>(i, 0)
                    * 200 / histMax)),
            Scalar(0));
    }

    return imgHist;
}

int main()
{
    // Lenna 영상 읽기
    Mat src = imread("lenna.bmp", IMREAD_GRAYSCALE);

    if (src.empty()) {
        cerr << "Image load failed!" << endl;
        return -1;
    }

    // 히스토그램 평활화
    Mat dst;
    equalizeHist(src, dst);

    // 히스토그램 계산
    Mat srcHist = calcGrayHist(src);
    Mat dstHist = calcGrayHist(dst);

    // 히스토그램 그래프 생성
    Mat srcHistImg = getGrayHistImage(srcHist);
    Mat dstHistImg = getGrayHistImage(dstHist);

    // 출력
    imshow("src", src);
    imshow("srcHist", srcHistImg);

    imshow("dst", dst);
    imshow("dstHist", dstHistImg);

    waitKey();

    return 0;
}
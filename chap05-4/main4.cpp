// **********************************************
// 제 목 : 실습과제4
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

    Mat histImg(200, 256, CV_8UC1, Scalar(255));

    for (int i = 0; i < 256; i++) {

        line(histImg,
            Point(i, 200),
            Point(i,
                200 - cvRound(hist.at<float>(i, 0)
                    * 200 / histMax)),
            Scalar(0));
    }

    return histImg;
}

int main()
{
    // 영상 읽기
    Mat src = imread("lenna.bmp", IMREAD_GRAYSCALE);

    if (src.empty()) {
        cerr << "Image load failed!" << endl;
        return -1;
    }

    // 최소값, 최대값
    double gmin, gmax;

    minMaxLoc(src, &gmin, &gmax);

    cout << "Gmin : " << gmin << endl;
    cout << "Gmax : " << gmax << endl;

    // 히스토그램 스트레칭
    Mat dst(src.rows, src.cols, CV_8UC1);

    for (int y = 0; y < src.rows; y++) {

        for (int x = 0; x < src.cols; x++) {

            uchar pixel = src.at<uchar>(y, x);

            int value =
                (pixel - gmin) * 255 / (gmax - gmin);

            dst.at<uchar>(y, x) =
                saturate_cast<uchar>(value);
        }
    }

    // 히스토그램 계산
    Mat srcHist = calcGrayHist(src);
    Mat dstHist = calcGrayHist(dst);

    // 히스토그램 영상 생성
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
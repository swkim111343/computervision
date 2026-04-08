// **********************************************
// 제 목 : 실습과제3
// 날 짜 : 2026년 4월8일
// 작성자 : 2001485 김선우
// **********************************************
// 소스코드 작성
#include "opencv2/opencv.hpp"
#include <iostream>
using namespace cv;
using namespace std;

void onMouse(int event, int x, int y, int flags, void* userdata)
{
    if (event == EVENT_LBUTTONDOWN) {
        Mat* img = (Mat*)userdata;

        int pixel = img->at<uchar>(y, x);   //Y,X 순서

        cout << "좌표 : (" << x << ", " << y << "),  화소값:"
            << pixel << endl;
    }
}

int main(void)
{
    Mat img = imread("lenna.bmp", IMREAD_GRAYSCALE);    //그레이스케일 영상
    if (img.empty()) {
        cerr << "Image load failed!" << endl;
        return -1;
    }

    imshow("img", img);

    // 이미지 포인터를 userdata로 전달
    setMouseCallback("img", onMouse, &img);

    while (true) {
        if (waitKey(1) == 'q')
            break;
    }

    destroyAllWindows();
    return 0;
}
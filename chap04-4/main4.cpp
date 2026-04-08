// **********************************************
// 제 목 : 실습과제4
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

        // 컬러 영상 → Vec3b이용
        Vec3b pixel = img->at<Vec3b>(y, x);

        cout << "좌표: (" << x << ", " << y << "),  화소값(B,G,R): ("
            << (int)pixel[0] << ", "
            << (int)pixel[1] << ", "
            << (int)pixel[2] <<")" << endl;
    }
}

int main(void)
{
    Mat img = imread("lenna.bmp", IMREAD_COLOR);    //컬러영상
    if (img.empty()) {
        cerr << "Image load failed!" << endl;
        return -1;
    }

    imshow("img", img);

    // 이미지 전달
    setMouseCallback("img", onMouse, &img);

    while (true) {
        if (waitKey(1) == 'q')
            break;
    }

    destroyAllWindows();
    return 0;
}
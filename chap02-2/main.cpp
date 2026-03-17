// **********************************************
// 제 목 : 과제1
// 날 짜 : 2026년 3월17일
// 작성자 : 2001485 김선우
// **********************************************
// 소스코드 작성
#include <opencv2/opencv.hpp>
#include <iostream>
using namespace cv;
using namespace std;
int main() {

    cout << "Hello OpenCV " << CV_VERSION << endl;
    Mat img;
    img = imread("swkim_sphoto.jpg");
    if (img.empty()) {
        cerr << "Image load failed!" << endl;
        return -1;
    }
    namedWindow("image");
    imshow("image", img);
    waitKey();
    return 0;
}
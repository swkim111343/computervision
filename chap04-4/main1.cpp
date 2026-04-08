// **********************************************
// 제 목 : 실습과제1
// 날 짜 : 2026년 4월8일
// 작성자 : 2001485 김선우
// **********************************************
// 소스코드 작성
#include "opencv2/opencv.hpp"
#include <iostream>
using namespace cv;
using namespace std;

int main(void)
{
    Mat img = imread("lenna.bmp");
    if (img.empty()) {
        cerr << "Image load failed!" << endl;
        return -1;
    }

    int keycode;

    while (true) {
        imshow("img", img);
        keycode = waitKey();    //키입력대기

        if (keycode == 'l') {
            //흰색선
            line(img, Point(133, 453), Point(410, 453), Scalar(255, 255, 255), 2);  //마지막 2는 선두께
        }
        else if (keycode == 'c') {
            //빨간원 (레나 코 중심)
            circle(img, Point(309, 318), 100, Scalar(0, 0, 255), 2);    //중심좌표와 반지름이 100인 원
        }
        else if (keycode == 't') {
            putText(img, "hello, lenna", Point(180, 50),
                FONT_HERSHEY_SIMPLEX, 1.0, Scalar(0, 255, 255), 2);
        }
        else if (keycode == 'q' || keycode == 'Q') {
            break;
        }
    }

    destroyAllWindows();    //종료처리 모든창 닫기
    return 0;
}
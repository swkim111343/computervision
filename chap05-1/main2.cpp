// **********************************************
// 제 목 : 실습과제2
// 날 짜 : 2026년 5월6일
// 작성자 : 2001485 김선우
// **********************************************
// 소스코드 작성
#include <opencv2/opencv.hpp>
#include <iostream>
using namespace cv;
using namespace std;

Mat img;
Point pt1, pt2;

void on_mouse(int event, int x, int y, int flag, void*);

int main(void)
{
	img = imread("lenna.bmp", IMREAD_GRAYSCALE);
	if (img.empty()) { cerr << "Image load failed!" << endl; return -1; }

	namedWindow("img");
	setMouseCallback("img", on_mouse);

	imshow("img", img);
	waitKey();

	return 0;
}

void on_mouse(int event, int x, int y, int flags, void*) {
	if (event == EVENT_LBUTTONDOWN) {
		pt1 = Point(x, y);
	}
	else if (event == EVENT_LBUTTONUP) {
		pt2 = Point(x, y);

		Rect roi(pt1, pt2);

		Mat img_roi = img(roi);
		img_roi += 50;

		imshow("img", img);
	}
}
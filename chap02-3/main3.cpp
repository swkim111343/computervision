// **********************************************
// 제 목 : 과제3
// 날 짜 : 2026년 3월17일
// 작성자 : 2001485 김선우
// **********************************************
// 소스코드 작성
#include "opencv2/opencv.hpp"
#include <iostream>
using namespace cv;
using namespace std;
int main()
{
	Mat img1, img2, img3, img4, img5, img6, img7, img8, img9, img0;
	img1 = imread("1.png");
	img2 = imread("2.png");
	img3 = imread("3.png");
	img4 = imread("4.png");
	img5 = imread("5.png");
	img6 = imread("6.png");
	img7 = imread("7.png");
	img8 = imread("8.png");
	img9 = imread("9.png");
	img0 = imread("0.png");

	if (img1.empty() && img2.empty() && img3.empty()
		&& img4.empty() && img5.empty() && img6.empty()
		&& img7.empty() && img8.empty() && img9.empty() 
		&& img0.empty()) {
		cerr << "Image load failed! " << endl;
		return -1;
	}
	
	Mat img[10] = { img1, img2, img3, img4, img5, img6, img7, img8, img9, img0 };
	
	int i = 0;
	while (true) {	//무한반복위해while문사용
		imshow("image", img[i]);
		waitKey(1000);
		i = (i + 1) % 10;	
	}
	return 0;
}

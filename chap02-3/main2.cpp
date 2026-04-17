// **********************************************
// 제 목 : 과제2
// 날 짜 : 2026년 4월17일
// 작성자 : 2001485 김선우
// **********************************************
// 소스코드 작성
#include "opencv2/opencv.hpp"
#include <iostream>
using namespace cv;
using namespace std;
int main()
{
	Mat img1, img2, img3;
	img1 = imread("lenna.bmp");
	img2 = imread("swkim_sphoto.jpg");
	img3 = imread("bright.jpg");
	
	if (img1.empty() && img2.empty() && img3.empty()) {
		cerr << "Image load failed! " << endl;
		return -1;
	}
	
	Mat img[3] = { img1, img2, img3 };
	
	int i = 0;
	while (true) {	//무한반복위해while문사용
		imshow("image", img[i]);
		waitKey(1000);
		i = (i + 1) % 3;	//0,1,2,0,1,2....
	}
	return 0;
}

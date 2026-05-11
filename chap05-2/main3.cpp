// **********************************************
// 제 목 : 실습과제3
// 날 짜 : 2026년 5월11일
// 작성자 : 2001485 김선우
// **********************************************
// 소스코드 작성
#include <opencv2/opencv.hpp>
#include <iostream>
using namespace cv;
using namespace std;
int main(void)
{
	Mat src = imread("lenna.bmp", IMREAD_GRAYSCALE);
	if (src.empty()) { cerr << "Image load failed!" << endl; return -1; }
	// 예를들어 알파가 5이면 밝은 픽셀은 더 밝아지고 어두운 픽셀은 더 어두워짐(대비가 강함)
	// 하지만 픽셀값 범위는 0~255이므로 대부분 값이 255로 고정 0으로 고정

	//반대로 알파가 -0.5로 너무 작은경우 (pixel-128)*alpha가 매우 작아짐
	//원래영상과 거의 비슷해짐(대비 변화 X)

	float alpha = -0.5f;
	Mat dst = src + (src - 128) * alpha; //*,+,-연산자함수(포화연산포함)
	imshow("src", src);
	imshow("dst", dst);
	waitKey();
	return 0;
}

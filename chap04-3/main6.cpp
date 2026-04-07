// **********************************************
// 제 목 : 실습과제6
// 날 짜 : 2026년 4월7일
// 작성자 : 2001485 김선우
// **********************************************
// 소스코드 작성
#include "opencv2/opencv.hpp"
using namespace cv;

int main() {
    Mat img = imread("lenna.bmp");
    if (img.empty()) {
        printf("Image load failed!\n");
        return -1;
    }

    String text = "Hello, Lenna";

    // 폰트 설정
    int fontFace = FONT_HERSHEY_SIMPLEX;    //일반 크기의 산세리프 폰트
    double fontScale = 1.0;
    int thickness = 2;

    // 텍스트 크기 계산
    int baseline = 0;
    Size textSize = getTextSize(text, fontFace, fontScale, thickness, &baseline);

    // 중앙 상단 위치 계산
    int x = (img.cols - textSize.width) / 2;
    int y = textSize.height + 10; // 위쪽 여백 조금 줌

    // 노란색
    Scalar yellow(0, 255, 255);

    // 텍스트 출력
    putText(img, text, Point(x, y), fontFace, fontScale, yellow, thickness);

    imshow("Lenna", img);
    waitKey(0);

    return 0;
}
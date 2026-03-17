// **********************************************
// 제 목 : 과제1
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
    cout << "Hello OpenCV " << CV_VERSION << endl;
    Mat img;    //이미지 객체 선언
    img = imread("lenna.bmp", IMREAD_GRAYSCALE);    //이미지 파일 읽기
    if (img.empty()) {  
        cerr << "Image load failed!" << endl;
        return -1;
    }
    namedWindow("image1",WINDOW_AUTOSIZE);  //첫번째 그레이스케일 변환된 원본 창 생성
    imshow("image1", img);  //이미지 출력
    Mat brightImg = img + 100;  //밝기 증가
    namedWindow("image2", WINDOW_AUTOSIZE); //두번째 밝아진 창 생성
    imshow("image2", brightImg);    //밝아진 이미지 출력

    imwrite("bright.jpg", img); //bright.jpg 파일로 저장(imwrite 함수 사용)
    waitKey();  //waitkey는 하나만 써도 가능
    return 0;
}
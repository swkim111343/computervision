// **********************************************
// 제 목 : 과제4
// 날 짜 : 2026년 3월26일
// 작성자 : 2001485 김선우
// **********************************************
// 소스코드 작성
#include "opencv2/opencv.hpp"
#include <iostream>
using namespace cv;
using namespace std;

int main()
{
    int key;

    Mat img1 = imread("dog.bmp", IMREAD_COLOR);
    if (img1.empty()) {
        cerr << "Image load failed!" << endl;
        return -1;
    }

    Rect roi(96, 34, 100, 100);
    // 얕은 복사 face와img는 같은 이미지데이터를가르킴
    Mat face = img1(roi);


    //원본 부분
    Mat face1;
    face.copyTo(face1);

    bool flag = true; // flag는 강아지 얼굴 색칠과 기존 얼굴 복원(face1)부분 스위치 역할

    while (true) {
        if (flag) {
            face = Scalar(255, 0, 0);      // 얕은 복사로 face 부분 blue변경
        }
        else {
            face1.copyTo(face);      // 깊은 복사로 복원
        }
        imshow("img1", img1);               // imshow 한 번만 사용
        flag = !flag;
        if (waitKey(1000) == 'q') break;
    }
    return 0;
}
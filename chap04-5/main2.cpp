// **********************************************
// 제 목 : 실습과제2
// 날 짜 : 2026년 4월13일
// 작성자 : 2001485 김선우
// **********************************************
// 소스코드 작성
#include "opencv2/opencv.hpp"
#include <iostream>
using namespace cv;
using namespace std;

Mat img(500, 500, CV_8UC3,Scalar(255,255,255)); // 500x500 흰색 배경의 컬러 영상
Point pt1, pt2; //마우스 드래그 시작점과 끝점을 저장할
bool drawing = false;   //드래그중인지 여부
int mode = 0; // 트랙바 값 (0~3)

void on_trackbar(int pos, void*)    //트랙바콜백함수
{
    mode = pos; //현재 트랙바 값을 모드로 저장
    cout << "모드: " << mode << endl;
}

void on_mouse(int event, int x, int y, int, void*)  //마우스 이벤트 처리 함수
{
    if (event == EVENT_LBUTTONDOWN) {   //왼쪽버튼누르면
        drawing = true; //드래그시작 
        pt1 = Point(x, y);  //시작 좌표 저장
    }
    else if (event == EVENT_MOUSEMOVE && drawing) { //마우스 이동
        pt2 = Point(x, y);  //현재좌표 저장
    }
    else if (event == EVENT_LBUTTONUP) {    //마우스 놓으면
        drawing = false;    //드래그 종료
        pt2 = Point(x, y);  //놓은 점 좌표 저장

        Rect rect(pt1, pt2);    //pt1, pt2로 사각형 생성

        // 모드에 따른 사각형 색상
        if (mode == 0) {   
            rectangle(img, rect, Scalar(255, 0, 0), 2); //0번 파란색 사각형
        }
        else if (mode == 1) {
            rectangle(img, rect, Scalar(0, 255, 0), 2); //1번 초록색 사각형
        }
        else if (mode == 2) {
            rectangle(img, rect, Scalar(0, 0, 255), 2); //2번 빨간색 사각형
        }
        else if (mode == 3) {
            rectangle(img, rect, Scalar(255, 255, 255), -1); //3번 지우기(하얀색으로 채움)
        }
    }
}

int main()
{
    namedWindow("src");

    // 트랙바 (0~3, 초기값 0)
    createTrackbar("trackbar", "src", &mode, 3, on_trackbar);

    // 마우스 이벤트 등록
    setMouseCallback("src", on_mouse);

    while (true)
    {
        imshow("src", img);

        if (waitKey(1) == 27) break;
    }

    return 0;
}
// **********************************************
// 제 목 : 실습과제5
// 날 짜 : 2026년 4월8일
// 작성자 : 2001485 김선우
// **********************************************
// 소스코드 작성
#include "opencv2/opencv.hpp"
#include <iostream>
using namespace cv;
using namespace std;

void event_handler(int event, int x, int y, int flags, void* userdata);

Mat img;
Point ptStart;   // 드래그 시작점

int main(void)
{
    img = imread("lenna.bmp");
    if (img.empty()) {
        cerr << "Image load failed!" << endl;
        return -1;
    }

    namedWindow("img");
    setMouseCallback("img", event_handler);

    int key;
    while (true) {
        imshow("img", img);
        key = waitKey(10);
        if (key == 'q') break;
    }

    destroyAllWindows();
    return 0;
}

void event_handler(int event, int x, int y, int flags, void* userdata)
{
    switch (event) {
    case EVENT_LBUTTONDOWN:
        ptStart = Point(x, y);   // 시작점 저장
        break;

    case EVENT_LBUTTONUP:
    {
        Point ptEnd(x, y);       // 끝점

        // 좌표 정렬 (드래그 방향 상관없이)
        int x1 = min(ptStart.x, ptEnd.x);
        int y1 = min(ptStart.y, ptEnd.y);
        int x2 = max(ptStart.x, ptEnd.x);
        int y2 = max(ptStart.y, ptEnd.y);

        //관심영역 생성
        Rect roi(x1, y1, x2 - x1, y2 - y1);

        // 영역 추출
        Mat cp = img(roi);

        //새창에 출력
        imshow("cp", cp);
        break;
    }
    }
}
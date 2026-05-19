// **********************************************
// 제 목 : 실습과제５
// 날 짜 : 2026년 5월19일
// 작성자 : 2001485 김선우
// **********************************************
#include <iostream>
#include <opencv2/opencv.hpp>
using namespace cv;
using namespace std;

Mat src, dst, temp;
Point pt1, pt2;
bool dragging = false;

void onMouse(int event, int x, int y, int flags, void* userdata)
{
    if (event == EVENT_LBUTTONDOWN)
    {
        dragging = true;
        pt1 = Point(x, y);
    }
    else if (event == EVENT_MOUSEMOVE && dragging)
    {
        temp = src.clone();
        pt2 = Point(x, y);
        rectangle(temp, pt1, pt2, Scalar(0, 255, 0), 2);
        imshow("Lenna", temp);
    }
    else if (event == EVENT_LBUTTONUP && dragging)
    {
        dragging = false;
        pt2 = Point(x, y);

        if (pt1.x > pt2.x) swap(pt1.x, pt2.x);
        if (pt1.y > pt2.y) swap(pt1.y, pt2.y);

        Rect roi(pt1, pt2);
        if (roi.width > 0 && roi.height > 0)
        {
            Mat blurred;
            GaussianBlur(src(roi), blurred, Size(0, 0), 5);
            blurred.copyTo(dst(roi));
        }
        imshow("Lenna", dst);
    }
}

int main(void)
{
    src = imread("lenna.bmp", IMREAD_GRAYSCALE);
    if (src.empty()) {
        cerr << "Image load failed!" << endl;
        return -1;
    }

    dst = src.clone();

    namedWindow("Lenna");
    setMouseCallback("Lenna", onMouse);

    imshow("Lenna", dst);

    while (true)
    {
        int key = waitKey(1);
        if (key == 27) break;           
        if (key == 'r' || key == 'R')  
            dst = src.clone();
    }

    return 0;
}
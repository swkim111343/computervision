// **********************************************
// 제 목 : 실습과제5
// 날 짜 : 2026년 6월 2일
// 작성자 : 2001485 김선우
// **********************************************
#include <opencv2/opencv.hpp>
#include <iostream>

using namespace cv;
using namespace std;

int main()
{
    Mat src = imread("lenna.bmp");    //레나로대체

    if (src.empty()) {
        cerr << "Image load failed!" << endl;
        return -1;
    }

    Mat dst;

    while (true)
    {
        imshow("src", src);

        char key = (char)waitKey(0);

        if (key == 'a')
        {
            // 좌우 대칭
            flip(src, dst, 1);
        }
        else if (key == 'b')
        {
            // 상하 대칭
            flip(src, dst, 0);
        }
        else if (key == 'c')
        {
            // 좌우 + 상하 대칭
            flip(src, dst, -1);
        }
        else if (key == 'q')
        {
            break;
        }
        else
        {
            continue;
        }

        imshow("dst", dst);
    }

    return 0;
}
// **********************************************
// 제 목 : 과제5
// 날 짜 : 2026년 3월17일
// 작성자 : 2001485 김선우
// **********************************************
// 소스코드 작성
#include <opencv2/opencv.hpp>
#include <iostream>
using namespace cv;
using namespace std;

int main()
{
    String str;

    for (int i = 1; i <= 15; i += 2) //실행결과가 15까지 출력 2씩 증가
    {
        str = format("실행결과%d.bmp", i);
        cout << str << endl;
    }

    return 0;
}
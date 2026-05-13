## 컴퓨터비전 챕터05-4 과제
## 실습과제 1
두 점 (Gmin, 0), (Gmax, 255)를 지나는 직선의 방정식을 이용한다.

직선의 기본식은 다음과 같다.

(y - y1) / (x - x1) = (y2 - y1) / (x2 - x1)

여기서

x1 = Gmin
y1 = 0

x2 = Gmax
y2 = 255

를 대입하면

(y - 0) / (x - Gmin) = (255 - 0) / (Gmax - Gmin)

즉,

y = ((x - Gmin) * 255) / (Gmax - Gmin)

이 된다.

영상 처리에서는

x → src(x,y)
y → dst(x,y)

로 바꾸므로,

dst(x,y) = ((src(x,y) - Gmin) * 255) / (Gmax - Gmin)

이 된다.

따라서 히스토그램 스트레칭의 최종 수식은

dst(x,y) = ((src(x,y) - Gmin) * 255) / (Gmax - Gmin)

이다.
------------
## 실습과제 2
1. 히스토그램 스트레칭: 영상의 최소 밝기값과 최대 밝기값을 이용하여 밝기 범위를 전체 영역(0~255)로 늘려주는 방법->좁게 분포된 히스트그램을 양쪽으로 펼쳐 명앞 대비를 증가

2. 히스토그램 평활화: 픽셀값의 분포를 전체 밝기 영역에 고르게 퍼지도록 재분배->특정 밝기값에 몰려있는 히스토그램을 전체적으로 균등하게 분포시키는 방법

------------
## 실습과제 3 출력결과
<img width="1283" height="535" alt="스크린샷 2026-05-13 210718" src="https://github.com/user-attachments/assets/f7a15442-562f-42a1-a584-db7c805ee132" />

------------
## 실습과제 4 출력결과
<img width="1031" height="796" alt="스크린샷 2026-05-13 211339" src="https://github.com/user-attachments/assets/f9194618-def2-4d3f-9b7e-6080890f2687" />

------------
## 실습과제 5 출력결과
<img width="1034" height="785" alt="스크린샷 2026-05-13 211220" src="https://github.com/user-attachments/assets/06b3e1e0-84ea-4ac2-8cb9-2bca88f52d36" />

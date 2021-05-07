#include <stdio.h>
#define _USE_MATH_DEFINES //파이 값을 제공해주기 위함.
#include <math.h> // 수학기호
#include <windows.h> //윈도우 응용 프로그램을 만들기 위함.
#include <stdlib.h> // 난수 생성
#include <time.h> // 난수 생성

#pragma warning(disable : 4996) //권장되지 않는 함수 사용에 대한 경고 무시

using namespace std;

HWND hwnd;
HDC hdc;

enum color { BLUE, RED, WHITE, GREEN }; // 열거형

void Draw(float val, int x_origin, int y_origin, int curx, color c) {
	if (c == BLUE) {
		SetPixel(hdc, x_origin + curx, y_origin - val, RGB(0, 0, 255));
	}
	else if (c == RED) {
		SetPixel(hdc, x_origin + curx, y_origin - val, RGB(255, 0, 0));
	}
	else if (c == GREEN) {
		SetPixel(hdc, x_origin + curx, y_origin - val, RGB(0, 255, 0));
	}
	else {
		SetPixel(hdc, x_origin + curx, y_origin - val, RGB(255, 255, 255));
	}
} //알맞은 색을 선택해 선을 그리는 함수.

void DrawHistogram(int histogram[400], int x_origin, int y_origin, int cnt) {
	MoveToEx(hdc, x_origin, y_origin, 0);
	LineTo(hdc, x_origin + cnt, y_origin);

	MoveToEx(hdc, x_origin, 100, 0);
	LineTo(hdc, x_origin, y_origin);

	for (int CurX = 0; CurX < cnt; CurX++) {
		for (int CurY = 0; CurY < histogram[CurX]; CurY++) {
			MoveToEx(hdc, x_origin + CurX, y_origin, 0);
			LineTo(hdc, x_origin + CurX, y_origin - histogram[CurX] / 2);
		}
	}
}// 히스토그램 그리기 int 형

void DrawHistogram(float histogram[400], int x_origin, int y_origin, int cnt) {
	MoveToEx(hdc, x_origin, y_origin, 0);
	LineTo(hdc, x_origin + cnt, y_origin);

	MoveToEx(hdc, x_origin, y_origin, 0);
	LineTo(hdc, x_origin, y_origin - 100);

	for (int CurX = 0; CurX < cnt; CurX++) {
		for (int CurY = 0; CurY < histogram[CurX]; CurY++) {
			MoveToEx(hdc, x_origin + CurX, y_origin, 0);
			LineTo(hdc, x_origin + CurX, y_origin - histogram[CurX]);
		}
	}
}// 히스토그램 그리기, float형
void nomalization(int histogram[400], float norm_histogram[400], int range, int rcnt) {
	for (int i = 0; i < range; i++) {
		norm_histogram[i] = (float)histogram[i] / 100;
	}
}// 표준화?


int Getfactorial(int n) {
	if (n == 0) {
		return 1;
	}

	int fac = n;
	for (int i = n - 1; i >= 1; i--) {
		fac *= i;
	}

	return fac;
} //factorial

float getERF(float x) {
	return 0;
}

float normal_cdf(float x, float rate, float mu = 0, float sigma = 1) {
	return (1 + erf((x - mu) / (sqrt(2) * sigma))) / 2; //erf : 오차함수(가우시안 함수)
}

float inverse_normal_cdf(float random_variable, float p, float mu = 0, float sigma = 2, float tolerance = 0.00001)
{
	float low_z = -200.0, low_p = 0; // 음의 무한대. z
	float hi_z = 200.0, hi_p = 1; // 양의 무한대
	float mid_z, mid_p;

	while (hi_z - low_z > tolerance)
	{
		mid_z = (low_z + hi_z) / 2; // 중간값
		mid_p = normal_cdf(mid_z, random_variable, mu, sigma); // 중간 값의 누적분포 값을 계산.

		if (mid_p < p) // 중간값이 p보다 작을 때
		{
			low_z = mid_z;
			low_p = mid_p;
		}
		else if (mid_p > p) // 중간값이 p보다 클 때
		{
			hi_z = mid_z;
			hi_p = mid_p;
		}
		else
			break;
	} // 오차범위보다 작아질 때까지 반복

	return mid_z;
} //cdf의 역함수 

double gaussDistributeRand(int value, int range, float average = 0, float sigma = 1) {
	return 0;
}

float normal_pdf(int x, float rate, float  mu = 0, float sigma = 1) {
	double pi = M_PI;

	double sqrt_two_pi = sqrt(2 * pi);
	double _exp = exp(-pow(((double)x / rate - mu), 2) / (2 * pow(sigma, 2)));
	return _exp / (sqrt_two_pi * sigma);
} // 표준화된 pdf

int pdf(int x, float rate, float  mu, float sigma) {
	double pi = M_PI;

	double sqrt_two_pi = sqrt(2 * pi);
	double _exp = exp(-pow(((double)x / rate - mu), 2) / (2 * pow(sigma, 2)));
	return _exp / (sqrt_two_pi * sigma) * 500;
} // pdf 공식 

int main(void)
{
	system("color F0"); //콘솔 출력 창 밝은 흰색, 글씨 검은색
	hwnd = GetForegroundWindow();
	hdc = GetWindowDC(hwnd);

	int y_axis = 300;

	int range = 400; // 0~400 범위 랜덤 변수
	int rcnt = 10000; // rcnt times 랜덤 변수 발생
	float avg = 0; // 평균
	float sigma = 1; // 표준편차
	int input_avg = 3;
	int input_sigma = 1;

	srand(time(NULL));
	int random_variable[401] = { 0, }; // 랜덤 변수 count
	int Gaussian_random_variable[401] = { 0, }; // 가우시안 변수 카운트
	float norm_Gaussian_random_variable[401] = { 0, };
	float gaussianCDF[401] = { 0, }; // 랜덤 가우시안 분포 CDF
	float gaussianCDF_true[401] = { 0, }; // 실제 정답 가우시안 분포 CDF

	int random_number[10000] = { 0, };

	for (int i = 0; i < rcnt; i++)
	{
		int num = (rand() % (range)) - (range / 2);
		random_number[i] = num;
	}

	for (int i = 0; i < rcnt; i++)
	{
		random_variable[random_number[i] + range / 2] += 1;
	}
	//uniform distribution의 random variable


	for (int i = 1; i < range; i++) 
	{
		Gaussian_random_variable[i] = pdf(i - 1 * range / 2, random_variable[i], input_avg, input_sigma);
		gaussianCDF[i + 1] += (gaussianCDF[i] + (float)Gaussian_random_variable[i] / 100);
	}


	nomalization(Gaussian_random_variable, norm_Gaussian_random_variable, range, rcnt);
	DrawHistogram(random_variable, 30, y_axis - 100, range);  // 랜덤 변수 분포 출력  //좌측 상단 그래프
	DrawHistogram(Gaussian_random_variable, 500, y_axis, range); // 가우시안 변수 분포 출력 // 우측 그래프

	float normal_cdf[400] = { 0, };
	for (int i = 1; i < range; i++) {
		float value = normal_pdf(i - 1 * range / 2, range / 20, avg, sigma);
		normal_cdf[i] += value + normal_cdf[i - 1];
		Draw(value * 250, 500, y_axis, i, RED);
	}
//	DrawHistogram(gaussianCDF_true, 30, y_axis + 100, range); // true 가우시안 cdf 정답 출력 // 좌측하단 그래프
	DrawHistogram(gaussianCDF, 30, y_axis + 100, range); // 가우시안 cdf 출력 // 좌측하단 그래프

	for (int i = 1; i < range; i++)
	{
		Draw(normal_cdf[i] * 5, 30, y_axis + 100, i, GREEN);
	} // normal_cdf출력

	return 0;
}

/*
HWND hwnd;
HDC hdc;

int main(void)
{
int x, y;
hwnd = GetForegroundWindow();
hdc = GetWindowDC(hwnd);
}
//그래픽을 하기 위해 필요한 값.
*/

/*
MoveToEx(hdc, A, B, NULL);
LineTo(hdc, C, D);
// (A,B)에서 (C,D)까지 직선을 그린다.
*/


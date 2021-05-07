#include <stdio.h>
#define _USE_MATH_DEFINES //���� ���� �������ֱ� ����.
#include <math.h> // ���б�ȣ
#include <windows.h> //������ ���� ���α׷��� ����� ����.
#include <stdlib.h> // ���� ����
#include <time.h> // ���� ����

#pragma warning(disable : 4996) //������� �ʴ� �Լ� ��뿡 ���� ��� ����

using namespace std;

HWND hwnd;
HDC hdc;

enum color { BLUE, RED, WHITE, GREEN }; // ������

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
} //�˸��� ���� ������ ���� �׸��� �Լ�.

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
}// ������׷� �׸��� int ��

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
}// ������׷� �׸���, float��
void nomalization(int histogram[400], float norm_histogram[400], int range, int rcnt) {
	for (int i = 0; i < range; i++) {
		norm_histogram[i] = (float)histogram[i] / 100;
	}
}// ǥ��ȭ?


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
	return (1 + erf((x - mu) / (sqrt(2) * sigma))) / 2; //erf : �����Լ�(����þ� �Լ�)
}

float inverse_normal_cdf(float random_variable, float p, float mu = 0, float sigma = 2, float tolerance = 0.00001)
{
	float low_z = -200.0, low_p = 0; // ���� ���Ѵ�. z
	float hi_z = 200.0, hi_p = 1; // ���� ���Ѵ�
	float mid_z, mid_p;

	while (hi_z - low_z > tolerance)
	{
		mid_z = (low_z + hi_z) / 2; // �߰���
		mid_p = normal_cdf(mid_z, random_variable, mu, sigma); // �߰� ���� �������� ���� ���.

		if (mid_p < p) // �߰����� p���� ���� ��
		{
			low_z = mid_z;
			low_p = mid_p;
		}
		else if (mid_p > p) // �߰����� p���� Ŭ ��
		{
			hi_z = mid_z;
			hi_p = mid_p;
		}
		else
			break;
	} // ������������ �۾��� ������ �ݺ�

	return mid_z;
} //cdf�� ���Լ� 

double gaussDistributeRand(int value, int range, float average = 0, float sigma = 1) {
	return 0;
}

float normal_pdf(int x, float rate, float  mu = 0, float sigma = 1) {
	double pi = M_PI;

	double sqrt_two_pi = sqrt(2 * pi);
	double _exp = exp(-pow(((double)x / rate - mu), 2) / (2 * pow(sigma, 2)));
	return _exp / (sqrt_two_pi * sigma);
} // ǥ��ȭ�� pdf

int pdf(int x, float rate, float  mu, float sigma) {
	double pi = M_PI;

	double sqrt_two_pi = sqrt(2 * pi);
	double _exp = exp(-pow(((double)x / rate - mu), 2) / (2 * pow(sigma, 2)));
	return _exp / (sqrt_two_pi * sigma) * 500;
} // pdf ���� 

int main(void)
{
	system("color F0"); //�ܼ� ��� â ���� ���, �۾� ������
	hwnd = GetForegroundWindow();
	hdc = GetWindowDC(hwnd);

	int y_axis = 300;

	int range = 400; // 0~400 ���� ���� ����
	int rcnt = 10000; // rcnt times ���� ���� �߻�
	float avg = 0; // ���
	float sigma = 1; // ǥ������
	int input_avg = 3;
	int input_sigma = 1;

	srand(time(NULL));
	int random_variable[401] = { 0, }; // ���� ���� count
	int Gaussian_random_variable[401] = { 0, }; // ����þ� ���� ī��Ʈ
	float norm_Gaussian_random_variable[401] = { 0, };
	float gaussianCDF[401] = { 0, }; // ���� ����þ� ���� CDF
	float gaussianCDF_true[401] = { 0, }; // ���� ���� ����þ� ���� CDF

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
	//uniform distribution�� random variable


	for (int i = 1; i < range; i++) 
	{
		Gaussian_random_variable[i] = pdf(i - 1 * range / 2, random_variable[i], input_avg, input_sigma);
		gaussianCDF[i + 1] += (gaussianCDF[i] + (float)Gaussian_random_variable[i] / 100);
	}


	nomalization(Gaussian_random_variable, norm_Gaussian_random_variable, range, rcnt);
	DrawHistogram(random_variable, 30, y_axis - 100, range);  // ���� ���� ���� ���  //���� ��� �׷���
	DrawHistogram(Gaussian_random_variable, 500, y_axis, range); // ����þ� ���� ���� ��� // ���� �׷���

	float normal_cdf[400] = { 0, };
	for (int i = 1; i < range; i++) {
		float value = normal_pdf(i - 1 * range / 2, range / 20, avg, sigma);
		normal_cdf[i] += value + normal_cdf[i - 1];
		Draw(value * 250, 500, y_axis, i, RED);
	}
//	DrawHistogram(gaussianCDF_true, 30, y_axis + 100, range); // true ����þ� cdf ���� ��� // �����ϴ� �׷���
	DrawHistogram(gaussianCDF, 30, y_axis + 100, range); // ����þ� cdf ��� // �����ϴ� �׷���

	for (int i = 1; i < range; i++)
	{
		Draw(normal_cdf[i] * 5, 30, y_axis + 100, i, GREEN);
	} // normal_cdf���

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
//�׷����� �ϱ� ���� �ʿ��� ��.
*/

/*
MoveToEx(hdc, A, B, NULL);
LineTo(hdc, C, D);
// (A,B)���� (C,D)���� ������ �׸���.
*/


#include <iostream>
#include <math.h>
#include <windows.h>

#pragma warning(disable : 4996)

using namespace std;

HWND hwnd;
HDC hdc;

void MemoryClear(UCHAR **buf) {
	if (buf) {
		free(buf[0]);
		free(buf);
		buf = NULL;
	}
}

UCHAR** memory_alloc2D(int width, int height) 
//malloc�Լ��� ���� ���� ����. �������� ����ŭ �޸𸮸� �����Ҵ�. �޸� ���� �Ҵ�� 0���� �ʱ�ȭ�� �޸� ������ ����.
{
	UCHAR** ppMem2D = 0;
	int	i;

	//arrary of pointer
	ppMem2D = (UCHAR**)calloc(sizeof(UCHAR*), height);
	if (ppMem2D == 0) {
		return 0;
	}

	*ppMem2D = (UCHAR*)calloc(sizeof(UCHAR), height * width);
	if ((*ppMem2D) == 0) {//free the memory of array of pointer        
		free(ppMem2D);
		return 0;
	}

	for (i = 1; i < height; i++) {
		ppMem2D[i] = ppMem2D[i - 1] + width;
	}

	return ppMem2D;
}

UCHAR** MakeHistogramEqualization(UCHAR** imgbuf, float histogram[256], float Equal_histogram[256], int width, int height)
{
	return 0;
}

void MakeHistogram(UCHAR** imgbuf, float histogram[256], int width, int height)
{
	for (int i = 0; i < width; i++)
	{
		for (int j = 0; j < height; j++)
		{
			histogram[imgbuf[i][j]] += 1;
		}
	}
}

void DrawCDF(float cdf[256], int x_origin, int y_origin) {
	for (int CurX = 0; CurX < 256; CurX++) {
		for (int CurY = 0; CurY < cdf[CurX]; CurY++) {
			MoveToEx(hdc, x_origin + CurX, y_origin, 0);
			SetPixel(hdc, x_origin + CurX, y_origin - cdf[CurX], RGB(0, 0, 255));
		}
	}
}

void DrawHistogram(float histogram[256], int x_origin, int y_origin) {
	MoveToEx(hdc, x_origin, y_origin, 0);
	LineTo(hdc, x_origin + 255, y_origin);

	MoveToEx(hdc, x_origin, 100, 0);
	LineTo(hdc, x_origin, y_origin);

	for (int CurX = 0; CurX < 256; CurX++) {
		for (int CurY = 0; CurY < histogram[CurX]; CurY++) {
			MoveToEx(hdc, x_origin + CurX, y_origin, 0);
			LineTo(hdc, x_origin + CurX, y_origin - histogram[CurX]);
		}
	}
}

int main(void)
{
	system("color F0");
	hwnd = GetForegroundWindow();
	hdc = GetWindowDC(hwnd);
	//window

	int width = 512;
	int height = 512;

	float Image_Histogram[256] = { 0, };
	float Image_equal_Histogram[256] = { 0, };
	float cdf[256] = { 0, };
	float normalized_cdf[256] = { 0, };

	FILE* fp_InputImg = fopen("gray\\barbara(512x512).raw", "rb"); // rb:bianry �б�.
	if (!fp_InputImg) {
		printf("Can not open file.");
	}

	UCHAR** Input_imgBuf = memory_alloc2D(width, height); // �޸� �����Ҵ�
	fread(&Input_imgBuf[0][0], sizeof(UCHAR), width * height, fp_InputImg); // 2���� �迭�� �̹��� �о����
	//fp_InputImg���� ������ ����� �о�´�
	//Input_imgBuf : �����͸� �о�� ����, sizeof �о�� ������ �ϳ��� ũ��,width*height:�о�� ������ ����, fp_InputImg:�Է����� ��Ʈ��.
	//��ȯ�� : �о�� ������ ����

	//printf("%d\n", &Input_imgBuf[0][1]);

	MakeHistogram(Input_imgBuf, Image_Histogram, width, height);
//	MakeHistogramEqualization(Input_imgBuf, Image_Histogram, Image_equal_Histogram, width, height);

	for (int i = 1; i < 256; i++)
	{
		cdf[i] = cdf[i - 1] + (Image_Histogram[i]); //���� ������׷�.
	}

	for (int i = 0; i < 256; i++)
	{
		normalized_cdf[i] = (cdf[i] / (float)(width*height)) * 255;
	}// ����ȭ�� ������׷�.

	UCHAR** Output_imgBuf = memory_alloc2D(width, height); // �޸� �����Ҵ�

	for (int i = 0; i < width; i++)
	{
		for (int j = 0; j < height; j++)
		{
			Output_imgBuf[i][j] = normalized_cdf[Input_imgBuf[i][j]];
			Image_equal_Histogram[Output_imgBuf[i][j]] += 1;
		}
	} //equalization�� ������׷�


	for (int i = 0; i < 256; i++)
	{
		Image_Histogram[i] = (Image_Histogram[i] / 50);
		Image_equal_Histogram[i] = Image_equal_Histogram[i] / 50;
		cdf[i] = cdf[i] / 2500;
	}
	//���� ���ֱ�

	DrawCDF(cdf, 30, 400); //������׷� cdf�׸���
	DrawHistogram(Image_Histogram, 30, 400); // ������׷� �׷���
	DrawHistogram(Image_equal_Histogram, 400, 400); // ������׷� ��Ȱȭ �׷���

	FILE* fp_outputImg = fopen("barbara.raw", "wb"); // ��� �����ϱ� // binary ����.
	fwrite(&Output_imgBuf[0][0], sizeof(UCHAR), width*height, fp_outputImg);

	//MemoryClear(Input_imgBuf);
	//MemoryClear(Histogram_imgBuf);
	fclose(fp_outputImg);
	fclose(fp_InputImg);
	return 0;
}

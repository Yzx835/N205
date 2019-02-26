#include "pch.h"
#include "ransac.h"
#include "SurfMatch.h"
#include<cstdlib>

double Nx[100010], Ny[100010], Nx_3[100010], Ny_3[100010];

int direct[9][2] = { {0, 1}, {0, -1}, {0, 0}, {1, 0}, {1, -1}, {1, 1}, {-1, 0}, {-1, 1}, {-1, -1} };

void paint_white(Mat img, double y, double x) {
	int row = img.rows;
	int col = img.cols;
	for (int i = 0; i < 9; i++)
		if ((int)x + direct[i][0] >= 0 && (int)x + direct[i][0] < row && (int)y + direct[i][1] >= 0 && (int)y + direct[i][1] < col) {
			img.at<Vec3b>((int)x + direct[i][0], (int)y + direct[i][1])[0] = 255;
			img.at<Vec3b>((int)x + direct[i][0], (int)y + direct[i][1])[1] = 255;
			img.at<Vec3b>((int)x + direct[i][0], (int)y + direct[i][1])[2] = 255;
		}
}

int TimeDomainChangeDetection(Mat srcImg1, Mat srcImg2, double Matrix[][3])
{
	//Mat tmpImg;
	//system("color 2F");
	//Mat srcImg1 = imread("E:\\5.jpg", 0);
	//Mat srcImg2 = imread("E:\\6.jpg", 0);
	int num = 0;
	//vector <KeyPoint> keypoints1, keypoints2;
	//if (!surf(srcImg1, keypoints1)) {
	//	cout << "error!!!" << endl;
	//}
	//if (!surf(srcImg2, keypoints2)) {
	//	cout << "error!!!" << endl;
	//}
	num = SurfMatch(srcImg1, srcImg2, Nx, Ny, Nx_3, Ny_3, num);
	if (num <= 0) {
		cout << "error!!!" << endl;
	}
	cout << endl;
	//int Matrix[3][3];
	memset(Matrix, 0, sizeof(Matrix));
	if (!ransac(num, Nx, Ny, Nx_3, Ny_3, Matrix)) {
		cout << "error" << endl;
	}
	imshow("SrcImg1", srcImg1);
	imshow("SrcImg2", srcImg2);
	for (int i = 0; i < num; i++) {
		paint_white(srcImg1, Nx[i], Ny[i]);
		double x_3, y_3;
		x_3 = Matrix[0][0] * Nx[i] + Matrix[0][1] * Ny[i] + Matrix[0][2];
		y_3 = Matrix[1][0] * Nx[i] + Matrix[1][1] * Ny[i] + Matrix[1][2];
		paint_white(srcImg2, x_3, y_3);
		cout << "aim x: " << Nx_3[i] << " act x: " << x_3 << " aim y : " << Ny_3[i] << " act y: " << y_3 << endl;
	}
	imshow("ChangedImg1", srcImg1);
	imshow("ChangedImg2", srcImg2);
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			cout << Matrix[i][j] << " ";
		}
		cout << endl;
	}
	waitKey(0);
	return 1;
}
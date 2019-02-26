// opencv_project.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include "pch.h"
#include "ransac.h"
#include "SurfMatch.h"
#include "TimeDomainChangeDetection.h"
/*#include<cstdlib>
#include<opencv2/core/core.hpp>
#include<opencv2/highgui/highgui.hpp>
#include<opencv2/xfeatures2d/nonfree.hpp>
#include<iostream>*

using namespace std;
using namespace cv;
using namespace cv::xfeatures2d;*/


int main()
{
	system("color 2F");
	Mat srcImg1 = imread("E:\\3.png", 1);
	Mat srcImg2 = imread("E:\\4.png", 1); 

	//int num = 0;
	//vector <KeyPoint> keypoints1, keypoints2;
	//if (!surf(srcImg1, keypoints1)) {
	//	cout << "error!!!" << endl;
	//}
	//if (!surf(srcImg2, keypoints2)) {
	//	cout << "error!!!" << endl;
	//}
	//if (!SurfMatch(srcImg1, srcImg2, Nx, Ny, Nx_3, Ny_3, num)) {
	//	cout << "error!!!" << endl;
	//}
	double Matrix[3][3];
	memset(Matrix, 0, sizeof(Matrix));
	if (!TimeDomainChangeDetection(srcImg1, srcImg2, Matrix)) 
		cout << "error" << endl;
	//for (int i = 0; i < 3; i++) {
    //    for (int j = 0; j < 3; j++) {
	//		cout << Matrix[i][j] << " ";
	//	}
	//	cout << endl;
	//}	
	return 0;
}

// 运行程序: Ctrl + F5 或调试 >“开始执行(不调试)”菜单 
// 调试程序: F5 或调试 >“开始调试”菜单

// 入门提示: 
//   1. 使用解决方案资源管理器窗口添加/管理文件
//   2. 使用团队资源管理器窗口连接到源代码管理
//   3. 使用输出窗口查看生成输出和其他消息
//   4. 使用错误列表窗口查看错误
//   5. 转到“项目”>“添加新项”以创建新的代码文件，或转到“项目”>“添加现有项”以将现有代码文件添加到项目
//   6. 将来，若要再次打开此项目，请转到“文件”>“打开”>“项目”并选择 .sln 文件

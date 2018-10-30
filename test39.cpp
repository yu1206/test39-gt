
#include <fstream>
#include <iostream>
#include <string>
#include <sstream> 
#include "opencv\cv.h"
#include "opencv\highgui.h"
#include "direct.h"
using namespace cv;
using namespace std;
int test39_ex(int argc, char *argv[])
{
	string imgpath = "G:/F/Traffic-signs/data/TrainIJCNN2013";
	string txtpath = "G:/F/Traffic-signs/data/TrainIJCNN2013/0ex.txt";
	string  drawpath = "G:/F/Traffic-signs/data/TrainIJCNN2013-draw";
	mkdir(drawpath.c_str());
	string  drawpathex = "G:/F/Traffic-signs/data/TrainIJCNN2013-draw/ex";
	mkdir(drawpathex.c_str());

	fstream finRead;
	finRead.open(txtpath, ios::in);
	if (!finRead.is_open())
	{
		cout << "finRead 文件数据打开错误！" << endl;
		system("pause");
		return false;
	}

	string line; int num = 0;
	while (getline(finRead, line))
	{
		num++;
		if (line.empty())
		{
			break;
		}

		cout << line.c_str() << endl;




		string name1; int x1, y1, x2, y2;
		stringstream str_s(line);
		str_s >> name1 >> x1 >> y1 >> x2 >> y2;


		string temp = imgpath + "/" + name1;

		Mat img = imread(temp.c_str());

		Point pt1, pt2;
		pt1.x = x1; pt1.y = y1; pt2.x = x2; pt2.y = y2;
		rectangle(img, pt1, pt2, Scalar(0, 0, 255));


		string path12 = drawpathex + "/" + name1;
		imwrite(path12.c_str(), img);



	}

	finRead.close();


	return 0;
}
int test39_gt(int argc, char *argv[])
{
	string imgpath = "G:/F/Traffic-signs/data/TrainIJCNN2013";
	string txtpath = "G:/F/Traffic-signs/data/TrainIJCNN2013/0gt.txt";
	string  drawpath = "G:/F/Traffic-signs/data/TrainIJCNN2013-draw";
	mkdir(drawpath.c_str());
	string  drawpathex = "G:/F/Traffic-signs/data/TrainIJCNN2013-draw/gt";
	mkdir(drawpathex.c_str());

	fstream finRead;
	finRead.open(txtpath, ios::in);
	if (!finRead.is_open())
	{
		cout << "finRead 文件数据打开错误！" << endl;
		system("pause");
		return false;
	}

	string line; int num = 0;
	while (getline(finRead, line))
	{
		num++;
		if (line.empty())
		{
			break;
		}

		cout << line.c_str() << endl;




		string name1; int x1, y1, x2, y2; string label;
		stringstream str_s(line);
		str_s >> name1 >> x1 >> y1 >> x2 >> y2>>label;


		string temp = imgpath + "/" + name1;

		Mat img = imread(temp.c_str());

		Point pt1, pt2;
		pt1.x = x1; pt1.y = y1; pt2.x = x2; pt2.y = y2;
		rectangle(img, pt1, pt2, Scalar(0, 0, 255));

		

		//设置绘制文本的相关参数
		string text = label;
		int font_face = cv::FONT_HERSHEY_COMPLEX;
		double font_scale = 2;
		int thickness = 2;
		int baseline;

		Size text_size = getTextSize(text, font_face, font_scale, thickness, &baseline);
		//将文本框居中绘制
		Point origin;
		origin.x =x1+5;
		origin.y = y1+5;
		putText(img, text, origin, font_face, font_scale, Scalar(0, 255, 255), thickness, 8, 0);

		




		string path12 = drawpathex + "/" + name1;
		imwrite(path12.c_str(), img);







	}

	finRead.close();


	return 0;
}
int test39(int argc, char *argv[])
{
	test39_ex(argc, argv);
	//test39_gt(argc, argv);
	return 0;
}
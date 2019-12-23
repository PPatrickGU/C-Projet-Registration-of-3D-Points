#include <iostream>
#include <string>
#include <pcl/io/pcd_io.h>
#include <pcl/io/ply_io.h>
#include <pcl/point_types.h>
#include <pcl/registration/icp.h>
#include <pcl/visualization/pcl_visualizer.h>//可视化头文件
#include <pcl/visualization/cloud_viewer.h>
#include <pcl/kdtree/kdtree_flann.h>
#include <time.h>
#include <fstream>
#include <iomanip>
#include <Eigen/Dense>//矩阵运算
#include <iostream>
#include <stdio.h>
#include "stdlib.h"
#include <tchar.h>



using namespace std;

bool next_iteration = false;

void print4x4Matrix(const Eigen::Matrix4d & matrix)    //打印旋转矩阵和平移矩阵
{
	printf("Rotation matrix :\n");
	printf("    | %6.3f %6.3f %6.3f | \n", matrix(0, 0), matrix(0, 1), matrix(0, 2));
	printf("R = | %6.3f %6.3f %6.3f | \n", matrix(1, 0), matrix(1, 1), matrix(1, 2));
	printf("    | %6.3f %6.3f %6.3f | \n", matrix(2, 0), matrix(2, 1), matrix(2, 2));
	printf("Translation vector :\n");
	printf("t = < %6.3f, %6.3f, %6.3f >\n\n", matrix(0, 3), matrix(1, 3), matrix(2, 3));
}

int main(int argc, char** argv)
{
	clock_t start, finish;
	double totaltime;

	// 创建点云指针
	pcl::PointCloud<pcl::PointXYZRGB>::Ptr cloud_in((new pcl::PointCloud<pcl::PointXYZRGB>));  // 原始点云
	pcl::PointCloud<pcl::PointXYZRGB>::Ptr cloud_tr((new pcl::PointCloud<pcl::PointXYZRGB>));  // 转换后的点云
	pcl::PointCloud<pcl::PointXYZRGB>::Ptr cloud_icp((new pcl::PointCloud<pcl::PointXYZRGB>));  // ICP 输出点云
	pcl::PointCloud<pcl::PointXYZRGB>::Ptr cloud_final((new pcl::PointCloud<pcl::PointXYZRGB>));  // ICP 输出点云


	start = clock();
	//读取ply文件	
	system("pause");

	if (pcl::io::loadPLYFile<pcl::PointXYZRGB>("E:\\graduating_design\\PCLTest\\PCDfiles_filtered\\11.ply", *cloud_in) == -1)//*打开点云文件
	{
		PCL_ERROR("Couldn't read file 11.ply\n");
		system("pause");
		return(-1);
	}
	finish = clock();
	totaltime = (double)(finish - start) / CLOCKS_PER_SEC;
	cout << "\nload 11.ply data : " << totaltime << "seconds!" << endl;

	system("pause");

	start = clock();
	if (pcl::io::loadPLYFile<pcl::PointXYZRGB>("E:\\graduating_design\\PCLTest\\PCDfiles_filtered\\21.ply", *cloud_icp) == -1)//*打开点云文件
	{
		PCL_ERROR("Couldn't read file 21.ply\n");
		system("pause");
		return(-1);
	}
	finish = clock();
	totaltime = (double)(finish - start) / CLOCKS_PER_SEC;
	cout << "\n load 21.ply data : " << totaltime << "seconds!" << endl;

	double array[4][4] = { 0.0 };//如果数据量过大 则需要把 array 定义成static类型，
	//因为默认的堆栈大小容量不够，可以放到静态存储区

	ifstream infile;//定义文件流对象

	infile.open("E:\\graduating_design\\PCLTest\\ICP_begin.txt");//打开文档

	//定义
	double* ptr = &array[0][0];
	while (!infile.eof())
	{
		infile >> *ptr;//这个是把文档里面的数对应在ptr位置的数值上
		ptr++;
	}

	infile.close();

	cout << "\nload ICP transformation original matix" << endl;
	system("pause");

	int iterations = 100;  // 默认的ICP迭代次数

	//定义旋转矩阵和平移向量Matrix4d是为4*4的矩阵
	Eigen::Matrix4d transformation_matrix = Eigen::Matrix4d::Identity();
	Eigen::Matrix4d total_transformation_matrix = Eigen::Matrix4d::Identity();

	//初始化
	//输入根据粗配准的刚体变化矩阵（见aln文件）
	for (int i = 0; i < 4; i++)
	{
		for (int j = 0; j < 4; j++)
		{
			transformation_matrix(i, j) = array[i][j];
		}
		cout << endl;
	}
	//左乘矩阵
	total_transformation_matrix = transformation_matrix * total_transformation_matrix;

	//打印转换矩阵
	std::cout << "Applying this rigid transformation to: cloud_in -> cloud_icp" << std::endl;
	//print4x4Matrix(transformation_matrix);

	// 执行点云转换
	*cloud_tr = *cloud_icp; //备份cloud_icp赋值给cloud_tr为后期使用
	pcl::transformPointCloud(*cloud_tr, *cloud_icp, transformation_matrix); //从cloud_tr通过转换矩阵进行转化，并存到cloud_icp里
	*cloud_tr = *cloud_icp;

	pcl::IterativeClosestPoint<pcl::PointXYZRGB, pcl::PointXYZRGB> icp; //创建ICP对象，用于ICP配准
	
	//icp配准
		icp.setMaximumIterations(100);    //设置最大迭代次数iterations=true
		icp.setInputCloud(cloud_icp); //设置输入点云
		icp.setInputTarget(cloud_in); //设置目标点云（输入点云进行仿射变换，得到目标点云）
		icp.align(*cloud_icp);          //匹配后源点云
		std::cout << "Applied " << iterations << " ICP iteration(s)" << std::endl;
		if (icp.hasConverged())//icp.hasConverged ()=1（true）输出变换矩阵的适合性评估
		{
			std::cout << "\nICP has converged, score is " << icp.getFitnessScore() << std::endl;
			std::cout << "\nICP transformation " << iterations << " : cloud_icp -> cloud_in" << std::endl;
			transformation_matrix = icp.getFinalTransformation().cast<double>();
			total_transformation_matrix = transformation_matrix * total_transformation_matrix;
			print4x4Matrix(total_transformation_matrix);
		}
		else
		{
			PCL_ERROR("\nICP has not converged.\n");
			return (-1);
		}

	//可视化
	pcl::visualization::PCLVisualizer viewer("ICP demo");
	// 创建两个观察视点
	int v1(0);
	int v2(1);
	viewer.createViewPort(0.0, 0.0, 0.5, 1.0, v1);
	viewer.createViewPort(0.5, 0.0, 1.0, 1.0, v2);

	// 定义显示的颜色信息
	float bckgr_gray_level = 0.0;  // Black
	float txt_gray_lvl = 1.0 - bckgr_gray_level;

	// 原始的点云设置为白色的
	pcl::visualization::PointCloudColorHandlerCustom<pcl::PointXYZRGB> cloud_in_color_h(cloud_in, (int)255 * txt_gray_lvl, (int)255 * txt_gray_lvl, (int)255 * txt_gray_lvl);

	viewer.addPointCloud(cloud_in, cloud_in_color_h, "cloud_in_v1", v1);//设置左边的原始的点云都是显示为白色
	viewer.addPointCloud(cloud_in, "cloud_in_v2", v2);

	/*
	viewer.addPointCloud(cloud_in, "cloud_in_v1",v1);
	viewer.addPointCloud(cloud_in, "cloud_in_v1", v2);
	*/

	// 转换后的点云显示为绿色
	pcl::visualization::PointCloudColorHandlerCustom<pcl::PointXYZRGB> cloud_tr_color_h(cloud_tr, 20, 180, 20);
	viewer.addPointCloud(cloud_tr, cloud_tr_color_h, "cloud_tr_v1", v1);

	// ICP配准后的点云为红色
	//pcl::visualization::PointCloudColorHandlerCustom<pcl::PointXYZRGB> cloud_icp_color_h(cloud_icp, 180, 20, 20);
	viewer.addPointCloud(cloud_icp, "cloud_icp_v2", v2);

	// 加入文本的描述在各自的视口界面
	//在指定视口viewport=v1添加字符串“white 。。。”其中"icp_info_1"是添加字符串的ID标志，（10，15）为坐标16为字符大小 后面分别是RGB值
	viewer.addText("White: Original point cloud \n Green: Matrix transformed point cloud", 10, 15, 16, txt_gray_lvl, txt_gray_lvl, txt_gray_lvl, "icp_info_1", v1);
	viewer.addText("  Original point cloud \n  ICP aligned point cloud", 10, 15, 16, txt_gray_lvl, txt_gray_lvl, txt_gray_lvl, "icp_info_2", v2);

	std::stringstream ss;
	ss << iterations;            //输入的迭代的次数
	std::string iterations_cnt = "ICP iterations = " + ss.str();
	viewer.addText(iterations_cnt, 10, 60, 16, txt_gray_lvl, txt_gray_lvl, txt_gray_lvl, "iterations_cnt", v2);

	// 设置背景颜色
	viewer.setBackgroundColor(bckgr_gray_level, bckgr_gray_level, bckgr_gray_level, v1);
	viewer.setBackgroundColor(bckgr_gray_level, bckgr_gray_level, bckgr_gray_level, v2);

	// 设置相机的坐标和方向
	//viewer.setCameraPosition(-3.68332, 2.94092, 5.71266, 0.289847, 0.921947, -0.256907, 0);
	viewer.setCameraPosition(
		0, 0, 0,
		0, 0, -1,
		0, 0, 0, v2);
	viewer.setSize(1240, 600);  // 可视化窗口的大小

	// 注册按键回调函数
	//viewer.registerKeyboardCallback(&KeyboardEventOccurred, (void*)NULL);

	//显示
	while (!viewer.wasStopped())
	{
		viewer.spinOnce();

		next_iteration = false;

		std::ofstream outfile("E:\\graduating_design\\PCLTest\\total_transformation_matrix.txt", std::ios::ate);

		if (outfile.is_open())
		{
			for (int i = 0; i< 4; i++)
			{
				for (int j = 0; j < 4; j++)
				{
					outfile << total_transformation_matrix(i, j) << " ";
				}
				outfile << "\n";
				// 会换行
			}
		}
		else
		{
			std::cout << "没有写入成功！" << std::endl;
		}

		*cloud_final = *cloud_in + *cloud_icp;//点云合并
		pcl::io::savePLYFile("E:\\graduating_design\\PCLTest\\cloud_final.ply", *cloud_final);

	}

	//ate，如果没有这个文件，会自动创建，如果有就清空
	//盘符后面一定是双斜杠  \\ 

	system("pause");
	return 0;

}

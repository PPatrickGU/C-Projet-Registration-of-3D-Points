#include <iostream>
#include <string>
#include <pcl/io/pcd_io.h>
#include <pcl/io/ply_io.h>
#include <pcl/point_types.h>
#include <pcl/registration/icp.h>
#include <pcl/visualization/pcl_visualizer.h>//���ӻ�ͷ�ļ�
#include <pcl/visualization/cloud_viewer.h>
#include <pcl/kdtree/kdtree_flann.h>
#include <time.h>
#include <fstream>
#include <iomanip>
#include <Eigen/Dense>//��������
#include <iostream>
#include <stdio.h>
#include "stdlib.h"
#include <tchar.h>



using namespace std;

bool next_iteration = false;

void print4x4Matrix(const Eigen::Matrix4d & matrix)    //��ӡ��ת�����ƽ�ƾ���
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

	// ��������ָ��
	pcl::PointCloud<pcl::PointXYZRGB>::Ptr cloud_in((new pcl::PointCloud<pcl::PointXYZRGB>));  // ԭʼ����
	pcl::PointCloud<pcl::PointXYZRGB>::Ptr cloud_tr((new pcl::PointCloud<pcl::PointXYZRGB>));  // ת����ĵ���
	pcl::PointCloud<pcl::PointXYZRGB>::Ptr cloud_icp((new pcl::PointCloud<pcl::PointXYZRGB>));  // ICP �������
	pcl::PointCloud<pcl::PointXYZRGB>::Ptr cloud_final((new pcl::PointCloud<pcl::PointXYZRGB>));  // ICP �������


	start = clock();
	//��ȡply�ļ�	
	system("pause");

	if (pcl::io::loadPLYFile<pcl::PointXYZRGB>("E:\\graduating_design\\PCLTest\\PCDfiles_filtered\\11.ply", *cloud_in) == -1)//*�򿪵����ļ�
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
	if (pcl::io::loadPLYFile<pcl::PointXYZRGB>("E:\\graduating_design\\PCLTest\\PCDfiles_filtered\\21.ply", *cloud_icp) == -1)//*�򿪵����ļ�
	{
		PCL_ERROR("Couldn't read file 21.ply\n");
		system("pause");
		return(-1);
	}
	finish = clock();
	totaltime = (double)(finish - start) / CLOCKS_PER_SEC;
	cout << "\n load 21.ply data : " << totaltime << "seconds!" << endl;

	double array[4][4] = { 0.0 };//������������� ����Ҫ�� array �����static���ͣ�
	//��ΪĬ�ϵĶ�ջ��С�������������Էŵ���̬�洢��

	ifstream infile;//�����ļ�������

	infile.open("E:\\graduating_design\\PCLTest\\ICP_begin.txt");//���ĵ�

	//����
	double* ptr = &array[0][0];
	while (!infile.eof())
	{
		infile >> *ptr;//����ǰ��ĵ����������Ӧ��ptrλ�õ���ֵ��
		ptr++;
	}

	infile.close();

	cout << "\nload ICP transformation original matix" << endl;
	system("pause");

	int iterations = 100;  // Ĭ�ϵ�ICP��������

	//������ת�����ƽ������Matrix4d��Ϊ4*4�ľ���
	Eigen::Matrix4d transformation_matrix = Eigen::Matrix4d::Identity();
	Eigen::Matrix4d total_transformation_matrix = Eigen::Matrix4d::Identity();

	//��ʼ��
	//������ݴ���׼�ĸ���仯���󣨼�aln�ļ���
	for (int i = 0; i < 4; i++)
	{
		for (int j = 0; j < 4; j++)
		{
			transformation_matrix(i, j) = array[i][j];
		}
		cout << endl;
	}
	//��˾���
	total_transformation_matrix = transformation_matrix * total_transformation_matrix;

	//��ӡת������
	std::cout << "Applying this rigid transformation to: cloud_in -> cloud_icp" << std::endl;
	//print4x4Matrix(transformation_matrix);

	// ִ�е���ת��
	*cloud_tr = *cloud_icp; //����cloud_icp��ֵ��cloud_trΪ����ʹ��
	pcl::transformPointCloud(*cloud_tr, *cloud_icp, transformation_matrix); //��cloud_trͨ��ת���������ת�������浽cloud_icp��
	*cloud_tr = *cloud_icp;

	pcl::IterativeClosestPoint<pcl::PointXYZRGB, pcl::PointXYZRGB> icp; //����ICP��������ICP��׼
	
	//icp��׼
		icp.setMaximumIterations(100);    //��������������iterations=true
		icp.setInputCloud(cloud_icp); //�����������
		icp.setInputTarget(cloud_in); //����Ŀ����ƣ�������ƽ��з���任���õ�Ŀ����ƣ�
		icp.align(*cloud_icp);          //ƥ���Դ����
		std::cout << "Applied " << iterations << " ICP iteration(s)" << std::endl;
		if (icp.hasConverged())//icp.hasConverged ()=1��true������任������ʺ�������
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

	//���ӻ�
	pcl::visualization::PCLVisualizer viewer("ICP demo");
	// ���������۲��ӵ�
	int v1(0);
	int v2(1);
	viewer.createViewPort(0.0, 0.0, 0.5, 1.0, v1);
	viewer.createViewPort(0.5, 0.0, 1.0, 1.0, v2);

	// ������ʾ����ɫ��Ϣ
	float bckgr_gray_level = 0.0;  // Black
	float txt_gray_lvl = 1.0 - bckgr_gray_level;

	// ԭʼ�ĵ�������Ϊ��ɫ��
	pcl::visualization::PointCloudColorHandlerCustom<pcl::PointXYZRGB> cloud_in_color_h(cloud_in, (int)255 * txt_gray_lvl, (int)255 * txt_gray_lvl, (int)255 * txt_gray_lvl);

	viewer.addPointCloud(cloud_in, cloud_in_color_h, "cloud_in_v1", v1);//������ߵ�ԭʼ�ĵ��ƶ�����ʾΪ��ɫ
	viewer.addPointCloud(cloud_in, "cloud_in_v2", v2);

	/*
	viewer.addPointCloud(cloud_in, "cloud_in_v1",v1);
	viewer.addPointCloud(cloud_in, "cloud_in_v1", v2);
	*/

	// ת����ĵ�����ʾΪ��ɫ
	pcl::visualization::PointCloudColorHandlerCustom<pcl::PointXYZRGB> cloud_tr_color_h(cloud_tr, 20, 180, 20);
	viewer.addPointCloud(cloud_tr, cloud_tr_color_h, "cloud_tr_v1", v1);

	// ICP��׼��ĵ���Ϊ��ɫ
	//pcl::visualization::PointCloudColorHandlerCustom<pcl::PointXYZRGB> cloud_icp_color_h(cloud_icp, 180, 20, 20);
	viewer.addPointCloud(cloud_icp, "cloud_icp_v2", v2);

	// �����ı��������ڸ��Ե��ӿڽ���
	//��ָ���ӿ�viewport=v1����ַ�����white ������������"icp_info_1"������ַ�����ID��־����10��15��Ϊ����16Ϊ�ַ���С ����ֱ���RGBֵ
	viewer.addText("White: Original point cloud \n Green: Matrix transformed point cloud", 10, 15, 16, txt_gray_lvl, txt_gray_lvl, txt_gray_lvl, "icp_info_1", v1);
	viewer.addText("  Original point cloud \n  ICP aligned point cloud", 10, 15, 16, txt_gray_lvl, txt_gray_lvl, txt_gray_lvl, "icp_info_2", v2);

	std::stringstream ss;
	ss << iterations;            //����ĵ����Ĵ���
	std::string iterations_cnt = "ICP iterations = " + ss.str();
	viewer.addText(iterations_cnt, 10, 60, 16, txt_gray_lvl, txt_gray_lvl, txt_gray_lvl, "iterations_cnt", v2);

	// ���ñ�����ɫ
	viewer.setBackgroundColor(bckgr_gray_level, bckgr_gray_level, bckgr_gray_level, v1);
	viewer.setBackgroundColor(bckgr_gray_level, bckgr_gray_level, bckgr_gray_level, v2);

	// �������������ͷ���
	//viewer.setCameraPosition(-3.68332, 2.94092, 5.71266, 0.289847, 0.921947, -0.256907, 0);
	viewer.setCameraPosition(
		0, 0, 0,
		0, 0, -1,
		0, 0, 0, v2);
	viewer.setSize(1240, 600);  // ���ӻ����ڵĴ�С

	// ע�ᰴ���ص�����
	//viewer.registerKeyboardCallback(&KeyboardEventOccurred, (void*)NULL);

	//��ʾ
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
				// �ỻ��
			}
		}
		else
		{
			std::cout << "û��д��ɹ���" << std::endl;
		}

		*cloud_final = *cloud_in + *cloud_icp;//���ƺϲ�
		pcl::io::savePLYFile("E:\\graduating_design\\PCLTest\\cloud_final.ply", *cloud_final);

	}

	//ate�����û������ļ������Զ�����������о����
	//�̷�����һ����˫б��  \\ 

	system("pause");
	return 0;

}

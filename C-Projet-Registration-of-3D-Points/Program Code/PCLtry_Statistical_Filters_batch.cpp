#include <iostream>
#include <string>
#include <sstream>
#include <pcl/io/pcd_io.h>
#include <pcl/io/ply_io.h>
#include <pcl/point_types.h>
#include <pcl/point_cloud.h>
#include <pcl/common/io.h>
#include <pcl/filters/statistical_outlier_removal.h>
#include <pcl/visualization/cloud_viewer.h>
#include <pcl/visualization/pcl_visualizer.h>

using namespace pcl;
using namespace pcl::io;

int main(int argc, char** argv)
{
	pcl::PointCloud<pcl::PointXYZRGB>::Ptr cloud(new pcl::PointCloud<pcl::PointXYZRGB>);
	pcl::PointCloud<pcl::PointXYZRGB>::Ptr cloud_inliner(new pcl::PointCloud<pcl::PointXYZRGB>);
	pcl::PointCloud<pcl::PointXYZRGB>::Ptr cloud_outliner(new pcl::PointCloud<pcl::PointXYZRGB>);
	// Fill in the cloud data

	pcl::PLYReader reader;

	system("pause");

	reader.read<pcl::PointXYZRGB>("E:\\graduating_design\\PCLTest\\PLYfiles\\1.ply", *cloud);

	system("pause");

	std::cerr << "Cloud1 before filtering: " << std::endl;
	std::cerr << *cloud << std::endl;

	// Create the filtering object
	pcl::StatisticalOutlierRemoval<pcl::PointXYZRGB> sor;
	sor.setInputCloud(cloud);
	sor.setMeanK(50);//50个临近点
	sor.setStddevMulThresh(1.0);//距离大于1倍标准方差

	sor.filter(*cloud_inliner);

	std::cerr << "Cloud1 after filtering: " << std::endl;
	std::cerr << *cloud_inliner << std::endl;

	//	pcl::PCDWriter writer;
	//	writer.write<pcl::PointXYZRGB>("E:\\graduating_design\\PCLTest\\PCDfiles_filtered\\test_pcda_inliers.pcd", *cloud_inliner, false);
	pcl::io::savePLYFile("E:\\graduating_design\\PCLTest\\PCDfiles_filtered\\11.ply", *cloud_inliner);
	sor.setNegative(true);
	sor.filter(*cloud_outliner);
	pcl::io::savePLYFile("E:\\graduating_design\\PCLTest\\PCDfiles_filtered\\12.ply", *cloud_outliner);

	pcl::PointCloud<pcl::PointXYZRGB>::Ptr cloud1(new pcl::PointCloud<pcl::PointXYZRGB>);
	pcl::PointCloud<pcl::PointXYZRGB>::Ptr cloud_inliner1(new pcl::PointCloud<pcl::PointXYZRGB>);
	pcl::PointCloud<pcl::PointXYZRGB>::Ptr cloud_outliner1(new pcl::PointCloud<pcl::PointXYZRGB>);

	reader.read<pcl::PointXYZRGB>("E:\\graduating_design\\PCLTest\\PLYfiles\\2.ply", *cloud1);

	system("pause");

	std::cerr << "Cloud2 before filtering: " << std::endl;
	std::cerr << *cloud1 << std::endl;

	// Create the filtering object
	pcl::StatisticalOutlierRemoval<pcl::PointXYZRGB> sor1;
	sor1.setInputCloud(cloud1);
	sor1.setMeanK(50);//50个临近点
	sor1.setStddevMulThresh(1.0);//距离大于1倍标准方差

	sor1.filter(*cloud_inliner1);

	std::cerr << "Cloud2 after filtering: " << std::endl;
	std::cerr << *cloud_inliner1 << std::endl;

	//	pcl::PCDWriter writer;
	//	writer.write<pcl::PointXYZRGB>("C:\\Users\\qiong\\Desktop\\PCLTest\\PCDfiles_filtered\\test_pcda_inliers.pcd", *cloud_inliner, false);
	pcl::io::savePLYFile("E:\\graduating_design\\PCLTest\\PCDfiles_filtered\\21.ply", *cloud_inliner1);
	sor1.setNegative(true);
	sor1.filter(*cloud_outliner1);
	pcl::io::savePLYFile("E:\\graduating_design\\PCLTest\\PCDfiles_filtered\\22.ply", *cloud_outliner1);



	std::cerr << "\nPLYfiles have been created : \n\nPresentation of the effect of filters" << std::endl;

	system("pause");
	return (0);



}

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

	std::cerr << "Cloud before filtering: " << std::endl;
	std::cerr << *cloud << std::endl;

	// Create the filtering object
	pcl::StatisticalOutlierRemoval<pcl::PointXYZRGB> sor;
	sor.setInputCloud(cloud);
	sor.setMeanK(50);//50个临近点
	sor.setStddevMulThresh(1.0);//距离大于1倍标准方差

	sor.filter(*cloud_inliner);

	std::cerr << "Cloud after filtering: " << std::endl;
	std::cerr << *cloud_inliner << std::endl;

	//	pcl::PCDWriter writer;
	//	writer.write<pcl::PointXYZRGB>("C:\\Users\\qiong\\Desktop\\PCLTest\\PCDfiles_filtered\\test_pcda_inliers.pcd", *cloud_inliner, false);
	pcl::io::savePLYFile("E:\\graduating_design\\PCLTest\\PCDfiles_filtered\\11.ply", *cloud_inliner);
	sor.setNegative(true);
	sor.filter(*cloud_outliner);
	pcl::io::savePLYFile("E:\\graduating_design\\PCLTest\\PCDfiles_filtered\\12.ply", *cloud_outliner);


	std::cerr << "\nPLYfiles have been created : \n\nPresentation of the effect of filters" << std::endl;

	system("pause");

	pcl::visualization::PCLVisualizer viewer("Filter");

	int v1(0);
	int v2(1);
	viewer.createViewPort(0.0, 0.0, 1.0, 1.0, v1);
	// The color we will be using
	float bckgr_gray_level = 0.0;  // Black
	float txt_gray_lvl = 1.0 - bckgr_gray_level;

	// Original point cloud is white
	pcl::visualization::PointCloudColorHandlerCustom<pcl::PointXYZRGB> cloud_in_color_h(cloud, (int)255 * txt_gray_lvl, (int)255 * txt_gray_lvl, (int)255 * txt_gray_lvl);
	viewer.addPointCloud(cloud_inliner, "cloud_in_v1", v1);       //viewer.addPointCloud(cloud_in, cloud_in_color_h, "cloud_in_v2", v2);
//	pcl::visualization::PointCloudColorHandlerCustom<pcl::PointXYZRGB> cloud_out_green(cloud_after_Condition, 20, 180, 20);
	//	viewer.addPointCloud(cloud_after_Condition, cloud_out_green, "cloud_out", v1);

	viewer.setBackgroundColor(bckgr_gray_level, bckgr_gray_level, bckgr_gray_level, v1);
	//  viewer.setBackgroundColor(bckgr_gray_level, bckgr_gray_level, bckgr_gray_level, v2);     
	viewer.setSize(1000, 650);  // Visualiser window size
	//viewer.showCloud(cloud_out);
	while (!viewer.wasStopped())
	{
		viewer.spinOnce();
	}

	system("pause");
	return (0);



}

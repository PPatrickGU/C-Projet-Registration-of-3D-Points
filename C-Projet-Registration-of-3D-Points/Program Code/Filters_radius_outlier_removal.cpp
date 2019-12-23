#include<iostream>
#include <string>
#include <sstream>
#include <pcl/io/pcd_io.h>
#include <pcl/io/ply_io.h>
#include <pcl/point_cloud.h>
#include <pcl/common/io.h>
#include <pcl/visualization/cloud_viewer.h>
#include <pcl/visualization/pcl_visualizer.h>
#include<pcl/point_types.h>
#include <pcl/filters/radius_outlier_removal.h>   //半径滤波器头文件

using namespace pcl;
using namespace pcl::io;

int main(int argc, char** argv)
{
	pcl::PointCloud<pcl::PointXYZRGB>::Ptr cloud(new pcl::PointCloud<pcl::PointXYZRGB>);
	pcl::PointCloud<pcl::PointXYZRGB>::Ptr cloud_after_Radius(new pcl::PointCloud<pcl::PointXYZRGB>);//
	
	// Fill in the cloud data
	pcl::PLYReader reader;
	reader.read<pcl::PointXYZRGB>("E:\\graduating_design\\PCLTest\\PLYfiles\\1.ply", *cloud);

	std::cout << "Cloud before filtering: " << std::endl;
	std::cout << *cloud << std::endl;

	///////****************************************************////////////////////
	/*半径滤波器*/

	pcl::RadiusOutlierRemoval<pcl::PointXYZRGB> radiusoutlier;  //创建滤波器

	radiusoutlier.setInputCloud(cloud);    //设置输入点云
	radiusoutlier.setRadiusSearch(10);     //设置半径为100的范围内找临近点
	radiusoutlier.setMinNeighborsInRadius(2); //设置查询点的邻域点集数小于2的删除

	radiusoutlier.filter(*cloud_after_Radius);
	std::cout << "半径滤波后点云数据点数：" << cloud_after_Radius->points.size() << std::endl;


	pcl::io::savePCDFile("E:\\graduating_design\\PCLTest\\PCDfiles_filtered\\cloud_after_Radius.pcd", *cloud_after_Radius);

	std::cout << "\nPCD files have been created : \n\nPresentation of the effect of filters" << std::endl;

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
	viewer.addPointCloud(cloud, cloud_in_color_h, "cloud_in_v1", v1);       //viewer.addPointCloud(cloud_in, cloud_in_color_h, "cloud_in_v2", v2);
	pcl::visualization::PointCloudColorHandlerCustom<pcl::PointXYZRGB> cloud_out_green(cloud_after_Radius, 20, 180, 20);
	viewer.addPointCloud(cloud_after_Radius, cloud_out_green, "cloud_out", v1);

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
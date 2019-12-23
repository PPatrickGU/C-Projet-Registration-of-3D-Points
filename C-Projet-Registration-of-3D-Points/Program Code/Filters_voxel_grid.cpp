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
#include<pcl/filters/voxel_grid.h>  //体素滤波器头文件

using namespace pcl;
using namespace pcl::io;

int main(int argc, char** argv)
{
	pcl::PointCloud<pcl::PointXYZRGB>::Ptr cloud(new pcl::PointCloud<pcl::PointXYZRGB>);
	pcl::PointCloud<pcl::PointXYZRGB>::Ptr cloud_after_voxelgrid(new pcl::PointCloud<pcl::PointXYZRGB>);//

	// Fill in the cloud data
	pcl::PLYReader reader;
	reader.read<pcl::PointXYZRGB>("E:\\graduating_design\\PCLTest\\PLYfiles\\1.ply", *cloud);

	std::cout << "Cloud before filtering: " << std::endl;
	std::cout << *cloud << std::endl;

	///////****************************************************////////////////////
	/*体素滤波器对点云进行处理。*/

	pcl::VoxelGrid<pcl::PointXYZRGB> voxelgrid;
	voxelgrid.setInputCloud(cloud);//输入点云数据
	voxelgrid.setLeafSize(1.0f, 1.0f, 1.0f);//AABB长宽高
	voxelgrid.filter(*cloud_after_voxelgrid);


	std::cout << "体素滤波后点云数据点数：" << cloud_after_voxelgrid->points.size() << std::endl;

	pcl::io::savePCDFile("E:\\graduating_design\\PCLTest\\PCDfiles_filtered\\cloud_after_voxelgrid.pcd", *cloud_after_voxelgrid);

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
	pcl::visualization::PointCloudColorHandlerCustom<pcl::PointXYZRGB> cloud_out_green(cloud_after_voxelgrid, 20, 180, 20);
	viewer.addPointCloud(cloud_after_voxelgrid, cloud_out_green, "cloud_out", v1);

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
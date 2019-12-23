#include <iostream>
#include <string>
#include <sstream>
#include <pcl/common/io.h>
#include <pcl/point_cloud.h>
#include <pcl/point_types.h>
#include <pcl/io/pcd_io.h>
#include <pcl/io/ply_io.h>
#include <pcl/point_types.h>

using namespace pcl;
using namespace pcl::io;

int main(int argc, char** argv)
{
	pcl::PLYReader reader;
	pcl::PointCloud<pcl::PointXYZRGB>::Ptr cloud(new pcl::PointCloud<pcl::PointXYZRGB>);
	reader.read<pcl::PointXYZRGB>("E:\\graduating_design\\PCLTest\\PLYfiles\\1.ply", *cloud);
	pcl::io::savePCDFile("E:\\graduating_design\\PCLTest\\PCDfiles_before_filtered\\test_pcda.pcd", *cloud);
	reader.read<pcl::PointXYZRGB>("E:\\graduating_design\\PCLTest\\PLYfiles\\2.ply", *cloud);
	pcl::io::savePCDFile("E:\\graduating_design\\PCLTest\\PCDfiles_before_filtered\\test_pcdb.pcd", *cloud);
	
	std::cout << "\n test_pcda.pcd and test_pcdb.pcd have been created! " << std::endl;

	system("pause ");
	return 0;
}

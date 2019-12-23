#include <iostream> 
#include <pcl/io/pcd_io.h> 
#include <pcl/point_types.h> 
#include <pcl/io/ply_io.h>
#include <pcl/visualization/pcl_visualizer.h>


int main(int argc, char** argv)
{
	pcl::PointCloud<pcl::PointXYZRGB>::Ptr cloud(new pcl::PointCloud<pcl::PointXYZRGB>);

	if (pcl::io::loadPLYFile<pcl::PointXYZRGB>("E:\\graduating_design\\PCLTest\\PLYfiles\\1.ply", *cloud) == -1) //* load the file 
	{
		PCL_ERROR("Couldn't read file 1.ply \n");
		system("PAUSE");
		return (-1);
	}
	
	pcl::visualization::PCLVisualizer viewer("PointCloud viewer");
	int v1(0);
	int v2(1);
	viewer.createViewPort(0.0, 0, 1.0, 1.0,v1);
	//viewer.createViewPort(0.5, 0, 1.0, 1.0, v2);
	viewer.setBackgroundColor(0, 0, 0,v1); //����ɫ��ɫ��Ϊ�˿��ӻ������������ɫ�ή����ɫ���� 
	//viewer.setBackgroundColor(0, 0, 0, v2);
	viewer.addPointCloud<pcl::PointXYZRGB>(cloud, "PointCloud viewer",v1);
//	viewer.addPointCloud<pcl::PointXYZRGB>(cloud, "PointCloud viewer", v2);
	viewer.setSize(1000, 650);  // ���ӻ����ڵĴ�С
	viewer.spin();//���б����У���Ȼ������ʾ����
	system("PAUSE");
	return (0);
}
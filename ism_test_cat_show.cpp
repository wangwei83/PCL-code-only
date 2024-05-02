//数据可视化
#include<iostream>
#include<pcl/io/pcd_io.h>
#include<pcl/point_types.h>
#include <pcl/visualization/cloud_viewer.h>

void viewerOneOff(pcl::visualization::PCLVisualizer& viewer)    //设置背景颜色
{
	viewer.setBackgroundColor(1.0f, 0.5f, 1.0f);
}

int main(int argc, char** argv)
{
	pcl::PointCloud<pcl::PointXYZ>::Ptr cloud(new pcl::PointCloud<pcl::PointXYZ>);

	//打开点云文件
	if (pcl::io::loadPCDFile<pcl::PointXYZ>("C://ism_test_cat.pcd", *cloud) == -1)
		//根据自己pcd文件的路径进行添加
	{
		PCL_ERROR("Couldn't read file rabbit.pcd\n");
		return(-1);
	}
	std::cout << cloud->points.size() << std::endl;   //points.size() 表示数据的大小也就是说点云文件中多少个点
	pcl::visualization::CloudViewer viewer("cloud viewer");  //showCloud 函数是同步的，在此处等待直到渲染显示为止
	viewer.showCloud(cloud);    //该注册函数在可视化时只调用一次

	viewer.runOnVisualizationThreadOnce(viewerOneOff);   //该注册函数在渲染输出是每次都调用

	while (!viewer.wasStopped())
	{

	}
	system("pause");
	return 0;
}
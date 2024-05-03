//https://blog.csdn.net/Small_Munich/article/details/106576902  【pcl入门教程滤波系列】之passThrough滤波
//https://github.com/halostorm/pointCloud_ground_detection/blob/master/16line.pcd  数据集
#include <iostream>
#include <pcl/io/pcd_io.h>
#include <pcl/point_types.h>
#include <pcl/filters/passthrough.h>

int main(int argc, char** argv)
{
	pcl::PointCloud<pcl::PointXYZ>::Ptr cloud(new pcl::PointCloud<pcl::PointXYZ>);
	pcl::PointCloud<pcl::PointXYZ>::Ptr cloud_filtered(new pcl::PointCloud<pcl::PointXYZ>);

	// Fill in the cloud data
	pcl::PCDReader reader;
	reader.read("16line.pcd", *cloud);
	std::cerr << "Cloud before filtering: " << cloud->points.size() << std::endl;
	// Create the filtering object
	pcl::PassThrough<pcl::PointXYZ> pass; // 声明直通滤波
	pass.setInputCloud(cloud); // 传入点云数据
	pass.setFilterFieldName("z"); // 设置操作的坐标轴
	pass.setFilterLimits(0.0, 3.0); // 设置坐标范围
	// pass.setFilterLimitsNegative(true); // 保留数据函数
	pass.filter(*cloud_filtered);  // 进行滤波输出

	std::cerr << "Cloud after filtering: " << cloud_filtered->points.size() << std::endl;

	// save filterd data 
	pcl::PCDWriter writer;
	writer.write("16line_filtered.pcd", *cloud_filtered, false);

	return 0;
}

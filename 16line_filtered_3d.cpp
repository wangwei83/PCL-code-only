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

	pcl::PointCloud<pcl::PointXYZ>::Ptr cloud_filtered2(new pcl::PointCloud<pcl::PointXYZ>);
	pcl::PointCloud<pcl::PointXYZ>::Ptr cloud_filtered3(new pcl::PointCloud<pcl::PointXYZ>);

	// Create the filtering object
	pcl::PassThrough<pcl::PointXYZ> pass;
	pass.setInputCloud(cloud);
	pass.setFilterFieldName("x");
	pass.setFilterLimits(-5.0, 5.0);
	// pass.setFilterLimitsNegative(true);
	pass.filter(*cloud_filtered2);
	// filter range Y-axis
	pass.setInputCloud(cloud_filtered2);
	pass.setFilterFieldName("y");
	pass.setFilterLimits(-5.0, 5.0);
	pass.filter(*cloud_filtered3);
	// filter range Z-axis
	pass.setInputCloud(cloud_filtered3);
	pass.setFilterFieldName("z");
	pass.setFilterLimits(-0.5, 3.0);
	pass.filter(*cloud_filtered);

	std::cerr << "Cloud after filtering: " << cloud_filtered->points.size() << std::endl;

	// save filterd data 
	pcl::PCDWriter writer;
	writer.write("16line_filtered_3d.pcd", *cloud_filtered, false);

	return 0;
}

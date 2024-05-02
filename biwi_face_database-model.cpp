#include <iostream>
#include <pcl/io/pcd_io.h>
#include <pcl/point_types.h>
#include <pcl/visualization/cloud_viewer.h>

void viewerOneOff(pcl::visualization::PCLVisualizer& viewer)
{
	viewer.setBackgroundColor(1, 0.5, 1);
}

int main(int argc, char** argv)
{
	pcl::PointCloud<pcl::PointXYZ>::Ptr cloud(new pcl::PointCloud<pcl::PointXYZ>);

	if (pcl::io::loadPCDFile<pcl::PointXYZ>("C://Users//19002//Desktop//data//biwi_face_database//model.pcd", *cloud) == -1)
	{
		return -1;
	}
	
	std::cout << cloud->points.size() << std::endl;

	pcl::visualization::CloudViewer viewer("cloud viewer");

	viewer.showCloud(cloud);
	viewer.runOnVisualizationThreadOnce(viewerOneOff);

	while (!viewer.wasStopped())
	{

	}
	system("pause");
	return 0;
}
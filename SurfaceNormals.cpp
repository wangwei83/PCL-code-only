#include <iostream>
#include <pcl/io/pcd_io.h>
#include <pcl/point_types.h>
#include <pcl/features/normal_3d.h>
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


	// Create the normal estimation class, and pass the input dataset to it
	pcl::NormalEstimation<pcl::PointXYZ, pcl::Normal> ne;
	ne.setInputCloud(cloud);

	// Create an empty kdtree representation, and pass it to the normal estimation object.
    // Its content will be filled inside the object, based on the given input dataset (as no other search surface is given).
	pcl::search::KdTree<pcl::PointXYZ>::Ptr tree(new pcl::search::KdTree<pcl::PointXYZ>());
	ne.setSearchMethod(tree);

	// Output datasets
	pcl::PointCloud<pcl::Normal>::Ptr cloud_normals(new pcl::PointCloud<pcl::Normal>);

	// Compute the features
	ne.compute(*cloud_normals);

	// Use all neighbors in a sphere of radius 3cm
	ne.setRadiusSearch(0.03);


	pcl::visualization::CloudViewer viewer("cloud viewer");

	viewer.showCloud(cloud);
	viewer.runOnVisualizationThreadOnce(viewerOneOff);

	while (!viewer.wasStopped())
	{

	}
	system("pause");
	return 0;
}
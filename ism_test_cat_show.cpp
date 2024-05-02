//��ʾ���ݣ�������һ�£�����ͬ��������һ�����Խ��б���
/*
#include<iostream>
#include<pcl/io/pcd_io.h>
#include<pcl/point_types.h>

int main(int argc, char** argv)   //����ʱ�������д��ڴ���������
{
	//������һ����Ϊcloud��ָ�룬����XYZ���͵ĵ�������
	pcl::PointCloud<pcl::PointXYZ>::Ptr cloud(new pcl::PointCloud<pcl::PointXYZ>);

	//
	//*�򿪵����ļ�
	if (pcl::io::loadPCDFile<pcl::PointXYZ>("C://Users//Administrator//Desktop//test1//Project2//rabbit.pcd", *cloud) == -1)  //��һ���ļ�������д�����ֵ-1����ʾ����ʧ��
	{
		PCL_ERROR("Couldn't read file rabbit.pcd\n");
		return(-1);
	}
	std::cout << "Loaded:" << cloud->width*cloud->height << "data points from test_pcd.pcd with the following fields:" << std::endl;
	// ->��ʾ��ȡcloud�е�width
	for (size_t i = 0; i < cloud->points.size(); ++i)   //points.size��ʾ�������ݵĴ�С
	{
		std::cout << "      " << cloud->points[i].x << "   " << cloud->points[i].y << "   " << cloud->points[i].z << "   " << std::endl;
	}
	system("pause");
	return 0;
}

*/
//���ݿ��ӻ�
#include<iostream>
#include<pcl/io/pcd_io.h>
#include<pcl/point_types.h>
#include <pcl/visualization/cloud_viewer.h>

void viewerOneOff(pcl::visualization::PCLVisualizer& viewer)    //���ñ�����ɫ
{
	viewer.setBackgroundColor(1.0f, 0.8f, 1.0f);
}

int main(int argc, char** argv)
{
	pcl::PointCloud<pcl::PointXYZ>::Ptr cloud(new pcl::PointCloud<pcl::PointXYZ>);

	//
	//*�򿪵����ļ�
	//if (pcl::io::loadPCDFile<pcl::PointXYZ>("C://Users//Administrator//Desktop//test1//Project2//rabbit.pcd", *cloud) == -1)  
	if (pcl::io::loadPCDFile<pcl::PointXYZ>("C://ism_test_cat.pcd", *cloud) == -1)
		//�����Լ�pcd�ļ���·���������
	{
		PCL_ERROR("Couldn't read file rabbit.pcd\n");
		return(-1);
	}
	std::cout << cloud->points.size() << std::endl;   //points.size() ��ʾ���ݵĴ�СҲ����˵�����ļ��ж��ٸ���
	pcl::visualization::CloudViewer viewer("cloud viewer");  //showCloud ������ͬ���ģ��ڴ˴��ȴ�ֱ����Ⱦ��ʾΪֹ
	viewer.showCloud(cloud);    //��ע�ắ���ڿ��ӻ�ʱֻ����һ��

	viewer.runOnVisualizationThreadOnce(viewerOneOff);   //��ע�ắ������Ⱦ�����ÿ�ζ�����

	while (!viewer.wasStopped())
	{

	}
	system("pause");
	return 0;
}
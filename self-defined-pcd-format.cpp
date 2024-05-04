#define PCL_NO_PRECOMPILE
#include <pcl/memory.h>
#include <pcl/pcl_macros.h>
#include <pcl/point_types.h>
#include <pcl/point_cloud.h>
#include <pcl/io/pcd_io.h>

struct EIGEN_ALIGN16 MyPointType    // enforce SSE padding for correct memory alignment
{
    PCL_ADD_POINT4D;                  // preferred way of adding a XYZ+padding
    float test;
    PCL_MAKE_ALIGNED_OPERATOR_NEW     // make sure our new allocators are aligned
};

POINT_CLOUD_REGISTER_POINT_STRUCT(MyPointType,           // here we assume a XYZ + "test" (as fields)
    (float, x, x)
    (float, y, y)
    (float, z, z)
    (float, test, test)
)


int
main(int argc, char** argv)
{
    pcl::PointCloud<MyPointType> cloud;
    cloud.resize(2);
    cloud.width = 2;
    cloud.height = 1;

    cloud[0].test = 1;
    cloud[1].test = 2;
    cloud[0].x = cloud[0].y = cloud[0].z = 0;
    cloud[1].x = cloud[1].y = cloud[1].z = 3;

    pcl::io::savePCDFile("test.pcd", cloud);
}
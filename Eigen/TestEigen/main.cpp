#include <iostream>
#include <Eigen/Core>
#include <Eigen/Dense>

using namespace Eigen;
using Eigen::MatrixXd;

using namespace std;

void TestEigenMatrix1();
void TestEigenMatrix2();

int main()
{
    TestEigenMatrix2();
    cout << "Finished!" << endl;
    return 0;
}

void TestEigenMatrix2()
{
    int nodesPerLevel = 36;
    char buf[255]={0,};
    for (int n = 0; n < nodesPerLevel; n++)
    {
        Eigen::AngleAxisd rotz(-M_PI + 2*n*M_PI / nodesPerLevel, Eigen::Vector3d::UnitZ());
        //Eigen::AngleAxisd roty(-0.5*M_PI + id*M_PI / (numLaps * nodesPerLevel), Eigen::Vector3d::UnitY());
        Eigen::Matrix3d rot = rotz.toRotationMatrix();// (rotz * roty).toRotationMatrix();
        Eigen::Isometry3d t;
        t = rot;
        
        cout << "#" << n << endl;
        //row-wise
        sprintf(buf, "%f\t%f\t%f\t%f\n%f\t%f\t%f\t%f\n%f\t%f\t%f\t%f\n%f\t%f\t%f\t%f",
                t(0,0), t(0,1),t(0,2), t(0,3),
                t(1,0), t(1,1),t(1,2), t(1,3),
                t(2,0), t(2,1),t(2,2), t(2,3),
                t(3,0), t(3,1),t(3,2), t(3,3) );
        cout << buf << endl<< endl;
        
        sprintf(buf, "%f\t%f\t%f\n%f\t%f\t%f\n%f\t%f\t%f",
                rot(0,0), rot(0,1),rot(0,2),
                rot(1,0), rot(1,1),rot(1,2),
                rot(2,0), rot(2,1),rot(2,2));
        cout << buf << endl<< endl;

    }
    
}

// from https://eigen.tuxfamily.org/dox-devel/group__TutorialAdvancedInitialization.html
void TestEigenMatrix1()
{
    Matrix3f m;
    m << 1, 2, 3,
         4, 5, 6,
         7, 8, 9;
    cout << m;
    cout << "\n\n";

    // typedef Matrix< double , Dynamic , Dynamic > Eigen::MatrixXd
    MatrixXd m2(2,2);
    m2(0,0) = 3;
    m2(1,0) = 2.5;
    m2(0,1) = -1;
    m2(1,1) = m2(1,0) + m2(0,1);
    std::cout << m2 ;
    cout << "\n\n";

    const int size = 6;
    MatrixXd mat1(size, size);
    mat1.topLeftCorner(size/2, size/2)     = MatrixXd::Zero(size/2, size/2);
    mat1.topRightCorner(size/2, size/2)    = MatrixXd::Identity(size/2, size/2);
    mat1.bottomLeftCorner(size/2, size/2)  = MatrixXd::Identity(size/2, size/2);
    mat1.bottomRightCorner(size/2, size/2) = MatrixXd::Zero(size/2, size/2);
    std::cout << mat1 << std::endl << std::endl;

    // see https://github.com/RainerKuemmerle/g2o/blob/master/g2o/examples/data_fitting/curve_fit.cpp
    cout << Eigen::Matrix<double, 1, 1>::Identity() << endl << endl;

}

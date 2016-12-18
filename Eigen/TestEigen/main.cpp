#include <iostream>
#include <Eigen/Core>
#include <Eigen/Dense>

using namespace Eigen;
using Eigen::MatrixXd;

using namespace std;

void TestEigenMatrix1();
int main()
{
    TestEigenMatrix1();
    cout << "Finished!" << endl;
    return 0;
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



}

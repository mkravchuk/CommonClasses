#include "stdafx.h"
#include "CommonClasses.h"
#include "ComplexPolar.h"
//#include <Eigen/Core>


void TestVectorNUnrolling()
{
    //CommonClasses::MatrixXi m;
    //Eigen::MatrixXi me = Eigen::MatrixXi::Random(1, 1);
    //int a = m.maxCoeff();
    //me.setConstant
    //me.setZero(
}

template <class T>
std::string test(const T& a, const T& a_should_be)
{
    return(a == a_should_be) ? "ok" : "fail";
}
template <class T>
__declspec(noinline) void couttest(std::string testName, const T& a, const T& a_should_be)
{
    std::string ok_fail = test(a, a_should_be);
    std::string  text = ok_fail + "  " + testName;
    cout << text << endl;
}

template <class T>
inline int couttest_only_if_failed(std::string testName, const T& a, const T& a_should_be)
{
    if (a != a_should_be)
    {
        std::string ok_fail = test(a, a_should_be);
        std::string  text = ok_fail + "  " + testName;
        cout << text;
        cout << "   expected " << a_should_be << "  but provided " << a << endl;
        cout << endl;
        return 1;
    }
    return 0;
}

template <class T>
inline int couttest_only_if_failed(const T& a, const T& a_should_be)
{
    if (a != a_should_be) 
    {
        return couttest_only_if_failed("", a, a_should_be);
    }
    return 0;
}

template <class Vector3i, class Vector4i>
__declspec(noinline) void TestVectorN()
{
    // Constructor (Default)
    Vector3i vDef;
    Eigen::Vector3i veDef;
    cout << "vDef=" << vDef << endl;

    // Constructor (index)
    Vector3i v(1, 1, 1);
    Eigen::Vector3i ve(2, 2, 2);
    couttest("v", v, Vector3i(1, 1, 1));

    // Constructor (Copy)
    Vector3i vConstructorCopy = v;
    couttest("v (ConstructorCopy)", vConstructorCopy, Vector3i(1, 1, 1));


    // Assigments by index
    v(0) = ve(0);
    ve(1) = v(1);
    couttest("v", v, Vector3i(2, 1, 1));

    // Assigments full
    Vector3i vCopy = v;
    couttest("vCopy", vCopy, Vector3i(2, 1, 1));


    //
    // Operators 4
    //
    cout << endl << "Testing operators" << endl;
    Vector4i a4(0, 1, 2, 3);
    Vector4i b4(2, 2, 2, 2);
    Vector4i op_a_plus_b = a4 + b4;
    Vector4i op_a_minus_b = a4 - b4;
    Vector4i op_b_mult_2 = b4 * 2;
    Vector4i op_b_div_2 = b4 / 2;

    couttest("a+b", op_a_plus_b, Vector4i(2, 3, 4, 5));
    couttest("a-b", op_a_minus_b, Vector4i(-2, -1, 0, 1));
    couttest("b*2", op_b_mult_2, Vector4i(4, 4, 4, 4));
    couttest("b/2", op_b_div_2, Vector4i(1, 1, 1, 1));


    //
    // Operators 3
    //
    Vector3i a3 = Vector3i::Random();
    Vector3i b3 = Vector3i::Random();
    Vector3i op_a3_plus_b3 = a3 + b3;
    Vector3i op_a3_minus_b3 = a3 - b3;
    Vector3i op_b3_mult_2 = b3 * 2;
    Vector3i op_b3_div_2 = b3 / 2;

    couttest("a+b", op_a3_plus_b3, Vector3i(a3(0) + b3(0), a3(1) + b3(1), a3(2) + b3(2)));
    couttest("a-b", op_a3_minus_b3, Vector3i(a3(0) - b3(0), a3(1) - b3(1), a3(2) - b3(2)));
    couttest("b*2", op_b3_mult_2, Vector3i(b3(0) * 2, b3(1) * 2, b3(2) * 2));
    couttest("b/2", op_b3_div_2, Vector3i(b3(0) / 2, b3(1) / 2, b3(2) / 2));
}

template <class Matrix3i, class Matrix4i>
__declspec(noinline) void TestMatrixN()
{
    Matrix3i Mi = Matrix3i::Identity();
    int a = Mi.data()[4];
    couttest("Identity()[4]", a, 1);
}

template <class Matrix33, class Vector3>
__declspec(noinline) void TestMatrixN3x3()
{
    cout << endl << "Testing Matrix 3x3" << endl;

    // Constant
//MatrixXi Mc = MatrixXi::Constant(3,3, 3);
    Matrix33 Mc = Matrix33::Constant(3);
    Vector3 v3c0 = Mc.row(0);
    Mc(1, 1) = 2;
    //TestMatrixTEST(Mc);
    Mc(1, 0) = Mc(1, 1) - 1;
    //TestMatrixTEST(Mc);
    Mc(1, 0) += Mc(2, 0);
    //TestMatrixTEST(Mc);
    Mc(1, 1) += Mc(2, 1);
    //TestMatrixTEST(Mc);
    Mc(1, 2) += Mc(2, 2);
    //TestMatrixTEST(Mc);
    Mc.row(2) = Mc.row(1);
    //TestMatrixTEST(Mc);

    Vector3 v3c1 = Mc.row(1);
    Vector3 v3c2 = Mc.row(2);
    couttest("v3c0   Constant(3, 3)", v3c0, Vector3(3, 3, 3));
    couttest("v3c1   Constant(3, 3)", v3c1, Vector3(1 + 3, 2 + 3, 3 + 3));
    couttest("v3c2   Constant(3, 3)", v3c2, v3c1);

    //
    // Indentity
    //
    Matrix33 Mi = Matrix33::Identity();
    Vector3 v3i = Mi.row(1);
    couttest("Identity().row(1)", v3i, Vector3(0, 1, 0));
    couttest("Matrix33::Identity(0,1)", Mi(0, 1), 0.0f);
    couttest("Matrix33::Identity(0,1)", Mi(1, 1), 1.0f);


    //
    // Matrix Operators
    //
    Matrix33 Mo = Matrix33::Constant(1);
    Matrix33 Mo3 = ((Mo * 4) / 2);
    Vector3 viMatrixOperators = Mo3 * Vector3(2, 1, 0);
    couttest("viMatrixOperators", viMatrixOperators, Vector3(6, 6, 6));
}

__declspec(noinline) void TestVector()
{
    cout << endl << "Testing Vector" << endl;
    using namespace CommonClasses;
    constexpr int size = 3;

    // Constructor (Default)
    VectorXi v;

    // resize
    v.resize(size);

    // Constant
    v = VectorXi::Constant(10, 1);
    cout << "vi   Constant(10, 1)  = " << v << endl;

    // conservativeResize
    v.conservativeResize(v.size() + 1);
    cout << "vi   conservativeResize(size + 1)  = " << v << endl;
}

__declspec(noinline) void TestMemoryDataLink()
{
    cout << endl << "Testing MemoryDataLink" << endl;
    using namespace CommonClasses;
    constexpr int rows = 3;
    constexpr int cols = 3;

    // Constructor (Default)
    TableXi M;

    // resize
    M.resize(rows, cols);

    // set data (Default)
    M.row(0) = Vector3i(0, 0, 0);
    M.row(1) = Vector3i(1, 1, 1);
    M.row(2) = Vector3i(2, 2, 2);

    // copy to VectorN
    Vector<int, 3> vx = M.row(1);
    M.row(2) = vx;
    Vector<int> v = M.row(1);
    M.row(0) = v;
    vx = M.row(0);
    v = M.row(2);

    // copy to vector
    couttest("vx", vx, Vector3i(1, 1, 1));

    //Vector3i vrr = M.row(0) + M.row(1) - M.row(2);
    //couttest("vrr", vrr, Vector3i(1, 1, 1));
}

template <class MatrixX3i>
__declspec(noinline) void TestMatrixTEST(const MatrixX3i& m)
{

    //std::string s;
    //for (int i = 0; i < m.size(); i++)
    //{
    //    if (i != 0) s += ", ";
    //    s += std::to_string(m.data()[i]);
    //}    
    cout << "Mc=" << m.toString() << endl;
}

template <class Vector3i, class Vector4i, class MatrixXi, class MatrixX3i, class Matrix3i>
__declspec(noinline) void TestMatrix()
{
    constexpr int rows = 3;
    constexpr int cols = 3;

    // Constructor (Default)
    MatrixXi M;

    // resize
    M.resize(rows, cols);

    // set data (Default)
    M.row(0) = Vector3i(0, 0, 0);
    M.row(1) = Vector3i(1, 1, 1);
    M.row(2) = Vector3i(2, 2, 2);

    // copy to vector 3
    Vector3i v3 = M.row(1);
    M.row(0) = v3;
    M.row(2) = M.row(0);
    v3 = M.row(1);
    M.row(0);

    /* ASM   comparison between Eigen and CommonClasses

    // EIGEN  ::row()
    Vector3i v3c0 = Mc.row(0);
    mov         rcx,qword ptr [Mc]
    mov         eax,dword ptr [rcx]
    mov         dword ptr [rbp-61h],eax
    mov         eax,dword ptr [rcx+4]
    mov         dword ptr [rbp-5Dh],eax
    mov         eax,dword ptr [rcx+8]
    mov         dword ptr [rbp-59h],eax

    // EIGEN SIMPLE  ::row()
    Vector3i v3c0 = Mc.row(0);
    mov         rcx,qword ptr [rsp+28h]
    movsd       xmm0,mmword ptr [rcx]
    movsd       mmword ptr [rbp-18h],xmm0
    mov         eax,dword ptr [rcx+8]
    mov         dword ptr [rbp-10h],eax
    */


    // conservativeResize
    M.conservativeResize(rows + 1, cols + 1);

    // copy to vector 4
    Vector4i v4_1 = M.row(1);
    M.row(0) = Vector4i(0, 0, 0, 0);
    M.row(1) = Vector4i(1, 1, 1, 1);
    M.row(2) = Vector4i(2, 2, 2, 2);
    Vector4i v4_2 = M.row(2);
    M.row(0) = M.row(1);
    Vector4i v4_0 = M.row(0);
    v4_1 = M.row(1);

    // copy to vector invalid
    //Vector3i v3invalid = M.row(0);
    //M.row(1) = v3invalid;
    couttest("v3", v3, Vector3i(1, 1, 1));
    couttest("v4(0)", v4_0, Vector4i(1, 1, 1, 1));
    couttest("v4(1)", v4_1, Vector4i(1, 1, 1, 1));
    couttest("v4(2)", v4_2, Vector4i(2, 2, 2, 2));


    // Constant
    //MatrixXi Mc = MatrixXi::Constant(3,3, 3);
    MatrixX3i Mc = MatrixX3i::Constant(3, 3, 3);
    Vector3i v3c0 = Mc.row(0);
    Mc(1, 1) = 2;
    //TestMatrixTEST(Mc);
    Mc(1, 0) = Mc(1, 1) - 1;
    //TestMatrixTEST(Mc);
    Mc(1, 0) += Mc(2, 0);
    //TestMatrixTEST(Mc);
    Mc(1, 1) += Mc(2, 1);
    //TestMatrixTEST(Mc);
    Mc(1, 2) += Mc(2, 2);
    //TestMatrixTEST(Mc);
    Mc.row(2) = Mc.row(1);
    //TestMatrixTEST(Mc);

    Vector3i v3c1 = Mc.row(1);
    Vector3i v3c2 = Mc.row(2);
    couttest("v3c0   Constant(3, 3)", v3c0, Vector3i(3, 3, 3));
    couttest("v3c1   Constant(3, 3)", v3c1, Vector3i(1 + 3, 2 + 3, 3 + 3));
    couttest("v3c2   Constant(3, 3)", v3c2, v3c1);

    //
    // Indentity
    //
    Matrix3i Mi = Matrix3i::Identity();
    Vector3i v3i = Mi.row(1);
    couttest("Identity().row(1)", v3i, Vector3i(0, 1, 0));
    couttest("Matrix3i::Identity.data()[1]", Mi.data()[1], 0);
    couttest("Matrix3i::Identity.data()[4]", Mi.data()[4], 1);


    //
    // Matrix Operators
    //
    Matrix3i Mo = Matrix3i::Constant(1);
    Matrix3i Mo3 = ((Mo * 4) / 2);
    Vector3i viMatrixOperators = Mo3 * Vector3i(2, 1, 0);
    couttest("viMatrixOperators", viMatrixOperators, Vector3i(6, 6, 6));

}

__declspec(noinline) void AllocateConsoleWindow()
{
    AllocConsole();
    freopen("CONOUT$", "w", stdout);
    freopen("CONOUT$", "w", stderr);

    // move console window to second monitor
    HWND consoleWindow = GetConsoleWindow();
    SetWindowPos(consoleWindow, 0, -1920, 7, 1920, 1200, SWP_NOZORDER); // second monitor is on left side
                                                                        //SetWindowPos(consoleWindow, 0, 1920, 0, 1920, 1200, SWP_NOZORDER);// second monitor is on right side

                                                                        // enable mouse wheel on console
    DWORD lpMode = 0;
    HANDLE hConsole = CreateFile("CONIN$", GENERIC_READ | GENERIC_WRITE, FILE_SHARE_READ | FILE_SHARE_WRITE, NULL, OPEN_EXISTING, FILE_ATTRIBUTE_NORMAL, NULL); //  get console handle
    if (!GetConsoleMode(hConsole, &lpMode)) // get mode of console 
    {
        DWORD err = GetLastError();
    }
    SetConsoleMode(hConsole, lpMode & ~ENABLE_MOUSE_INPUT | ENABLE_PROCESSED_INPUT); // update mode with mouse wheel enabled mode
}

__declspec(noinline) void TestSIMD()
{
    //const int N = 128;
    //float a[N];
    //float b[N];
    //float c[N];
    //float r[N];
    //for (int i = 0; i < N; i++)
    //{
    //    a[i] = rand();
    //    b[i] = rand();
    //    c[i] = rand();
    //}
    ////#pragma omp simd
    //{
    //    for (int i = 0; i<N; i++)
    //    {
    //        r[i] = a[i] + b[i] * c[i];
    //    }
    //}

    //int sum = 0;
    //for (int i = 0; i < N; i++)
    //{
    //    sum += r[i];
    //}

    //cout << "sum=" << sum << endl;
}
// Polar coordinate system     https://en.wikipedia.org/wiki/Polar_coordinate_system
// Integer and Floating - Point Arithmetic Speed vs Precision      http://nicolas.limare.net/pro/notes/2014/12/12_arit_speed/
__declspec(noinline) void TestComplexVsPolar()
{
    Complex max_error_p = complex<float>(0);
    Complex max_error_i = complex<float>(0);
    auto measureError = [](Complex origin, Complex tested, Complex& max_error)
    {
        float real_error = abs(origin.real - tested.real);
        max_error.real = max(max_error.real, real_error);
        float img_error = abs(origin.imag - tested.imag);
        max_error.imag = max(max_error.imag, img_error);
    };
    float K = 0;
    for (int i = 0; i < 1000 * 1000; i++)
    {
        K += 1.f / (1000 * 100);
        constexpr float r = 1;
        //constexpr float K = static_cast<float>(M_PI * 5.5);
        Polar p = { r, K };
        Polar p2 = p * p;
        Polar p4 = p * p*p*p;
        Complex c2 = p2;
        Complex c4 = p4;
        PolarInt i2 = p2;
        PolarInt i4 = p4;

        complex<float> s2 = std::polar(p2.r, p2.angle);
        float cos = s2.real();//!!! should be taken without weight, that currently is equal to 1
        float sin = s2.imag();//!!! should be taken without weight, that currently is equal to 1
        complex<float> s4 = complex<float>(cos*cos - sin * sin, 2 * sin*cos); // since: cos(2a) = cos^2(a) - sin^2(a),  and sin(2a) = 2sin(a)cos(a)

        Complex p2_c = p2;
        Complex p4_c = p4;
        Complex i2_c = i2;
        Complex i4_c = i4;


        Complex c_mult = c2 * c4;
        Polar p_mult = p2 * p4;
        PolarInt i_mult = i2 * i4;

        Complex p_mult_c = p_mult;
        Complex i_mult_c = i_mult;

        measureError(c2, p2_c, max_error_p);
        measureError(c2, i2_c, max_error_i);
        measureError(c4, p4_c, max_error_p);
        measureError(c4, i4_c, max_error_i);
        measureError(c_mult, p_mult_c, max_error_p);
        measureError(c_mult, i_mult_c, max_error_i);
    }
    cout << "K = " << K << endl;
    cout << "max error p = {" << max_error_p.real << ", " << max_error_p.imag << "}" << endl;
    cout << "max error i = {" << max_error_i.real << ", " << max_error_i.imag << "}" << endl;
}

template <class Vector3f>
__declspec(noinline) void TestV3(string libname, Vector3f v3, Vector3f v32)
{
    cout << endl << "Testing Vector34f   (" << libname << ")" << endl;

    //float sum = v3.sum();
    //couttest("v3.sum", sum, static_cast<float>(v3(0)+ v3(1)+ v3(2)));

    float v3min = v3.minCoeff();
    float stdmin = min(min(v3(0), v3(1)), v3(2));
    couttest("v3.min", v3min, stdmin);


    float v3max = v3.maxCoeff();
    float stdmax = max(max(v3(0), v3(1)), v3(2));
    couttest("v3.max", v3max, stdmax);

    //cout << v3min << endl;
    float cross_norm = v3.cross(v32).norm();
    cout << "cross_norm = " << cross_norm << endl;

    float dot = v3.dot(v32);
    cout << "dot = " << dot << endl;

}

__declspec(noinline) void Test_StaticSort()
{
    int a[6] = { 0, 5, 4, 3, 2, 1 };
    StaticSort<6> s;
    s(a);

    pair<int, int> ap[6] = { {0, 0}, {5, 1}, {4, 2}, {3, 3}, {2, 4}, {1, 5} };
    StaticSort<6> sp;
    sp(ap);

}

// define std methods for mixed use of D and DD
//namespace std
//{
//    
//
//    inline float min(const float& a, const double& b)
//    {
//        float bd = static_cast<float>(b);
//        return a < bd ? a : bd;
//    }
//    inline float min(const double& a, const float& b)
//    {
//        float ad = static_cast<float>(a);
//        return ad < b ? ad : b;
//    }
//    inline float max(const float& a, const double& b)
//    {
//        float bd = static_cast<float>(b);
//        return a > bd ? a : bd;
//    }
//    inline float max(const double& a, const float& b)
//    {
//        float ad = static_cast<float>(a);
//        return ad > b ? ad : b;
//    }
//
//}


#include <ctime>
#include <chrono>
chrono::high_resolution_clock::time_point timeNow()
{
    //COMISO::StopWatch sw; sw.start();
    //clock_t start = clock();
    return  chrono::high_resolution_clock::now();
}
int ElapsedMilliseconds(const chrono::high_resolution_clock::time_point&  startTime)
{
    chrono::high_resolution_clock::time_point now = timeNow();
    std::chrono::high_resolution_clock::duration d = now - startTime;
    return chrono::duration_cast<chrono::milliseconds>(d).count();
}
__declspec(noinline) void TestVectorBool()
{
    cout << endl << "Testing TestVectorBool" << endl;
    using namespace CommonClasses;

    int fails = 0;
    constexpr int SET_EVERY_BIT = 2;
    constexpr int kBEGIN = 11111;
    constexpr int kEND = 41111;
    //constexpr int kBEGIN = 128;
    //constexpr int kEND = 500;

    //
    // vector
    //
    cout << "std::vector<bool> ...";
    auto startTimev = timeNow();
    for (int k = kBEGIN; k < kEND; k++)
    {
        vector<bool> bv(k, false);
        for (int i = 0; i < bv.size(); i += SET_EVERY_BIT)
        {
            bv[i] = true;
        }
        for (int i = 0; i < bv.size(); i++)
        {
            bool bval = bv[i];
            bool shouldbe = ((i % SET_EVERY_BIT) == 0);
            fails += couttest_only_if_failed(bval, shouldbe);
        }
        fails += couttest_only_if_failed("b.countOfValues(true)", (int)count(bv.begin(), bv.end(), true), (int)(1 + (bv.size() - 1) / SET_EVERY_BIT));
    }
    cout << " done with " << fails << " errors.  (elapsed " << ElapsedMilliseconds(startTimev) << " ms)" << endl;



    //
    // Vector<bool>
    //
    cout << "Vector<bool> ..." ;
    auto startTimeV = timeNow();
    for (int k = kBEGIN; k < kEND; k++)
    {
        Vector<bool> b;
        b.setConstant(k, false);
        for (int i = 0; i < b.size(); i += SET_EVERY_BIT)
        {
            b[i] = true;
        }
        for (int i = 0; i < b.size(); i++)
        {
            bool bval = b(i);
            bool shouldbe = ((i % SET_EVERY_BIT) == 0);
            fails += couttest_only_if_failed(bval, shouldbe);
        }
        fails += couttest_only_if_failed("b.countOfValues(true)", b.countOfValues(true), 1 + (b.size() - 1) / SET_EVERY_BIT);
    }
    cout << " done with " << fails << " errors.  (elapsed " << ElapsedMilliseconds(startTimeV) << " ms)" << endl;


    cout << "Test ToIndexes ...";
    int fails_indexes = 0;
    Vector<bool> indexes_bool;
    indexes_bool.resize(kEND);
    indexes_bool.setConstant(false); 
    for (int i = 0; i < indexes_bool.size(); i++)
    {
        if (i == 128) indexes_bool[i] = true; // set first bit of second bach of 128 bits
        if (i < kBEGIN) continue; // keep false until kBEGIN
        indexes_bool[i] = true;// set true after kBEGIN
    }
    auto startTime_ToIndexes = timeNow();
    for (int k = kBEGIN; k < kEND; k++)
    {
        indexes_bool[k] = false; // clear
        vector<int> indexes;
        for (int i = 0; i < indexes_bool.size(); i++)
        {
            if (indexes_bool[i]) indexes.push_back(i);
        }
        Vector<int> indexes_fast;
        indexes_bool.ToIndexes(indexes_fast); // use fast method
        if (indexes.size() != indexes_fast.size())
        {
            fails_indexes++;
        }
        else
        {
            for (int i = 0; i < indexes.size(); i++)
                if (indexes[i] != indexes_fast[i])
                {
                    fails_indexes++;
                    break;
                }
        }
        indexes_bool[k] = true; //restore
    }
    cout << " done with " << fails_indexes << " errors.  (elapsed " << ElapsedMilliseconds(startTime_ToIndexes) << " ms)" << endl;

}

__declspec(noinline) void TestNatvis()
{
    cout << endl << "Testing eigen.natvis" << endl;
    using namespace CommonClasses;

    //const int count = 5;
    for (int count = 0; count < 10; count++)
    {
        if (count != 0)
        {
            vector<float> fv(count, 1.0f);
            cout << "fv[0]=" << fv[0] << endl;
        }

        Vector<float> fs;
        fs.setRandom(count);
        cout << "fs.sum=" << fs.sum<float>() << endl;

        Vector<bool> bs;
        bs.setConstant(count, true);
        cout << "b.countOfValues(true)=" << bs.countOfValues(true) << endl;
    }

    Vector<bool> b;
    b.setConstant(10, false);
    b[0] = true;
    b[1] = true;
    cout << "b[2]=" << b[2] << endl;
}

void Test_CompactVectorVector()
{
    CompactVectorVector<int>::run_example_of_usage();
}

int main()
{
    AllocateConsoleWindow();

    //TestAbstractClassInheritance();

    //cout << sizeof(v4_2) << endl;
    //CommonClasses::Vector3i v3c111(1, 2, 3);
    //cout << sizeof(v3c111) << endl;
    //int m_data[3];
    //cout << sizeof(m_data) << endl;

    //cout << min(1.0, 2.0) << endl;
    //cout << min(1.0f, 2.0) << endl;


    cout << "------------------------------------------------" << endl;
    cout << "     TESTING EIGEN SIMPLE" << endl;
    cout << "------------------------------------------------" << endl;
    /*
    TestMatrixN3x3<Eigen::Matrix3f, Eigen::Vector3f>();
    TestMatrixN3x3<CommonClasses::Matrix3f, CommonClasses::Vector3f>();
    TestMatrixN3x3<CommonClasses::Matrix34f, CommonClasses::Vector34f>();

    TestVectorNUnrolling();
    //TestVectorN<Eigen::Vector3i, Eigen::Vector4i>();
    TestVectorN<CommonClasses::Vector3i, CommonClasses::Vector4i>();
    //TestMatrixN<Eigen::Matrix3i, Eigen::Matrix4i>();
    TestMatrixN<CommonClasses::Matrix3i, CommonClasses::Matrix4i>();
    TestVector();
    TestMemoryDataLink();

    //TestMatrix<Eigen::Vector3i, Eigen::Vector4i, Eigen::MatrixXi, Eigen::MatrixX3i, Eigen::Matrix3i>();
    TestMatrix<CommonClasses::Vector3i, CommonClasses::Vector4i, CommonClasses::MatrixXi, CommonClasses::MatrixX3i, CommonClasses::Matrix3i>();
           
    float x = static_cast<float>(rand());
    float y = static_cast<float>(rand());
    float z = static_cast<float>(rand());
    float dx = static_cast<float>(rand());
    float dy = -static_cast<float>(rand());
    float dz = static_cast<float>(rand());
    //TestV3<Eigen::Vector3f>("Eigen Vector3f", Eigen::Vector3f(x,y,z), Eigen::Vector3f(x+ dx, y+dy, z+dz));
    //TestV3<CommonClasses::Vector3f>("CommonClasses Vector3f", CommonClasses::Vector3f(x, y, z), CommonClasses::Vector3f(x + dx, y + dy, z + dz));
    TestV3<CommonClasses::Vector34f>("CommonClasses Vector34f", CommonClasses::Vector34f(x, y, z), CommonClasses::Vector34f(x + dx, y + dy, z + dz));
*/


    //TestVectorBool();
    //TestNatvis();


    //TestSIMD();
    //TestComplexVsPolar();

    //Test_StaticSort();
    Test_CompactVectorVector();

    cout << "------------------------------------------------" << endl;
    return 0;
}


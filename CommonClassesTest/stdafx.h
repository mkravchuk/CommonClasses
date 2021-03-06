
#pragma once

#define __SSE4_2__
#define NOMINMAX                         // disable min,max macroses to give opportunite override min,max for different types
// disable vector range checking and increase speed in debug mode
//#define _HAS_ITERATOR_DEBUGGING 0
//#define _ITERATOR_DEBUG_LEVEL 2
//#define EIGEN_DEFAULT_TO_ROW_MAJOR 1
#undef ASSERT
#include "targetver.h"
#define _AFXDLL
#include "afxwin.h"

#define WIN32_LEAN_AND_MEAN             // Exclude rarely-used stuff from Windows headers
#include <windows.h>
#include "../CommonTypes/disabled_warnings.h"
// C RunTime Header Files
//For /Wall
#pragma warning(push)
#pragma warning(disable : 4820)
#pragma warning(disable : 4619)
#pragma warning(disable : 4548)
#pragma warning(disable : 4668)
#pragma warning(disable : 4365)
#pragma warning(disable : 4710)
#pragma warning(disable : 4371)
#pragma warning(disable : 4826)
#pragma warning(disable : 4061)
#pragma warning(disable : 4640)
#if DEBUG
#include <cassert>
#endif
#include <stdio.h>
#include <string>
//#include <vector>
#include <iostream>
//#include <algorithm>
//#include <set>
//#include <map>
//#include <list>
//#include <stdlib.h>
//#include <malloc.h>
//#include <memory.h>
//#include <tchar.h>
//#include <xlocale>
//#include <limits>
//#include <exception>
//#include <numeric>
//#include <fstream>
//#include <future>
//#include <chrono>
//#include <atomic>
#include <complex>
#include <iomanip>
#include <tchar.h>
#pragma warning(pop) //For /Wall

#include <Eigen/Core>
#include <Eigen/Geometry>
#define COMMONCLASSES_DEFINE_SHORTCUTS
#include "CommonClasses.h"

//using namespace std;
#ifndef M_PI
#define M_PI 3.14159265358979323846
#endif

using namespace std;


template <class T>
std::string test2(const T& a, const T& a_should_be)
{
    return(a == a_should_be) ? "ok" : "fail";
}
template <class T>
__declspec(noinline) void couttest2(std::string testName, const T& a, const T& a_should_be)
{
    std::string ok_fail = test2(a, a_should_be);
    std::string  text = ok_fail + "  " + testName;
    cout << text << endl;
}

__declspec(noinline) void TestVectorN2()
{
    using namespace Eigen;
    // Constructor (Default)
    Vector3i vDef;
    Eigen::Vector3i veDef;
    cout << "vDef=" << vDef << endl;

    // Constructor (index)
    Vector3i v(1, 1, 1);
    Eigen::Vector3i ve(2, 2, 2);
    couttest2("v", v, Vector3i(1, 1, 1));

    // Constructor (Copy)
    Vector3i vConstructorCopy = v;
    couttest2("v (ConstructorCopy)", vConstructorCopy, Vector3i(1, 1, 1));


    // Assigments by index
    v(0) = ve(0);
    ve(1) = v(1);
    couttest2("v", v, Vector3i(2, 1, 1));

    // Assigments full
    Vector3i vCopy = v;
    couttest2("vCopy", vCopy, Vector3i(2, 1, 1));


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

    couttest2("a+b", op_a_plus_b, Vector4i(2, 3, 4, 5));
    couttest2("a-b", op_a_minus_b, Vector4i(-2, -1, 0, 1));
    couttest2("b*2", op_b_mult_2, Vector4i(4, 4, 4, 4));
    couttest2("b/2", op_b_div_2, Vector4i(1, 1, 1, 1));

    op_a_plus_b = op_a_plus_b + b4;
    op_a_minus_b = op_a_minus_b - b4;
    op_b_mult_2 = op_b_mult_2 * 2;
    op_b_div_2 = op_b_div_2 / 2;
    couttest2("a+b", op_a_plus_b, Vector4i(2, 3, 4, 5));
    couttest2("a-b", op_a_minus_b, Vector4i(-2, -1, 0, 1));
    couttest2("b*2", op_b_mult_2, Vector4i(4, 4, 4, 4));
    couttest2("b/2", op_b_div_2, Vector4i(1, 1, 1, 1));

    op_a_plus_b = op_a_plus_b + b4;
    op_a_minus_b = op_a_minus_b - b4;
    op_b_mult_2 = op_b_mult_2 * 2;
    op_b_div_2 = op_b_div_2 / 2;
    couttest2("a+b", op_a_plus_b, Vector4i(2, 3, 4, 5));
    couttest2("a-b", op_a_minus_b, Vector4i(-2, -1, 0, 1));
    couttest2("b*2", op_b_mult_2, Vector4i(4, 4, 4, 4));
    couttest2("b/2", op_b_div_2, Vector4i(1, 1, 1, 1));

    op_a_plus_b = op_a_plus_b + b4;
    op_a_minus_b = op_a_minus_b - b4;
    op_b_mult_2 = op_b_mult_2 * 2;
    op_b_div_2 = op_b_div_2 / 2;
    couttest2("a+b", op_a_plus_b, Vector4i(2, 3, 4, 5));
    couttest2("a-b", op_a_minus_b, Vector4i(-2, -1, 0, 1));
    couttest2("b*2", op_b_mult_2, Vector4i(4, 4, 4, 4));
    couttest2("b/2", op_b_div_2, Vector4i(1, 1, 1, 1));

    op_a_plus_b = op_a_plus_b + b4;
    op_a_minus_b = op_a_minus_b - b4;
    op_b_mult_2 = op_b_mult_2 * 2;
    op_b_div_2 = op_b_div_2 / 2;
    couttest2("a+b", op_a_plus_b, Vector4i(2, 3, 4, 5));
    couttest2("a-b", op_a_minus_b, Vector4i(-2, -1, 0, 1));
    couttest2("b*2", op_b_mult_2, Vector4i(4, 4, 4, 4));
    couttest2("b/2", op_b_div_2, Vector4i(1, 1, 1, 1));

    op_a_plus_b = op_a_plus_b + b4;
    op_a_minus_b = op_a_minus_b - b4;
    op_b_mult_2 = op_b_mult_2 * 2;
    op_b_div_2 = op_b_div_2 / 2;
    couttest2("a+b", op_a_plus_b, Vector4i(2, 3, 4, 5));
    couttest2("a-b", op_a_minus_b, Vector4i(-2, -1, 0, 1));
    couttest2("b*2", op_b_mult_2, Vector4i(4, 4, 4, 4));
    couttest2("b/2", op_b_div_2, Vector4i(1, 1, 1, 1));

    //
    // Operators 3
    //
    Vector3i a3 = Vector3i::Random();
    Vector3i b3 = Vector3i::Random();
    Vector3i op_a3_plus_b3 = a3 + b3;
    Vector3i op_a3_minus_b3 = a3 - b3;
    Vector3i op_b3_mult_2 = b3 * 2;
    Vector3i op_b3_div_2 = b3 / 2;

    couttest2("a+b", op_a3_plus_b3, Vector3i(a3(0) + b3(0), a3(1) + b3(1), a3(2) + b3(2)));
    couttest2("a-b", op_a3_minus_b3, Vector3i(a3(0) - b3(0), a3(1) - b3(1), a3(2) - b3(2)));
    couttest2("b*2", op_b3_mult_2, Vector3i(b3(0) * 2, b3(1) * 2, b3(2) * 2));
    couttest2("b/2", op_b3_div_2, Vector3i(b3(0) / 2, b3(1) / 2, b3(2) / 2));
}


__declspec(noinline) void TestMatrixN2()
{
    using namespace Eigen;
    Matrix3i Mi = Matrix3i::Identity();
    int a = Mi.data()[4];
    couttest2("Identity()[4]", a, 1);
}


__declspec(noinline) void TestMatrix2()
{
    using namespace Eigen;

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

    // copy to vector invalid
    //Vector3i v3invalid = M.row(0);
    //M.row(1) = v3invalid;
    couttest2("v3", v3, Vector3i(1, 1, 1));
    couttest2("v4(0)", v4_0, Vector4i(1, 1, 1, 1));
    couttest2("v4(1)", v4_1, Vector4i(1, 1, 1, 1));
    couttest2("v4(2)", v4_2, Vector4i(2, 2, 2, 2));



    // Constant
    //MatrixXi Mc = MatrixXi::Constant(3,3, 3);
    MatrixX3i Mc = MatrixX3i::Constant(3, 3, 3);
    Vector3i v3c0 = Mc.row(0);
    Mc(1, 1) = 2;
    Mc(1, 0) = Mc(1, 1) - 1;
    Mc(1, 0) += Mc(2, 0);
    Mc(1, 1) += Mc(2, 1);
    Mc(1, 2) += Mc(2, 2);
    Mc.row(2) = Mc.row(1);

    Vector3i v3c1 = Mc.row(1);
    Vector3i v3c2 = Mc.row(2);
    couttest2("v3c0   Constant(3, 3)", v3c0, Vector3i(3, 3, 3));
    couttest2("v3c1   Constant(3, 3)", v3c1, Vector3i(1 + 3, 2 + 3, 3 + 3));
    couttest2("v3c2   Constant(3, 3)", v3c2, v3c1);

    //
    // Indentity
    //
    Matrix3i Mi = Matrix3i::Identity();
    Vector3i v3i = Mi.row(1);
    couttest2("Identity().row(1)", v3i, Vector3i(0, 1, 0));
    couttest2("Matrix3i::Identity.data()[1]", Mi.data()[1], 0);
    couttest2("Matrix3i::Identity.data()[4]", Mi.data()[4], 1);


    //
    // Matrix Operators
    //
    Matrix3i Mo = Matrix3i::Constant(1);
    Vector3i viMatrixOperators = ((Mo * 4) / 2)*Vector3i(2, 1, 0);
    couttest2("viMatrixOperators", viMatrixOperators, Vector3i(2 * 2 * 3, 2 * 1 * 3, 2 * 0 * 3));

}
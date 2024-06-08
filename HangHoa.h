#pragma once
#include<string>
#include<vector>
#include<iostream>
#include <fstream>
#include <sstream>
#include <iomanip>

using namespace std;

class Hanghoa{
    private:
        string san_pham;
        string ma_san_pham;
        double gia_thanh;
        
    public:
        Hanghoa();
        Hanghoa(string, string, double);
        // void giao_dien_tim_kiem();
        // void giao_dien_chinh();
        // void them_san_pham();
        void nhap();
        void xuat();
        void setTensp(string tensp);
        void setMasp(string ma);
        void setGiasp(double gia);
        // void xoa_san_pham();
        void suaSanPham(vector<Hanghoa>&);
        // void tim_kiem();
        // void xuat_file();
        // void giao_dien_chinh_sua();
        string layMaDonHang();
        string layTenSanPham();
        double layGiaThanh();
};

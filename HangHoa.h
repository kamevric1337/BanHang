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
        int so_luong;
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
        void sua_san_pham(vector<Hanghoa>&);
        // void tim_kiem();
        // void xuat_file();
        // void giao_dien_chinh_sua();
        string lay_ma_don_hang();
        string lay_ten_san_pham();
        double lay_gia_thanh();
        int lay_so_luong();
};

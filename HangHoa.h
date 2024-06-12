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
        Hanghoa(string, string, double, int);
        // void giao_dien_tim_kiem();
        // void giao_dien_chinh();
        // void them_san_pham();
        void nhap();
        void xuat();
        void setTensp(string tensp);
        void setMasp(string ma);
        void setGiasp(double gia);
        void setSoLuong(int soLuong);
        // void xoa_san_pham();
        void suaSanPham(vector<Hanghoa>&);
        // void tim_kiem();
        // void xuat_file();
        // void giao_dien_chinh_sua();
        friend void /*Hanghoa::*/doc_file(vector<Hanghoa> &san_pham);
        friend void /*Hanghoa::*/xuat_file(vector<Hanghoa> &san_pham);
        string layMaDonHang();
        string layTenSanPham();
        double layGiaThanh();
        int laySoLuong();
};

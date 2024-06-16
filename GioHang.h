#pragma once
#include"HangHoa.h"



class GioHang
{
private:
    /* data */
    std::vector<Hanghoa> gioHang;
    double tienThanhToan;
    int soLuongHang;
    double phanTramGiamGia;

    void capNhatTienThanhToan(); // De cap nhat tien khi them hoac xoa san pham
public:
    GioHang(/* args */);
    void themSanPham(Hanghoa sanPham);
    void xoaSanPham(int index);

    void inGioHang();
    void apMaGiamGia(double phanTram);
    void thanhToan();

    double layTienThanhToan();
    int laySoLuongHang();
    double layPhanTramGiamGia();
    
    ~GioHang();
};



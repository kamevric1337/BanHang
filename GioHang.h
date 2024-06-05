#pragma once
#include"HangHoa.h"



class GioHang
{
private:
    /* data */
    std::vector<Hanghoa> gioHang;
    double tienThanhToan = 0;
    int soLuongHang = 0;

    void capNhatTienThanhToan(); // De cap nhat tien khi them hoac xoa san pham

public:
    GioHang(/* args */);
    void themSanPham();
    void xoaSanPham();
    void inGioHang();
    double layTienThanhToan();
    void apMaGiamGia(double phanTram);
    ~GioHang();
};



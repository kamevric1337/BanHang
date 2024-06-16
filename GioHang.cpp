
#include<iostream>
#include<vector>
#include<string>
#include"GioHang.h"

GioHang::GioHang(): tienThanhToan(0), soLuongHang(0), phanTramGiamGia(0){}

void GioHang::capNhatTienThanhToan()
{
    this->tienThanhToan = 0;
    for(int i = 0; i < this->gioHang.size();i++)
    {
        tienThanhToan += gioHang[i].layGiaThanh() * gioHang[i].laySoLuong();
    }

}

void GioHang::themSanPham(Hanghoa sanPham)
{
    this->gioHang.push_back(sanPham);

    this->soLuongHang++;
    this->capNhatTienThanhToan();
}

void GioHang::xoaSanPham(int index)
{
    this->gioHang.erase(gioHang.begin() + index);

    this->soLuongHang--;
    capNhatTienThanhToan();
}

void GioHang::inGioHang()
{
    std::cout << "\n<------------------Gio hang cua ban---------------->";
    for(int i = 0; i < gioHang.size(); i++)
    {
        std::cout << "\n" << i + 1 << ". ";
        this->gioHang[i].xuat();
    }
}

double GioHang::layTienThanhToan()
{
    return this->tienThanhToan;
}

int GioHang::laySoLuongHang()
{
    return this->gioHang.size();
}
double GioHang::layPhanTramGiamGia()
{
    return this->phanTramGiamGia;
}

void GioHang::apMaGiamGia(double phanTram)
{
    this->phanTramGiamGia = phanTram;
    this->tienThanhToan *= (1 - phanTram/100);
}

void GioHang::thanhToan()
{
    this->inGioHang();
    cout << "\nSo tien phai tra la: " << this->layTienThanhToan() << " VND\n";
}

GioHang::~GioHang()
{
    
}
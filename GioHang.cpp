
#include<iostream>
#include<vector>
#include<string>
#include"GioHang.h"

GioHang::GioHang(): tienThanhToan(0), soLuongHang(0){}

void GioHang::capNhatTienThanhToan()
{
    this->tienThanhToan = 0;
    for(int i = 0; i < this->gioHang.size();i++)
    {
        tienThanhToan += gioHang[i].lay_gia_thanh();
    }

}

void GioHang::themSanPham()
{
    Hanghoa sanPham;
    sanPham.nhap();
    this->gioHang.push_back(sanPham);

    this->soLuongHang++;
    capNhatTienThanhToan();
}

void GioHang::xoaSanPham()
{
    int STT;
    std::cout << "\nNhap STT cua san pham muon xoa: ";
    std::cin >> STT;
    this->gioHang.erase(gioHang.begin() + STT - 1);

    this->soLuongHang--;
    capNhatTienThanhToan();
}

void GioHang::inGioHang()
{
    for(int i = 0; i < gioHang.size(); i++)
    {
        std::cout << "\n";
        this->gioHang[i].xuat();
    }
}

double GioHang::layTienThanhToan()
{
    return this->tienThanhToan;
}

void GioHang::apMaGiamGia(double phanTram)
{
    this->tienThanhToan *= (1 - phanTram/100);
}

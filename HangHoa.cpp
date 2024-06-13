#include"HangHoa.h"

Hanghoa::Hanghoa()
{

}
Hanghoa::Hanghoa(string sanPham, string maSanPham, double giaThanh)
{
    this->san_pham = sanPham;
    this->ma_san_pham = maSanPham;
    this->gia_thanh = giaThanh;
}

Hanghoa::Hanghoa(string sanPham, string maSanPham, double giaThanh, int soLuong)
{
    this->san_pham = sanPham;
    this->ma_san_pham = maSanPham;
    this->gia_thanh = giaThanh;
    this->so_luong = soLuong;
}




double Hanghoa::layGiaThanh(){
    return gia_thanh;
}
// bool operator < (Hanghoa a, Hanghoa b){
//     return a.lay_gia_thanh() < b.lay_gia_thanh(); 
// }
string Hanghoa:: layTenSanPham(){
    return san_pham;
}
string Hanghoa::layMaDonHang(){
    return ma_san_pham;
}

int Hanghoa::laySoLuong()
{
    return so_luong;
}

void Hanghoa::setTensp(string tensp){
    san_pham=tensp;
}
void Hanghoa::setMasp(string ma){
    ma_san_pham=ma;
}
void Hanghoa::setGiasp(double gia){
    gia_thanh=gia;
}

void Hanghoa::setSoLuong(int soLuong)
{
    so_luong = soLuong;
}
void Hanghoa::nhap(){
    cout << "Nhap thong tin san pham: ";
    cout << "\nNhap ten san pham: ";
    getline(cin,san_pham);
    cout << "\nNhap ma san pham: ";
    getline(cin,ma_san_pham);
    cout << "\nNhap gia thanh san pham: ";
    cin >> gia_thanh;
    cout << "\nNhap so luong san pham: ";
    cin >> so_luong;
}
void Hanghoa::xuat(){
    cout << " " << san_pham << "    " << ma_san_pham << "     " << gia_thanh << "VND     x" << so_luong <<  endl;
}


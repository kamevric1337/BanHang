#include"HangHoa.h"

Hanghoa::Hanghoa(string sanPham, string maSanPham, double giaThanh)
{
    this->san_pham = sanPham;
    this->ma_san_pham = maSanPham;
    this->gia_thanh = giaThanh;
}

double Hanghoa::lay_gia_thanh(){
    return gia_thanh;
}
// bool operator < (Hanghoa a, Hanghoa b){
//     return a.lay_gia_thanh() < b.lay_gia_thanh(); 
// }
string Hanghoa:: lay_ten_san_pham(){
    return san_pham;
}
string Hanghoa::lay_ma_don_hang(){
    return ma_san_pham;
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
void Hanghoa::nhap(){
    cout << "Nhap thong tin san pham: ";
    cout << "\nNhap ten san pham: ";
    getline(cin,san_pham);
    cout << "\nNhap ma san pham: ";
    getline(cin,ma_san_pham);
    cout << "\nNhap gia thanh san pham: ";
    cin >> gia_thanh;
}
void Hanghoa::xuat(){
    cout << setw(34) << san_pham << setw(34) << ma_san_pham << gia_thanh << endl;
}

void Hanghoa::sua_san_pham(vector<Hanghoa>& san_pham){
    string masp;
    cout << "nhap ma so cua san pham can sua:";
    getline(cin,masp);
    for(int i = 0; i < san_pham.size(); i++){
        if(san_pham[i].lay_ma_don_hang() == masp){
        string ten;
        string ma;
        double gia;
         cout << "Nhap thong tin san pham moi: ";
        cout << "\nNhap ten san pham moi: ";
        getline(cin,ten);
        cout << "\nNhap ma san pham moi: ";
        getline(cin,ma);
        cout << "\nNhap gia thanh san pham moi: ";
        cin >> gia;
        san_pham[i].setTensp(ten);
        san_pham[i].setMasp(ma);
        san_pham[i].setGiasp(gia);
        }
    }
}



#include"HangHoa.h"


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

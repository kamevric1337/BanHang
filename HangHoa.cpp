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
void them_san_pham( vector<Hanghoa>& san_pham){
    Hanghoa sp;
    sp.nhap();
    san_pham.push_back(sp);
}
void Hanghoa::sua_san_pham(vector<Hanghoa>& san_pham){
    string masp;
    cout << "nhap ma so cua san pham can sua:";
    getline(cin,masp);
    for(auto& hanghoa:san_pham){
        if(hanghoa.lay_ma_don_hang()==masp){
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
        hanghoa.setTensp(ten);
        hanghoa.setMasp(ma);
        hanghoa.setGiasp(gia);
        }
    }
void xoa_san_pham(vector<Hanghoa>& san_pham){
    string ma_sp_xoa;
    cout << "Nhap ma san pham can xoa: ";
    getline(cin,ma_sp_xoa);
    
}
}

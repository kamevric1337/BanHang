#include<iostream>
using namespace std;

class Hanghoa {
private:
    string tensp[100]; // cai nay minh dung danh sach ten cac san pham de tien viec them, xoa, sua
    string masp; // masp: ma san pham
    static int maso; // ma so thu tu cac loai hang vi du giay so 1 2 3 
public:
    void themsanpham(); // su dung trong tuy chinh
    void hienthisanpham();
    string laytensp();
    string laymasp();
};
int Hanghoa::maso = 16; 
/*quy dinh ma so (so thu tu hang hoa) la 16
 vi minh se cho san 16 sp con lai 84 sp la minh nhap them*/ 
void Hanghoa::themsanpham(){
    cout << "Nhap ten hang hoa ban muon them: ";
    maso++;
    cin >> tensp[maso];
    masp = "MDH" + string(4-to_string(maso).length(),'0') + to_string(maso); 
    // vi du moi khi nhap them 1 san pham thi so thu tu(maso) se tang len
    // khi do no co masp la MDH0017
}
string Hanghoa::laytensp(){
    return *tensp;
}
string Hanghoa::laymasp(){
    return masp;
}
void Hanghoa::hienthisanpham(){
    cout << laytensp() << "     " << laymasp() << endl;
}
int main(){
    Hanghoa a;
    a.themsanpham();
    a.hienthisanpham();
}
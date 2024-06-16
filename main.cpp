#include <fstream>
#include <iostream>
#include <sstream>
#include <iomanip>
#include"HangHoa.cpp"
#include"GioHang.cpp"
#include <algorithm>
#define PASSWORD 2

using namespace std;

void inDanhSachSanPham(vector<Hanghoa>& san_pham);
void themSanPham( vector<Hanghoa>& san_pham);
void xoaSanPham(vector<Hanghoa>& san_pham);
void sua_san_pham(vector<Hanghoa>& san_pham);
// void swap(Hanghoa a, Hanghoa b);
void sapXepTheoGia(vector<Hanghoa>& dssp);
void sapXepTheoMaSanPham(vector<Hanghoa>& dssp);
void sapXepTheoTen(vector<Hanghoa>& dssp);
void timKiemTheoMaSanPham(vector<Hanghoa> dssp);
void timKiemTheoTen(vector<Hanghoa> dssp);
void sapXep(vector<Hanghoa>& dssp);
void giaoDienTimKiem( vector<Hanghoa> san_pham);
void giaoDienChinhSua( vector<Hanghoa>& san_pham);
void giaoDienThanhToan(vector<Hanghoa>& san_pham, GioHang& quay_thanh_toan);
void giaoDienChinh(vector<Hanghoa>& san_pham, GioHang& quay_thanh_toan);


bool operator > (Hanghoa a, Hanghoa b){
    return a.gia_thanh > b.gia_thanh; 
}
Hanghoa Hanghoa ::operator = (Hanghoa a){
    if(this != &a){
        san_pham=a.san_pham;
        gia_thanh=a.gia_thanh;
        ma_san_pham=a.ma_san_pham;
        so_luong=a.so_luong; 
    }
    return *this;
}
void inDanhSachSanPham(vector<Hanghoa>& san_pham)
{
    cout << "\n<-------Danh sach cac san pham dang bay ban: -------> \n";
    for(int i = 0; i < san_pham.size(); i++)
    {
        cout << i + 1 << ". ";
        san_pham[i].xuat();
    }
}
void themSanPham( vector<Hanghoa>& san_pham){
nhan:
    Hanghoa new_item;
    new_item.nhap_de_them_sp();
    new_item.ma_san_pham = "MDH"+string(4-to_string(san_pham.size()+1).length(),'0')+ to_string(san_pham.size()+1);
    san_pham.push_back(new_item);
    char lc;
    cout << "Ban co muon tiep tuc khong (y/n) ?";
    cin >> lc;
    if(lc == 'y'){
        goto nhan;
    }
}
void xoaSanPham(vector<Hanghoa>& san_pham){
nhan:
    string ma_sp_xoa;
    bool ktra = false;
    cout << "Nhap ma san pham can xoa (MDHxxxx): ";
    cin.ignore();
    getline(cin,ma_sp_xoa);
    transform(ma_sp_xoa.begin(), ma_sp_xoa.end(), ma_sp_xoa.begin(), ::toupper);
    //chuc nang xoa san pham
    for (int i = 0; i < san_pham.size(); i++) {
        if (san_pham[i].layMaDonHang() == ma_sp_xoa) {
            san_pham.erase(san_pham.begin() + i);
            cout << "San pham da duoc xoa" << endl;
            ktra = true;
            break;
        }
    }
    if(ktra == false){
        cout << "Khong tim thay san pham voi ma da nhap!" << endl;
    }
    char lc;
    cout << "Ban co muon tiep tuc xoa khong (y/n) ?";
    cin >> lc;
    if(lc == 'y'){
        goto nhan;
    }
}
void sua_san_pham(vector<Hanghoa>& san_pham){
nhan:
    string masp;
    bool ktra = false;
    cout << "Nhap ma so cua san pham can sua (MDHxxxx):";
    cin.ignore();
    getline(cin,masp);
    transform(masp.begin(), masp.end(), masp.begin(), ::toupper);
    for(int i = 0; i < san_pham.size(); i++){
        if(san_pham[i].layMaDonHang() == masp){
        string ten;
        string ma;
        double gia;
        int soluong;
        cout << "Nhap thong tin san pham moi: ";
        cout << "\nNhap ten san pham moi: ";
        // cin.ignore();
        getline(cin,ten);
        // cout << "\nNhap ma san pham moi: ";
        // getline(cin,ma);
        cout << "Nhap gia thanh san pham moi: ";
        cin >> gia;
        cout << "Nhap so luong san pham: ";
        cin >> soluong;
        san_pham[i].setTensp(ten);
        // san_pham[i].setMasp(ma);
        san_pham[i].setGiasp(gia);
        san_pham[i].setSoLuong(soluong);
        ktra = true;
        }
    }
    if(ktra == false){
        cout << "Khong tim thay san pham voi ma da nhap!" << endl;
    }
    char lc;
    cout << "Ban co muon tiep tuc xoa khong (y/n) ?";
    cin >> lc;
    if(lc == 'y'){
        goto nhan;
    }
}
void swap(Hanghoa &a, Hanghoa& b){
    Hanghoa temp;
    temp = a;
    a = b;
    b = temp;
}
void sapXepTheoGia(vector<Hanghoa>& dssp){
    for(int i=0;i<dssp.size();i++){
        for(int j = i+1;j<dssp.size();j++){
            if(dssp[i] > dssp[j]){
                swap(dssp[i],dssp[j]);
            }
        }
    }
    // sort(dssp.begin(),dssp.end(),[]( Hanghoa&a, Hanghoa&b){
    //     return a.layGiaThanh()<b.layGiaThanh();
    // });
    }
void sapXepTheoMaSanPham(vector<Hanghoa>& dssp){ // chương trình tự sắp xếp theo mã sẵn rồi nên cái này thừa
    // for(int i=0;i<dssp.size();i++){
    //     for(int j = i+1;j<dssp.size();j++){
    //         if(dssp[i].layMaDonHang() < dssp[j].layMaDonHang()){
    //             swap(dssp[i],dssp[j]);
    //         }
    //     }
    // }
}
void sapXepTheoTen(vector<Hanghoa>& dssp){
    for (int i = 0; i < dssp.size(); i++) {
        for (int j = i + 1; j < dssp.size(); j++) {
            if (dssp[i].layTenSanPham() > dssp[j].layTenSanPham()) {
                swap(dssp[i], dssp[j]);
            }
        }
    }
}
void sapXep(vector<Hanghoa>& dssp){
    int luachon;
    cout << " __________________________________________________________________" << endl;
    cout << "|                              SAP XEP                             |" << endl;
    cout << "|__________________________________________________________________|" << endl;
    cout << "|                                                                  |" << endl;
    cout << "|  1.  Sap xep theo gia                                            |" << endl;
    // cout << "|  2.  Sap xep theo ma san pham                                    |" << endl;
    cout << "|  2.  Sap xep theo ten san pham                                   |" << endl;
    cout << "|  3.  Quay lai trang chu                                          |" << endl;
    cout << "|*________________________________________________________________*|" << endl;
    cout <<" Nhap lua chon cua ban: ";
    cin >> luachon;
    switch(luachon){
        case(1):
            sapXepTheoGia(dssp);
            break;
        // case(2):
        //     sapXepTheoMaSanPham(dssp);
        //     break;
        case(2):
            sapXepTheoTen(dssp);
            break;
        case(3):
            break;
    }
}
void timKiemTheoMaSanPham( vector<Hanghoa> san_pham){
nhan:
    cin.ignore();
    string ma_don_hang;
    bool isExist = false;
    cout << "Nhap ma don hang ban can tim kiem (MDHxxxx): ";
    getline(cin,ma_don_hang);
    for(int i = 0; i < san_pham.size(); i++){
        if(san_pham[i].layMaDonHang() == ma_don_hang){
            san_pham[i].xuat();
            isExist = true; // da tim thay san pham
            break;
        }
    }
    //neu khong tim thay thi thong bao
    if(!isExist){
        cout << "Khong tim thay san pham voi ma da nhap\n";
    }
    char lc;
    cout << "Ban co muon tiep tuc tim khong (y/n) ?";
    cin >> lc;
    if(lc == 'y'){
        goto nhan;
    }
}
void timKiemTheoTen( vector<Hanghoa> san_pham){
nhan:
    int count =0;
    cin.ignore();
    string ten_san_pham;
    cout << "Nhap ten san pham ban muon tim: ";
    getline(cin,ten_san_pham);
    for(int i = 0; i < san_pham.size(); i++){
        if(san_pham[i].layTenSanPham() == ten_san_pham){
            san_pham[i].xuat();
            count++;
            break;
        }
    }
    //neu khong tim thay thi thong bao
    if(count == 0){
        cout << "Khong tim thay san pham voi ten da nhap\n";
    }
    char lc;
    cout << "Ban co muon tiep tuc tim khong (y/n) ?";
    cin >> lc;
    if(lc == 'y'){
        goto nhan;
    }
}
void giaoDienTimKiem( vector<Hanghoa> san_pham){
    // cin.ignore();
    int choice_;
    system("clear");
    cout << " __________________________________________________________________" << endl;
    cout << "|                             TIM KIEM                             |" << endl;
    cout << "|__________________________________________________________________|" << endl;
    cout << "|                                                                  |" << endl;
    cout << "|  1.  Tim kiem theo ten                                           |" << endl;
    cout << "|  2.  Tim kiem theo ma san pham                                   |" << endl;
    cout << "|  3.  Quay lai trang chu                                          |" << endl;
    cout << "|*________________________________________________________________*|" << endl;
    cout << "Nhap lua chon cua ban: ";
    cin >> choice_;
    switch(choice_){
        case (1):
            // cin.ignore();
            timKiemTheoTen(san_pham);
            break;
        case (2):
            timKiemTheoMaSanPham(san_pham);
            break;
        case (3):
            break;
    }
}
void giaoDienChinhSua( vector<Hanghoa>& san_pham){
    // system("clear"); 
    int _choice;
    cout << " __________________________________________________________________" << endl;
    cout << "|                         QUYEN CHINH SUA                          |" << endl;
    cout << "|__________________________________________________________________|" << endl;
    cout << "|                                                                  |" << endl;
    cout << "|  1.  Them san pham                                               |" << endl;
    cout << "|  2.  Xoa san pham                                                |" << endl;
    cout << "|  3.  Thay doi san pham                                           |" << endl;
    cout << "|  4.  Quay lai trang chu                                          |" << endl;
    cout << "|*________________________________________________________________*|" << endl;
        cout << "Nhap lua chon cua ban: ";
        cin >> _choice;
        switch (_choice){
            case (1):
                // system("clear");
                themSanPham(san_pham);
                break;
            case (2):
                xoaSanPham(san_pham);
                break;
            case (3):
                sua_san_pham(san_pham);
                break;
            case (4):
                break;
            default:
                cout << "Khong co tinh nang da nhap !";
                break;
            }
    
}
void giaoDienThanhToan(vector<Hanghoa>& san_pham, GioHang& quay_thanh_toan)
{
    int choice_;
    double phanTram = 0;
    int STT_xoa = -1;
    int STT_them = -1;
    int so_luong = 1;

    system("clear");
    quay_thanh_toan.inGioHang();
    cout << "\n";
    cout << " __________________________________________________________________" << endl;
    cout << "|                         THANH TOAN GIO HANG                      |" << endl;
    cout << "|__________________________________________________________________|" << endl;
    cout << "|                                                                  |" << endl;
    cout << "|  1.  Them san pham                                               |" << endl;
    cout << "|  2.  Xoa san pham                                                |" << endl;
    cout << "|  3.  Thanh toan                                                  |" << endl;
    cout << "|  4.  Quay lai trang chu                                          |" << endl;
    cout << "|*________________________________________________________________*|" << endl;
    cout << "Nhap lua chon cua ban: ";
    cin >> choice_;
    switch (choice_)
    {
    case 1:

        inDanhSachSanPham(san_pham);
        cout << "\nBan muon them san pham so bao nhieu: ";
        cin >> STT_them;
        cout << "\nNhap so luong muon mua cua san pham vua chon: ";
        cin >> so_luong;
        san_pham[STT_them-1].setSoLuong(so_luong);
        quay_thanh_toan.themSanPham(san_pham[STT_them - 1]); // Them san pham co STT  tu danh sach vao gio hang
        quay_thanh_toan.inGioHang();
        giaoDienThanhToan(san_pham, quay_thanh_toan); // quay lai giao dien thanh toan
        break;
    case 2:
        quay_thanh_toan.inGioHang();
        cout << "\nBan muon xoa san pham so bao nhieu: ";
        cin >> STT_xoa;
        quay_thanh_toan.xoaSanPham(STT_xoa - 1); // Xoa san pham co STT STT ra khoi gio hang
        quay_thanh_toan.inGioHang();
        giaoDienThanhToan(san_pham, quay_thanh_toan); // quay lai giao dien thanh toan

        break;
    case 3:
        cout << "\nNhap ti le giam gia: ";
        cin >> phanTram;
        quay_thanh_toan.apMaGiamGia(phanTram);
        quay_thanh_toan.inGioHang();
        cout << "\nSo tien phai tra la: " << quay_thanh_toan.layTienThanhToan() << " VND";
        break;
    case 4:
        break;
    default:
        break;
    }
}
void giaoDienChinh( vector<Hanghoa>& san_pham, GioHang& quay_thanh_toan){
    int choice;
do{
    // system("clear"); 
    cout << " __________________________________________________________________" << endl;
    cout << "|                      QUAN LI CUA HANG MINI                       |" << endl;
    cout << "|__________________________________________________________________|" << endl;
    cout << "|                                                                  |" << endl;
    cout << "|  1.  Tim kiem san pham                                           |" << endl;
    cout << "|  2.  Xuat hoa don mua hang                                       |" << endl;
    cout << "|  3.  Quyen chinh sua                                             |" << endl;
    cout << "|  4.  Thanh toan                                                  |" << endl;
    cout << "|  5.  Sap xep                                                     |" << endl;
    cout << "|  6.  In danh sach hien tai                                       |" << endl;
    cout << "|  7.  Thoat                                                       |" << endl;
    cout << "|*________________________________________________________________*|" << endl;
    cout << "                                                                    " << endl;
    cout << "Nhap lua chon cua ban [1-7]: ";
    cin >> choice;
    switch(choice){
        case(1):
            // cout <<"chay dc" << endl;
            system("clear");
            giaoDienTimKiem(san_pham);
            break;
        case(2):
            system("clear");
            xuat_file(san_pham);
            cout << "Xuat danh sach san pham thanh cong! \n";
            break;
        case(3):
            system("clear");
            int mat_khau;
            cout << "Nhap mat khau de truy cap: ";
            cin >> mat_khau;
            if(mat_khau==PASSWORD){
                int _choice;
                giaoDienChinhSua(san_pham);
                break;
            }
            else{
                cout << "Mat khau khong hop le !";
                break;
            }
        case(4): 
            system("clear");
            giaoDienThanhToan(san_pham, quay_thanh_toan);
            break;
        case(5): 
            system("clear");
            sapXep(san_pham);
            cout << "Sap xep thanh cong! \n";
            break;
        case(6): 
            system("clear");
            cout << "Shop gui quy khach danh sach san pham hien co :33\n";
            inDanhSachSanPham(san_pham);
            break;
        case(7):
            system("clear");
            cout <<"Cam on ban da su dung chuong trinh !";
            exit(0);
        default:
            system("clear");
            cout << "Lua chon cua ban chua hop le, vui long chon lai !" << endl;
            break;
    }
    // break;
} while (true);
}
void doc_file(vector<Hanghoa> &san_pham){
    // /home/hoangtung/Documents/giay.txt
    ifstream file("/home/hoangtung/Documents/giay.txt");// thay doi duong dan trong window nhu sau: E:\\ .....
    if (!file.is_open()) {
        cout << "Khong the mo file!" << endl;
    }
    string line;
    // int dem_vec = 0;
    // san_pham.size();
    while(getline(file,line)){
        istringstream iss(line);
        Hanghoa temp;
        getline(iss, temp.ma_san_pham, ',');
        getline(iss, temp.san_pham, ',');
        iss >> temp.gia_thanh;
        iss.ignore(); 
        iss >> temp.so_luong;

        san_pham.push_back(temp);
        // dem_vec++;
    }
    file.close();
}
void xuat_file(vector<Hanghoa> &san_pham){
    ofstream file("/home/hoangtung/Documents/hanghoa.txt");
    if (!file.is_open()) {
        cout << "Không thể mở file!" << endl;
    }
    for(vector<Hanghoa> :: iterator x = san_pham.begin();x!= san_pham.end();x++){
        file << x->layMaDonHang() << "," << x->layTenSanPham() << "," << x->layGiaThanh() << "," << x->laySoLuong() << endl;
    }
    file.close();
}

int main()
{
    GioHang quay_thanh_toan;
    vector<Hanghoa> danh_sach_san_pham;
    doc_file(danh_sach_san_pham);
    giaoDienChinh(danh_sach_san_pham, quay_thanh_toan);
}
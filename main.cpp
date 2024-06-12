#include <fstream>
#include <iostream>
#include <sstream>
#include <iomanip>
#include"HangHoa.cpp"
#include"GioHang.cpp"
#define PASSWORD 20232024

using namespace std;

void inDanhSachSanPham(vector<Hanghoa>& san_pham);
void themSanPham( vector<Hanghoa>& san_pham);
void xoaSanPham(vector<Hanghoa>& san_pham);
void sua_san_pham(vector<Hanghoa>& san_pham);
void swap(Hanghoa a, Hanghoa b);
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






void inDanhSachSanPham(vector<Hanghoa>& san_pham)
{
    cout << "\n<-------Danh sach cac san pham dang bay ban: ------->";
    for(int i = 0; i < san_pham.size(); i++)
    {
        cout << "\n" << i + 1 << ". ";
        san_pham[i].xuat();
    }
}

void themSanPham( vector<Hanghoa>& san_pham){
    Hanghoa new_item;
    new_item.nhap();
    san_pham.push_back(new_item);
}
void xoaSanPham(vector<Hanghoa>& san_pham){
    string ma_sp_xoa;
    cout << "Nhap ma san pham can xoa: ";
    cin.ignore();
    getline(cin,ma_sp_xoa);
    //chuc nang xoa san pham
    for (int i = 0; i < san_pham.size(); i++) {
        if (san_pham[i].layMaDonHang() == ma_sp_xoa) {
            san_pham.erase(san_pham.begin() + i);
            cout << "San pham da duoc xoa.\n";
            return;
        }
    }
    cout << "Khong tim thay san pham voi ma da nhap.\n";
}
void sua_san_pham(vector<Hanghoa>& san_pham){
    string masp;
    cout << "nhap ma so cua san pham can sua:";
    getline(cin,masp);
    for(int i = 0; i < san_pham.size(); i++){
        if(san_pham[i].layMaDonHang() == masp){
        string ten;
        string ma;
        double gia;
        int soluong;
         cout << "Nhap thong tin san pham moi: ";
        cout << "\nNhap ten san pham moi: ";
        getline(cin,ten);
        cout << "\nNhap ma san pham moi: ";
        getline(cin,ma);
        cout << "\nNhap gia thanh san pham moi: ";
        cin >> gia;
        cout << "\nNhap so luong san pham: ";
        cin >> soluong;
        san_pham[i].setTensp(ten);
        san_pham[i].setMasp(ma);
        san_pham[i].setGiasp(gia);
        san_pham[i].setSoLuong(soluong);
        }
    }
}
void swap(Hanghoa a, Hanghoa b){
    Hanghoa temp;
    temp = a;
    a = b;
    b = temp;
}
void sapXepTheoGia(vector<Hanghoa>& dssp){
    for(int i=0;i<dssp.size();i++){
        for(int j = i+1;j<dssp.size();j++){
            if(dssp[i].layGiaThanh() < dssp[j].layGiaThanh()){
                swap(dssp[i],dssp[j]);
            }
        }
    }
}
void sapXepTheoMaSanPham(vector<Hanghoa>& dssp){
    for(int i=0;i<dssp.size();i++){
        for(int j = i+1;j<dssp.size();j++){
            if(dssp[i].layMaDonHang() < dssp[j].layMaDonHang()){
                swap(dssp[i],dssp[j]);
            }
        }
    }
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
    cout << "|  2.  Sap xep theo ma san pham                                    |" << endl;
    cout << "|  2.  Sap xep theo ten san pham                                   |" << endl;
    cout << "|  3.  Quay lai trang chu                                          |" << endl;
    cout << "|*________________________________________________________________*|" << endl;
    cout <<" Nhap lua chon cua ban: ";
    cin >> luachon;
    switch(luachon){
        case(1):
            sapXepTheoGia(dssp);
            break;
        case(2):
            sapXepTheoMaSanPham(dssp);
            break;
        case(3):
            sapXepTheoTen(dssp);
            break;
    }
}
void timKiemTheoMaSanPham( vector<Hanghoa> san_pham){
    string ma_don_hang;
    bool isExist = false;
    cout << " Nhap ma don hang ban can tim kiem: ";
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
        cout << "Khong tim thay san pham voi ma da nhap.\n";
    }
}
void timKiemTheoTen( vector<Hanghoa> san_pham){
    string ten_san_pham;
    cout << "Nhap ten san pham ban muon tim: ";
    getline(cin,ten_san_pham);
    for(int i = 0; i < san_pham.size(); i++){
        if(san_pham[i].layTenSanPham() == ten_san_pham){
            san_pham[i].xuat();
            return;//return ngay tai day
        }
    }
    //neu khong tim thay thi thong bao
    cout << "Khong tim thay san pham voi ten da nhap.\n";

}
void giaoDienTimKiem( vector<Hanghoa> san_pham){
    int choice_;
    system("cls");
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
    system("cls"); 
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

    system("cls");
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
    system("cls");  
    cout << " __________________________________________________________________" << endl;
    cout << "|                      QUAN LI CUA HANG MINI                       |" << endl;
    cout << "|__________________________________________________________________|" << endl;
    cout << "|                                                                  |" << endl;
    cout << "|  1.  Tim kiem san pham                                           |" << endl;
    cout << "|  2.  Xuat hoa don mua hang                                       |" << endl;
    cout << "|  3.  Quyen chinh sua                                             |" << endl;
    cout << "|  4.  Thanh toan                                                  |" << endl;
    cout << "|  5.  Thoat                                                       |" << endl;
    cout << "|*________________________________________________________________*|" << endl;
    cout << "                                                                    " << endl;
    cout << "Nhap lua chon cua ban [1-5]: ";
    cin >> choice;
    switch(choice){
        case(1):
            giaoDienTimKiem(san_pham);
            break;
        case(2):
            // xuat_file(san_pham);
            break;
        case(3):
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
            giaoDienThanhToan(san_pham, quay_thanh_toan);
            break;
        case(5):
            cout <<"Cam on ban da su dung chuong trinh !";
            break;
        default:
            cout << "Lua chon cua ban chua hop le, vui long chon lai !";
            break;
    }
} while (choice != 4);
}

// void Hanghoa::tim_kiem(){}
void /*Hanghoa::*/doc_file(vector<Hanghoa> &san_pham){
    ifstream file("/home/hoangtung/Documents/giay.txt");
    if (!file.is_open()) {
        cout << "Không thể mở file!" << endl;
    }
    string line;
    int dem_vec = 0;
    // san_pham.size();
    while(getline(file,line)){
        istringstream iss(line);
        getline(iss,san_pham[dem_vec].ma_san_pham,',');
        getline(iss,san_pham[dem_vec].san_pham,',');
        getline(iss,san_pham[dem_vec].san_pham,',');
        iss >> san_pham[dem_vec].gia_thanh >> san_pham[dem_vec].so_luong ;
        // string ten {};
        // string ma {};
        // double gia {};
        // new Hanghoa a {ten , ma, gia};
        san_pham.push_back(san_pham[dem_vec]);
        dem_vec++;
    }
}

int main()
{
    GioHang quay_thanh_toan;
    vector<Hanghoa> danh_sach_san_pham;



    // mot vai test sample
    Hanghoa sanpham1("caPheDen", "CPH0001", 5000, 100); danh_sach_san_pham.push_back(sanpham1);
    Hanghoa sanpham2("caPheNau", "CPH0002", 5000, 100);  danh_sach_san_pham.push_back(sanpham2);
    Hanghoa sanpham3("caPheSua", "CPH0003", 5000, 100);  danh_sach_san_pham.push_back(sanpham3);
    Hanghoa sanpham4("caPheMuoi", "CPH0004", 7000, 100); danh_sach_san_pham.push_back(sanpham4);
    Hanghoa sanpham5("caPheTrung", "CPH0005", 8000, 100);  danh_sach_san_pham.push_back(sanpham5);
    Hanghoa sanpham6("Chocolate Bar","FB2101", 2000, 100);  danh_sach_san_pham.push_back(sanpham6);
    Hanghoa sanpham7("Granola","FB2201", 5000, 100);  danh_sach_san_pham.push_back(sanpham7);
    Hanghoa sanpham8("Greek Yogurt","FB2401", 3000, 100);  danh_sach_san_pham.push_back(sanpham8);
    Hanghoa sanpham9("Pasta","FB2601", 4000, 100);  danh_sach_san_pham.push_back(sanpham9);
    Hanghoa sanpham10("Canned Tuna","FB2801", 3500, 100);  danh_sach_san_pham.push_back(sanpham10);
    Hanghoa sanpham11("Green Tea","FB3001", 6000, 100);  danh_sach_san_pham.push_back(sanpham11);
    Hanghoa sanpham12("Olive Oil","FB2701", 15000, 100);  danh_sach_san_pham.push_back(sanpham12);
    Hanghoa sanpham13("Coconut Milk","FB3901", 4500, 100);  danh_sach_san_pham.push_back(sanpham13);
    Hanghoa sanpham14("Tomato Sauce","FB3701", 3000, 100);  danh_sach_san_pham.push_back(sanpham14);
    Hanghoa sanpham15("Instant Noodles","FB3301", 1500, 100);  danh_sach_san_pham.push_back(sanpham15);
    Hanghoa sanpham16("Peanut Butter","FB3101", 4500, 100);  danh_sach_san_pham.push_back(sanpham16);
    Hanghoa sanpham17("Pho Noodles","VF5101", 3500, 100);  danh_sach_san_pham.push_back(sanpham17);


    giaoDienChinh(danh_sach_san_pham, quay_thanh_toan); 
    

}
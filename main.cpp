
#include <fstream>
#include <iostream>
#include <sstream>
#include <iomanip>
#include"HangHoa.cpp"
#include"GioHang.cpp"
#define PASSWORD 20232024

void them_san_pham( vector<Hanghoa>& san_pham){
    Hanghoa new_item;
    new_item.nhap();
    san_pham.push_back(new_item);
}
void xoa_san_pham(vector<Hanghoa>& san_pham){
    string ma_sp_xoa;
    cout << "Nhap ma san pham can xoa: ";
    getline(cin,ma_sp_xoa);
    
}
void sua(vector<Hanghoa>& san_pham){

}
void swap(Hanghoa a, Hanghoa b){
    Hanghoa temp;
    temp = a;
    a = b;
    b = temp;
}
void sapxeptheogia(vector<Hanghoa>& dssp){
    for(int i=0;i<dssp.size();i++){
        for(int j = i+1;j<dssp.size();j++){
            if(dssp[i].lay_gia_thanh() < dssp[j].lay_gia_thanh()){
                swap(dssp[i],dssp[j]);
            }
        }
    }
}
void sapxeptheomasanpham(vector<Hanghoa>& dssp){
    for(int i=0;i<dssp.size();i++){
        for(int j = i+1;j<dssp.size();j++){
            if(dssp[i].lay_ma_don_hang() < dssp[j].lay_ma_don_hang()){
                swap(dssp[i],dssp[j]);
            }
        }
    }
}
void sapxeptheoten(vector<Hanghoa>& dssp){
    
}
void sapxep(vector<Hanghoa>& dssp){
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
            sapxeptheogia(dssp);
            break;
        case(2):
            sapxeptheomasanpham(dssp);
            break;
        case(3):
            sapxeptheoten(dssp);
            break;
    }
}
void tim_kiem_theo_ma_san_pham( vector<Hanghoa> san_pham){
    string ma_don_hang;
    cout << " Nhap ma don hang ban can tim kiem: ";
    getline(cin,ma_don_hang);
    for(Hanghoa ma_DH : san_pham){
        if(ma_DH.lay_ma_don_hang() == ma_don_hang){
            ma_DH.xuat();
        }
    }
}
void tim_kiem_theo_ten( vector<Hanghoa> san_pham){
    string ten_san_pham;
    cout << "Nhap ten san pham ban muon tim: ";
    getline(cin,ten_san_pham);
    for(Hanghoa ten_sp : san_pham){
        if(ten_sp.lay_ten_san_pham() == ten_san_pham){
            ten_sp.xuat();
        }
    }
}
void giao_dien_tim_kiem( vector<Hanghoa> san_pham){
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
            tim_kiem_theo_ten(san_pham);
            break;
        case (2):
            tim_kiem_theo_ma_san_pham(san_pham);
            break;
        case (3):
            break;
    }
}
void giao_dien_chinh_sua( vector<Hanghoa>& san_pham){
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
                them_san_pham(san_pham);
                break;
            case (2):
                xoa_san_pham(san_pham);
                break;
            case (3):
                sua(san_pham);
                break;
            case (4):
                break;
            default:
                cout << "Khong co tinh nang da nhap !";
                break;
            }
    
}
void giao_dien_chinh( vector<Hanghoa>& san_pham){
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
    cout << "|  4.  Thoat                                                       |" << endl;
    cout << "|*________________________________________________________________*|" << endl;
    cout << "                                                                    " << endl;
    cout << "Nhap lua chon cua ban [1-5]: ";
    cin >> choice;
    switch(choice){
        case(1):
            giao_dien_tim_kiem(san_pham);
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
                giao_dien_chinh_sua(san_pham);
                break;
            }
            else{
                cout << "Mat khau khong hop le !";
                break;
            }
        case(4):
            cout <<"Cam on ban da su dung chuong trinh !";
            break;
        default:
            cout << "Lua chon cua ban chua hop le, vui long chon lai !";
            break;
    }
} while (choice != 4);
}

// void Hanghoa::tim_kiem(){}
void /*Hanghoa::*/xuat_file(vector<Hanghoa> san_pham){}

int main()
{
    vector<Hanghoa> danh_sach_san_pham;
    giao_dien_chinh(danh_sach_san_pham); 
}
#include<iostream>
#include<fstream>
#include<string>
#include<vector>

using namespace std;

class KhachHang {
    private:
        string hoten;
        string diachi;
        string ngaysinh;
        string sodienthoai;
    public:
        KhachHang() {
            hoten = "";
            diachi = "";
            ngaysinh = "";
            sodienthoai = "";
        }
        KhachHang(string hoten, string diachi, string ngaysinh, string sodienthoai) {
            this->hoten = hoten;
            this->diachi = diachi;
            this->ngaysinh = ngaysinh;
            this->sodienthoai = sodienthoai;
        }
        void ThongTin();
};

void KhachHang::ThongTin() {
    cout<<" - Ten khach hang: "<<hoten<<endl;
    cout<<" - Dia chi: "<<diachi<<endl;
    cout<<" - Ngay sinh: "<<ngaysinh<<endl;
    cout<<" - So dien thoai: "<<sodienthoai<<endl;
}

class LoaiPhong {
    private:
        string ma;
        string ten;
        int thang;
        int dien;
        int nuoc;
        int internet;
        
    public:
        LoaiPhong() {
            ma = "";
            ten = "";
            thang = 0;
            dien = 0;
            nuoc = 0;
            internet = 0;
        }

        LoaiPhong(string ma, string ten, int thang, int dien, int nuoc, int internet) {
            this->ma = ma;
            this->ten = ten;
            this->thang = thang;
            this->dien = dien;
            this->nuoc = nuoc;
            this->internet = internet;
        }

        void Sua();
        void ThongTin();
};

void LoaiPhong::ThongTin() {
    cout<<"* "<<ten<<" ("<<ma<<"): "<<endl;
    cout<<" - Tien thang: "<<thang<<endl;
    cout<<" - Tien dien: "<<dien<<endl;
    cout<<" - Tien nuoc: "<<nuoc<<endl;
    cout<<" - Tien internet: "<<internet<<endl;
}

void LoaiPhong::Sua() {
    system("cls");
    cout<<"---SUA LOAI PHONG---"<<endl;
    ThongTin();
    cout<<"-NHAP THONG TIN SUA-"<<endl;
    cout<<"Ma loai phong: ";
    cin>>ma;
    cout<<"Ten loai phong: ";
    cin>>ten;
    cout<<"Tien thang: ";
    cin>>thang;
    cout<<"Tien dien: ";
    cin>>dien;
    cout<<"Tien nuoc: ";
    cin>>nuoc;
    cout<<"Tien internet: ";
    cin>>internet;
}

class Phong{
    private:
        string maphong;
        string maloaiphong;
        bool trangthai;
        KhachHang khachhang;
        string ngaythue;

    public:

        Phong() {
            this->maphong = "";
            this->maloaiphong = "";
            this->trangthai = false;
            this->khachhang = KhachHang();
            this->ngaythue = "";
        }

        Phong(string maphong, string maloaiphong) {
            this->maphong = maphong;
            this->maloaiphong = maloaiphong;
            this->trangthai = false;
            this->khachhang = KhachHang();
            this->ngaythue = "";

        }

        Phong(string maphong, string maloaiphong, KhachHang khachhang, string ngaythue) {
            this->maphong = maphong;
            this->maloaiphong = maloaiphong;
            this->trangthai = true;
            this->khachhang = khachhang;
            this->ngaythue = ngaythue;
        }

        void ThongTinKhachHang();
        void ThongTin();

};

void Phong::ThongTinKhachHang() {
    khachhang.ThongTin();
}

void Phong::ThongTin() {
    cout<<" - Phong : "<<maphong<<endl;
}

class DanhSachPhong{
    private:
        vector<Phong> phong;
        vector<LoaiPhong> loaiphong;
        const string fLoaiPhongName = "LoaiPhong.bin";
        const string fPhongName = "Phong.bin";
        void readLP() {
            fstream fLoaiPhong;
            fLoaiPhong.open(fLoaiPhongName, std::fstream::binary);
            LoaiPhong p;
            while (fLoaiPhong)
            {
                fLoaiPhong.read((char*)&p, sizeof(p));
                loaiphong.push_back(p);
            }
            fLoaiPhong.close();
        }

        void writeLP() {
            fstream fLoaiPhong;
            fLoaiPhong.open(fLoaiPhongName, std::fstream::binary);
            for(vector<LoaiPhong>::iterator p = loaiphong.begin(); p!=loaiphong.end(); p++) {
                fLoaiPhong.write((char*)&p, sizeof(p));
            }
            fLoaiPhong.close();
        }

        void read() {
            fstream fPhong;
            fPhong.open(fPhongName, std::fstream::binary);
            Phong p;
            while (fPhong)
            {
                fPhong.read((char*)&p, sizeof(p));
                phong.push_back(p);
            }
            fPhong.close();
        }

        void write() {
            fstream fPhong;
            fPhong.open(fPhongName, std::fstream::binary);
            for(vector<Phong>::iterator p = phong.begin(); p!=phong.end(); p++) {
                fPhong.write((char*)&p, sizeof(p));
            }
            fPhong.close();
        }

    public:
        DanhSachPhong(){
            readLP();
            read();
        }

        void ThongTinLoaiPhong();
        void ThemLoaiPhong();
        void ThuePhong();
        void PhongDaThue();
        void ChinhSuaPhong();
        void XoaPhong();
        void DanhSachThuePhong();
};

void DanhSachPhong::ThongTinLoaiPhong() {
    system("cls");
    cout << "***** Cac Loai Phong *****\n";
    for(vector<LoaiPhong>::iterator p = loaiphong.begin(); p!=loaiphong.end(); p++) {
        p -> ThongTin();
    }
}

void DanhSachPhong::ThemLoaiPhong() {
    system("cls");
    string ma, ten;
    int thang, dien, nuoc, internet;
    cout<<"---THEM LOAI PHONG---"<<endl;
    cout<<"Ma loai phong: ";
    cin>>ma;
    cout<<"Ten loai phong: ";
    cin>>ten;
    cout<<"Tien thang: ";
    cin>>thang;
    cout<<"Tien dien: ";
    cin>>dien;
    cout<<"Tien nuoc: ";
    cin>>nuoc;
    cout<<"Tien internet: ";
    cin>>internet;
    loaiphong.push_back(LoaiPhong(ma, ten, thang, dien, nuoc, internet));
    writeLP();
}

void DanhSachPhong::ThuePhong() {
    system("cls");
    string maphong, loaiphong, hoten, diachi, ngaysinh, sodienthoai, ngaythue;

    cout<<"---THUE PHONG---"<<endl;
    cout << "\nNgay Thue: ";
    cin >> ngaythue;
    cout << "Chon Loai Phong: ";
    cin >> loaiphong;
    cout << "Nhap STT Phong: ";
    cin >> maphong;
    cout << "Nhap Ho Ten: ";
    cin.ignore(1); //doc va xoa 1 ki tu con trong trong bo nho dem
    getline(cin, hoten);
    cout << "Nhap Dia Chi: ";
    getline(cin, diachi);
    cout << "Nhap Ngay Sinh (dd/mm/yyyy): ";
    getline(cin, ngaysinh);
    cout << "Nhap So Dien Thoai: ";
    getline(cin, sodienthoai);
    phong.push_back(Phong(maphong, loaiphong, KhachHang(hoten, diachi, ngaysinh, sodienthoai), ngaythue));
    write();
}

void DanhSachPhong::ChinhSuaPhong() {

}

void DanhSachPhong::PhongDaThue() {
    system("cls");
    cout<<"---PHONG DA THUE---"<<endl;
    for(vector<Phong>::iterator p = phong.begin(); p!=phong.end(); p++) {
        p->ThongTin();
    }
}

void DanhSachPhong::DanhSachThuePhong() {
    system("cls");
    cout<<"---KHACH HANG THUE---"<<endl;
    for(vector<Phong>::iterator p = phong.begin(); p!=phong.end(); p++) {
        p->ThongTinKhachHang();
    }
}

int main() {

    return 0;
}
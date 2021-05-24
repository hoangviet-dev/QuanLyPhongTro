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
        void Edit(string hoten, string diachi, string ngaysinh, string sodienthoai) ;
        void ThongTin();
        string ToString();
        string ToInfo();
};


string KhachHang::ToInfo(){
	return " - Ten khach hang: " + hoten+"\n"+ " - Dia chi: " + diachi+"\n"+" - Ngay sinh: " + ngaysinh+"\n"+ " - So dien thoai: " + sodienthoai+"\n";
}

string KhachHang::ToString(){
	return hoten+"\n"+diachi+"\n"+ngaysinh+"\n"+sodienthoai+"\n";
}
void KhachHang::Edit(string hoten, string diachi, string ngaysinh, string sodienthoai) {
    this->hoten = hoten;
    this->diachi = diachi;
    this->ngaysinh = ngaysinh;
    this->sodienthoai = sodienthoai;
}

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
        string ToString();
};

string LoaiPhong::ToString(){
	return ma+"\n"+ten+"\n"+to_string(thang)+"\n"+to_string(dien)+"\n"+to_string(nuoc)+"\n"+to_string(internet)+"\n";
}

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

        bool KiemMaPhong(string maphong);

        void ThongTinKhachHang();
        void ThongTin();
        KhachHang GetKhachHang();
        void Edit(string maphong, string maloaiphong, KhachHang khachhang, string ngaythue);
        string ToString();
};

KhachHang Phong::GetKhachHang(){
    return this->khachhang;
}

string Phong::ToString(){
	return maphong+"\n"+maloaiphong+"\n"+(trangthai?"1":"0")+"\n"+khachhang.ToString()+ngaythue+"\n";
}

void Phong::Edit(string maphong, string maloaiphong, KhachHang khachhang, string ngaythue) {
    this->maphong = maphong;
    this->maloaiphong = maloaiphong;
    this->trangthai = true;
    this->khachhang = khachhang;
    this->ngaythue = ngaythue;
}

bool Phong::KiemMaPhong(string maphong){
    return this->maphong == maphong;
}

void Phong::ThongTinKhachHang() {
    khachhang.ThongTin();
}

void Phong::ThongTin() {
    cout<<" - Phong : "<<maphong<<endl;
    cout<<" - Ma loai phong : "<<maloaiphong<<endl;
    cout<<" - trang thai: "<<trangthai?"duoc thue":"chua duoc thue";
    khachhang.ThongTin();
    cout<<" - ngay thue : "<<ngaythue<<endl;
}

class DanhSachPhong{
    private:
        vector<Phong> phong;
        vector<LoaiPhong> loaiphong;
        const string fLoaiPhongName = "LoaiPhong.txt";
        const string fPhongName = "Phong.txt";
        void readLP() {
            ifstream fLoaiPhong;
            fLoaiPhong.open(fLoaiPhongName, ios::in);
		    string ma, ten;
		    int thang, dien, nuoc, internet, n;
            if (fLoaiPhong.is_open()){
		    	fLoaiPhong>>n;
		    	for	(int i=0; i< n; i++){
	                fLoaiPhong>>ma;
	                fLoaiPhong.ignore(1);
					fLoaiPhong>>ten;
	                fLoaiPhong.ignore(1);
					fLoaiPhong>>thang>>dien>>nuoc>>internet;
	                loaiphong.push_back(LoaiPhong(ma, ten, thang, dien, nuoc, internet));
				}
            }
            fLoaiPhong.close();
        }

        void writeLP() {
            ofstream fLoaiPhong;
            fLoaiPhong.open(fLoaiPhongName, ios::out);
            fLoaiPhong<<loaiphong.size()<<endl;
            for(vector<LoaiPhong>::iterator p = loaiphong.begin(); p!=loaiphong.end(); p++) {
                fLoaiPhong<<p->ToString();
            }
            fLoaiPhong.close();
        }

        void read() {
            ifstream fPhong;
            fPhong.open(fPhongName, ios::in);
            Phong p;
    		string maphong, loaiphong, hoten, diachi, ngaysinh, sodienthoai, ngaythue;
    		int n;
    		bool trangthai;
            if (fPhong.is_open()){
		    	fPhong>>n;
		    	for	(int i=0; i< n; i++){
	                fPhong>>maphong;
	                fPhong.ignore(1);
					fPhong>>loaiphong;
	                fPhong.ignore(1);
	                fPhong>>trangthai;
					fPhong>>hoten;
	                fPhong.ignore(1);
					fPhong>>diachi;
	                fPhong.ignore(1);
					fPhong>>ngaysinh;
	                fPhong.ignore(1);
					fPhong>>sodienthoai;
	                fPhong.ignore(1);
					fPhong>>ngaythue;
	                fPhong.ignore(1);
	                
    				phong.push_back(Phong(maphong, loaiphong, KhachHang(hoten, diachi, ngaysinh, sodienthoai), ngaythue));
				}
			}
            fPhong.close();
        }

        void write() {
            ofstream fPhong;
            fPhong.open(fPhongName, ios::out);
            fPhong<<phong.size()<<endl;
            for(vector<Phong>::iterator p = phong.begin(); p!=phong.end(); p++) {
                fPhong<<p->ToString();
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
        void TraPhong();
        void DanhSachThuePhong();
};

void DanhSachPhong::ThongTinLoaiPhong() {
    system("cls");
    cout << "***** Cac Loai Phong *****\n";
    for(vector<LoaiPhong>::iterator p = loaiphong.begin(); p!=loaiphong.end(); p++) {
        p -> ThongTin();
    }
    system("pause");
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
    system("pause");
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
    system("pause");
}

void DanhSachPhong::ChinhSuaPhong() {
    system("cls");
    cout<<"---CHIN SUA---"<<endl;
    string _maphong;
    cout<<"Nhap STT phong can sua: ";
    cin>>_maphong;
    Phong *p = NULL;
    do {
        for(int i =0; i < phong.size(); i++) {
            if (phong[i].KiemMaPhong(_maphong)){
                p = &phong[i];
                break;
            }
        }
        if (p==NULL && _maphong != "") {
            cout<<"Khong tim thay phong, vui long chon lai!!!\nNhap STT phong can sua:";
            cin>>_maphong;
        }
    } while (p==NULL && _maphong != "");
    if (p!=NULL) {
        cout<<"Thong tin:\n";
        p->ThongTin();
        string maphong, loaiphong, hoten, diachi, ngaysinh, sodienthoai, ngaythue;
        cout<<"Nhap lai thong tin cua phong co so thu tu "<<_maphong<<": \n";
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
        p->GetKhachHang().Edit(hoten, diachi, ngaysinh, sodienthoai);
        p->Edit(maphong, loaiphong, p->GetKhachHang(), ngaythue);
        cout<<"Da chinh sua\n";
        write();
    }
    system("pause");
    
}

void DanhSachPhong::TraPhong() {
    system("cls");
    cout<<"---TRA PHONG---"<<endl;
    string maphong;
    cout<<"Nhap STT phong can tra: ";
    cin>>maphong;
    do {
        for(vector<Phong>::iterator p = phong.begin(); p!=phong.end(); p++) {
            if (p->KiemMaPhong(maphong)){
                phong.erase(p);
                cout<<"Da tra phong thanh cong";
                write();
    			system("pause");
                return;
            }
        }
        if (maphong != "") {
            cout<<"Khong tim thay phong, vui long chon lai!!!\nNhap STT phong can tra:";
            cin>>maphong;
        }
    } while (maphong != "");
    system("pause");
}

void DanhSachPhong::PhongDaThue() {
    system("cls");
    cout<<"---PHONG DA THUE---"<<endl;
    for(vector<Phong>::iterator p = phong.begin(); p!=phong.end(); p++) {
        p->ThongTin();
    }
    system("pause");
}

void DanhSachPhong::DanhSachThuePhong() {
    system("cls");
    cout<<"---KHACH HANG THUE---"<<endl;
    ofstream fKH;
    fKH.open("KhachHang.txt", ios::out);
    int i = 0;
    for(vector<Phong>::iterator p = phong.begin(); p!=phong.end(); p++) {
        p->ThongTinKhachHang();
        fKH<<"*Khach hang "<<++i<<"*"<<endl;
        fKH<<p->GetKhachHang().ToInfo();
    }
    fKH.close();
    system("pause");
}

void menu() {
    system("cls");
    cout << "********* QUAN LI CHO THUE PHONG TRO *********\n";
    cout << "\n  1. Thong Tin Phong.";
    cout << "\n  2. Trang Thai Phong.";
    cout << "\n  3. Thue Phong.";
    cout << "\n  4. Sua Thong Tin Phong.";
    cout << "\n  5. Tra Phong.";
    cout << "\n  6. Danh Sach KH Thue Phong.";
    cout << "\n  7. Them loai phong.";
    cout << "\n  8. Exit";
    cout << "\nNhap Tuy Chon <1-8>: ";
}

int main() {
    DanhSachPhong p;
	int tuychon;
	do
	{
        menu();
        cin >> tuychon;
		switch (tuychon)
		{
		case 1:
		   p.ThongTinLoaiPhong();
		   break;
		case 2:
		   p.PhongDaThue();
		   break;
		case 3:
		   p.ThuePhong();
		   break;
		case 4:
		   p.ChinhSuaPhong();
		   break;
		case 5:
		   p.TraPhong();
		   break;
		case 6:
		   p.DanhSachThuePhong();
		   break;
		case 7:
		   p.ThemLoaiPhong();
		   break;
		case 8:
		   cout << "\nTHANK YOU!";
		   break;
		default:
		   cout << "\nNhap Lai Tuy Chon.";
		   system("pause");
		   break;
		}
    } while (tuychon != 8);
    return 0;
}

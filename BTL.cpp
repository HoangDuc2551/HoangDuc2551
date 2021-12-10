//BTL nhom 38
#include <iostream>
#include <iomanip>
#include <string>
#include <cstdlib>
using namespace std;
//Tao Class Sinh Vien
class SinhVien {
protected:
	string HoTenSV;
	string LopSV;
	string MSsv;
public:
	string getMSsv();
	void Input(); //nhap thong tin sinh vien
	void Output();// xuat thong tin sinh vien
};
//Tao Class Diem
class Diem {
protected:
	string XepLoaiSV;
	float DiemCC, DiemBT, DiemGK, DiemCK;
public:
	void Input(); //nhap Diem
	void Output();// xuat Diem
	float TinhDiemTB();
	string XepLoai();

};

//Tao Class ALL thuc hien cac thao cua sinh vien va diem
class all :public SinhVien, public Diem {
public:
	void Nhap();
	void Xuat();
};
all arr[100];
int index = 0;
// Tao Class Lop chua thong tin cua tat ca sinh vien
class Lop {
public:
	void Menu();
	void ThongTinSV();
};
int main() {
	string f;
	Lop* l = new Lop;
	l->Menu();
	cin.get();
	//	l->TimKiemSV(f);
	delete l;
}
void Lop::ThongTinSV()
{
	cout << "\t \t ===================  THONG TIN SINH VIEN  ===================" << left << endl;
	cout << setw(12) << "MSSV" << setw(20) << "Ho Ten" << setw(20) << "Lop Hoc" << setw(10) << "Chuyen Can" << setw(10) << "Bai Tap"
		<< setw(10) << "Giua Ky" << setw(10) << "Cuoi Ky" << setw(10) << "TBM" << setw(10) << "Xep Loai" << endl;
}

// Class SinhVien
void SinhVien::Input() {
	cin.ignore();
	cout << "MSSV : ";
	getline(cin, MSsv);
	cout << "Ho Ten : ";
	getline(cin, HoTenSV);
	cout << "Lop Hoc : ";
	getline(cin, LopSV);
}
void SinhVien::Output() {
	cout << setw(12) << MSsv << setw(20) << HoTenSV << setw(20) << LopSV;
}
string SinhVien::getMSsv() {
	return MSsv;
}

// Class Diem
void Diem::Input() {
	cout << "Diem chuyen can : ";
	cin >> DiemCC;
	cout << "Diem bai tap : ";
	cin >> DiemBT;
	cout << "Diem giua ky : ";
	cin >> DiemGK;
	cout << "Diem cuoi ky : ";
	cin >> DiemCK;
}
float Diem::TinhDiemTB() {
	return  (DiemCC * 0.1 + DiemBT * 0.1 + DiemGK * 0.2 + DiemCC * 0.4);
}

string Diem::XepLoai()
{
	float a = TinhDiemTB();
	if (a >= 4.0 && a <= 5.4)
	{
		return XepLoaiSV = "D";
	}
	else if (a >= 5.5 && a <= 6.9)
	{
		return XepLoaiSV = "C";
	}
	else if (a >= 7.0 && a <= 8.4)
	{
		return XepLoaiSV = "B";
	}
	else if (a >= 8.5 && a <= 10)
	{
		return XepLoaiSV = "A";
	}
	else
	{
		return XepLoaiSV = "F";
	}
}
void Diem::Output() {
	cout << setw(10) << DiemCC << setw(10) << DiemBT << setw(10) << DiemGK << setw(10) << DiemCK << setw(10) << TinhDiemTB() << setw(10) << XepLoai() << endl;
}
// Class ALL
void all::Nhap() {
	SinhVien::Input();
	Diem::Input();

}
void all::Xuat() {
	SinhVien::Output();
	Diem::Output();
}
// Class Lop
void Lop::Menu() {
	int luachon;
	int dem = 0;
	float tb;
	int sx;
	do {
		system("cls");
		cout << "\n\n\t\t\t============ XIN MOI LUA CHON TINH NANG ============";
		cout << "\n\t\t1. Them Sinh Vien Vao Danh Sach." << endl;
		cout << "\n\t\t2. Hien Thi Danh Sach Sinh Vien." << endl;
		cout << "\n\t\t3. Tim Kiem Sinh Vien Co Trong Danh Sach." << endl;
		cout << "\n\t\t4. Xoa Sinh Vien." << endl;
		cout << "\n\t\t5. Tim Kiem Diem TB." << endl;
		cout << "\n\t\t6. Sap Xep Diem TB." << endl;
		cout << "\n\t\t7. Thoat Khoi Chuong Trinh." << endl;
		cout << "\n\t\tTinh Nang Ban Chon La : ";
		cin >> luachon;
		system("cls");
		all* a;
		string f;
		switch (luachon) {
		case 1:
			int n;
			cout << "So luong sinh vien : ";
			cin >> n;
			cout << endl;
			for (int i = 0; i < n; i++)
			{
				all sv;
				sv.Nhap();
				arr[index] = sv;
				index++;
				cout << endl;

			}
			break;
		case 2:
			cout << "\t \t 0.0.0===================  THONG TIN SINH VIEN  ===================0.0.0" << left << endl;
			cout << setw(12) << "MSSV" << setw(20) << "HoTen" << setw(20) << "LopHoc" << setw(10) << "ChuyenCan" << setw(10) << "BaiTap"
				<< setw(10) << "GiuaKy" << setw(10) << "CuoiKy" << setw(10) << "TBM" << setw(10) << "XepLoai" << left << endl;
			for (int i = 0; i < index; i++)
			{
				arr[i].Xuat();
			}
			break;
			break;
		case 3:
			if(n > 0) {
                    cout << "\n 3. Tim kiem sinh vien theo danh sach.";
                    char strTen[20];
                    cout << "\nNhap ten de tim kiem: "; fflush(stdin); gets(strTen);
                    //void SinhVien ((arr[index], strTen, n));
                }else{
                    cout << "\nDanh sach sinh vien hien chua co!";
                }
			break;
		case 4:
			if(n > 0) {
                    int MSSV;
                    cout << "\n 4. Xoa sinh vien.";
                    cout << "\n Nhap MSSV: "; cin >> MSSV;
                    if ((arr[index], MSSV,n) == 1) {
                     printf("\nSinh vien co MSSV =%d da bi xoa.", &MSSV);
                     n--;
                    }
				 } else{
                    cout << "\n Danh sach sinh vien hien chua co!";
                }
			break;
		case 5:
		  if(n>0) {
		  	 cout << "\n 5. Tim kiem diemTB. ";
		  	 float a;
		  	 cout << "\nNhap diem de tim kiem: "; fflush(stdin); float(DTB);
		  	 //timkiemdiemTB()
		  	 } else{
		  	 	cout << "\nDanh sach sinh vien hien chua co!";
			   }
			break;
		case 6:
		    if(n > 0) {
                    cout << "\n 6. Sap xep diem trung binh. ";
                    float a ((arr[index], n));
                    float Diem ((arr[index],a));
                }else{
                    cout << "\n Danh sach sinh vien hien chua co!";
                }
			break;
		case 7:
			exit(0);
		default:
			cout << "Ban vui long nhap lai!" << endl;
		}
		cout << endl;
		system("pause");
	} while (luachon != 7);
}

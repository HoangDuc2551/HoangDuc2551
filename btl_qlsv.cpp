//6051071032
//Nguyen Le Hoang Duc
#include<iostream> 
#include<cstring>
#include<string>
#include<conio.h>
#define MAX 100
using namespace std;
/////////////////////
class People { 
 protected:
	 char hoten[20], noisinh[70], gioitinh[10];
	 int dd, mm, yyyy;
};
/////////////////////
class Diem{
 protected:
	 string ten_mon_hoc[8];
	 float mon_hoc[8];
	 int so_tin_chi[8];
	 int size_mh;
};
//////////////////////
class Sinhvien :public People,public Diem {
 private:
	 int MSSV;
	 char nganh[30];
	 float dtb;
 public:
	Sinhvien();//hàm tạo không tham số
	Sinhvien(int, char [20], int, int, int, char [10] , char [70],
	 char [30], int, string [8], float [8], int [8], float );//hàm tạo có tham số
	Sinhvien(const Sinhvien&);//hàm tạo sao chép
	~Sinhvien();//hàm hủy
	int getMSSV();//trả về MSSV
	int getNgay();//trả về ngày sinh
	int getThang();//trả về tháng sinh
	int getNam();//trả về năm sinh
	char getTen();//trả về họ tên
	char getGT();//trả về giới tính
	char getNoiSinh();//trả về nơi sinh
	char getNganh();//trả về ngành học
	float getdtb();//trả về điểm trung bình
	bool operator>(Sinhvien sv);//toán tử so sánh >
	bool operator<(Sinhvien sv);//toán tử so sánh <
	bool operator==(Sinhvien sv);//toán tử so sánh ==
    bool operator>=(Sinhvien sv);//toán tử so sánh >=
	bool operator<=(Sinhvien sv);//toán tử so sánh <=
	bool operator!=(Sinhvien sv);//toán tử so sánh !=
	friend ostream& operator<<(ostream&, Sinhvien&);//toán tử xuất
	friend istream& operator>>(istream&, Sinhvien&);//toán tử nhập
	void xemdiem();
};
////////////////////////////////////////////hàm tạo sao chép
Sinhvien::Sinhvien(const Sinhvien& x) {
	MSSV = x.MSSV;
	dd = x.dd;
	mm = x.mm;
	yyyy = x.yyyy;
	strcpy(hoten, x.hoten);
	strcpy(gioitinh, x.gioitinh);
	strcpy(noisinh, x.noisinh);
	strcpy(nganh, x.nganh);
	size_mh=x.size_mh;
	for(int i=0;i<size_mh;i++){
		ten_mon_hoc[i]=x.ten_mon_hoc[i];
		mon_hoc[i]=x.mon_hoc[i];
		so_tin_chi[i]=x.so_tin_chi[i];
	}
	dtb=x.dtb;
}
/////////////////////////////////////hàm tạo có tham số
Sinhvien::Sinhvien(int Id, char ten[20], int ngay, int thang, int nam, char gioi[10], char noisinh[70], char nganh[30], int n ,string tenmh[8], float diem[8], int tc[8], float dtb) {
	MSSV = Id;
	strcpy(hoten, ten);
	dd = ngay;
	mm = thang;
	yyyy = nam;
	strcpy(gioitinh, gioi);
	strcpy(noisinh, noi);
	strcpy(this->nganh,nganh);
	for(int i=0;i<n;i++){
		ten_mon_hoc[i]=tenmh[i];
		mon_hoc[i]=diem[i];
		so_tin_chi[i]=tc[i];
	}
	this->dtb=dtb;
}
//////////////////////////////////////////hàm tạo không có tham số
Sinhvien::Sinhvien() {
	dd = yyyy = mm = 0;
	strcpy(hoten, "");
	strcpy(gioitinh, "");
	strcpy(noisinh, "");
	MSSV = 0;
	strcpy(nganh,"");
	size_mh=0;
	dtb=0.0;
}
///////////////////////////////////////
Sinhvien::~Sinhvien() {}////////////////hàm hủy
//////////////////////// hàm lấy giá trị
int Sinhvien::getNgay(){ 
	return dd;
 }
int Sinhvien::getThang(){
	return mm;
 }
int Sinhvien::getNam(){
	return yyyy;
 }
char Sinhvien::getTen(){
	return hoten;
 }
char Sinhvien::getGT(){
	return gioitinh;
 }
char Sinhvien::getNoiSinh(){
	return noisinh;
 }
char Sinhvien::getNganh(){
	return nganh;
 }
int Sinhvien::getMSSV(){
	return MSSV;
 }
float Sinhvien::getdtb(){
	return dtb;
 }
///////////////////////////////////toán tử nhập
istream& operator>>(istream& is, Sinhvien& x) {
	cout << "Ma so sinh vien la: ";
	is >> x.MSSV;
	is.ignore(1);
	cout << "Ten la: ";
	is.getline(x.hoten,20);
	cout << "Noi sinh la: ";
	is.getline(x.noisinh,70);
	cout << "Gioi tinh la: ";
	is.getline(x.gioitinh,10);
	cout << "Nganh la: ";
	is.getline(x.nganh,30);
	cout << "Nhap ngay thang nam sinh la: " <<endl;
	cout<< "Ngay la: ";
	is >> x.dd;
	cout<< "Thang la: ";
	is >> x.mm;
	cout<< "Nam la: ";
	is >> x.yyyy;
	cout<< "So luong mon hoc can nhap diem la: ";
	is>>x.size_mh;
	for(int j=0;j<x.size_mh;j++){
		is.ignore(1);
		cout<< "Nhap ten mon hoc la: ";
		getline(is,x.ten_mon_hoc[j]);
		cout<< "Nhap diem la: ";
		is>>x.mon_hoc[j];
		cout<< "Tin chi la: ";
		is>>x.so_tin_chi[j];
	}
	x.dtb=diem_he_4(x.mon_hoc,x.so_tin_chi,x.size_mh);
	return is;
}
///////////////////////////////toán tử xuất
ostream& operator<<(ostream& os, Sinhvien& x) {
	os<< x.MSSV <<endl;
	os<< x.dd<<" " <<setw(2)<<x.mm<< " " <<setw(4)<<x.yyyy <<endl;
	os<< x.hoten <<endl;	
	os<< x.gioitinh <<endl;
	os<< x.noisinh <<endl;
	os<< x.nganh <<endl;
	os<< x.size_mh <<endl;
	for(int i=0;i<x.size_mh;i++){
		os<< x.ten_mon_hoc[i] <<endl;
		os<< x.mon_hoc[i] <<endl;
		os<< x.so_tin_chi[i] <<endl;
	}
	os<<setprecision(4);
	os<< x.dtb <<endl;
	return os;
}
//////////////////////////toán tử so sánh >
bool Sinhvien::operator>(Sinhvien sv){
	if(DTB()>sv.DTB())
	return 1;
	return 0;
	
}
//////////////////////////toán tử so sánh <
bool Sinhvien::operator<(Sinhvien sv){
	if(DTB()<sv.DTB())
	return 1;
	return 0;
}
/////////////////////////toán tử so sánh ==
bool Sinhvien::operator==(Sinhvien sv){
	if(DTB()==sv.DTB())
	return 1;
	return 0;
}
/////////////////////////toán tử so sánh >=
bool Sinhvien::operator>=(Sinhvien sv){
	if(DTB()>=sv.DTB())
	return 1;
	return 0;
	
}
/////////////////////////toán tử so sánh <=
bool Sinhvien::operator<=(Sinhvien sv){
	if(DTB()<=sv.DTB())
	return 1;
	return 0;
}
/////////////////////////toán tử so sánh !=
bool Sinhvien::operator!=(Sinhvien sv){
	if(DTB()!=sv.DTB())
	return 1;
	return 0;
}
/////////////////////////////////////////////////tính điểm trung bình hệ số 4
float diem_he_4(float diem[], int tin_chi[], int n){
	float b[n],Sum=0;
	int tch=0;
	for(int j=0;j<n;j++){
		if(diem[j]<=1.9) b[j]=0;
		else if(diem[j]>=2.0 && diem[j]<=3.9) b[j]=0.5;
		else if(diem[j]>=4.0 && diem[j]<=4.4) b[j]=1;
		else if(diem[j]>=4.5 && diem[j]<=5.4) b[j]=1.5;
		else if(diem[j]>=5.5 && diem[j]<=5.9) b[j]=2;
		else if(diem[j]>=6.0 && diem[j]<=6.9) b[j]=2.5;
		else if(diem[j]>=7.0 && diem[j]<=7.9) b[j]=3.0;
		else if(diem[j]>=8.0 && diem[j]<=8.4) b[j]=3.5;
		else if(diem[j]>=8.5 && diem[j]<=9.4) b[j]=3.8;
		else b[j]=4;
		tch+=tin_chi[j];
		Sum=Sum+b[j]*((float) tin_chi[j]);
	}
	float dtb=(float) Sum/tch;
	return dtb;
}
///////////////////////////////////////////////////////
int main(){
	Sinhvien a(),b(); 
    cout<< "Thong tin sinh vien la:" <<endl;
    cout<< a <<endl;
    cout<< b <<endl;
    cout<< "***************************\n";
    cout<< "Toan tu so sanh >,<,== "<<endl;
    if(a>b)
        cout<< "Diem tb a cao hon" <<endl;
    else if(a<b)
        cout<< "Diem tb a be hon b" <<endl;
    else if(a==b)
         cout<< "a=b" <<endl;
    else
         cout<< "khong xac dinh" <<endl;
    cout<< "***************************\n";
    cout<< "Toan tu so sanh >= <=, != " <<endl;
    if(a>=b)
    cout<< "Diem tb a lon hon hoac bang b" <<endl;
    if(a<=b)
    cout<< "Diem tb a be hon hoac bang b" <<endl;
    if(a!=b)
    cout<< "a!=b" <<endl;
    system("pause");
    return 0;
}
#include <iostream>
#include <string>
#include <fstream>
#include <Windows.h>
#include <unistd.h>
using namespace std;


struct {
	string jenisArray[100] = {"Persia", "Bengal", "Tutu", "Rom", "umai", "koti" };
	string warnaArray[100] = {"Putih", "Oren", "Merah","abu", "item", "ungu" }; 
	string mataArray[100]={"Merah", "Putih", "Ijo", "item", "pink", "red"};
	int hargaArray[100] = {2000000, 50000000, 1000000, 111111, 444444, 55555555};
	int umurArray[100] = {18, 1, 2, 10, 4, 5},i;
}Kucing;

int m = 0;
int w;
int *umur = Kucing.umurArray;
int *harga = Kucing.hargaArray;
int n = sizeof (Kucing.hargaArray)/sizeof(harga[0]);
int menu();	
void menambahKucing();
void tampilKucing();
void ubahKucing();
void hapusKucing();
int jumlah(int m);
int no;

// shell sort Ascending berdasarkan Umur
int sAumur(int *arr, int z){
	for (int gap = z/2; gap > 0; gap /= 2){
		for (int i = gap; i < z; i += 1){
			int temp = arr[i];
			int temp2 = Kucing.hargaArray[i];
			string temp3 = Kucing.jenisArray[i];
			string temp4 = Kucing.warnaArray[i];
			string temp5 = Kucing.mataArray[i];
			
			int j;
			for (j = i; j >= gap && arr[j - gap] > temp; j -= gap) arr[j] = arr[j - gap], Kucing.hargaArray[j] = Kucing.hargaArray[j - gap], Kucing.jenisArray[j] = Kucing.jenisArray[j - gap], Kucing.warnaArray[j] = Kucing.warnaArray[j - gap], Kucing.mataArray[j] = Kucing.mataArray[j - gap] ;
				arr[j] = temp;
				Kucing.hargaArray[j] = temp2;
				Kucing.jenisArray[j] = temp3;
				Kucing.warnaArray[j] = temp4;
				Kucing.mataArray[j] = temp5;

			}
	}
	
	return 0;
}

// shell sort Ascending berdasarkan Harga
int sAharga(int *arr2, int z){
	for (int gap = z/2; gap > 0; gap /= 2){
		for (int i = gap; i < z; i += 1){
			int temp = arr2[i];
			int temp2 = Kucing.umurArray[i];
			string temp3 = Kucing.jenisArray[i];
			string temp4 = Kucing.warnaArray[i];
			string temp5 = Kucing.mataArray[i];
			
			int j;
			for (j = i; j >= gap && arr2[j - gap] > temp; j -= gap) arr2[j] = arr2[j - gap], Kucing.umurArray[j] = Kucing.umurArray[j - gap], Kucing.jenisArray[j] = Kucing.jenisArray[j - gap], Kucing.warnaArray[j] = Kucing.warnaArray[j - gap], Kucing.mataArray[j] = Kucing.mataArray[j - gap] ;
				arr2[j] = temp;
				Kucing.umurArray[j] = temp2;
				Kucing.jenisArray[j] = temp3;
				Kucing.warnaArray[j] = temp4;
				Kucing.mataArray[j] = temp5;

			}
	}
	
	return 0;
}

// shell sort Descending berdasarkan Harga
int sDharga(int *arr3, int z){
	for (int gap = z/2; gap > 0; gap /= 2){
		for (int i = gap; i < z; i += 1){
			int temp = arr3[i];
			int temp2 = Kucing.umurArray[i];
			string temp3 = Kucing.jenisArray[i];
			string temp4 = Kucing.warnaArray[i];
			string temp5 = Kucing.mataArray[i];
			
			int j;
			for (j = i; j >= gap && arr3[j - gap] < temp; j -= gap) arr3[j] = arr3[j - gap], Kucing.umurArray[j] = Kucing.umurArray[j - gap], Kucing.jenisArray[j] = Kucing.jenisArray[j - gap], Kucing.warnaArray[j] = Kucing.warnaArray[j - gap], Kucing.mataArray[j] = Kucing.mataArray[j - gap] ;
				arr3[j] = temp;
				Kucing.umurArray[j] = temp2;
				Kucing.jenisArray[j] = temp3;
				Kucing.warnaArray[j] = temp4;
				Kucing.mataArray[j] = temp5;

			}
	}
	
	return 0;
}

// shell sort Descending berdasarkan Umur
int sDumur(int *arr4, int z){
	for (int gap = z/2; gap > 0; gap /= 2){
		for (int i = gap; i < z; i += 1){
			int temp = arr4[i];
			int temp2 = Kucing.hargaArray[i];
			string temp3 = Kucing.jenisArray[i];
			string temp4 = Kucing.warnaArray[i];
			string temp5 = Kucing.mataArray[i];
			
			int j;
			for (j = i; j >= gap && arr4[j - gap] < temp; j -= gap) arr4[j] = arr4[j - gap], Kucing.hargaArray[j] = Kucing.hargaArray[j - gap], Kucing.jenisArray[j] = Kucing.jenisArray[j - gap], Kucing.warnaArray[j] = Kucing.warnaArray[j - gap], Kucing.mataArray[j] = Kucing.mataArray[j - gap] ;
				arr4[j] = temp;
				Kucing.hargaArray[j] = temp2;
				Kucing.jenisArray[j] = temp3;
				Kucing.warnaArray[j] = temp4;
				Kucing.mataArray[j] = temp5;

			}
	}
	
	return 0;
}

int main(){
	
	int pilih = menu();
	while (pilih != 10){
		if (pilih == 1){
			cout << "================================" << endl;
			cout << "|    MENAMBAHKAN DATA KUCING   |" << endl;
			cout << "--------------------------------" << endl;
			menambahKucing();
			cout << "--------------------------------" << endl;
			cout << "|       DATA DITAMBAHKAN       |" << endl;
			cout << "================================" << endl;
			cout << "\n" << endl;
			system("pause");
			pilih = menu();
		}else if (pilih == 2){
			cout << "==========================================================================================" << endl;
			cout << "|                                      DATA KUCING                                       |" << endl;
			cout << "------------------------------------------------------------------------------------------" << endl;
			tampilKucing();
			cout << "\n" << endl;
			system("pause");
			pilih = menu();
		}else if (pilih == 3){
			cout << "==========================================================================================" << endl;
			cout << "|                                      DATA KUCING                                       |" << endl;
			cout << "------------------------------------------------------------------------------------------" << endl;
			tampilKucing();
			cout << "\n" << endl;
			cout << "================================" << endl;
			cout << "|     MENGUBAH DATA KUCING      |" << endl;
			cout << "--------------------------------" << endl;
			ubahKucing();
			cout << "--------------------------------" << endl;
			cout << "|          DATA DIUBAH          |" << endl;
			cout << "================================" << endl;
			cout << "\n" <<endl;
			cout << "==========================================================================================" << endl;
			cout << "|                                 PERUBAHAN DATA KUCING                                  |" << endl;
			cout << "------------------------------------------------------------------------------------------" << endl;
			tampilKucing();
			cout << "\n" << endl;
			system("pause");
			pilih = menu();
		}else if (pilih == 4){
			cout << "==========================================================================================" << endl;
			cout << "|                                      DATA KUCING                                       |" << endl;
			cout << "------------------------------------------------------------------------------------------" << endl;
			tampilKucing();
			cout << "\n" << endl;
			cout << "=================================" << endl;
			cout << "|     MENGHAPUS DATA KUCING     |" << endl;
			cout << "---------------------------------" << endl;
			hapusKucing();
			cout << "\n" << endl;
			cout << "==========================================================================================" << endl;
			cout << "|                                 PERUBAHAN DATA KUCING                                  |" << endl;
			cout << "------------------------------------------------------------------------------------------" << endl;
			tampilKucing();
			cout << "\n" << endl;
			system("pause");
			pilih = menu();
		}else if (pilih == 5){
			cout << "==========================================================================================" << endl;
			cout << "|                                      DATA KUCING                                       |" << endl;
			cout << "------------------------------------------------------------------------------------------" << endl;
			tampilKucing();
			cout << "==========================================================================================" << endl;
			w = jumlah(m);
			sAumur(umur, w);
			cout << "\n" << endl;
			cout << "==========================================================================================" << endl;
			cout << "|                         DATA KUCING BERDASARKAN UMUR (ASCENDING)                       |" << endl;
			cout << "------------------------------------------------------------------------------------------" << endl;
			tampilKucing();
			cout << "==========================================================================================" << endl;
			system("pause");
			pilih = menu();
		}else if (pilih == 6){
			cout << "==========================================================================================" << endl;
			cout << "|                                      DATA KUCING                                       |" << endl;
			cout << "------------------------------------------------------------------------------------------" << endl;
			tampilKucing();
			cout << "==========================================================================================" << endl;
			w = jumlah(m);
			sDumur(umur, w);
			cout << "\n" << endl;
			cout << "==========================================================================================" << endl;
			cout << "|                        DATA KUCING BERDASARKAN UMUR (DESCENDING)                       |" << endl;
			cout << "------------------------------------------------------------------------------------------" << endl;
			tampilKucing();
			cout << "==========================================================================================" << endl;
			system("pause");
			pilih = menu();
		}else if (pilih == 7){
			cout << "==========================================================================================" << endl;
			cout << "|                                      DATA KUCING                                       |" << endl;
			cout << "------------------------------------------------------------------------------------------" << endl;
			tampilKucing();
			cout << "==========================================================================================" << endl;
			w = jumlah(m);
			sAharga(harga, w);
			cout << "\n" << endl;
			cout << "==========================================================================================" << endl;
			cout << "|                        DATA KUCING BERDASARKAN HARGA (ASCENDING)                       |" << endl;
			cout << "------------------------------------------------------------------------------------------" << endl;
			tampilKucing();
			cout << "==========================================================================================" << endl;
			system("pause");
			pilih = menu();
		}else if (pilih == 8){
			cout << "==========================================================================================" << endl;
			cout << "|                                      DATA KUCING                                       |" << endl;
			cout << "------------------------------------------------------------------------------------------" << endl;
			tampilKucing();
			cout << "==========================================================================================" << endl;
			w = jumlah(m);
			sDharga(harga, w);
			cout << "\n" << endl;
			cout << "==========================================================================================" << endl;
			cout << "|                       DATA KUCING BERDASARKAN HARGA (DESCENDING)                       |" << endl;
			cout << "------------------------------------------------------------------------------------------" << endl;
			tampilKucing();
			cout << "==========================================================================================" << endl;
			system("pause");
			pilih = menu();
		}else if (pilih == 9){
			cout << "Nyangkyuuu" <<endl;
			cout << "\n" << endl;
			system("pause");
			exit(0);
		}else{
			cout << "PILIH 1 - 9 Saja" << endl;
			system("pause");
			pilih = menu();
		}
}
	return 0;
}

int menu(){
	int input;
	system("cls");
	cout << "==============================" << endl;
	cout << "     Data Kucing Toko KQD     " << endl;
	cout << "==============================" << endl;
	cout << "|1.| Tambah Data Kucing      |" << endl;
	cout << "|2.| Tampil Data Kucing      |" << endl;
	cout << "|3.| Ubah Data Kucing        |" << endl;
	cout << "|4.| Hapus Data Kucing       |" << endl;
	cout << "|5.| Urut Umur (Ascending)   |" << endl;
	cout << "|6.| Urut Umur (Descending)  |" << endl;
	cout << "|7.| Urut Harga (Ascending)  |" << endl;
	cout << "|8.| Urut Harga (Descending) |" << endl;
	cout << "|9.| Keluar                  |" << endl;
	cout << "==============================" << endl;
	cout << "PILIHAN :  "; cin >> input;
	cin.ignore(1, '\n');
	return input;
}

void menambahKucing(){
	int index = -1;
	for(int i = 0; i < 10; i++) {
		if(Kucing.jenisArray[i] == "") {
			index = i;
			break;
	}
	}
	if(index != -1){
	cout << "JENIS : "; getline(cin, *(Kucing.jenisArray+index));
	cout << "WARNA : "; getline(cin, *(Kucing.warnaArray+index));
	cout << "MATA  : "; getline(cin, *(Kucing.mataArray+index));
	cout << "UMUR  : "; cin >> *(Kucing.umurArray+index);
	cout << "HARGA : "; cin >> *(Kucing.hargaArray+index);
	}
}

int jumlah(int m){
	for(int i = 0; i < n; i++) {
		if(Kucing.umurArray[i] == 0){
			continue;
		}else{
			m = m + 1;
		}
}
	return m;
}

void tampilKucing(){
	int besar = *(&Kucing.jenisArray + 1) - Kucing.jenisArray;
	cout << "|NO\t|JENIS\t\t|WARNA\t\t|MATA\t\t|UMUR (Bulan)\t|HARGA (Rupiah)  |" << endl;
	cout << "==========================================================================================" << endl;
	for(int i = 0; i < besar; i++) {
		if(Kucing.jenisArray[i] == ""){
			continue;
		}else{
			cout << "|" << i+1 << "\t|";
			cout << *(Kucing.jenisArray+i) << "\t\t|";
			cout << *(Kucing.warnaArray+i) << "\t\t|";
			cout << *(Kucing.mataArray+i) << "\t\t|";
			cout << *(Kucing.umurArray+i) << "\t\t|";
			cout << *(Kucing.hargaArray+i) << endl;
			no++;
			}
}
}

void ubahKucing(){
	int pilihan;
	cout << "NO KUCING : "; cin >> pilihan;
	cin.ignore();
	cout << "JENIS     : "; getline(cin, *(Kucing.jenisArray+pilihan-1));
	cout << "WARNA     : "; getline(cin, *(Kucing.warnaArray+pilihan-1));
	cout << "MATA      : "; getline(cin, *(Kucing.mataArray+pilihan-1));
	cout << "UMUR      : "; cin >> *(Kucing.umurArray+pilihan-1);
	cout << "HARGA     : "; cin >> *(Kucing.hargaArray+pilihan-1);
}

void hapusKucing(){
	int hapus;
	int big = *(&Kucing.jenisArray + 1) - Kucing.jenisArray;
	cout << "NO KUCING : "; cin >> hapus;
	if (Kucing.jenisArray[hapus-1] == ""){
		cout << "Tidak ada data" <<endl;
	}else{
		for(int i = hapus-1; i <= no+1; i++){
			Kucing.jenisArray[i] = Kucing.jenisArray[i+1];
			if(big+1-i == 0){
				Kucing.jenisArray[i] = "";

			}
		}
	}
	int big2 = *(&Kucing.warnaArray + 1) - Kucing.warnaArray;
	if (Kucing.warnaArray[hapus-1] == ""){
		cout << "Tidak ada data" <<endl;
	}else{
		for(int i = hapus-1; i <= no+1; i++){
			Kucing.warnaArray[i] = Kucing.warnaArray[i+1];
			if(big2+1-i == 0){
				Kucing.warnaArray[i] = "";

			}
		}
	}
	int big5 = *(&Kucing.mataArray + 1) - Kucing.mataArray;
	if (Kucing.mataArray[hapus-1] == ""){
		cout << "Tidak ada data" <<endl;
	}else{
		for(int i = hapus-1; i <= no+1; i++){
			Kucing.mataArray[i] = Kucing.mataArray[i+1];
			if(big5+1-i == 0){
				Kucing.mataArray[i] = "";

			}
		}
	}
	int big3 = *(&Kucing.umurArray + 1) - Kucing.umurArray;
	if (Kucing.umurArray[hapus-1] == 0){
		cout << "Tidak ada data" <<endl;
	}else{
		for(int i = hapus-1; i <= no+1; i++){
			Kucing.umurArray[i] = Kucing.umurArray[i+1];
			if(big3+1-i == 0){
				Kucing.umurArray[i] = 0;

			}
		}
	}
	int big4 = *(&Kucing.hargaArray + 1) - Kucing.hargaArray;
	if (Kucing.hargaArray[hapus-1] == 0){
		cout << "Tidak ada data" <<endl;
	}else{
		for(int i = hapus-1; i <= no+1; i++){
			Kucing.hargaArray[i] = Kucing.hargaArray[i+1];
			if(big4+1-i == 0){
				Kucing.hargaArray[i] = 0;

			}
		}
	}
}

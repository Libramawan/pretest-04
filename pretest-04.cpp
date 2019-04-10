/**
 * Nama     : Prayudha Adhitia Libramawan
 * NPM      : 140810180008
 * Kelas    : B
 * Tanggal  : 10-04-2019
 * Deskripsi: Program ini berisi input data mahasiswa yang dapat dimanipulasi disorting berdasarkan IPK lalu dicetak
*/
#include <iostream>
#include <iomanip>

using namespace std;

struct ElemtList{
    char npm[14];
    char nama[40];
    float ipk;
    ElemtList* next;
};
typedef ElemtList* pointer;
typedef pointer List;

void createList(List& First);
void createElemt(pointer& pBaru);
void insertSortIPK(List& First,pointer pBaru);
void traversal (List First);

int main()
{	
    List mhs;
    int n,pilihan;
    pointer p;

    createList(mhs);
    do{
        system("cls");
        cout<<"Banyak mahasiswa : "; cin>>n;
        cout<<"==========================="<<endl; 
        for(int i=0;i<n;i++){
            cout<<"Input Mahasiswa ke-"<<i+1<<": "<<endl;
            createElemt(p);
            insertSortIPK(mhs,p);            
            cout<<"==========================="<<endl; 
        }
        cout<<"============================================================================================="<<endl;
        cout<<setw(6)<<"No"
            <<setw(20)<<"Nama"
            <<setw(20)<<"NPM"
            <<setw(20)<<"IPK"<<endl;
        cout<<"---------------------------------------------------------------------------------------------"<<endl;
        traversal(mhs);
        cout<<"============================================================================================="<<endl;
        cout<<"\n\n1. Tambah Data"<<endl;
        cout<<"2. Keluar"<<endl;
        cout<<"Pilih : "; cin>>pilihan;
    }while(pilihan==1);
}

void createList(List& First){
    First = NULL;
}

void createElemt(pointer& pBaru){
    pBaru = new ElemtList;
    cout<<"Masukkan Nama: "; cin.ignore();cin.getline(pBaru->nama,40);
    cout<<"Masukkan NPM : "; cin>>pBaru->npm;
    cout<<"Masukkan IPK : "; cin>>pBaru->ipk;
    pBaru->next=NULL;
}

void insertSortIPK(List& First, pointer pBaru){
    pointer Last;
    if (First==NULL){
        First=pBaru;
    }
    else {
        Last=First;
        while (Last->next!=NULL){
            Last=Last->next;
        }
        Last->next=pBaru;
    }

    /*
    if (First==NULL){ 
	    First=pBaru;
	}
	else {
		if (pBaru->ipk > pBaru->next->ipk){
			pBaru->next=First; 
			First=pBaru; 
		}	
		else{
			First->next=pBaru;
		}
	}
    */
}

void traversal(List First){
    pointer pBantu;
    pBantu=First;
    int i=1;
    while(pBantu != NULL){
        cout<<setw(6)<<i
            <<setw(20)<<pBantu->nama
            <<setw(20)<<pBantu->npm
            <<setw(20)<<pBantu->ipk<<endl;
        pBantu=pBantu->next;
        i++;
    }
}


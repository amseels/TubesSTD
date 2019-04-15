#include<bits/stdc++.h>
#include "fungsi.cpp"

using namespace std;

listSupir S;
listBus B;

adrSupir getSupir()
{
    string nama;
    cout<<"Nama Supir : ";
    cin>>nama;

    adrSupir S=alokasiSupir(nama);

    return S;
}

adrBus getBus()
{
    string kode, supir="",kondektur="";
    cout<<"Kode Bus : ";
    cin>>kode;
    adrBus B=alokasiBus(kode,supir,kondektur);
    return B;
}

void menu()
{
    int pilihan;
    adrSupir supirNow;
    adrBus busNow;
    cout<<"1. Tambah Supir Baru"<<endl;
    cout<<"2. Tambah Bus Baru"<<endl;
    cout<<"3. Tambah Relasi Supir-Bus"<<endl;
    cout<<"4. Hapus Supir"<<endl;
    cout<<"5. Hapus Bus"<<endl;
    cout<<"6. Tampilkan Data Supir"<<endl;
    cout<<"7. Tampilkan Data Bis"<<endl;
    cout<<endl;
    cout<<"Pilihan anda : ";
    cin>>pilihan;
    cout<<endl;
    switch(pilihan)
    {
        case 1:
            supirNow=getSupir();
            insertSupir(S,supirNow);
            break;
        case 2:
            busNow=getBus();
            insertBus(B,busNow);
            break;
        case 3:
            {
            string kodeBus,namaSupir,namaKondektur;
            cout<<"Masukkan data yang ingin ditambahkan:"<<endl;
            cout<<"Kode Bus : ";
            cin>>kodeBus;
            cout<<"Nama Supir: ";
            cin>>namaSupir;
            cout<<"Nama Kondektur: ";
            cin>>namaKondektur;
            insertRelasi(S,namaSupir,namaKondektur,B,kodeBus);
            }
            break;
        case 4:
            break;
        case 5 :
            break;
        case 6:
            cout<<"Data Seluruh Supir"<<endl;
            printSupir(S);
            break;
        case 7:
            cout<<"Data Seluruh Bus"<<endl;
            printBus(B);
            break;
    }
    cout<<endl;
    menu();
}
int main()
{
    createListSupir(S);
    createListBus(B);
    menu();
}

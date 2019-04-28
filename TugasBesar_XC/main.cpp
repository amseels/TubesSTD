#include <iostream>
#include "Header.h"
#include <cstdlib>
#include <stddef.h>
#include <stdlib.h>
#include <curses.h>

using namespace std;

listSupir S;
listBus B;

adrSupir getSupir()
{
    adrSupir P;
    string nama;
    cout<<"Nama Supir : ";
    cin>>nama;
    adrSupir NS = searchSupir(S, nama);
    while (NS != nil) {
            cout<<"Nama Sudah Terdaftar "<<endl;
            cout<<"Nama Supir : ";
            cin>>nama;
            NS = searchSupir(S, nama);
            P = alokasiSupir(nama);
    }
    P = alokasiSupir(nama);
    return P;
}

adrBus getBus()
{
    adrBus Q ;
    string kode, supir="",kondektur="";
    cout<<"Kode Bus : ";
    cin>>kode;
    adrBus NB = searchBus(B,kode);
    while (NB != nil) {
        cout<<"Bus Sudah Terdaftar "<<endl;
        cout<<"kode Bus : ";
        cin>>kode;
        NB = searchBus(B,kode);
        Q = alokasiBus(kode,supir,kondektur);
    }
    Q=alokasiBus(kode,supir,kondektur);
    return Q;
}

void menu()
{
    int pilihan = 1;
    while (pilihan != 99) {
    system("CLEAR");
    adrSupir supirNow;
    adrBus busNow;
    judul();
        cout<<"==  MENU  =="<<endl;
        cout<<""<<endl;
    cout<<"1. Tambah Supir Baru"<<endl;
    cout<<"2. Tambah Bus Baru"<<endl;
    cout<<"3. Tambah Relasi Supir-Bus"<<endl;
    cout<<"4. Hapus Supir"<<endl;
    cout<<"5. Hapus Bus"<<endl;
    cout<<"6. Tampilkan Data Supir"<<endl;
    cout<<"7. Tampilkan Data Bis"<<endl;
    cout<<"8. Supir yang memiliki jumlah bis paling banyak"<<endl;
    cout<<"9. Supir yang memiliki jumlah bis paling sedikit"<<endl;
    cout<<"0. EXIT "<<endl;
    cout<<endl;
    cout<<"Pilihan anda : ";
    cin>>pilihan;
    cout<<endl;
    switch(pilihan)
    {
        case 1:
            system("CLEAR");
            judul();
            cout<<"----------------------------------------"<<endl;
            supirNow=getSupir();
            insertSupir(S,supirNow);
            system("CLEAR");
            judul();
            cout<<"||  SUPIR DITAMBAHKAN ||"<<endl;
            cout<<"                 press ENTER To Continue.."<<endl;
            system("read -n1 -p ' ' key");
            break;
        case 2:
            system("CLEAR");
            judul();
            cout<<"----------------------------------------"<<endl;
            busNow=getBus();
            insertBus(B,busNow);
            system("CLEAR");
            judul();
            cout<<"||  BUS DITAMBAHKAN ||"<<endl;
            cout<<"                 press ENTER To Continue.."<<endl;
            system("read -n1 -p ' ' key");
            break;
        case 3:
        {
            system("CLEAR");
            judul();
            cout<<"----------------------------------------"<<endl;
            string kodeBus,namaSupir,namaKondektur;
            cout<<"Masukkan data yang ingin ditambahkan:"<<endl;
            cout<<"Kode Bus : ";
            cin>>kodeBus;
            adrBus bis = searchBus(B,kodeBus);
            if (bis == nil) {
                cout<<"Kode Bus tidak ditemukan"<<endl;
            }
            else {
                cout<<"Nama Supir: ";
                cin>>namaSupir;
                adrSupir supir = searchSupir(S,namaSupir);
                if (supir == nil ){
                    cout<<"Nama tidak ditemukan"<<endl;
                }
                else {
                    cout<<"Nama Kondektur: ";
                    cin>>namaKondektur;
                    adrSupir kondektur = searchSupir(S,namaKondektur);
                    if (kondektur == nil ){
                        cout<<"Nama tidak ditemukan"<<endl;
                    }
                    else {
                        insertRelasi(S,namaSupir,namaKondektur,B,kodeBus);
                        system("CLEAR");
                        judul();
                        cout<<"RELASI DITAMBAHKAN"<<endl;
                        cout<<"                     Press ENTER to Continue"<<endl;
                        system("read -n1 -p ' ' key");
                    }
                }
            }
        }
            break;
        case 4:
            {
                system("CLEAR");
                judul();
                cout<<"----------------------------------------"<<endl;
                string nama;
                cout<<"Masukan Nama Supir : ";
                cin>>nama;
                adrSupir X = searchSupir(S, nama);
                while (X == nil) {
                    cout<<"Nama Tidak Ditemukan "<<endl;
                    cout<<"Masukan Nama Supir : ";
                    cin>>nama;
                }
                deleteSupir(S,nama);
                system("CLEAR");
                judul();
                cout<<" ||   "<<nama<<" Telah Dihapus   ||"<<endl;
                cout<<"                          Press ENTER to Continue"<<endl;
                system("read -n1 -p ' ' key");
            }
            break;
        case 5 :
            {
                system("CLEAR");
                judul();
                cout<<"----------------------------------------"<<endl;
                string kodeBus;
                cout<<"masukan kode bus : ";
                cin>>kodeBus;
                adrBus X = searchBus(B,kodeBus);
                while (X == nil) {
                    cout<<"Bus Tidak Ditemukan "<<endl;
                    cout<<"Masukan Kode Bus : ";
                    cin>>kodeBus;
                }
                deleteBus(S,B,kodeBus);
                system("CLEAR");
                judul();
                cout<<" ||  Bus  "<<kodeBus<<" Telah Dihapus   ||"<<endl;
                cout<<"                          Press ENTER to Continue"<<endl;
                system("read -n1 -p ' ' key");
            }
            break;
        case 6:{
            system("CLEAR");
            judul();
            cout<<"-----------------------------------"<<endl;
            cout<<"         Data Seluruh Supir        "<<endl;
            printSupir(S);
            cout<<"-----------------------------------"<<endl;
            cout<<"                          Press ENTER to Continue"<<endl;
            system("read -n1 -p ' ' key");
        }
            break;
        case 7:
            system("CLEAR");
            judul();
            cout<<"-----------------------------------"<<endl;
            cout<<"         Data Seluruh Bus"<<endl;
            printBus(B);
            cout<<"                          Press ENTER to Continue"<<endl;
            system("read -n1 -p ' ' key");
            break;
        case 8:
            system("CLEAR");
            judul();
            maxSupir(S);
            cout<<"                          Press ENTER to Continue"<<endl;
            system("read -n1 -p ' ' key");
            break;
        case 9:
            system("CLEAR");
            judul();
            minSupir(S);
            cout<<"                          Press ENTER to Continue"<<endl;
            system("read -n1 -p ' ' key");
            break;
        case 0:
            system("CLEAR");
            cout<<"========================================"<<endl;
            cout<<"            TERIMA KASIH"<<endl;
            cout<<"========================================"<<endl;
            pilihan = 99;
        default :
            break;
    }
    cout<<endl;
    }
}
int main()
{
    createListSupir(S);
    createListBus(B);
    menu();
}

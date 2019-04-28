#ifndef Header_h
#define Header_h
#include <string>

#define nama(S) S->nama
#define nextSupir(S) S->nextSupir
#define firstSupir(S) S.firstSupir
#define kode(B) B->kode
#define supir(B) B->supir
#define kondektur(B) B->kondektur
#define nextBus(B) B->nextBus
#define firstBus(B) B.firstBus
#define nextRelasi(R) R->nextRelasi
#define bus(R)  R->bus
#define firstRelasi(S) S->firstRelasi
#define nil NULL
#define null NULL
using namespace std;

typedef struct elmBus *adrBus;

struct elmBus
{
    string kode,supir, kondektur;
    adrBus nextBus;
};

struct listBus
{
    adrBus firstBus;
};

typedef struct elmRelasi *adrRelasi;

struct elmRelasi
{
    adrRelasi nextRelasi;
    adrBus bus;
};


typedef struct elmSupir *adrSupir;

struct elmSupir
{
    string nama;
    adrSupir nextSupir;
    adrRelasi firstRelasi;
};

struct listSupir
{
    adrSupir firstSupir;
};

void createListSupir(listSupir &S);
void createListBus(listBus &B);
adrSupir alokasiSupir(string nama);
adrBus alokasiBus(string kode, string supir, string kondektur);
adrRelasi alokasiRelasi(adrBus bus);
bool isEmptySupir(listSupir &S);
bool isEmptyRelasi(adrSupir S);
bool isEmptyBus(listBus &B);
void insertSupir(listSupir &S, adrSupir P);
void printSupir(listSupir S);
void insertBus(listBus &B, adrBus P);
void printBus(listBus B);
adrSupir searchSupir(listSupir &S,string namaSupir);
adrBus searchBus(listBus &B,string kodeBus);
void insertLastRelasi(adrSupir &S, adrRelasi P);
void insertRelasi(listSupir &S, string namaSupir, string namaKondektur, listBus &B, string kodeBus);
int countBus(adrSupir S);
void maxSupir(listSupir S);
void minSupir(listSupir S);
void deleteBus(listSupir &S,listBus &B, string kodeBus);
void deleteSupir (listSupir &S, string  nama);
void deleteRelasi ();
void judul();

#endif /* Header_h */

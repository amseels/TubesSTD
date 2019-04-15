#ifndef HEAD_H_INCLUDED
#define HEAD_H_INCLUDED

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





#endif // HEAD_H_INCLUDED

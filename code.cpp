#include "Header.h"
#include <iostream>
#include <string>
#include <unistd.h>
#include <term.h>

void createListSupir(listSupir &S)
{
    firstSupir(S)=null;
}

void createListBus(listBus &B)
{
    firstBus(B)=null;
}

adrSupir alokasiSupir (string nama)
{
    adrSupir S=new elmSupir;
    nama(S)=nama;
    nextSupir(S)=null;
    firstRelasi(S)=null;
    return S;
}

adrBus alokasiBus(string kode, string supir, string kondektur)
{
    adrBus B=new elmBus;
    kode(B)=kode;
    supir(B)=supir;
    kondektur(B)=kondektur;
    
    nextBus(B)=null;
    return B;
}

adrRelasi alokasiRelasi(adrBus bus)
{
    adrRelasi R = new elmRelasi;
    bus(R)=bus;
    nextRelasi(R)=null;
    return R;
}

bool isEmptySupir(listSupir &S)
{
    return (firstSupir(S)==null);
}

bool isEmptyRelasi(adrSupir S)
{
    return (firstRelasi(S)==null);
}

bool isEmptyBus(listBus &B)
{
    return (firstBus(B)==null);
}

void insertSupir(listSupir &S, adrSupir P)
{
    if (isEmptySupir(S))
    {
        firstSupir(S)=P;
        nextSupir(P)=null;
    }
    else
    {
        adrSupir Last=firstSupir(S);
        while (nextSupir(Last)!=null)
        {
            Last=nextSupir(Last);
        }
        
        nextSupir(Last)=P;
        nextSupir(P)=null;
    }
}

void printSupir(listSupir S)
{
    int num = 0;
    adrSupir P=firstSupir(S);
    cout<<"-----------------------------------"<<endl;
    cout<<"|   Nama    \t|       Bus      \t| "<<endl;
    while (P!=null)
    {
         num++;
        cout<<"|"<<num<<"|"<<nama(P)<<"\t"<<" \t| ";
        adrRelasi R=firstRelasi(P);
        while (R!=NULL)
        {
            cout<<kode(bus(R))<<", ";
            R=nextRelasi(R);
        }
        cout<<"\t\t\t|"<<endl;
        P=nextSupir(P);
    }
}

void insertBus(listBus &B, adrBus P)
{
    if (isEmptyBus(B))
    {
        firstBus(B)=P;
        nextBus(P)=null;
    }
    else
    {
        adrBus Last=firstBus(B);
        while (nextBus(Last)!=null)
        {
            Last=nextBus(Last);
        }
        
        nextBus(Last)=P;
        nextBus(P)=null;
    }
}

void printBus(listBus B)
{
    adrBus P=firstBus(B);
    while (P!=null)
    {
        cout<<" --- "<<kode(P)<<" ---"<<endl;
        cout<<"| Supir     : "<<supir(P)<<endl;
        cout<<" ---------------------"<<endl;
        cout<<"| Kondektur : "<<kondektur(P)<<endl;
        cout<<"----------------------"<<endl;
        cout<<endl;
        P=nextBus(P);
    }
}

adrSupir searchSupir(listSupir &S,string namaSupir)
{
    adrSupir P=firstSupir(S);
    while (P!=NULL && nama(P)!=namaSupir)
    {
        P=nextSupir(P);
    }
    return P;
}


adrBus searchBus(listBus &B,string kodeBus)
{
    adrBus P=firstBus(B);
    while (P!=NULL && kode(P)!=kodeBus)
    {
        P=nextBus(P);
    }
    return P;
}

void insertLastRelasi(adrSupir &S, adrRelasi P)
{
    adrRelasi lastRelasi=firstRelasi(S);
    if (lastRelasi==NULL)
    {
        firstRelasi(S)=P;
        nextRelasi(P)=NULL;
    }
    else
    {
        while (nextRelasi(lastRelasi)!=NULL)
        {
            lastRelasi=nextRelasi(lastRelasi);
        }
        nextRelasi(lastRelasi)=P;
        nextRelasi(P)=NULL;
    }
    
}
void insertRelasi(listSupir &S, string namaSupir, string namaKondektur, listBus &B, string kodeBus)
{
    adrBus bus=searchBus(B,kodeBus);
    
    
    kondektur(bus)=namaKondektur;
    supir(bus)=namaSupir;
    
    adrSupir supir=searchSupir(S, namaSupir);
    adrSupir kondektur=searchSupir(S,namaKondektur);
    
    adrRelasi newRelasi=alokasiRelasi(bus);
    insertLastRelasi(supir, newRelasi);
    
    adrRelasi newRelasi2=alokasiRelasi(bus);
    insertLastRelasi(kondektur,newRelasi2);
}

int countBus(adrSupir S)
{
    int counts=0;
    adrRelasi P=firstRelasi(S);
    while (P!=NULL)
    {
        counts++;
        P=nextRelasi(P);
    }
    return counts;
}

void maxSupir(listSupir S)
{
    adrSupir i=firstSupir(S);
    int maks=0;
    adrSupir supirTerbanyak=NULL;
    while (i!=NULL)
    {
        int tmp=countBus(i);
        if (tmp>maks)
        {
            maks=tmp;
            supirTerbanyak=i;
        }
        i=nextSupir(i);
    }
    
    cout<<"Supir dengan bus terbanyak adalah "<<nama(supirTerbanyak)<<" : ";
    adrRelasi R=firstRelasi(supirTerbanyak);
    while (R!=NULL)
    {
        cout<<kode(bus(R))<<", ";
        R=nextRelasi(R);
    }
    cout<<endl;
}

void minSupir(listSupir S)
{
    adrSupir i=firstSupir(S);
    int mins=1000;
    adrSupir supir=NULL;
    while (i!=NULL)
    {
        int tmp=countBus(i);
        if (tmp<mins)
        {
            mins=tmp;
            supir=i;
        }
        i=nextSupir(i);
    }
    
    cout<<"Supir dengan bus paling sedikit adalah "<<nama(supir)<<" : ";
    adrRelasi R=firstRelasi(supir);
    while (R!=NULL)
    {
        cout<<kode(bus(R))<<", ";
        R=nextRelasi(R);
    }
    cout<<endl;
}

void deleteFirstBus (listBus &B, adrBus &P) {
    if (firstBus(B) != nil) {
        P = firstBus(B);
        firstBus(B) = nextBus(firstBus(B));
        nextBus(P)=nil;
    }
    else {
        cout<<"Data tidak ditemukan"<<endl;
    }
}

void deleteFirstSupir (listSupir &S,adrSupir &P) {
    if (firstSupir(S) != nil) {
        P = firstSupir(S);
        firstSupir(S) = nextSupir(firstSupir(S));
        nextSupir(P)=nil;
    }
    else {
        cout<<"Data tidak ditemukan"<<endl;
    }
}

void deleteFirstRelasi (adrSupir &S, adrRelasi &P) {
    P=firstRelasi(S);
    if (firstRelasi(S) != nil) {
        P = firstRelasi(S);
        firstRelasi(S) = nextRelasi(firstRelasi(S));
        nextRelasi(P)=nil;
    }
    else {
        cout<<"Data tidak ditemukan"<<endl;
    }
}

void deleteLastBus (listBus &B, adrBus &P) {
    adrBus Q;
    Q = firstBus(B);
    P = nextBus(Q);
    while (nextBus(Q) != nil) {
        Q = nextBus(Q);
        P = nextBus(P);
    }
    nextBus(Q) = nil;
}

void deleteLastSupir (listSupir &S, adrSupir &P) {
    adrSupir Q;
    Q = firstSupir(S);
    P = nextSupir(Q);
    while (nextSupir(Q) != nil) {
        Q = nextSupir(Q);
        P = nextSupir(P);
    }
    nextSupir(Q) = nil;
}

void deleteLastRelasi (adrSupir &S,adrRelasi &P) {
    adrRelasi Q;
    Q = firstRelasi(S);
    P = nextRelasi(Q);
    while (nextRelasi(Q) != nil) {
        Q = nextRelasi(Q);
        P = nextRelasi(P);
    }
    nextRelasi(Q) = nil;
}

void deleteAfterBus (listBus &B,adrBus &P) {
    adrBus Q = firstBus(B);
    while (nextBus(Q) != P) {
        Q = nextBus(Q);
    }
    nextBus(Q) = nextBus(P);
    nextBus(P) = nil;
}


void deleteAfterSupir (listSupir &S,adrSupir &P) {
    adrSupir Q = firstSupir(S);
    while (nextSupir(Q) != P) {
        Q = nextSupir(Q);
    }
    nextSupir(Q) = nextSupir(P);
    nextSupir(P) = nil;
}

void deleteAfterRelasi (adrSupir &S,adrRelasi &P) {
    adrRelasi Q;
    Q = firstRelasi(S);
    while (nextRelasi(Q) != P) {
        Q = nextRelasi(Q);
    }
    nextRelasi(Q) = nextRelasi(P);
    nextRelasi(P) = nil;
}


adrRelasi searchRelasi (adrSupir &S, string Bis) {
    adrRelasi P = firstRelasi(S);
    while ((P != nil) && (kode(bus(P))!= Bis)) {
        P = nextRelasi(P);
    }
    return P;
}


void deleteRelasi(adrSupir &S, adrRelasi &R){
    adrBus B=bus(R);
    if (supir(B)==nama(S))
        supir(B)="";
    else if (kondektur(B)==nama(S)){
        kondektur(B)="";
    }
    
    if(R==firstRelasi(S)){
        deleteFirstRelasi(S, R);
    }
    else if (next(R) == nil ) {
        deleteLastRelasi(S, R);
    }
    else {
        deleteAfterRelasi(S,R);
    }
}

void deleteBus (listSupir &S, listBus &B, string kodeBus) {
    
    adrBus P = searchBus (B,kodeBus);
    
    adrSupir XS=searchSupir(S, supir(P));
    adrRelasi XR=searchRelasi(XS, kodeBus);
    deleteRelasi(XS, XR);
    
    
    XS=searchSupir(S, kondektur(P));
    XR=searchRelasi(XS, kodeBus);
    deleteRelasi(XS, XR);
    
    if (firstBus(B)!= nil) {
        if (P == firstBus(B)) {
            cout<<"delete first";
            deleteFirstBus(B,P);
        }
        else if (next(P) == nil ) {
            deleteLastBus(B,P);
            cout<<"delete last";
        }
        else {
            deleteAfterBus(B,P);
            cout<<"delete after";
        }
    }
    else {
        cout<<"Data tidak ditemukan"<<endl;
    }
    
}
 
void deleteAllRelasi(adrSupir &S){
    adrRelasi R=firstRelasi(S);
    while(R!=nil){
        
        adrBus B=bus(R);
        if (supir(B)==nama(S))
            supir(B)="";
        else if (kondektur(B)==nama(S)){
            kondektur(B)="";
        }
        
        adrRelasi tmp=R;
        R=nextRelasi(R);
        deleteFirstRelasi(S, tmp);
    }
}


void deleteSupir (listSupir &S, string  nama) {
    adrSupir P = searchSupir (S,nama);
    
    deleteAllRelasi(P);
    
    if (firstSupir(S)!= nil) {
        
        if (P == firstSupir(S)) {
            cout<<"delete first";
            deleteFirstSupir(S,P);
        }
        else if (next(P) == nil ) {
            deleteLastSupir(S,P);
            cout<<"delete last";
        }
        else {
            deleteAfterSupir(S,P);
            cout<<"delete after";
        }
    }
    else {
        cout<<"Data tidak ditemukan"<<endl;
    }
}

void judul() {
    cout<<"==============================================================="<<endl;
    cout<<"                TUGAS BESAR MATA KULIAH"<<endl;
    cout<<"                     STRUKTUR DATA"<<endl;
    cout<<""<<endl;
    cout<<"        NURIL KAUNAINI R.  -  HAMMAMUL ACHDAN E. "<<endl;
    cout<<"           1301181017            1301184210"<<endl;
    cout<<"==============================================================="<<endl;
    cout<<""<<endl;
    cout<<""<<endl;
}

#include "head.h"


void createListSupir(listSupir &S)
{
    firstSupir(S)=null;
}

void createListBus(listBus &B)
{
    firstBus(B)=null;
}

adrSupir alokasiSupir(string nama)
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
    adrRelasi R=new elmRelasi;
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
    adrSupir P=firstSupir(S);
    while (P!=null)
    {
        cout<<nama(P) <<" : ";
        adrRelasi R=firstRelasi(P);
        while (R!=NULL)
        {
            cout<<kode(bus(R))<<", ";
            R=nextRelasi(R);
        }
        cout<<endl;
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
        cout<<"--- "<<kode(P)<<" ---"<<endl;
        cout<<"Supir     : "<<supir(P)<<endl;
        cout<<"Kondektur : "<<kondektur(P)<<endl;
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

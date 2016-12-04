#include "list_relasi.h"

void createList(List_relasi &L)
{
    first(L) = NULL;
}

address_relasi alokasi(address_child C)
{
    address_relasi P = new elmlist_relasi;
    info(P) = C;
    next(P) = NULL;
    return P;
}

void insertFirst(List_relasi &L, address_relasi P)
{
    next(P) = first(L);
    first(L) = P;
}

void insertLast(List_relasi &L, address_relasi P)
{
    if(L.first == NULL)
    {
        L.first = P;
    }
    else
    {
        address_relasi q = L.first;
        while(q->next != NULL)
        {
            q=q->next;
        }
        q->next = P;
    }
}

void deleteFirst(List_relasi &L, address_relasi &P)
{
    if(L.first == NULL)
    {
        // isi pesan dalam kutip
        //cout << "List Telah Kosong. Tidak ada elemen yang dapat dihapus"<<endl;
    }
    else
    {
        P = L.first;
        L.first = P->next;
        P->next = NULL;

    }
}
void deleteLast(List_relasi &L, address_relasi &P)
{
    if(L.first == NULL)
    {
        // isi pesan dalam kutip
        //cout << "List Telah Kosong. Tidak ada elemen yang dapat dihapus"<<endl;
    }
    else
    {
        P=L.first;
        if(P->next == NULL)
        {
            L.first = NULL;

        }
        else
        {
            address_relasi q=P;
            while(q->next->next != NULL)
            {
                q=q->next;
            }
            P = q->next;
            q->next = NULL;

        }
    }
}

void printInfo(List_relasi L)
{
    address_relasi P = first(L);
    if ( P == NULL )
    {
        cout << "Tidak Ada Murid" << endl << endl;
    }
    else
    {
      while(P !=NULL)
      {
          cout<<"NISN Murid             :"<<info(info(P)).nisn<<endl;
        P = next(P);
      }
    }

}


address_relasi findElm(List_relasi L, address_child C)
{
    address_relasi P = first(L);
    while(P != NULL)
    {
        if(info(P)== C)
        {
            return P;
        }
        P = next(P);
    }
    return NULL;
}

void insertAfter(address_relasi &Prec, address_relasi P)
{
    next(P) = next(Prec);
    next(Prec) = P;
}

void deleteAfter(address_relasi Prec, address_relasi &P)
{
    P = Prec->next;
    Prec->next = P->next;
    P->next = NULL;

}

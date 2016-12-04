#include "list_child.h"

void createList(List_child &L)
/*  I.S: sembarang
    F.S:terbentuk list child tidak ada
    //1301154426
    //1301154286*/
{
    first(L) = NULL;
    last(L) = NULL;
}

address_child alokasi(infotype_child x)
/*  FS: mengembalikan elemen list baru dengan info = x,next elemen = Nil
    //1301154426
    //1301154286*/
{
    address_child P = new elmlist_child;
    info(P) = x;
    next(P) = NULL;
    prev(P) = NULL;
    return P;
}

void insertFirst(List_child &L, address_child P)
/*  IS: P udah dialokasikan
    FS: menempatkan element beralamat P pada awal list
    //1301154426
    //1301154286*/
{
    if(first(L) == NULL)
    {
        last(L) = P;
        first(L) = P;
    }
    else
    {
        next(P) = first(L);
        prev(first(L)) = P;
        first(L) = P;
    }
}

void insertLast(List_child &L, address_child P)
/*    IS: p udah dialokasikan
      FS: menempatkan element beralamat P pada akhir list
      //1301154426
      //1301154286*/
{
    if(first(L) == NULL)
    {
        first(L) = P;
        last(L) = P;
    }
    else
    {
        P->prev = L.last;
        L.last->next = P;
        L.last = P;
    }
}
void deleteFirst(List_child &L,address_child&P)
 /*   IS: list sudah kosong
      FS: menghapus element alamat pada element pertama list
      //1301154426
      //1301154286*/
{
    if(first(L)!=NULL)
    {
        P = first(L);

        if(first(L) == L.last)
        {
            L.last = NULL;
            L.first = NULL;
        }
        else
        {
            L.first = P->next;
            L.first->prev = NULL;
            P->next = NULL;
        }
    }
}
void deleteLast(List_child &L, address_child &P)
 /*   IS: list sudah kosong
      FS: menghapus element alamat pada element pertama list
      //1301154426
      //1301154286*/
{
    if(L.first!=NULL)
    {
        P = L.last;

        if(L.first == L.last)
        {
            L.first = NULL;
            L.last = NULL;
        }
        else
        {
            L.last = P->prev;
            L.last->next = NULL;
            P->prev = NULL;
        }
    }
}
void printInfo(List_child L)
 /*  FS: menampilkan info dari elemen list L
     //1301154426
     //1301154286*/
{
    address_child P = first(L);
    while(P !=NULL)
    {
        cout<<"NAMA           :"<<info(P).nama<<endl;
        cout<<"NISN           :"<<info(P).nisn<<endl;
        cout<<"ALAMAT         :"<<info(P).alamatm<<endl;
        cout<<"TANGGAL LAHIR  :"<<info(P).tanggal_lahir<<endl;
        cout<<"JENIS KELAMIN  :"<<info(P).jenis_kelamin<<endl;
        cout<<"NEM            :"<<info(P).nem<<endl;
        P = next(P);
    }
}


address_child findElm(List_child L, infotype_child x)
 /*   IS: list_parent L mungkin kosong
      FS: mengembalikan elemen dengan info = x
      //1301154426
      //1301154286*/
{
    address_child P = first(L);
    while(P != NULL)
    {
        if(info(P).nisn==x.nisn)
        {
            return P;
        }
        P = next(P);
    }
    return NULL;
}

void insertAfter(address_child Prec, address_child P)
 /*   IS: P sudah dialokasikan
      FS: menempatkan elemen beralamat P sesudah element beralamat prec
      //1301154426
      //1301154286*/
{
    prev(next(Prec)) = P;
    next(P) = next(Prec);
    prev(P) = Prec;
    next(Prec) = P;
}

void deleteAfter(address_child Prec, address_child &P)
 /*   IS: list sudah kosong
      FS: menghapus element alamat pada element next(prec) list
      //1301154426
      //1301154286*/
{
    P= Prec->next;

    Prec->next = P->next;
    Prec->next->prev = P->prev;

    P->next = NULL;
    P->prev = NULL;
}


void sorting1(List_child L)
 /*   FS: mengurutkan data child
      //1301154426
      //1301154286*/
{
    List_child lc;
    createList(lc);
    infotype_child infoc;

    address_child P = first (L);
    address_child Q;
    while(P !=NULL)
    {
        infoc.nama=info(P).nama;
        infoc.nisn=info(P).nisn;
        infoc.alamatm=info(P).alamatm;
        infoc.tanggal_lahir=info(P).tanggal_lahir;
        infoc.jenis_kelamin=info(P).jenis_kelamin;
        infoc.nem=info (P).nem;

        Q = alokasi(infoc);
        ascendingnem(lc,Q);

        P = next(P);

    }
    ;
    printInfo(lc);


}
void ascending1(List_child &L, address_child P)
 /*  FS: mengurutkan secara ascending
     //1301154426
     //1301154286*/
{
    address_child Q=first(L);
    address_child prec=first(L);
    address_child r=findElm(L,info(P));
    if(r==NULL)
    {

        if ((first(L) == NULL) || (info(P).nisn <info(Q).nisn))
        {
            insertFirst(L,P);
        }
        else
        {
            Q = next(Q);

            while (Q !=NULL)
            {
                if (info(P).nisn> info(Q).nisn)
                {

                    prec =next(prec);
                }
                Q= next(Q);
            }
            if (next(prec) !=NULL)
            {
                insertAfter(prec,P);
            }
            else
            {
                insertLast(L,P);
            }


        }
    }
    else
    {
        cout<< "NISN Sudah Ada" <<endl;
    }

}


void ascendingnem(List_child &L, address_child P)
 /*  FS: mengurutkan data child
     //1301154426
     //1301154286*/
{
    address_child Q=first(L);
    address_child prec=first(L);

    if ((first(L) == NULL) || (info(P).nem <info(Q).nem))
    {
        insertFirst(L,P);
    }
    else
    {
        Q = next(Q);

        while (Q !=NULL)
        {
            if (info(P).nem> info(Q).nem)
            {

                prec =next(prec);
            }
            Q= next(Q);
        }
        if (next(prec) !=NULL)
        {
            insertAfter(prec,P);
        }
        else
        {
            insertLast(L,P);
        }
    }
}

void ratanem (List_child L)
 /*   FS: mendapatkan rata-rata berdasarkan child
      //1301154426
      //1301154286*/
{
    address_child P = first(L);
    int jumlah=0;
    double rata = 0;
    int i = 0;

    if (P != NULL)
    {
        while (P != NULL)
        {
            i++;
            jumlah = jumlah + info(P).nem;
            P = next(P);
        };

    }
    rata = jumlah/i;
    cout << rata << endl;
}


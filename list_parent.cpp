#include "list_parent.h"

void createList(List_parent &L)
{
    /**
    * FS : first(L) diset Nil
    //1301154426
    //1301154286
    */
    first(L) = NULL;
}

address_parent alokasi(infotype_parent x)
{
    /**
    * FS : mengembalikan elemen list baru dengan info = x, next elemen = Nil
    //1301154426
    //1301154286
    */

    address_parent P;
    P = new elmlist_parent;
    info(P) = x;
    next(P) = NULL;
    createList(child(P));
    return P;
}

void insertFirst(List_parent &L, address_parent P)
{
    /**
    * IS : List_parent L mungkin kosong
    * FS : elemen yang ditunjuk P menjadi elemen pertama pada List_parent L
    *      next dari last elemen menunjuk ke first elemen
    //1301154426
    //1301154286
    */
    address_parent Q;
    if(first(L) == NULL)
    {
        first(L) = P;
        next(P) = P;
    }
    else
    {
        Q = first(L);
        while(next(Q) != first(L))
        {
            Q = next(Q);
        }
        next(P) = first(L);
        next(Q) = P;
        first(L) = P;
    }
}

void insertLast(List_parent &L, address_parent P)
/**
    * IS : List_parent L mungkin kosong
    * FS : elemen yang ditunjuk P menjadi elemen terakhir pada List_parent L
    *
    //1301154426
    //1301154286
    */
{
    if(L.first == NULL)
    {
        L.first = P;
    }
    else
    {
        address_parent q = L.first;
        while(q->next != NULL)
        {
            q=q->next;
        }
        q->next = P;
    }
}

void printInfo(List_parent L)
{
    /**
    * FS : menampilkan info seluruh elemen list L
    //1301154426
    //1301154286
    */
    address_parent P = first(L);
    if(first(L)!=NULL)
    {
        do
        {
            cout<<"ID SEKOLAH               :"<<info(P).id_sekolah<<endl;
            cout<<"NAMA SEKOLAH             :"<<info(P).nama_sekolah<<endl;
            cout<<"JENIS                    :"<<info(P).jenis<<endl;
            cout<<"AKREDITAS                :"<<info(P).akreditasi<<endl;
            cout<<"BIAYA SPP                :"<<info(P).biaya_spp<<endl;
            cout<<"ALAMAT                   :"<<info(P).alamat<<endl;
            printInfo(child(P));
            P = next(P);
        }
        while((P)!=first(L));
    }
}

void deleteFirst(List_parent &L, address_parent &P)
/**
    * IS : List kosong
    * FS : alamat dari elemen pertama
    //1301154426
    //1301154286
    */
{
    if(L.first == NULL)
    {

    }
    else
    {
        P = L.first;
        L.first = P->next;
        P->next = NULL;

    }
}
void deleteLast(List_parent &L, address_parent &P)
/**
    * IS : List kosong
    * FS : alamat dari elemen terakhir
    //1301154426
    //1301154286
    */
{
    if(L.first == NULL)
    {


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
            address_parent q=P;
            while(q->next->next != NULL)
            {
                q=q->next;
            }
            P = q->next;
            q->next = NULL;

        }
    }
}
void insertAfter(List_parent &L, address_parent Prec, address_parent P)
/* IS: list_parent L mungkin kosong
    FS:elemen yang ditunjuk P menjadi elemen prec pada List_parent L
    next dari last elemen menunjuk ke after elemen
    //1301154426
    //1301154286
 */
{
    P->next = Prec->next;
    Prec->next = P;
}

void deleteAfter(List_parent &L, address_parent Prec, address_parent &P)
/*  IS: List Tidak Kosong
    F.S:alamat dari next(prec), menghapus next(prec) daari list
    //1301154426
    //1301154286
    */
{
    P = Prec->next;
    Prec->next = P->next;
    P->next = NULL;
}
address_parent findElm(List_parent L, infotype_parent x)
{
    /**
    * IS : List_parent L mungkin kosong
    * FS : mengembalikan elemen dengan info nim = x.nim,
    * FS : mengembalikan elemen dengan info = x,
           mengembalikan Nil jika tidak ditemukan
           //1301154426
           //1301154286
    */
    address_parent P = first(L);
    if (P != NULL)
    {
        do
        {
            if(info(P).id_sekolah == x.id_sekolah)
            {
                return P;
            }
            P = next(P);
        }
        while(P != first(L));
    }

    return NULL;
}

void sorting(List_parent L)
//  F.S:mengurutkan data nem berdasarkan sekolah
    //1301154426
    //1301154286
//
{
    List_parent lp;
    createList(lp);
    infotype_parent infop;

    address_parent P = first (L);
    address_parent Q;
    do
    {
        infop.id_sekolah=info(P).id_sekolah;
        infop.nama_sekolah=info(P).nama_sekolah;
        infop.jenis=info(P).jenis;
        infop.akreditasi=info(P).akreditasi;
        infop.biaya_spp=info(P).biaya_spp;
        infop.alamat=info (P).alamat;

        Q = alokasi(infop);
        ascendingbiaya_spp(lp,Q);

        P = next(P);

    }
    while(P !=first(L));
    printInfo(lp);


}
void ascending(List_parent &L, address_parent P)
/**
    * FS : mengurutkan data elemen
    //1301154426
    //1301154286
    */
{
    address_parent Q=first(L);
    address_parent prec=first(L);
    address_parent r=findElm(L,info(P));
    if(r==NULL)
    {

        if ((first(L) == NULL) || (info(P).id_sekolah <info(Q).id_sekolah))
        {
            insertFirst(L,P);
        }
        else
        {
            Q = next(Q);
            while ((info(P).id_sekolah > info(Q).id_sekolah) && (Q !=first(L)))
            {
                Q= next(Q);
                prec =next(prec);
            }
            insertAfter(L,prec,P);
        }
    }
    else
    {
        cout<< "ID Sudah Ada" <<endl;
    }

}

void ascendingbiaya_spp(List_parent &L, address_parent P)
/*  f.s: mengurutkan berdasarkan biaya spp
    //1301154426
    //1301154286
*/
{
    address_parent Q=first(L);
    address_parent prec=first(L);

    if ((first(L) == NULL) || (info(P).biaya_spp <=info(Q).biaya_spp))
    {
        insertFirst(L,P);
    }
    else
    {
        Q = next(Q);
        while ((info(P).biaya_spp >= info(Q).biaya_spp) && (Q !=first(L)))
        {
            Q= next(Q);
            prec =next(prec);
        }
        insertAfter(L,prec,P);
    }
}

void ratabiaya (List_parent L)
/*  mencari rata-rata biaya berdasarkan yang sudah di inputkan
    //1301154426
    //1301154286
*/
{
    address_parent P = first(L);
    int jumlah=0;
    double rata = 0;
    int i = 0;

    if (P != NULL)
    {
        do
        {
            i++;
            jumlah = jumlah + info(P).biaya_spp;
            P = next(P);
        }
        while (P != first(L));
    }
    rata = jumlah/i;
    cout << rata << endl;
}





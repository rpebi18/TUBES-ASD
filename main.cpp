#include <iostream>
#include <stdlib.h>
#include <conio.h>

using namespace std;
#include "list_child.h"
#include "list_parent.h"

int main()
{
    List_child lc;
    createList(lc);
    List_parent lp;
    createList(lp);
    infotype_parent infop;
    infotype_child infoc;
    int pilihan;
    int biaya_spp, nem, nisn;
    string nama_sekolah,jenis,akreditasi,alamat,alamatm,nama,tempat,tanggal_lahir,jenis_kelamin;

    do
    {
        system("cls");
        cout<<"Selamat Datang : "<<endl;
        cout<<" "<<endl;
        cout<<"1. Masukkan Data Sekolah"<<endl;
        cout<<"2. Masukkan Data Murid"<<endl;
        cout<<"3. Tambah Data Murid"<<endl;
        cout<<"4. Cari Data Sekolah"<<endl;
        cout<<"5. Cari Data Murid "<<endl;
        cout<<"6. Delete Data Sekolah"<<endl;
        cout<<"7. Lihat Semua Data"<<endl;
        cout<<"8. Sorting Sekolah"<<endl;
        cout<<"9. Sorting Murid"<<endl;
        cout<<"10.Report Sekolah"<<endl;
        cout<<"11.Report Murid"<<endl;
        cout<<"12.Keluar"<<endl;
        cout<<"Pilihan : ";
        cin>>pilihan;
        if(pilihan==1)
        //1301154426
        //1301154286
        {
            cout<<"Masukkan Data Sekolah"<<endl;
            cout<<"Id_Sekolah    :";
            cin>> infop.id_sekolah;
            cout<<"Nama Sekolah  :";
            cin>> infop.nama_sekolah;
            cout<<"Jenis Sekolah :";
            cin>>infop.jenis;
            cout<<"Akreditasi    :";
            cin>>infop.akreditasi;
            cout<<"Alamat        :";
            cin>>infop.alamat;
            cout<<"Biaya SPP     :";
            cin>>infop.biaya_spp;


            address_parent p = alokasi(infop);
            ascending(lp,p);
            getch();
        }
        else if(pilihan==2)
            //1301154426
        //1301154286
        {
            cout<<"Masukkan Data Murid"<<endl;
            cout<<"Nama          :";
            cin>>infoc.nama;
            cout<<"NISN          :";
            cin>>infoc.nisn;
            cout<<"Alamat        :";
            cin>>infoc.alamatm;
            cout<<"Tanggal Lahir :";
            cin>>infoc.tanggal_lahir;
            cout<<"Jenis Kelamin :";
            cin>>infoc.jenis_kelamin;
            cout<<"NEM           :";
            cin>>infoc.nem;

            address_child c = alokasi(infoc);
            ascending1(lc,c);
            getch();
        }
        else if(pilihan==3)
            //1301154426
        //1301154286
        {
            cout<<"Tambah Murid"<<endl;
            cout<<"NISN Murid   :";
            cin>> infoc.nisn;
            cout<<"ID Sekolah :";
            cin>> infop.id_sekolah;
            address_parent p= findElm(lp, infop);
            address_child c=findElm(lc,infoc);
            if(p!=NULL && c!=NULL)
            {
                address_relasi r = alokasi(c);
                insertFirst(p->child,r);
            }
            else
            {
                cout<<"enggak ada"<<endl;
            }

            getch();
        }
        else if(pilihan==4)
            //1301154426
        //1301154286
        {
            cout<<"Cari Sekolah :"<<endl;
            cout<<"Id Sekolah   :";
            cin>> infop.id_sekolah;

            address_parent p= findElm(lp, infop);
            if(p!=NULL )
            {
                cout<<"Id Sekolah    :"<<info(p).id_sekolah<< endl;
                cout<<"Nama Sekolah  :"<<info(p).nama_sekolah<<endl;
                cout<<"Jenis         :"<<info(p).jenis<<endl;
                cout<<"Akreditasi    :"<<info(p).akreditasi<<endl;
                cout<<"Biaya SPP     :"<<info(p).biaya_spp<<endl;
                cout<<"Alamat        :"<<info(p).alamat<<endl;


            }
            else
            {
                cout<<"error"<<endl;
            }

            getch();
        }

        else if(pilihan==5)
            //1301154426
        //1301154286
        {
            cout<<"Cari Murid :"<<endl;
            cout<<"NISN       :";
            cin>> infoc.nisn;

            address_child c= findElm(lc, infoc);
            if(c!=NULL )
            {
                cout<<"Nama          :"<<info(c).nama <<endl;
                cout<<"NISN          :"<<info(c).nisn <<endl;
                cout<<"Alamat        :"<<info(c).alamatm <<endl;
                cout<<"Tanggal Lahir :"<<info(c).tanggal_lahir <<endl;
                cout<<"Jenis Kelamin :"<<info(c).jenis_kelamin <<endl;
                cout<<"NEM           :"<<info(c).nem <<endl;
            }
            else
            {
                cout<<"error"<<endl;
            }

            getch();
        }

        else if(pilihan==6)
            //1301154426
        //1301154286
        {
            cout<<"Delete Data"<<endl;
            {
                createList(lp);
                createList(lc);
            }

            cout<<"Data Sudah di Hapus"<<endl;

            getch();
        }
        else if(pilihan==7)
            //1301154426
        //1301154286
        {
            cout<<" Lihat Semua Data"<<endl;
            {
                printInfo(lp);
                printInfo(lc);
            }


            getch();
        }

        else if(pilihan==8)
            //1301154426
        //1301154286
        {
            cout<<"Sorting Sekolah"<<endl;
            sorting(lp);
            getch();
        }
        else if(pilihan==9)
        //1301154426
        //1301154286
        {
            cout<<"Sorting Murid"<<endl;
            sorting1(lc);
            getch();
        }
        else if(pilihan==10)
        //1301154426
        //1301154286
        {
            cout<<"Rata-Rata Biaya"<<endl;
            ratabiaya(lp);

            getch();
        }
        else if(pilihan==11)
            //1301154426
        //1301154286
        {
            cout<<"Rata-Rata NEM"<<endl;
            ratanem(lc);

            getch();
        }
        else if(pilihan==12)
            //1301154426
        //1301154286
        {
            cout<<"Keluar";
            getch();
        }
        else
        {
            cout<<"Menu Tidak Tersedia"<<endl;
            getch();
        }
    }
    while(pilihan!=12);
}

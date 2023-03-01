#include<stdio.h>
#include<conio.h>
#include<math.h>
#include<time.h>
#include<stdlib.h>
#include<string.h>
#include<stddef.h>

struct hasta 
{

    char ad[20];
    char soyad[20];
    char tc[11];
    char tel[11];
    char adres[50];
    int doktorNo;
    int klinikNo;
    int durum;

};

struct doktor 
{

    char ad[20];
    char soyad[20];
    int klinikNo;
    int doktorNo;


};

void hastaKayit()
{
    system("cls");
    struct hasta h1;
    struct doktor d1;
    int sonuc;
    sonuc = 0;
    
    system("color 0a");
    printf("\n HASTA KAYIT EKRANINA HOSGELDINIZ \n");
    printf("\n Adi giriniz : ");
    scanf("%s",&h1.ad);
    printf("\n Soyadi giriniz : ");
    scanf("%s",&h1.soyad);
    printf("\n Tc giriniz : ");
    scanf("%s",&h1.tc);
    printf("\n Telefon giriniz : ");
    scanf("%s",&h1.tel);
    printf("\n Adres giriniz : ");
    scanf("%s",&h1.adres);
    system("cls");

    printf("\n klinikler \n : \n");
    printf("\n 1- Kardiyoloji \n");
    printf("\n 2- Cildiye \n");
    printf("\n 3- Dahiliye \n");
    printf("\n 4- Ortopedi \n");
    printf("\n 5- Psikiyatri \n");
    printf("klinik no giriniz : ");
    scanf("%d",&d1.klinikNo);

    FILE *ptr = fopen("hasta.txt", "a");
    while (fread(&h1, sizeof(struct hasta), 1, ptr));
    {
       if (h1.klinikNo == d1.klinikNo)
       {
       sonuc = 1;
       printf("\n klinik numarasi bulundu \n");
       printf(" %s %S \n ",d1 .ad, d1.soyad);
       }
       
    fclose(ptr);
    
    if (sonuc == 0)
    {
        printf("\n klinik numarasi bulunamadi \n");
    }
    else
    {
        printf("bu bolumun doktoru yoktur");
    }
       

    printf("\n Doktor numarasini giriniz : ");
    scanf("%d",&d1.doktorNo);
    h1.durum = 0;
    FILE *Hptr = fopen("doktor.txt", "a");
    fwrite(&d1, sizeof(struct hasta), 1, Hptr);
    fclose(Hptr);
    printf("\n Hastta kaydi basariyla yapildi \n");
     

}
}

void doktorGiris()
{
    system("cls");
    struct doktor d1;
    char kullaniciadi[20];
    char sifre[20];


    printf("\n DOKTOR GIRIS EKRANINA HOSGELDINIZ \n");
    printf("\n Kullanici Adi giriniz : ");
    scanf("%s",&kullaniciadi);
    printf("\n Sifre giriniz : ");
    scanf("%s",&sifre);

    
    FILE *ptr = fopen("doktor.txt", "r+b");
    while ( fread(&d1, sizeof(struct doktor), 1, ptr) !=NULL)
    {
        if(strcmp(d1.ad,kullaniciadi)==0 && strcmp(d1.soyad,sifre)==0)
        {
            printf("\n Doktor girisi basarili \n");
            break;
        }
        else
        {
            printf("\n Kullanici adi veya sifre yanlis \n");
            break;
        }
    }
    fclose(ptr);
    printf("\n Doktor giris basariyla yapildi \n");


}


void doktorKayit()
{
   system("cls");
   struct doktor d1;

    printf("\n DOKTOR KAYIT EKRANINA HOSGELDINIZ \n");
    printf("\n Adi giriniz : ");
    scanf("%s",&d1.ad);
    printf("\n Soyadi giriniz : ");
    scanf("%s",&d1.soyad);
    system("cls");

    printf("\n klinikler \n : \n");
    printf("\n 1- Kardiyoloji \n");
    printf("\n 2- Cildiye \n");
    printf("\n 3- Dahiliye \n");
    printf("\n 4- Ortopedi \n");
    printf("\n 5- Psikiyatri \n");
    printf("klinik no giriniz : ");
    scanf("%d",&d1.klinikNo);
    printf("\n Doktor numarasini giriniz : ");
    scanf("%d",&d1.doktorNo);
    
    FILE *ptr = fopen("doktor.txt", "a");
    fwrite(&d1, sizeof(struct doktor), 1, ptr);
    fclose(ptr);
    printf("\n Doktor basariyla kaydedildi \n");


}


int menu ()
{

    int secim;
    printf("\n HASTANE OTOMASYONU \n");
    printf("\n 1- Hasta kayit \n");
    printf("\n 2-Doktor girisi \n");
    printf("\n 3- Doktor kayit \n");
    printf("\n 0- Cikis \n");
    printf("\n Seciminizi giriniz : ");
    scanf("%d",&secim);

    return secim;
}

int main ()
{

    int secim;
    secim=menu();

    while(secim!=0)
    {
        switch(secim)
        {
        case 1:
            hastaKayit();
            break;
        case 2:
            doktorGiris();
            break;
        case 3:
            doktorKayit();
            break;
        case 0:
            break;
        default:
            printf("\n Yanlis secim \n");
            break;
        }
        secim=menu();
    }


    return 0;
}
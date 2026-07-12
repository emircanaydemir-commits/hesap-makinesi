#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <ctype.h>
// yiğit yapısı
#define max 15
char yigitoperator[max];
double yigitsayi[max + 1];
int topoperator = -1;
int topsayi = -1;
/*----------operatör yiğiti----------*/
// dolumu kontrol
int dolumu_operator()
{
    if (topoperator == max - 1)
    {
        return 1;
    }
    return 0;
}
// boşmu kontrol
int bosmu_operator()
{
    if (topoperator == -1)
    {
        return 1;
    }
    return 0;
}
// yiğita ekleme
void ekle_operator(char veri)
{
    if (dolumu_operator())
    {
        return;
    }
    topoperator++;
    yigitoperator[topoperator] = veri;
}
// yiğitan çıkarma
char cikar_operator()
{
    if (bosmu_operator())
    {
        return '\0';
    }
    char cikan = yigitoperator[topoperator];
    topoperator--;
    return cikan;
}
/*--------sayi yiğiti------*/
// boşmu kontrol
int bosmu_sayi()
{
    if (topsayi == -1)
    {
        return 1;
    }
    return 0;
}
// dolumu kontrol
int dolumu_sayi()
{
    if (topsayi == max - 1)
    {
        return 1;
    }
    return 0;
}
// ekleme
void ekle_sayi(double veri)
{
    if (dolumu_sayi())
    {
        return;
    }
    topsayi++;
    yigitsayi[topsayi] = veri;
}
double cikar_sayi()
{
    if (bosmu_sayi())
    {
        printf("\nyiğit bos!\n");
        return NAN;
    }
    else
    {
        double cikan = yigitsayi[topsayi];
        topsayi--;
        return cikan;
    }
}
// test
void yazdirsayi()
{
    for (int i = 0; i <= topsayi; i++)
    {
        printf("%lf ", yigitsayi[i]);
    }
    printf("\n");
}
void yazdiroperator()
{
    for (int i = 0; i <= topoperator; i++)
    {
        printf("%c", yigitoperator[i]);
    }
    printf("\n");
}
// işlem önceliği kontrolu
int kontrol(char operator)
{
    if (operator == '*' || operator == '%')
    {
        return 2;
    }
    else if (operator == '+' || operator == '-')
    {
        return 1;
    }
    return 0;
}
// işlemi kontrol edip yığıta ekle
void hesapla_ekle()
{
    char islem = cikar_operator();
    double sag = cikar_sayi();
    double sol = cikar_sayi();
    double sonuc = 0;
    if (islem == '*')
    {
        sonuc = sol * sag;
    }
    else if (islem == '%')
    {
        if (sag == 0)
        {
            printf("hatalı işlem girildi!");
            sonuc = NAN;
        }
        else
        {
            sonuc = sol / sag;
        }
    }

    else if (islem == '+')
    {
        sonuc = sol + sag;
    }
    else if (islem == '-')
    {
        sonuc = sol - sag;
    }
    ekle_sayi(sonuc);
}
//parçala ve yığına ekle 
double parcala(char ifade[]) {
    char *gezici = ifade;
    char *kalan;
   while(*gezici!='\0'){
    //eğer sayiysa direkt  yiğta ekle
    if (isdigit(*gezici))
    {
        double sayi=strtod(gezici,&kalan);
        ekle_sayi(sayi);
        gezici=kalan;
    }
    //eğer " ( " görürsen direkt yiğita ekle
    else if (gezici[0]=='(')
    {
        ekle_operator(gezici[0]);
        gezici++;
    }
    // " ) " görürsen yiğita ekleme ondan öceki işlemleri yap en son geziciyi artır
    else if (gezici[0]==')')
    {
       while (yigitoperator[topoperator]!='(')
       {
        hesapla_ekle();
       }
       cikar_operator();
       gezici++;
    }
    //işlem önceliğine göre hesapla
    // bir önceki işlem şuan girenden güçlüyse işlemi eklemeden önce hesapla
    else if(gezici[0]=='+' || gezici[0]=='-' || gezici[0]=='*' || gezici[0]=='%'){
        while (!bosmu_operator()&&kontrol(yigitoperator[topoperator])>=kontrol(gezici[0]))
        {
            hesapla_ekle();
        }
        ekle_operator(gezici[0]);
        gezici++;
        
    }
    //başka ifade varsa atla
    else{
        gezici++;
    }
   }
   //kalan ifadelerin tümünü hesapla
    while (!bosmu_operator())
    {
       hesapla_ekle();
    }
    return yigitsayi[topsayi];
    
}

int main()
{
    return 0;
}
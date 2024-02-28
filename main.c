#include <stdio.h>
#include <math.h>
#define max 10
#define order 4
  struct fonksiyon{
        float xcoef[10]; //polinom
        float xexp[10];
        int counter;
        float ustxcoef[10]; //üstel
        float ustxexp[10];
        float ustfonkxcoef[10];
        float ustfonkexp[10];
        float base[10];
        int ustelCounter;
        float logxcoef[10]; //logaritma
        float logxexp[10];
        float logfonkxcoef[10];
        float logfonkexp[10];
        float logbase[10];
        int logCounter;
        float t[10]; //trigonometri
        float txcoef[10];
        float txexp[10];
        float tfonxcoef[10];
        float tfonkxexp[10];
        int tcounter;
        float at[10]; //terstrigonometri
        float atxcoef[10];
        float atxexp[10];
        float atfonxcoef[10];
        float atfonkxexp[10];
        int atcounter;
    };
    double matrix[max][max];
    int matrixcounter;
    struct fonksiyon tgirdi;
    struct fonksiyon girdi;
    double FonksiyonCevap(double myvalue , struct fonksiyon girdifonk);
    void FonksiyonAl(int a);
    void menu();
    void tureval();
    double determinant(double a[10][10], double k);
int main()
{
    menu();
}
void menu()
{
    int girdi1;
    //ana menü
    do{
    printf("Lutfen Yapmak Istediginiz Islemi Secin \n");
    printf("1-Bisection yontemi\n");
    printf("2-Regula-Falsi yontemi\n");
    printf("3-Newton-Rapshon yontemi\n");
    printf("4-NxN'lik bir matrisin tersi\n");
    printf("5-Gauus Eleminasyon\n");
    printf("6-Gauss Seidal yontemleri\n");
    printf("7-Sayisal Turev\n");
    printf("8-Simpson yontemi\n");
    printf("9-Trapez yontemi\n");
    printf("10-Degisken dunusumsuz Gregory newton Enterpolasyonu\n");
    printf("0-Cikis\n\nGirdi : ");
    scanf("%d",&girdi1);
    if(girdi1==1)
    {
        system("CLS");
        FonksiyonAl(1);
        bisection();
    }
    else if(girdi1==2)
    {
        system("CLS");
        FonksiyonAl(1);
        regulafalsi();
    }
    else if(girdi1==3)
    {
        system("CLS");
        FonksiyonAl(0);
        newtonrapthson();
    }
    else if(girdi1==4)
         {
            system("CLS");
            matrixal();
            tersmatrix();
         }
    else if(girdi1==5)
        {
            system("CLS");
            gauselimination();
        }
    else if(girdi1==6)
       {
            system("CLS");
            gausseidal();
       }
    else if(girdi1==7)
        {
            system("CLS");
            FonksiyonAl(1);
            sayisalturev();
        }
    else if(girdi1==8)
    {
        system("CLS");
        FonksiyonAl(1);
        simpson();
    }
    else if(girdi1==9)
    {
        system("CLS");
        FonksiyonAl(1);
        trapezyontem();
    }
    else if(girdi1 ==10)
    {
        system("CLS");
        enterpolasyon();
    }
    else if(girdi1==0)
        printf("Cikis yapiliyor iyi gunler...");
    else{
        printf("Lutfen gecerli bir deger giriniz!!\n\n");
        }
    }while(girdi1!=0);
}
void gausseidal()
{
    float a[max][max], b[max], x[max], y[max];
    int n = 0, m = 0, i = 0, j = 0;
    printf("NxN matrixin N(satirsayisini girin : ");
    scanf("%d",&n);
    printf("Iterasyon sayisini girin : ");
    scanf("%d",&m);
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < n; j++)
        {
           printf("Matrisin [%d][%d]. elemaninin girin :",i+1,j+1);
            scanf("%d",&a[i][j]);
        }
    }
    printf("Sonuc matrisinin degerlerini girin\n");
    for (i = 0; i < n; i++)
    {
        printf("Matrisin [%d]. elemaninin girin  ",i+1);
        scanf("%d",&b[i]);
    }
    printf("X baslangic degerlerini girin :");
    for (i = 0; i < n; i++)
    {
        printf("x%d. : ",i+1);
        scanf("%d",&x[i]);
    }
    while (m > 0)
    {
        for (i = 0; i < n; i++)
        {
            y[i] = (b[i] / a[i][i]);
            for (j = 0; j < n; j++)
            {
                if (j == i)
                {

                }
                else
                {
                y[i] = y[i] - ((a[i][j] / a[i][i]) * x[j]);
                x[i] = y[i];
                }

            }
            printf("x%d = %f    ", i + 1, y[i]);
        }
        printf("\n");
        m--;
    }
}
void enterpolasyon()
{
    double ax[max+1], ay [max+1], fark[max+1][order+1], nr=1, dr=1,x,p,h,yp;
    int n,i,j,k;
    printf("Girilecek kac adet (x,y) ikilisi bulunmakta :\n");
    scanf("%d",&n);

    printf("x ve y degerlerini girin (tek satirda bir bosluk birakarak):\n");
    for (i=0;i<n;i++)
    {
       printf("%d.x %d.y icin : ",i+1,i+1);
       scanf("%lf %lf",&ax[i],&ay[i]);
    }
    printf("Bulmak istediginiz x degerini giriniz :\n");
    scanf("%lf",&x);
    h=ax[1]-ax[0];

    for (i=0;i<=n-1;i++)
        fark[i][1] = ay[i+1]-ay[i];

    for (j=2;j<=order;j++)
        for(i=0;i<=n-j;i++)
        fark[i][j] = fark[i+1][j-1] - fark[i][j-1];

    i=0;
    while (!(ax[i]>x))
        i++;

    i--;
    p = (x-ax[i])/h;
    yp = ay[i];

    for (k=1;k<=order;k++)
    {
        nr *=p-k+1;
        dr *=k;
        yp +=(nr/dr)*fark[i][k];
    }
    printf("x = %lf icin y = %lf\n",x,yp);

}
void gauselimination()
{
    int i,j,k,n;
    float matrix1[max][max],c,x[max],toplam=0;
    printf("matrixin satir sayisini girin : ");
    scanf("%d",&n);
    printf("matrisin elemanlarini tek tek girin. \n");
    for(i=1; i<=n; i++)
    {
        for(j=1; j<=(n+1); j++)
        {
            printf("Matrix[%d][%d] : ", i,j);
            scanf("%f",&matrix1[i][j]);
        }
    }
    for(j=1; j<=n; j++)
    {
        for(i=1; i<=n; i++)
        {
            if(i>j)
            {
                c=matrix1[i][j]/matrix1[j][j];
                for(k=1; k<=n+1; k++)
                {
                    matrix1[i][k]=matrix1[i][k]-c*matrix1[j][k];
                }
            }
        }
    }
    x[n]=matrix1[n][n+1]/matrix1[n][n];
    for(i=n-1; i>=1; i--)
    {
        toplam=0;
        for(j=i+1; j<=n; j++)
        {
            toplam=toplam+matrix1[i][j]*x[j];
        }
        x[i]=(matrix1[i][n+1]-toplam)/matrix1[i][i];
    }
    printf("\nCevaplar :: \n");
    for(i=1; i<=n; i++)
    {
        printf("x%d=%f\n",i,x[i]);
    }
}
void tersmatrix()
{
   if(determinant(matrix,matrixcounter)==0)
   {
       printf("Matrixin tersi yoktur");
   }
   else
   {
       cofactor(matrix,matrixcounter);
   }
}
 void cofactor(double num[max][max], int f)
{
 double b[max][max], fac[max][max];
 int p, q, m, n, i, j;
 for (q = 0;q < f; q++)
 {
   for (p = 0;p < f; p++)
    {
     m = 0;
     n = 0;
     for (i = 0;i < f; i++)
     {
       for (j = 0;j < f; j++)
        {
          if (i != q && j != p)
          {
            b[m][n] = num[i][j];
            if (n < (f - 2))
             n++;
            else
             {
               n = 0;
               m++;
               }
            }
        }
      }
      fac[q][p] = pow(-1, q + p) * determinant(b, f - 1);
    }
  }
  transpoz(num, fac, f);
}
void transpoz(double num[max][max], double fac[max][max], int r)
{
  int i, j;
  double b[max][max], inverse[max][max], d;

  for (i = 0;i < r; i++)
    {
     for (j = 0;j < r; j++)
       {
         b[i][j] = fac[j][i];
        }
    }
  d = determinant(num, r);
  for (i = 0;i < r; i++)
    {
     for (j = 0;j < r; j++)
       {
        inverse[i][j] = b[i][j] / d;
        }
    }
   printf("\tmatrixin tersi : \n");

   for (i = 0;i < r; i++)
    {
     for (j = 0;j < r; j++)
       {
         printf("\t[%lf]", inverse[i][j]);
        }
    printf("\n");
     }
}
double determinant(double a[max][max], double k)
{
  double s = 1, det = 0, b[max][max];
  int i, j, m, n, c;
  if (k == 1)
    {
     return (a[0][0]);
    }
  else
    {
     det = 0;
     for (c = 0; c < k; c++)
       {
        m = 0;
        n = 0;
        for (i = 0;i < k; i++)
          {
            for (j = 0 ;j < k; j++)
              {
                b[i][j] = 0;
                if (i != 0 && j != c)
                 {
                   b[m][n] = a[i][j];
                   if (n < (k - 2))
                    n++;
                   else
                    {
                     n = 0;
                     m++;
                     }
                   }
               }
             }
          det += s * (a[0][c] * determinant(b, k - 1));
          s = -1 * s;
          }
    }

    return det;
}
void sayisalturev()
{
    int choice;
    double h,X0,cevap=0;
    printf("Lutfen yapmak istediginiz islemi secin \n 1-ileri \n 2-geri \n 3-merkezi \n");
    scanf("%d",&choice);
    printf("Lutfen X0 degerini giriniz : \n");
    scanf("%lf",&X0);
    printf("Lutfen h degerini giriniz(geri fark yontemini kullanacaksaniz lutfen h degerini mutlak deger islemine tabi tutup giriniz) : \n");
    scanf("%lf",&h);
    if(choice==1)
    {
        cevap = (FonksiyonCevap(X0+h,girdi)-FonksiyonCevap(X0,girdi))/h ;
    }
    else if(choice==2)
    {
        cevap = (FonksiyonCevap(X0,girdi)-FonksiyonCevap(X0-h,girdi))/h ;
    }
    else if(choice==3)
    {
        cevap = (1/(2*h))*(FonksiyonCevap(X0+h,girdi)-FonksiyonCevap(X0-h,girdi));
    }
    printf("cevap : %lf \n",cevap);

}
void newtonrapthson()
{
        double baslangic,epsilon,cevap;
        int maxiter,iterasyon=0,kontrol = 1;
        printf("Lutfen baslangic degerini giriniz : \n");
        scanf("%lf",&baslangic);
        printf("Lutfen epsilon degerini giriniz : \n");
        scanf("%lf",&epsilon);
        printf("Lutfen maxiterasyon degerini giriniz : \n");
        scanf("%d",&maxiter);
        while (kontrol==1 && iterasyon<maxiter)
        {

        tureval();
        iterasyon++;
        if(FonksiyonCevap(baslangic,tgirdi)==0)
        {
            printf("!!!HATA GIRILEN DEGERLERDE MATEMATIKSEL MANTIK HATASI BULUNMAKTADIR!!!");
            kontrol=0;

        }
        if(kontrol==1)
        {
            cevap = baslangic - (FonksiyonCevap(baslangic,girdi) / FonksiyonCevap(baslangic,tgirdi));
            printf("baslagic : %lf \n",baslangic);
            printf("cevap : %lf \n",cevap);
            printf("f(baslangic) : %lf \n",FonksiyonCevap(baslangic,girdi));
            printf("df(baslangic) : %lf \n",FonksiyonCevap(baslangic,tgirdi));
            printf("Iterasyon : %d \n\n",iterasyon);
            if (fabs((cevap - baslangic) / cevap) < epsilon)
                {
                    printf("onaylanmis cevap : %lf\n", cevap);
                    kontrol = 0;
                }
            baslangic = cevap;
        }
        }
}
void bisection()
{
    double Baslangic, Son, Epsilon,Mid,GercekKok;
    int MaxIterasyon,Kosul,sayac = 0,kontrol =1;
    printf("Lutfen baslangic degerini giriniz : ");
    scanf("%lf",&Baslangic);
    printf("Lutfen Son degerini giriniz : ");
    scanf("%lf",&Son);
    printf("Lutfen Epsilon degerini giriniz : ");
    scanf("%lf",&Epsilon);
    printf("Lutfen Kosul degerini giriniz : \n");
    printf("1-Gercek kok ile \n2-gercek kok olmadan \n");
    scanf("%d",&Kosul);
    if(Kosul==1)
    {
        printf("\nLutfen gercek kok degerini giriniz : ");
        scanf("%lf",&GercekKok);
    }
    printf("Lutfen Max Iterasyon degerini giriniz : ");
    scanf("%d",&MaxIterasyon);
    do{
    sayac++;
    Mid = (Baslangic+Son)/2;
    printf("Baslangic : %lf\n",Baslangic);
    printf("Son : %lf\n",Son);
    printf("Orta : %lf\n",Mid);
    printf("f(baslangic) : %lf\n",FonksiyonCevap(Baslangic,girdi));
    printf("f(son) : %lf\n",FonksiyonCevap(Son,girdi));
    printf("f(mid) : %lf\n",FonksiyonCevap(Mid,girdi));
    printf("Iterasyon : %d\n\n",sayac);

    if(FonksiyonCevap(Mid,girdi)*FonksiyonCevap(Baslangic,girdi) < 0)
        Son = Mid;
    else
        Baslangic = Mid;
    if(Kosul==1 && fabs(GercekKok-Mid)<=Epsilon)
    {
        kontrol =0;
        printf("Cevap : %lf \n",Mid);
    }
    else if(Kosul==2 && ((Son-Baslangic)/pow(2,sayac))<= Epsilon)
    {
        kontrol =0;
        printf("Cevap : %lf \n",Mid);
    }

    }while(sayac<MaxIterasyon && kontrol==1);

}
void simpson()
{
    double baslangic, son,cevap=0.0,x1;
    int i,choice,kontrol,bolsayi;
    do{
    kontrol = 1;
    printf("yapmak istediginiz islem nedir ? \n 1-simpson 1/3 \n 2-simpson 3/8\n");
    scanf("%d",&choice);
    printf("Baslangic degerini girin : \n");
    scanf("%lf",&baslangic);
    printf("end degerini girin : \n");
    scanf("%lf",&son);
    printf("Bolum 'n' sayisini girin : \n");
    scanf("%d",&bolsayi);
    if(choice == 1)
    {
        x1=(son-baslangic)/bolsayi;
        for(i=1;i<=bolsayi;i++)
        {
            baslangic = son-x1;
            cevap += ((son-baslangic)*(FonksiyonCevap(baslangic,girdi)+4*FonksiyonCevap((baslangic+son)/2,girdi)+FonksiyonCevap(son,girdi)))/6;
            son = baslangic;
        }
    }
    else if(choice == 2)
    {
        x1=((son-baslangic)/bolsayi);
        for(i=1;i<=bolsayi;i++)
        {
            baslangic = son-x1;
            cevap += (((son-baslangic)*(FonksiyonCevap(baslangic,girdi)+3*FonksiyonCevap(baslangic+(2*(son-baslangic)/3),girdi)+3*FonksiyonCevap(baslangic+((son-baslangic)/3),girdi)+FonksiyonCevap(son,girdi)))/8.0);
            son= baslangic;
        }
    }
    else
    {
        printf("girilen komut hatali lutfen dogru bir komut girin\n");
        kontrol = 0;
    }
    }while(kontrol==0);
    printf("cevap : %lf\n",cevap);
}
void regulafalsi()
{
    float baslangic, son, dogrux  , epsilon;
    int maxiter , iterasyon = 0,kontrol=1;

    printf("Lutfen baslangic degerini giriniz : \n");
    scanf("%f",&baslangic);
    printf("Lutfen Son degerini giriniz : \n");
    scanf("%f",&son);
    printf("Lutfen Epsilon degerini giriniz : \n");
    scanf("%f",&epsilon);
    printf("Lutfen Max Iterasyon degerini giriniz : \n");
    scanf("%d",&maxiter);
    if((FonksiyonCevap(baslangic,girdi)*FonksiyonCevap(son,girdi))>0)
    {
        printf("Verilen aralıkta kök bulunmamaktadır \n");
        kontrol = 0;
    }
     while (kontrol == 1 && iterasyon < maxiter)
     {
         iterasyon++;
        if(FonksiyonCevap(son,girdi) == FonksiyonCevap(baslangic,girdi))
        {
            printf("HATA !!! LUTFEN GIRILEN DEGERLERIN MATEMATIKSEL MANTIK KURALLARINA UYGUN OLDUGUNU KONTROL EDINIZ !!! ");
            kontrol = 0;
        }
        else
        {
              dogrux = (baslangic*FonksiyonCevap(son,girdi) - son*FonksiyonCevap(baslangic,girdi)) / (FonksiyonCevap(son,girdi) - FonksiyonCevap(baslangic,girdi));
            if (FonksiyonCevap(dogrux,girdi) * FonksiyonCevap(baslangic,girdi) < 0)
            {
                son = dogrux;
            } else
            {
                baslangic = dogrux;
            }
            printf("Baslangic : %f \n",baslangic);
            printf("f(Baslangic) : %lf \n",FonksiyonCevap(baslangic,girdi));
            printf("Son : %f \n",son);
            printf("f(son) : %lf \n",FonksiyonCevap(son,girdi));
            printf("c : %f \n",dogrux);
            printf("f(c) : %lf \n",FonksiyonCevap(dogrux,girdi));
            printf("iterasyon : %d \n\n",iterasyon);
            if (fabs(son-baslangic)/pow(2,iterasyon) < epsilon)
            {
                printf("Cevap : %lf \n",dogrux);
                kontrol = 0;
            }
        }
    }
}
void trapezyontem()
{
    double baslangic,son,bolsayi, cevap=0,ikinoktaarasi;
    int h,i;
    printf("Lutfen baslangic degerini giriniz : \n");
    scanf("%lf",&baslangic);
    printf("Lutfen end degerini giriniz : \n");
    scanf("%lf",&son);
    printf("Lutfen bolunme sayisi degerini giriniz : \n");
    scanf("%lf",&bolsayi);
    ikinoktaarasi = (son-baslangic)/bolsayi;
    for(i=1;i<=bolsayi;i++)
        {
            cevap += (FonksiyonCevap(baslangic+(i*ikinoktaarasi),girdi)+ FonksiyonCevap(baslangic+((i-1)*ikinoktaarasi),girdi))/2;
        }
        cevap = cevap*ikinoktaarasi;
        printf("%lf \n",cevap);
}
double FonksiyonCevap(double myvalue , struct fonksiyon girdifonk) //   myvalue = fonksiyon içide işlem yapılacak x değeri   girdifonk = fonksiyonun katsayıları
{
    double sonuc=0;
    int i;
    double log1;
    if(girdifonk.counter>0)
    {
        for(i=0;i<girdifonk.counter;i++)
        {
            sonuc += girdifonk.xcoef[i] * pow(myvalue,girdifonk.xexp[i]);
        }
    }
    if(girdifonk.ustelCounter>0)
    {
        for(i=0;i<girdifonk.ustelCounter;i++)
        {
            sonuc += (girdifonk.ustfonkxcoef[i] * pow(pow(girdifonk.base[i],girdifonk.ustxcoef[i]*pow(myvalue,girdifonk.ustxexp[i])),girdifonk.ustfonkexp[i]));
        }
    }
    if(girdifonk.logCounter>0)
    {
         for(i=0;i<girdifonk.logCounter;i++)
        {   log1=0;
            log1 = log(girdifonk.logxcoef[i] * pow(myvalue,girdifonk.logxexp[i]))/log(girdifonk.logbase[i]);
            sonuc += (girdifonk.logfonkxcoef[i] * pow(log1,girdifonk.logfonkexp[i]));
        }
    }
    if(girdifonk.tcounter>0)
    {
        for(i=0;i<girdifonk.tcounter;i++)
        {
            if(girdifonk.t[i]==1) // sin
            {
                sonuc += girdifonk.tfonxcoef[i] * (pow(sin(girdifonk.txcoef[i] * pow(myvalue,girdifonk.txexp[i])),girdifonk.tfonkxexp[i]));
            }
             else if(girdifonk.t[i]==2) //cos
            {
                sonuc += girdifonk.tfonxcoef[i] * (pow(cos(girdifonk.txcoef[i] * pow(myvalue,girdifonk.txexp[i])),girdifonk.tfonkxexp[i]));
            }
            else if(girdifonk.t[i]==3)  // tan
            {
                sonuc += girdifonk.tfonxcoef[i] * (pow(tan(girdifonk.txcoef[i] * pow(myvalue,girdifonk.txexp[i])),girdifonk.tfonkxexp[i]));
            }
            else if(girdifonk.t[i]==4)  //cot
            {
                 sonuc += girdifonk.tfonxcoef[i] * (pow(1/tan(girdifonk.txcoef[i] * pow(myvalue,girdifonk.txexp[i])),girdifonk.tfonkxexp[i]));
            }
        }
    }
    if(girdifonk.atcounter>0)
    {
        for(i=0;i<girdifonk.atcounter;i++)
        {
            if(girdifonk.at[i]==1) // arcsin
            {
                sonuc += girdifonk.atfonxcoef[i] * (pow(asin(girdifonk.atxcoef[i] * pow(myvalue,girdifonk.atxexp[i])),girdifonk.atfonkxexp[i]));
            }
             else if(girdifonk.at[i]==2) //arccos
            {
                sonuc += girdifonk.atfonxcoef[i] * (pow(acos(girdifonk.atxcoef[i] * pow(myvalue,girdifonk.atxexp[i])),girdifonk.atfonkxexp[i]));
            }
            else if(girdifonk.at[i]==3)  // arctan
            {
                sonuc += girdifonk.atfonxcoef[i] * (pow(atan(girdifonk.atxcoef[i] * pow(myvalue,girdifonk.atxexp[i])),girdifonk.atfonkxexp[i]));
            }
            else if(girdifonk.at[i]==4)  //arccot
            {
                sonuc += girdifonk.atfonxcoef[i] * (pow(atan(girdifonk.atxcoef[i] * pow(1/myvalue,girdifonk.atxexp[i])),girdifonk.atfonkxexp[i]));
            }
        }
    }
    return sonuc;
}
void FonksiyonAl(int a) // int a polinom dışında işlem yapacaksam 1 yapmayacaksam 0 olacak
{
    char kontrol;
    girdi.counter=0;
    girdi.ustelCounter=0;
    girdi.logCounter=0;
    girdi.tcounter=0;
    girdi.atcounter=0;
    while(girdi.counter<10 && (kontrol !='e' && kontrol!='E'))
    {
        printf("Foknsiyonun polinomsal degerlerine ekleme yapmak icin a sonraki isleme gecmek icin e tusuna basin :");
        scanf(" %c",&kontrol);
        if(kontrol == 'a' || kontrol =='A')
        {
            printf("x'in katsayisi : ");
            scanf("%f",&girdi.xcoef[girdi.counter]);
            printf("x'in ussu : ");
            scanf("%f",&girdi.xexp[girdi.counter]);
            girdi.counter++;
        }
        else if (kontrol !='e'&& kontrol!='E' && kontrol != 'a'&& kontrol !='A')
            printf("Lutfen gecerli bir deger giriniz\n");
    }
    if(girdi.counter==10)
        printf("Bu uygulama maximum 10 parcadan olusan fonksiyonlar uzerinde islem yapabilmektedir\n");
//--------------------------------------------------------------------------------------------------------------------------------
        kontrol = '\n';
        if(a==1) //islemler polinom disindaki fonksiyon turlerinde de degisken aliyorsa 1 almiyorsa 0
        {
        while(girdi.ustelCounter<10 && (kontrol !='e' && kontrol!='E'))
    {
        printf("Foknsiyonun ustel degerlerine ekleme yapmak icin a sonraki isleme gecmek icin e tusuna basin :");
        scanf(" %c",&kontrol);
        if(kontrol == 'a' || kontrol =='A')
        {
            printf("x'in katsayisi : ");
            scanf("%f",&girdi.ustxcoef[girdi.ustelCounter]);
            printf("x'in ussu : ");
            scanf("%f",&girdi.ustxexp[girdi.ustelCounter]);
            printf("fonksiyonun katsayisi : ");
            scanf("%f",&girdi.ustfonkxcoef[girdi.ustelCounter]);
            printf("fonksiyonun ussu : ");
            scanf("%f",&girdi.ustfonkexp[girdi.ustelCounter]);
            printf("taban : ");
            scanf("%f",&girdi.base[girdi.ustelCounter]);
            girdi.ustelCounter++;
        }
        else if (kontrol !='e'&& kontrol!='E' && kontrol != 'a'&& kontrol !='A')
            printf("Lutfen gecerli bir deger giriniz\n");
    }
    if(girdi.ustelCounter==10)
        printf("Bu uygulama maximum 10 parcadan olusan fonksiyonlar uzerinde islem yapabilmektedir\n");
        //--------------------------------------------------------------------------------------------------------------------------------
        kontrol = '\n';
        while(girdi.logCounter<10 && (kontrol !='e' && kontrol!='E'))
    {
        printf("Foknsiyonun logaritmik degerlerine ekleme yapmak icin a sonraki isleme gecmek icin e tusuna basin :");
        scanf(" %c",&kontrol);
        if(kontrol == 'a' || kontrol =='A')
        {
            printf("x'in katsayisi : ");
            scanf("%f",&girdi.logxcoef[girdi.logCounter]);
            printf("x'in ussu : ");
            scanf("%f",&girdi.logxexp[girdi.logCounter]);
            printf("fonksiyonun katsayisi : ");
            scanf("%f",&girdi.logfonkxcoef[girdi.logCounter]);
            printf("fonksiyonun ussu : ");
            scanf("%f",&girdi.logfonkexp[girdi.logCounter]);
            printf(" logaritmanin taban : ");
            scanf("%f",&girdi.logbase[girdi.logCounter]);
            girdi.logCounter++;
        }
        else if (kontrol !='e'&& kontrol!='E' && kontrol != 'a'&& kontrol !='A')
            printf("Lutfen gecerli bir deger giriniz\n");
    }
    if(girdi.logCounter==10)
        printf("Bu uygulama maximum 10 parcadan olusan fonksiyonlar uzerinde islem yapabilmektedir\n");
        //--------------------------------------------------------------------------------------------------------------------------------
        kontrol = '\n';
        while(girdi.tcounter<10 && (kontrol !='e' && kontrol!='E'))
    {
        printf("Foknsiyonun trigonometrik degerlerine ekleme yapmak icin a sonraki isleme gecmek icin e tusuna basin :");
        scanf(" %c",&kontrol);
        if(kontrol == 'a' || kontrol =='A')
        {
            printf("sin : 1 - cos : 2 - tan : 3 - cot : 4\n");
            printf("trigonometrik tur : ");
            scanf("%f",&girdi.t[girdi.tcounter]);
            printf("x'in katsayisi : ");
            scanf("%f",&girdi.txcoef[girdi.tcounter]);
            printf("x'in ussu : ");
            scanf("%f",&girdi.txexp[girdi.tcounter]);
            printf("fonksiyonun katsayisi : ");
            scanf("%f",&girdi.tfonxcoef[girdi.tcounter]);
            printf("fonksiyonun ussu : ");
            scanf("%f",&girdi.tfonkxexp[girdi.tcounter]);
            girdi.tcounter++;
        }
        else if (kontrol !='e'&& kontrol!='E' && kontrol != 'a'&& kontrol !='A')
            printf("Lutfen gecerli bir deger giriniz\n");
    }
    if(girdi.tcounter==10)
        printf("Bu uygulama maximum 10 parcadan olusan fonksiyonlar uzerinde islem yapabilmektedir\n");
        //--------------------------------------------------------------------------------------------------------------------------------
        kontrol = '\n';
        while(girdi.atcounter<10 && (kontrol !='e' && kontrol!='E'))
    {
        printf("Foknsiyonun terstrigonemetrik degerlerine ekleme yapmak icin a sonraki isleme gecmek icin e tusuna basin :");
        scanf(" %c",&kontrol);
        if(kontrol == 'a' || kontrol =='A')
        {
            printf("arcsin : 1 - arccos : 2 - arctan : 3 - arccot : 4\n");
            printf("trigonometrik tur : ");
            scanf("%f",&girdi.at[girdi.atcounter]);
            printf("x'in katsayisi : ");
            scanf("%f",&girdi.atxcoef[girdi.atcounter]);
            printf("x'in ussu : ");
            scanf("%f",&girdi.atxexp[girdi.atcounter]);
            printf("fonksiyonun katsayisi : ");
            scanf("%f",&girdi.atfonxcoef[girdi.atcounter]);
            printf("fonksiyonun ussu : ");
            scanf("%f",&girdi.atfonkxexp[girdi.atcounter]);
            girdi.atcounter++;
        }
        else if (kontrol !='e'&& kontrol!='E' && kontrol != 'a'&& kontrol !='A')
            printf("Lutfen gecerli bir deger giriniz\n");
    }
    if(girdi.atcounter==10)
        printf("Bu uygulama maximum 10 parcadan olusan fonksiyonlar uzerinde islem yapabilmektedir\n");
        }
}
void tureval()
{
    int i,k=0;
    if (girdi.counter>0)
    {
        for(i=0;i<girdi.counter;i++)
        {
            tgirdi.xcoef[i] = girdi.xcoef[i]*girdi.xexp[i];
            if(girdi.xexp[i]>0)
            {
                tgirdi.xexp[i] = girdi.xexp[i]-1;
            }
            else
            {
                k++;
            }

        }
        tgirdi.counter = girdi.counter - k ;
    }
    else
        printf("LUTFEN BİR FONKSİYON GIRIN VE TEKRAR DENEYIN");
}
void matrixal()
{
    int i, j;
    printf("Alinacak matris NxN formatin da olacaktir. \n");
    printf("Lutfen N sayisini giriniz\n");
    scanf("%d",&matrixcounter);
    for(i=0;i<matrixcounter;i++)
    {
        for(j=0;j<matrixcounter;j++)
        {
            printf("Lutfen matrisin [%d]x[%d]. elemanini girin.\n",i+1,j+1);
            scanf("%lf",&matrix[i][j]);
        }
    }
    printf("Girilien matris\n");
    for(i=0;i<matrixcounter;i++)
    {
        for(j=0;j<matrixcounter;j++)
        {
            printf("[%lf]",matrix[i][j]);
        }
        printf("\n");
    }
}

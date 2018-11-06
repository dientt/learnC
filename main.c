#include<stdio.h>
#include<math.h>
#include<stdlib.h>

//dem so phan tu cua mang
int count_array(int *a){
    int result = 0;
    while (*a) {
        a++;
        result++;
    }
    return result;
}

// nhap mang
int *nhap_mang(){
    int n = 0;
    printf("Nhap n: ");
    scanf("%d",&n);
    int *a = (int*)malloc(n*sizeof(int));
    for (int i=0; i<n; i++) {
        printf("a[%d] = ", i);
        scanf("%d", &a[i]);
    }
    return a;
}

// xuat mang
void xuat_mang(int *a){
    int n = count_array(a);
    printf("Mang da nhap la: \n");
    for (int i=0; i<n; i++) {
        printf("%d\t",a[i]);
    }
    printf("\n");
}

/*void dem_phan_am( int a[], int n){
    int dem=0;
    for (int i=0; i<n; i++) {
        if(a[i]<0)
            dem++;
    }
    if(dem>0)
        printf("\nMang co %d so am.\n ",dem);
    else
        printf("\nMang ko co so am\n");
}
void max( int a[], int n){
    int max =a[0];
    for (int i= 0; i<n; i++) {
        if(max<a[i] )
            max= a[i];
    }
    printf("Gia tri lon nhat la:%d\n", max);
}
void min( int a[], int n){
    int min =a[0];
    for (int i= 0; i<n; i++) {
        if(min>a[i] )
            min = a[i];
    }
    printf("Gia tri be nhat la:%d\n", min);
}
 void hoan_vi( int *a, int *b){
 int temp = *a;
 *a=*b;
 *b= temp;
 }
void sap_xep_giam_dan( int a[], int n){
    for (int i=0; i<n-1; i++) {
        for (int j=i+1;j<n;j++) {
            if( a[i]< a[j]){
                int temp= a[i];
                a[i]=a[j];
                a[j]=temp;
            }
        }
    }
    printf("Mang da sap xep giam dan la:");
    xuat_mang(a, n);
}

void sap_xep_noi_bot( int a[],int n){
    for (int i = 0; i < n-1; i++) {
        for(int j=n-1;j>i;j--){
            if( a[i] > a[j]){
                hoan_vi(&a[i], &a[j]);
            }
        }
    }
    printf("\nMang sau khi sap xep la:");
    xuat_mang(a,n);
}
void so_chinh_phuong( int a[], int n){
    printf("\nCac so chinh phuong ");
    for (int i =0; i<n; i++) {
        if(sqrt(a[i]) * sqrt(a[i]) == a[i])
            printf("%d\t", a[i]);
    }
}
void so_nguyen_to( int a[], int n){
    printf("\nCac so nguyen to la: ");
    for (int i =0; i< n; i++) {
        if(a[i]%2== 1)
            printf("%d\t",a[i]);
    }
}


void tach_mang( int a[], int n, int temp[], int *ntemp){
    *ntemp = 0;
    for (int i= 0; i<n; i++) {
        if( a[i]<0){
            temp[*ntemp] = a[i];
            (*ntemp)++;
        }
    }
    if(*ntemp>0){
    printf("\nMang so am la: ");
        xuat_mang(temp,*ntemp);
       // max(temp, ntemp);
   }
    else{
        printf("\nMang ko co so am: ");
    }
 }

void gop_mang( int a[], int n, int temp[], int ntemp){

    a[] = {1, 2, 3 ,4, 5} --> n = 5
    temp[] = {6, 7, 8} --> ntemp = 3


    n+= ntemp;
    // n == 8;
    // n-ntemp == 5;
    int x[n];
    for (int i = 0; i < n-ntemp; i++) {
        x[i] = a[i];
    }
    for (int i=n-ntemp; i<n; i++) {
        x[i]=temp[i-(n-ntemp)];
        // x[5] = temp[0] -->x[5] == 6;
    }
    printf("\nGop mang: ");
    xuat_mang(x, n);
}

void sap_xep_nhanh( int a[], int left, int right){
    int i =left;
    int j=right;
    int chot =a[(right + left)/2];
    while (a[i]< chot)  {
        i++;
    }
    while (a[j]>chot) j++;
    if (i<j) {

            int temp = a[i];
            a[i]=a[j];
            a[j]= temp;

        i++;
        j++;
    }
    if (left<j) {
        sap_xep_nhanh(a, left, j);
    }
    if(i<right ){
        sap_xep_nhanh(a, i, right);}
}
 */

int main(){
    int *a = nhap_mang();
    xuat_mang(a);
   /*dem_phan_am(a, n);
    max(a, n);
    min(a, n);
    sap_xep_giam_dan(a,n);
    sap_xep_noi_bot(a, n);
    so_chinh_phuong(a, n);
    so_nguyen_to(a, n);*/
    // tach_mang(a, n, temp, &ntemp);
//    sap_xep_nhanh(a,0,n);
    // gop_mang(a, n, temp, ntemp);
    free(a);
    return 0;
}

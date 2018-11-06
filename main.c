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
    for (int i = 0; i < n; i++) {
        printf("%d\t",a[i]);
    }
    printf("\n");
}

// dem phan am
void dem_phan_am(int *a){
    int count = 0;
    int n = count_array(a);
    for (int i = 0; i<n; i++){
        if(a[i] < 0) count++;
    }
    if(count > 0)
        printf("Mang co %d so am\n ",count);
    else
        printf("Mang ko co so am\n");
}

// tim gia tri lon nhat
void max(int *a){
    int n = count_array(a);
    int max = a[0];
    for (int i=0; i<n; i++) {
        if(max < a[i]) max = a[i];
    }
    printf("Gia tri lon nhat la: %d\n", max);
}

// tim gia tri nho nhat
void min(int *a){
    int n = count_array(a);
    int min =a[0];
    for (int i= 0; i<n; i++) {
        if(min > a[i]) min = a[i];
    }
    printf("Gia tri be nhat la: %d\n", min);
}

// hoan vi
void hoan_vi(int *a, int *b){
    int temp = *a;
    *a = *b;
    *b = temp;
 }

// sap xep giam dan
void sap_xep_giam_dan(int *a){
    int n = count_array(a);
    for (int i = 0; i < n-1; i++) {
        for (int j = i+1; j < n; j++) {
            if( a[i]< a[j]){
                hoan_vi(&a[i], &a[j]);
            }
        }
    }
    printf("Mang da sap xep giam dan la:");
    xuat_mang(a);
}

// sap xep noi bot
void sap_xep_noi_bot(int *a){
    int n = count_array(a);
    for (int i = 0; i < n-1; i++) {
        for(int j=n-1;j>i;j--){
            if( a[i] > a[j]){
                hoan_vi(&a[i], &a[j]);
            }
        }
    }
    printf("Mang da sap xep tang dan la:");
    xuat_mang(a);
}

// so chinh phuong
void so_chinh_phuong(int *a){
    int n = count_array(a);
    printf("Cac so chinh phuong la: ");
    for (int i = 0; i < n; i++) {
        if(sqrt(a[i]) * sqrt(a[i]) == a[i])
            printf("%d\t", a[i]);
    }
    printf("\n");
}

// so nguyen to
void so_nguyen_to(int *a){
    int n = count_array(a);
    printf("Cac so nguyen to la: ");
    for (int i = 0; i<n; i++) {
        if(a[i]%2 == 1)
            printf("%d\t",a[i]);
    }
    printf("\n");
}

// tach mang
int *tach_mang(int *a){
    int *result = NULL;
    int n = count_array(a);
    int count = 0;
    //count so cac so am
    for (int i = 0; i < n; i++) {
        if (a[i]<0) {
            count++;
        }
    }

    if (count == 0) {
        printf("Mang ko co so am: \n");
        return result;
    }

    result = (int*)malloc(count*sizeof(int));
    n = count;
    count = 0;
    for (int i = 0; i < n; i++) {
        if( a[i]<0){
            result[count] = a[i];
            count++;
        }
    }

    printf("Mang cac so am la: ");
    xuat_mang(result);
    return result;
}

// gop mang
int *gop_mang(int *a, int *b){
    int n = count_array(a);
    int m = count_array(b);
    int *result = (int*)malloc((m+n)*sizeof(int));
    for (int i = 0; i < n; i++) {
        result[i] = a[i];
    }
    for (int i = 0; i < m; i++) {
        result[i+n-1] = b[i];
    }
    printf("Gop mang: ");
    xuat_mang(result);
    return result;
}

// sap xep nhanh
void sap_xep_nhanh(int *a, int left, int right){
    int i = left;
    int j = right;
    int pivot = a[(left + right)/2];
    while (i <= j) {
      while (a[i] < pivot) {
        i++;
      }

      while (a[j] > pivot) {
        j--;
      }

      if (i <= j) {
        hoan_vi(&a[i],&a[j]);
        i++;
        j--;
      }
    }
    if (left < j) {
        sap_xep_nhanh(a, left, j);
    }
    if (i < right ){
        sap_xep_nhanh(a, i, right);
    }
}

int main(){
    int *a = nhap_mang();
    printf("Mang da nhap la: \n");
    xuat_mang(a);
    dem_phan_am(a);
    max(a);
    min(a);
    sap_xep_giam_dan(a);
    sap_xep_noi_bot(a);
    so_chinh_phuong(a);
    so_nguyen_to(a);
    int *b = tach_mang(a);
    sap_xep_nhanh(a, 0, count_array(a)-1);
    printf("Mang da sap xep tang dan la:\n");
    xuat_mang(a);
    int *c = gop_mang(a,b);
    free(a);
    free(b);
    free(c);
    return 0;
}

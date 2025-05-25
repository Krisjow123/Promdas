#include <stdio.h>      // Library standar untuk input/output
#include <string.h>     // Library untuk operasi string seperti strcpy, strcmp

#define MAX_TIM 5       // Mendefinisikan konstanta jumlah maksimal tim

// Struktur data untuk menyimpan informasi satu tim
struct Tim {
    char nama[50];      // Variabel array karakter untuk nama tim
    int poin;           // Variabel untuk menyimpan poin tim
};

// Fungsi untuk menukar dua data tim (digunakan dalam sorting)
// Konsep dasar: Fungsi, Pointer, Struct
void tukar(struct Tim *a, struct Tim *b) {
    struct Tim temp = *a;   // Simpan sementara nilai a
    *a = *b;                // Salin nilai b ke a
    *b = temp;              // Salin nilai sementara ke b
}

// Fungsi untuk mengurutkan tim berdasarkan poin secara menurun
// Konsep dasar: Fungsi, Perulangan, Array, Struct
void urutkanTim(struct Tim liga[], int jumlah) {
    for (int i = 0; i < jumlah - 1; i++) {             // Perulangan luar
        for (int j = 0; j < jumlah - i - 1; j++) {     // Perulangan dalam
            if (liga[j].poin < liga[j + 1].poin) {     // Percabangan: jika poin lebih kecil, tukar posisi
                tukar(&liga[j], &liga[j + 1]);         // Panggil fungsi tukar
            }
        }
    }
}

// Fungsi utama program
int main() {
    struct Tim liga[MAX_TIM];      // Array struct untuk menyimpan data semua tim
    int jumlahTim;                 // Variabel untuk menyimpan jumlah tim

    printf("=== Simulasi Klasemen Mini Liga Indonesia ===\n");

    // Input jumlah tim
    printf("Masukkan jumlah tim (maks %d): ", MAX_TIM);
    scanf("%d", &jumlahTim);       // Input bilangan bulat
    // Percabangan untuk validasi input
    if (jumlahTim < 2 || jumlahTim > MAX_TIM) {
        printf("Jumlah tim tidak valid!\n");   // Tampilkan pesan jika input tidak valid
        return 1;       // Keluar dari program
    }

    // Perulangan untuk menginput nama dan poin setiap tim
    for (int i = 0; i < jumlahTim; i++) {
        printf("\nNama Tim #%d: ", i + 1);
        scanf(" %[^\n]", liga[i].nama);    // Input string dengan spasi

        printf("Poin %s: ", liga[i].nama);
        scanf("%d", &liga[i].poin);        // Input poin (integer)
    }

    // Memanggil fungsi untuk mengurutkan tim berdasarkan poin
    urutkanTim(liga, jumlahTim);

    // Menampilkan klasemen akhir
    printf("\n--- Klasemen Akhir ---\n");
    printf("%-5s %-20s %-5s\n", "No", "Nama Tim", "Poin"); // Header tabel

    // Perulangan untuk mencetak isi array tim yang sudah diurutkan
    for (int i = 0; i < jumlahTim; i++) {
        printf("%-5d %-20s %-5d\n", i + 1, liga[i].nama, liga[i].poin); // Baris klasemen
    }

    return 0;   // Akhir program
}

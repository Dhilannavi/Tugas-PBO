#include <iostream>
#include <iomanip>

// Mendefinisikan kelas Akun 
class Akun {
private:
    int nomor;
    double saldo;

public:
    // Konstruktor pertama untuk menginisialisasi objek Akun dengan nomor tertentu dan saldo awal 0
    Akun(int nomor) {
        this->nomor = nomor;
        this->saldo = 0.0; 
    }

    // Konstruktor kedua untuk menginisialisasi objek Akun dengan nomor dan saldo awal tertentu
    Akun(int nomor, double saldo) {
        this->nomor = nomor;
        this->saldo = saldo;
    }

    // Fungsi getter untuk mendapatkan nomor akun
    int DapatkanNomor() {
        return this->nomor;
    }

    // Fungsi getter untuk mendapatkan saldo
    double DapatkanSaldo() {
        return this->saldo;
    }

    // Mengonversi Akun ke dalam bentuk string dengan format "Akun[nomor=...,saldo=$...]"
    std::string KonversiKeString() {
        return "Akun[nomor=" + std::to_string(this->nomor) + ",saldo=$" + std::to_string(this->saldo) + "]";
    }

    // Menambahkan jumlah tertentu ke saldo
    void Kredit(double jumlah) {
        this->saldo += jumlah;
    }

    // Mengurangi saldo sejumlah tertentu, jika saldo cukup
    void Debit(double jumlah) {
        if (this->saldo >= jumlah) {
            this->saldo -= jumlah;
        } else {
            std::cout << "jumlah melebihi saldo" << std::endl;
        }
    }

    // Mentransfer jumlah tertentu ke Akun lain, jika saldo cukup
    void TransferKe(double jumlah, Akun &tujuan) {
        if (this->saldo >= jumlah) {
            this->saldo -= jumlah;
            tujuan.Kredit(jumlah);
        } else {
            std::cout << "jumlah melebihi saldo" << std::endl;
        }
    }
};

int main() {
    // Membuat objek Akun dan menginisialisasi dengan nomor tertentu
    Akun akun1(5566);
    std::cout << akun1.KonversiKeString() << std::endl; 

    // Membuat objek Akun dengan nomor dan saldo awal tertentu
    Akun akun2(1234, 99.9);
    std::cout << akun2.KonversiKeString() << std::endl; 

    // Menggunakan fungsi DapatkanNomor() dan DapatkanSaldo() untuk mendapatkan informasi akun
    std::cout << "Nomor akun: " << akun2.DapatkanNomor() << std::endl; 
    std::cout << "Saldo: $" << akun2.DapatkanSaldo() << std::endl;

    // Menggunakan fungsi Kredit(), Debit(), dan TransferKe()
    akun1.Kredit(11.1);
    std::cout << akun1.KonversiKeString() << std::endl; 
    akun1.Debit(5.5);
    std::cout << akun1.KonversiKeString() << std::endl; 
    akun1.Debit(500); // Uji error debit
    std::cout << akun1.KonversiKeString() << std::endl; 

    akun2.TransferKe(1.0, akun1);
    std::cout << akun1.KonversiKeString() << std::endl; 
    std::cout << akun2.KonversiKeString() << std::endl; 

    return 0;
}

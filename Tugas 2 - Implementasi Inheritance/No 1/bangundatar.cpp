#include <iostream>
#include <string>
#include <cmath>

using namespace std; // Menggunakan namespace std

class BangunDatar {
public:
    string nama;

    BangunDatar(string n) : nama(n) {}

    virtual double hitungLuas() {
        
        return 0.0;
    }

    virtual double hitungKeliling() {
        
        return 0.0;
    }
};

class Persegi : public BangunDatar {
private:
    double sisi;

public:
    Persegi(string n, double s) : BangunDatar(n), sisi(s) {}

    double hitungLuas() override {
        return sisi * sisi;
    }

    double hitungKeliling() override {
        return 4 * sisi;
    }
};

class PersegiPanjang : public BangunDatar {
private:
    double panjang;
    double lebar;

public:
    PersegiPanjang(string n, double p, double l) : BangunDatar(n), panjang(p), lebar(l) {}

    double hitungLuas() override {
        return panjang * lebar;
    }

    double hitungKeliling() override {
        return 2 * (panjang + lebar);
    }
};

class Segitiga : public BangunDatar {
private:
    double sisi1;
    double sisi2;
    double sisi3;

public:
    Segitiga(string n, double s1, double s2, double s3) : BangunDatar(n), sisi1(s1), sisi2(s2), sisi3(s3) {}
    
    
        

    double hitungLuas() override {
        double s = (sisi1 + sisi2 + sisi3) / 2.0;
        return sqrt(s * (s - sisi1) * (s - sisi2) * (s - sisi3));
    }

    double hitungKeliling() override {
        return sisi1 + sisi2 + sisi3;
    }
};

class Lingkaran : public BangunDatar {
private:
    double jariJari;

public:
    Lingkaran(string n, double r) : BangunDatar(n), jariJari(r) {}

    double hitungLuas() override {
        return 3.14 * jariJari * jariJari;
    }

    double hitungKeliling() override {
        return 2 * 3.14 * jariJari;
    }
};

int main() {
    string namaBangunDatar;
    cout << "Masukkan jenis bangun datar (persegi, persegi_panjang, segitiga, lingkaran): ";
    cin >> namaBangunDatar;

    if (namaBangunDatar == "persegi") {
        double sisi;
        cout << "Masukkan panjang sisi: ";
        cin >> sisi;
        Persegi persegi(namaBangunDatar, sisi);
        cout << "Luas: " << persegi.hitungLuas() << endl;
        cout << "Keliling: " << persegi.hitungKeliling() << endl;
    } else if (namaBangunDatar == "persegi_panjang") {
        double panjang, lebar;
        cout << "Masukkan panjang: ";
        cin >> panjang;
        cout << "Masukkan lebar: ";
        cin >> lebar;
        PersegiPanjang persegiPanjang(namaBangunDatar, panjang, lebar);
        cout << "Luas: " << persegiPanjang.hitungLuas() << endl;
        cout << "Keliling: " << persegiPanjang.hitungKeliling() << endl;
    } else if (namaBangunDatar == "segitiga") {
        double s1, s2, s3;
        cout << "Masukkan panjang sisi 1: ";
        cin >> s1;
        cout << "Masukkan panjang sisi 2: ";
        cin >> s2;
        cout << "Masukkan panjang sisi 3: ";
        cin >> s3;
        if(s1 + s2 > s3 && s2 + s3 > s1 && s1 + s3 > s2) {
        Segitiga segitiga(namaBangunDatar, s1, s2, s3);
        cout << "Luas: " << segitiga.hitungLuas() << endl;
        cout << "Keliling: " << segitiga.hitungKeliling() << endl;
        }
        else {
            cout << "Sisi yang anda masukkan tidak membentuk segitiga, gunakan nilai yang valid!";
            return 0;
        }
        
    } else if (namaBangunDatar == "lingkaran") {
        double jariJari;
        cout << "Masukkan jari-jari: ";
        cin >> jariJari;
        Lingkaran lingkaran(namaBangunDatar, jariJari);
        cout << "Luas: " << lingkaran.hitungLuas() << endl;
        cout << "Keliling: " << lingkaran.hitungKeliling() << endl;
    } else {
        cout << "Jenis bangun datar tidak valid." << endl;
    }

    return 0;
}

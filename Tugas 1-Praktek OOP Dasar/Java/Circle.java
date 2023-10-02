/**
 * kelas Circle menggambarkan sebuah lingkaran dengan Jari Jari dan warna.
 */
public class Circle {
    // Variabel instan privat 
    private double JariJari;
    private String Warna;
 
    // Konstruktor (di-overload)
    /**Membuat sebuah instance lingkaran dengan radius dan warna default*/
    public Circle() {                   // konstruktor pertama  (konstruktor default)
       JariJari = 1.0;
       Warna = "Merah";
    }
    /** Membuat sebuah instance lingkaran dangan radius tertentu dan warna default*/
    public Circle(double r) {           // konstruktor kedua
       JariJari = r;
       Warna = "Merah";
    }
    /** Membuat sebuah instance lingkaran dengan radius dan warna tertentu*/
    public Circle(double r, String c) { // konstruktor ketiga
       JariJari = r;
       Warna = c;
    }
 
    // Metode public
    /** mengembalikan nilai dan jari jari*/
    public double getJariJari() {  // getter untuk Jari Jari 
       return JariJari;
    }
    /** Mengembalikan nilai warna */
    public String getWarna() {   // getter untuk warna
       return Warna;
    }
    /** Mengembalikan luas dan lingkaran  */
    public double getLuas() {
       return JariJari * JariJari * Math.PI;
    }
 }
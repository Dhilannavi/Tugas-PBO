/**
 * Program pengujian untuk kelas Circle
 */
public class TestCircle {    // Simpan sebagai "TestCircle.java"
   public static void main(String[] args) {   // Titik masuk program 
      // mendeklarasikan dan membuat sebuah instance dari kelas lingkaran yang disebut C1
      Circle c1 = new Circle(2.0, "Biru");  // Menggunakan konstruktor 3
      System.out.println("Jari Jarinya adalah : " + c1.getJariJari()); //Menggunakan konstruktor untuk memanggil metode anggota 
      System.out.println("Warnanya adalah : " + c1.getWarna());
      System.out.printf("Luasnya adalah : %.2f%n", c1.getLuas());

      // mendeklarasikan dan membuat instance lain dari kelas lingkaran yang di sebut c2
      Circle c2 = new Circle(2.0);  // Menggunakan kontruktor 2
      System.out.println("Jari Jarinya adalah : " + c2.getJariJari());
      System.out.println("Warnanya adalah : " + c2.getWarna());
      System.out.printf("Luasnya adalah : %.2f%n", c2.getLuas());

      // mendeklarasikan dan membuat instance lain dari kelas lingkaran yang disebut c3
      Circle c3 = new Circle();  // menggunakan konstruktor 1
      System.out.println("Jari Jarinya adalah : " + c3.getJariJari());
      System.out.println("Warnanya adalah : " + c3.getWarna());
      System.out.printf("Luasnya adalah : %.2f%n", c3.getLuas());
   }
}
/**
 *  Kelas time menggambarkan sebuah instance waktu dengan detik, menit, dan jam 
 * kelas ini tidak melakukan validasi input untuk detik, menit dan jam 
 */

public class Time {
    //Variabel instance privat 
    private int detik, menit, jam;

    //konstruktor (overloaded)
    // membuat instance Time dengan detik, menit, dan jam yang diberikan tidak ada validasi input
    public Time (int detik, int menit, int jam){
        this.detik = detik; 
        this.menit = menit;
        this.jam = jam;
    }

    //membuat instance Time dengan nilai default
    public Time(){
        this.detik = 0;
        this.menit = 0;
        this.jam = 0;
    }

    //getter/setter publik untuk variabel privat 
    // mengembalikan detik 
    public int getDetik(){
        return this.detik;
    }

    //mengembalikan menit
    public int getMenit(){
        return this.menit;
    }

    //mengembalikan jam
    public int getJam(){
        return this.jam;
    }

    //mengatur detik. tidak ada validasi input
    public void setDetik(int detik){
        this.detik = detik;
    }

    //mengatur menit. tidak ada validasi input
    public void setMenit(int menit){
        this.menit = menit;
    }

    //mengatur jam tidak ada validasi input 
    public void setJam(int jam){
        this.jam = jam;
    }

    //mengembalikan string yang menjelaskan dirinya sendiri dalam fromat "hh:mm:ss" dengan leading zeros
    public String toString(){
        // menggunakan fungsi bawaan String.format()untuk membentuk string yang diformat 
        return String.format ("%02d:%02d;%02d", jam, menit, detik);
        // "0" digunakan untuk mencetak loading zeros, jika tersedia 
    }

    //mengatur detik, menit dan jam ke nilai yang diberikan 
    public void setTime(int detik, int menit, int jam ){
        //tidak ada validasi input 
        this.detik = detik;
        this.menit = menit;
        this.jam = jam;
    }

    //melanjutkan intance waktu ini dengan satu detik dan mengembalikan instance ini untuk mendukung operasi berantai 
    public Time detikBerikutnya(){
        ++detik;
        if (detik >= 60){
            detik = 0;
            ++menit;
            if(menit>= 60){
                menit = 0;
                ++jam;
                if(jam>=24){
                    jam = 0;
                }
            }
        }
        return this; //mengembalikan instance "this" untuk mendukung operasi berantai 
    }
}


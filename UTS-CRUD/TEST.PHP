<?php
// Database configuration
$servername = "localhost";
$username = "username";
$password = "password";
$dbname = "nama_database";

// Class untuk CRUD dan pengelolaan gambar
class SepatuCRUD {
    private $conn;

    public function __construct($servername, $username, $password, $dbname) {
        // Membuat koneksi ke database
        $this->conn = new mysqli($servername, $username, $password, $dbname);

        // Memeriksa koneksi
        if ($this->conn->connect_error) {
            die("Koneksi gagal: " . $this->conn->connect_error);
        }
    }

    public function tambahSepatu($nama, $deskripsi, $harga, $gambar) {
        // Menyiapkan statement SQL untuk menambah sepatu
        $stmt = $this->conn->prepare("INSERT INTO sepatu (nama, deskripsi, harga, gambar) VALUES (?, ?, ?, ?)");
        $stmt->bind_param("ssis", $nama, $deskripsi, $harga, $gambar);

        // Mengeksekusi statement SQL
        $result = $stmt->execute();

        // Menutup statement
        $stmt->close();

        return $result;
    }

    public function ambilSepatu($id) {
        // Menyiapkan statement SQL untuk mengambil sepatu berdasarkan ID
        $stmt = $this->conn->prepare("SELECT * FROM sepatu WHERE id = ?");
        $stmt->bind_param("i", $id);

        // Mengeksekusi statement SQL
        $stmt->execute();

        // Mengambil hasil query
        $result = $stmt->get_result()->fetch_assoc();

        // Menutup statement
        $stmt->close();

        return $result;
    }

    public function ubahSepatu($id, $nama, $deskripsi, $harga, $gambar) {
        // Menyiapkan statement SQL untuk mengubah data sepatu
        $stmt = $this->conn->prepare("UPDATE sepatu SET nama = ?, deskripsi = ?, harga = ?, gambar = ? WHERE id = ?");
        $stmt->bind_param("ssisi", $nama, $deskripsi, $harga, $gambar, $id);

        // Mengeksekusi statement SQL
        $result = $stmt->execute();

        // Menutup statement
        $stmt->close();

        return $result;
    }

    public function hapusSepatu($id) {
        // Menyiapkan statement SQL untuk menghapus sepatu berdasarkan ID
        $stmt = $this->conn->prepare("DELETE FROM sepatu WHERE id = ?");
        $stmt->bind_param("i", $id);

        // Mengeksekusi statement SQL
        $result = $stmt->execute();

        // Menutup statement
        $stmt->close();

        return $result;
    }

    public function __destruct() {
        // Menutup koneksi ketika objek dihancurkan
        $this->conn->close();
    }
}

// Membuat objek SepatuCRUD
$sepatuCRUD = new SepatuCRUD($servername, $username, $password, $dbname);

// Contoh penggunaan
// $sepatuCRUD->tambahSepatu("Sepatu Sport", "Sepatu olahraga yang nyaman", 150000, "nama_gambar.jpg");
// $sepatu = $sepatuCRUD->ambilSepatu(1);
// $sepatuCRUD->ubahSepatu(1, "Sepatu Casual", "Sepatu santai untuk sehari-hari", 120000, "gambar_baru.jpg");
// $sepatuCRUD->hapusSepatu(1);
?>

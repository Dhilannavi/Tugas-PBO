<?php 
	session_start();
	include 'db.php';
?>
<!DOCTYPE html>
<html>
<head>
<link rel="stylesheet" href="https://maxcdn.bootstrapcdn.com/bootstrap/3.4.0/css/bootstrap.min.css">
</head>

<body>
	<!-- header -->
	<header>
		<div class="container">
			<h1>DATABASE SEPATU</h1>
			<ul>
				<li><a href="data-kategori.php">Data Kategori</a></li>
				<li><a href="data-produk.php">Data Produk</a></li>
			</ul>
		</div>
	</header>

	<!-- content -->
		<div class="container">
			<h3>Tambah Data Kategori</h3>
				<form action="" method="POST">
					<input type="text" name="nama" placeholder="Nama Kategori" class="input-control" required>
					<input type="submit" name="submit" value="Submit" class="btn">
				</form>
				<?php 
					if(isset($_POST['submit'])){

						$nama = ucwords($_POST['nama']);

						$insert = mysqli_query($conn, "INSERT INTO tb_category VALUES (
											null,
											'".$nama."') ");
						if($insert){
							echo '<script>alert("Tambah data berhasil")</script>';
							echo '<script>window.location="data-kategori.php"</script>';
						}else{
							echo 'gagal '.mysqli_error($conn);
						}

					}
				?>
		</div>

	<!-- footer -->
	<footer>
	</footer>
</body>
</html>
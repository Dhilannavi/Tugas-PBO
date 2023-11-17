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
			<h3>Data Kategori</h3>
				<p><a href="tambah-kategori.php">Tambah Data</a></p>
				<table class="table">
					<thead>
						<tr>
							<th width="30px">No</th>
							<th>Kategori</th>
							<th width="150px">Aksi</th>
						</tr>
					</thead>
					<tbody>
						<?php
							$no = 1;
							$kategori = mysqli_query($conn, "SELECT * FROM tb_category ORDER BY category_id DESC");
							if(mysqli_num_rows($kategori) > 0){
							while($row = mysqli_fetch_array($kategori)){
						?>
						<tr>
							<td><?php echo $no++ ?></td>
							<td><?php echo $row['category_name'] ?></td>
							<td>
								<a class="btn btn-info" href="edit-kategori.php?id=<?php echo $row['category_id'] ?>">Edit</a> || <a class="btn btn-danger" href="proses-hapus.php?idk=<?php echo $row['category_id'] ?>" onclick="return confirm('Yakin ingin hapus ?')">Hapus</a>
							</td>
						</tr>
						<?php }}else{ ?>
							<tr>
								<td colspan="3">Tidak ada data</td>
							</tr>
						<?php } ?>
					</tbody>
				</table>
		</div>

	<!-- footer -->
	<footer>
	</footer>
</body>
</html>
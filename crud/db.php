<?php 
	$hostname = 'localhost';
	$username = 'root';
	$password = '';
	$dbname   = 'crud';

	$conn = mysqli_connect($hostname, $username, $password, $dbname) or die ('Gagal terhubung ke database');
?>
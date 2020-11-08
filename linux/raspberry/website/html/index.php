<!doctype html>
<meta charset="utf-8">
<meta name="viewport" content="width=device-width, initial-scale=1">
<link rel="stylesheet" href="css/sensum.css">
<body>

	<div class="header">
		<h1>sensum</h1>
		<p>amplifier control interface</p>
	</div>

	<div class="navbar">
		<a href="index.php">amplifier</a>
		<a href="i2c.php">i2c</a>
		<a href="#">system</a>
		<a href="#" class="right">info</a>
	</div>

	<div class="row">
		<div class="side">
			<h2>the amplifer</h2>
			<h5>ma1207</h5>
			<div style="height:200px;">image</div>
			<p>if you want to get more information for this amplifier please refer to </p> 
			<h3>more text</h3>

		</div>
		<div class="main">
			<form action="index.php" method="get">
			<?php include('buttonMute.php'); ?>
			<?php include('buttonEnable.php'); ?>
			</form>
		</div>
</body>
</html>

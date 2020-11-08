<!DOCTYPE html>
<meta charset="UTF-8">
<meta name="viewport" content="width=device-width, initial-scale=1">
<link rel="stylesheet" href="css/sensum.css">
<body>

	<div class="header">
		<h1>SENSUM</h1>
		<p>I2C Communicatiom module</p>
	</div>

	<div class="navbar">
		<a href="index.php">Amplifier</a>
		<a href="i2c.php">I2C</a>
		<a href="#">System</a>
		<a href="#" class="right">Info</a>
	</div>

	<div class="row">
		<div class="side">
			<h1>Write</h1>
			<form action="i2c.php" method="get">
				<div class="container">
					<label for="send_i2caddress">Device</label>
					<select id="send_i2caddress" name="send_i2caddress">
						<option value="0x20">MA12070P 0x20</option>
						<option value="0x21">MA12070P 0x21</option>
					</select>
					<br>
					<label for="i2creg">Register</label>
					<input type="text" id="i2creg" name="send_register" placeholder="Ex: 0x25">
					<br>
					<label for="i2cdata">Data</label>
					<input type="text" id="i2cdata" name="send_data" placeholder="Ex: 0x25">
					<br>
					<br>
					<input type="submit" value="Send" name="send">
				</div>
			</form>

			<h3> 
				<?php
				if(isset($_GET['send']))
				{
					$sendReg=$_GET['send_register'];
					$sendAddress=$_GET['send_i2caddress'];
					$sendData=$_GET['send_data'];
					$command = "script/i2cComm.sh 1 "."$sendAddress"." "."$sendReg"." "."$sendData";
					echo("<br>");
					echo("Device: "."$sendAddress");
					echo("<br>");
					echo("Register: 0x"."$sendReg");
					echo("<br>");
					echo ("Data: 0x"."$sendData");
					echo("<br>");
					echo shell_exec("$command");	
				}
				?>	
			</h3>	
		</div>
		
		<div class="main">
			<h1>Read</h1>
			<form action="i2c.php" method="get">
				<div class="container">
					<label for="read_i2caddress">Device</label>
					<select id="read_i2caddress" name="read_i2caddress">
						<option value="0x20">MA12070P 0x20</option>
						<option value="0x21">MA12070P 0x21</option>
					</select>
					<br>
					<label for="i2creg">Register</label>
					<input type="text" id="i2creg" name="read_register" placeholder="Ex: 0x25">
					<br>
					<br>
					<input type="submit" value="Read" name="read">
				</div>
			</form>

			<h3>
				<?php
				if(isset($_GET['read']))
				{
					$readReg=$_GET['read_register'];
					$readAddress=$_GET['read_i2caddress'];
					$command = "script/i2cComm.sh 1 "."$readAddress"." "."$readReg";
					echo shell_exec("$command"); 	
				}
				?>	
			</h3>	
		</div>
	</div>

	<div class="footer">
		<h2>This website is under construction and only ment for internal use </h2>
	</div>

</body>
</html>

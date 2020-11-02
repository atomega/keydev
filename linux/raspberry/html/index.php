<!DOCTYPE html>
<meta charset="UTF-8">
<meta name="viewport" content="width=device-width, initial-scale=1">
<link rel="stylesheet" href="sensum.css">
<body>

	<div class="header">
		<h1>SENSUM</h1>
		<p>Amplifier Control Interface</p>
	</div>

	<div class="navbar">
		<a href="*">Amplifier</a>
		<a href="i2c.php">I2C</a>
		<a href="#">System</a>
		<a href="#" class="right">Info</a>
	</div>

	<div class="row">
		<div class="side">
			<h2>The amplifer</h2>
			<h5>MA1207</h5>
			<div class="fakeimg" style="height:200px;">Image</div>
			<p>If you want to get more information cvoncerning the used amplifieir please refer to :</p>
			<h3>More Text</h3>
			<p>Lorem ipsum dolor sit ame.</p>
			<div class="fakeimg" style="height:60px;">Image</div><br>
			<label for="i2creg">Register</label>
			<input type="text" id="i2creg" name="register" placeholder="Register to write">
			<br>
			<label for="i2cdata">Data</label>
			<input type="text" id="i2cdata" name="data" placeholder="Data to write">
			<br>
			<label for="i2caddress">Device</label>
			<select id="i2caddress" name="i2caddress">
				<option value="0x20">MA12070P 0x20</option>
				<option value="0x21">MA12070P 0x21</option>
			</select>
			<br>
			<input type="submit" value="Submit">
		</div>
		<div class="main">
			<h2>TITLE HEADING</h2>
			<h5>Title description, Dec 7, 2017</h5>
			<div class="fakeimg" style="height:200px;">Image</div>
			<p>Some text..</p>
			<p>Sunt in culpa qui officia deserunt mollit anim id est laborum consectetur adipiscing elit, sed do eiusmod tempor incididunt ut labore et dolore magna aliqua. Ut enim ad minim veniam, quis nostrud exercitation ullamco.</p>
			<br>
			<h2>TITLE HEADING</h2>
			<h5>Title description, Sep 2, 2017</h5>
			<div class="fakeimg" style="height:200px;">Image</div>
			<p>Some text..</p>
			<p>Sunt in culpa qui officia deserunt mollit anim id est laborum consectetur adipiscing elit, sed do eiusmod tempor incididunt ut labore et dolore magna aliqua. Ut enim ad minim veniam, quis nostrud exercitation ullamco.</p>
		</div>
	</div>

	<div class="footer">
		<h2>This website is under construction and only ment for internal use </h2>
	</div>

</body>
</html>

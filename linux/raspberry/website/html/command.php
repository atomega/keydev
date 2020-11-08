<?php
if (isset($_GET["mute"])) 
{
	$sm = strip_tags ($_GET['mute']);
	if($sm == "Mute")
	{
		echo("Mute Pressed<br>");
		shell_exec('bin/gpio/webGpio set mute low');
	}
	elseif($sm == "Sound") 
	{
		echo("Sound Pressed<br>");
		shell_exec('bin/gpio/webGpio set mute high');
	}
	else 
	{
		echo("Error<br>");
	}
}
?>


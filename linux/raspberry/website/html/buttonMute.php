<?php 
	if (!isset($_GET["muteOnOff"])) 
	{	
		$mutePin = shell_exec('bin/gpio/webGpio get mute');
		if($mutePin	== 0)
		{
			?><input type="submit" value="Mute" id="muteOnOff" name="muteOnOff" class="muteButton buttonRed" /> <?php
		}
		elseif($mutePin == 1)
		{
			?> <input type="submit" value="Sound" id="muteOnOff" name="muteOnOff" class="muteButton buttonGreen" /> <?php
		}
		else 
		{
			?><input type="submit" value="Error" id="mute" class="muteButton buttonGreen" /><?php
		}
	}
	
	if (isset($_GET["muteOnOff"])) 
	{
		$status=strip_tags($_GET["muteOnOff"]);
		if($status == "Sound")
		{
			shell_exec('bin/gpio/webGpio set mute low');
		}
		elseif($status == "Mute")
		{
			shell_exec('bin/gpio/webGpio set mute high');
		}
		else 
		{
			echo("Error : Unhandled _GET<br>");
		}
	
		$mutePin = shell_exec('bin/gpio/webGpio get mute');
		if($mutePin	== 0)
		{
			?><input type="submit" value="Mute" id="muteOnOff" name="muteOnOff" class="muteButton buttonRed" /> <?php
		}
		elseif($mutePin == 1)
		{
			?> <input type="submit" value="Sound" id="muteOnOff" name="muteOnOff" class="muteButton buttonGreen" /> <?php
		}
		else 
		{
			?><input type="submit" value="Error" id="mute" class="muteButton buttonGreen" /><?php
		}
	}
?>

<?php 
	if (!isset($_GET["enableOnOff"])) 
	{	
		$enablePin = shell_exec('bin/gpio/webGpio get enable');
		if($enablePin == 1)
		{
			?><input type="submit" value="Disable" id="enableOnOff" name="enableOnOff" class="muteButton buttonRed" /> <?php
		}
		elseif($enablePin == 0)
		{
			?> <input type="submit" value="Enable" id="enableOnOff" name="enableOnOff" class="muteButton buttonGreen" /> <?php
		}
		else 
		{
			?><input type="submit" value="Error" id="enableOnOff" name="enableOnOff" class="muteButton buttonRed" /> <?php
		}
	}
	
	if (isset($_GET["enableOnOff"])) 
	{
		$status=strip_tags($_GET["enableOnOff"]);
		if($status == "Enable")
		{
			shell_exec('bin/gpio/webGpio set enable high');
		}
		elseif($status == "Disable")
		{
			shell_exec('bin/gpio/webGpio set enable low');
		}
		else 
		{
			echo("Error : Unhandled _GET<br>");
		}
	
		$enablePin = shell_exec('bin/gpio/webGpio get enable');
		if($enablePin == 1)
		{
			?><input type="submit" value="Disable" id="enableOnOff" name="enableOnOff" class="muteButton buttonRed" /> <?php
		}
		elseif($enablePin == 0)
		{
			?> <input type="submit" value="Enable" id="enableOnOff" name="enableOnOff" class="muteButton buttonGreen" /> <?php
		}
		else 
		{
			?><input type="submit" value="Error" id="enableOnOff" name="enableOnOff" class="muteButton buttonRed" /> <?php
		}
	}
?>

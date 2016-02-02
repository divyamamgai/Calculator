<?php
	if(isset($_POST['SETUP_FLAG'])){
		$HOST = $_POST['host'];
		$USER = $_POST['user'];
		$PASS = $_POST['pass'];
		$Mysql_connection = mysql_connect($HOST,$USER,$PASS);
		if($Mysql_connection){
		    $SettingsFile = fopen("settings_data.dat",'w');
			$SettingsString = "[MYSQLHOST::".$HOST."][MYSQLUSER::".$USER."][MYSQLPASS::".$PASS."][DEFAULT_TIMEZONE::Asia/Calcutta][SITE_TITLE::Calculator.1.0]";
		    fwrite($SettingsFile,$SettingsString);
		    fclose($SettingsFile);
		    $SetupFlagFile = fopen("setup_done_flag.bin",'w');
		    fwrite($SetupFlagFile,"1");
		    fclose($SetupFlagFile);
			mysql_query("CREATE DATABASE cs_project");
			header('Location: setupdone.php');
			die();
		}else{
			$ErrorFlag = 1;
		}
	}
?>
<h1 style="position:relative;top:15px;left:15px;width:800px">Calculator.1.0 Development Tools Setup</h1>
<hr style="border: 1px solid #666;">
<style>
   body {
   background:black;
   color:grey;
   font-family:VideoTerminalScreen-Normal;
   }
   textarea,input {
   border: 2px solid #666;
   background:black;
   font-size:12pt;
   font-family:VideoTerminalScreen-Normal;
   color:grey;
   padding-left:5px;
   padding-right:5px;
   padding-top:5px;
   padding-bottom:5px;
   outline:none;
   }
   input:hover{
   background:#666;
   color:black;
   outline:none;
   }
   div.MSG{
   position:absolute;
   top:10px;
   right:10px;
   border: 2px solid #666;
   font-size:12pt;
   padding-left:8px;
   padding-right:8px;
   padding-top:8px;
   padding-bottom:5px;
   background:#666;
   color:#000;
   }
   div.action{
   position:absolute;
   top:44px;
   left:39%;
   outline:none;
   }
   a.button{
   text-decoration:none;
   border: 2px solid #666;
   font-size:12pt;
   padding-left:8px;
   padding-right:8px;
   padding-top:8px;
   padding-bottom:5px;
   color:grey;
   outline:none;
   position:relative;
   left:20px;
   }
   a.button:hover{
   border: 2px solid #666;
   font-size:12pt;
   padding-left:8px;
   padding-right:8px;
   padding-top:8px;
   padding-bottom:5px;
   background:#666;
   color:#000;
   }
</style>
<?php
	if(isset($_POST['SETUP_FLAG'])){
		if($ErrorFlag){
			echo "<h2>Error! The Host-Name, User-Name and Password you provided do not match the server information, please retry with correct data.</h2>";
		}
	}
?>
<form action="setup.php" method="post">
			<input type="text" name="SETUP_FLAG" style="width:0px;height:0px;position:absolute;padding: 0px 0px 0px 0px;border:none;" value="1">
			Enter Your MYSQL Host-Name: <input type="text" name="host" style="width:390pt;">
			<br>
			Enter Your MYSQL User-Name: <input type="text" name="user" style="width:390pt;">
			<br>
			Enter Your MYSQL Password  : <input type="password" name="pass" style="width:390pt;">
			<br>
            <input type="submit" style="border: 2px solid #666;padding-top:8px;padding-left:8px;padding-right:8px;position:relative;right:-2px;" value="Complete Setup">
</form>